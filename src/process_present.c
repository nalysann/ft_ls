#include <dirent.h>
#include <errno.h>
#include <stdbool.h>

#include "ft_stdio.h"
#include "ft_string.h"
#include "ft_vector.h"

#include "cmp.h"
#include "error.h"
#include "item.h"
#include "options.h"
#include "parse.h"
#include "print.h"

static void	process_files(t_vector present, unsigned int *options)
{
	t_vector	files;
	size_t		i;
	t_item		*item;

	files = vector_on_stack();
	i = 0;
	while (i < present.size)
	{
		item = (t_item *)present.data[i++];
		item->dir = opendir(item->path);
		if (!item->dir)
		{
			if (errno == ENOTDIR)
				vector_push_back(&files, item);
			else
				print_error(options, item->path, errno);
		}
	}
	print(files, options);
}

static bool	is_processable(t_item *item, unsigned int *options)
{
	if ((S_ISDIR(item->st.st_mode))
		&& !(ft_strequ(item->name, "."))
		&& !(ft_strequ(item->name, "..")))
	{
		ft_putchar('\n');
		ft_putstr(item->path);
		ft_putendl(":");
		item->dir = opendir(item->path);
		if (!item->dir)
			print_error(options, item->name, errno);
		else
			return (true);
	}
	return (false);
}

static void	process_contents(t_vector dir_contents, unsigned int *options)
{
	if (!(*options & OP_F_LOWER))
	{
		vector_sort(&dir_contents, cmp_item_lex);
		if (*options & OP_T_LOWER)
			vector_sort(&dir_contents, ???);
	}
	if (*options & OP_R_LOWER)
		vector_reverse(&dir_contents);
//	if (*options & OP_L_LOWER)
//	{
//		ft_putstr("total ");
//		ft_putnbr_lli(get_total_blocks(*head));
//		write(1, "\n", 1);
//	}
	print(dir_contents, options);
}

static void	process_dir(t_item *item, unsigned int *options)
{
	t_vector		dir_contents;
	struct dirent	*dirent;
	size_t			i;
	t_item			*dir_item;

	dir_contents = vector_on_stack();
	dirent = readdir(item->dir);
	while (dirent)
	{
		if (!(*options & OP_A_UPPER & OP_A_LOWER) && dirent->d_name[0] == '.')
			continue ;
		if ((*options & OP_A_UPPER) && !(*options & OP_A_LOWER)
		&& (ft_strequ(dirent->d_name, ".") || ft_strequ(dirent->d_name, "..")))
			continue ;
		add_item(&dir_contents, dirent->d_name, item->path);
		dirent = readdir(item->dir);
	}
	closedir(item->dir);
	process_contents(dir_contents, options);
	i = 0;
	if (*options & OP_R_UPPER)
		while (i < dir_contents.size)
		{
			dir_item = (t_item *)dir_contents.data[i++];
			if (is_processable(dir_item, options))
				process_dir(dir_item, options);
		}
	vector_free_deep(&dir_contents, ???);
}

void	process_present(t_vector present, unsigned int *options)
{
	size_t	i;
	t_item	*item;
	bool	first;

	process_files(present, options);
	i = 0;
	first = true;
	while (i < present.size)
	{
		item = (t_item *)present.data[i++];
		if (item->dir)
		{
			if (*options & OP_DIR_NAME)
			{
				if (!first)
					ft_putchar('\n');
				first = false;
				ft_putstr(item->path);
				ft_putendl(":");
			}
			process_dir(item, options);
		}
	}
}
