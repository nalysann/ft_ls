#include "ft_stdio.h"
#include "ft_vector.h"

#include "file.h"
#include "options.h"

//void	parse_time(t_file *file, time_t now)
//{
//	(void)file;
//	(void) now;
//	// todo: fill month and day, fill time or year (that depends on diff between now and file time)
//}

void	print_files_long(t_vector file_stats, unsigned *options, int is_dir)
{
	t_file	*file;
	size_t	i;

	i = 0;
	(void)is_dir;
	(void)options;
//	if (is_dir)
//		print_total();
	while (i < file_stats.size)
	{
		file = (t_file *)vector_get(&file_stats, i);

	username = ft_strdup(getpwuid(file->st.st_uid)->pw_name);
	groupname = ft_strdup(getgrgid(file->st.st_gid)->gr_name);
	file->user_name = username; // think how to detect not known users and what to do with them
	file->group_name = groupname;
	parse_time(file, now);
	ft_printf("%s\t%s\t%u\t%s\n", username, groupname, file->st.st_size, file->name);
		++i;
	}
}

void	print_files(t_vector file_stats, unsigned *options, int is_dir)
{
	t_file	*file;
	size_t	i;
//	time_t	now;

	i = 0;
	// TODO
	(void)is_dir;
	(void)options;
//	if (is_dir)
//		print_total();
//	now = time(NULL);
	while (i < file_stats.size)
	{
		file = (t_file *)vector_get(&file_stats, i);
		ft_printf("%s\t", file->name);
		++i;
	}
	if (file_stats.size > 0)
		ft_printf("\n");
}
