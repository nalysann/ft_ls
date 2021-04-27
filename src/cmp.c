#include "ft_string.h"

#include "file.h"

int		cmp_lexicographical(const void *a, const void *b)
{
	return ft_strcmp(*(const char **)a, *(const char **)b);
}

int		cmp_modification_time(const void *a, const void *b)
{
	t_file	*file_a;
	t_file	*file_b;
	int		time_diff;

	file_a = *(t_file **)a;
	file_b = *(t_file **)b;
	time_diff = file_a->st.st_mtimespec.tv_sec - file_b->st.st_mtimespec.tv_sec;
	if (time_diff == 0)
		return (ft_strcmp(file_b->name, file_a->name));
	return (time_diff);
}

int	compare_by_time_modified(const void *obj1, const void *obj2)
{
	t_file	*file1;
	t_file	*file2;
	int		time_diff;

	if (obj1 == NULL || obj2 == NULL)
		return (0);
	file1 = *(t_file **)obj1;
	file2 = *(t_file **)obj2;
	time_diff = file2->st.st_mtimespec.tv_sec - file1->st.st_mtimespec.tv_sec;
	if (time_diff == 0)
		return (ft_strcmp(file1->name, file2->name));
	return (time_diff);
}

int	compare_by_name_rev(const void *obj1, const void *obj2)
{
	t_file	*file1;
	t_file	*file2;

	if (obj1 == NULL || obj2 == NULL)
		return (0);
	file1 = *(t_file **)obj1;
	file2 = *(t_file **)obj2;
	return (ft_strcmp(file2->name, file1->name));
}

int	compare_by_name(const void *obj1, const void *obj2)
{
	t_file	*file1;
	t_file	*file2;

	if (obj1 == NULL || obj2 == NULL)
		return (0);
	file1 = *(t_file **)obj1;
	file2 = *(t_file **)obj2;
	return (ft_strcmp(file1->name, file2->name));
}
