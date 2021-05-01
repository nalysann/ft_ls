#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <unistd.h>

#include "ft_stdlib.h"
#include "ft_string.h"
#include "ft_vector.h"

#include "args.h"
#include "cmp.h"
#include "error.h"
#include "item.h"
#include "options.h"
#include "parse.h"

static void	handle_options(unsigned int *options, unsigned int op)
{
	*options |= op;
	if (op == OP_G_LOWER)
	{
		*options |= OP_L_LOWER;
		op = OP_L_LOWER;
	}
	if (op == OP_C_UPPER)
		*options &= ~OP_L_LOWER & ~OP_X_LOWER & ~OP_ONE;
	else if (op == OP_L_LOWER)
		*options &= ~OP_C_UPPER & ~OP_X_LOWER & ~OP_ONE;
	else if (op == OP_X_LOWER)
		*options &= ~OP_C_UPPER & ~OP_L_LOWER & ~OP_ONE;
	else if (op == OP_ONE)
		*options &= ~OP_C_UPPER & ~OP_L_LOWER & ~OP_X_LOWER;
	else if (op == OP_F_LOWER)
		*options |= OP_A_LOWER;
	else if (op == OP_C_LOWER)
		*options &= ~OP_U_LOWER;
	else if (op == OP_U_LOWER)
		*options &= ~OP_C_LOWER;
	else if (op == OP_G_UPPER && !isatty(STDOUT_FILENO))
		*options &= ~OP_G_UPPER;
}

static int	parse_options(int argc, char *argv[], unsigned int *options)
{
	int		i;
	int		j;
	char	*pos;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-' || ft_strcmp(argv[i], "-") == 0)
			break ;
		if (ft_strcmp(argv[i], "--") == 0)
			return (i + 1);
		j = 1;
		while (argv[i][j] != '\0')
		{
			pos = ft_strchr(OPTIONS, argv[i][j]);
			if (pos == NULL)
				illegal_option(argv[i][j]);
			handle_options(options, 1U << (pos - OPTIONS));
			++j;
		}
		++i;
	}
	return (i);
}

static char	*get_path(const char *name, const char *parent)
{
	char	*path;
	size_t	parent_len;
	size_t	name_len;

	if (!parent)
		return (ft_strdup(name));
	parent_len = ft_strlen(parent);
	if (parent[parent_len - 1] == '/')
		--parent_len;
	name_len = ft_strlen(name);
	path = (char *)xmalloc(parent_len + 1 + name_len + 1);
	ft_memmove(path, parent, parent_len);
	path[parent_len] = '/';
	ft_memmove(path + parent_len + 1, name, name_len);
	path[parent_len + 1 + name_len] = '\0';
	return (path);
}

void	add_item(t_vector *items, const char *name, const char *parent)
{
	t_item		*item;
	char		buf[PATH_MAX + 1];
	ssize_t		ret;

	item = (t_item *)xcalloc(1, sizeof(t_item));
	item->path = get_path(name, parent);
	item->path_len = ft_strlen(item->path);
	if (parent)
	{
		item->name = ft_strdup(name);
		item->name_len = ft_strlen(item->name);
	}
	lstat(item->path, &item->st);
	if (S_ISLNK(item->st.st_mode))
	{
		ret = readlink(item->path, buf, PATH_MAX);
		buf[ret] = '\0';
		item->link = ft_strdup(buf);
		item->link_len = ft_strlen(item->link);
	}
	vector_push_back(items, item);
}

void	parse(int argc, char *argv[], t_args *args, unsigned int *options)
{
	int				i;
	struct stat		st;

	i = parse_options(argc, argv, options);
	if (i + 1 < argc)
		*options |= OP_DIR_NAME;
	while (i < argc)
	{
		if (lstat(argv[i], &st) != 0 && errno == ENOENT)
			vector_push_back(&args->absent, argv[i]);
		else
			add_item(&args->present, argv[i], NULL);
		++i;
	}
	if (args->present.size == 0)
		add_item(&args->present, ".", NULL);
	if (*options & OP_F_LOWER)
		return ;
	vector_sort(&args->absent, cmp_str_lex);
	vector_sort(&args->present, cmp_item_lex);
}
