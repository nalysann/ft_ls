#ifndef ITEM_H
# define ITEM_H

# include <dirent.h>
# include <sys/stat.h>

struct s_item
{
	struct stat		st;
	DIR				*dir;
	const char		*path;
	const char		*name;
	const char		*link;
	size_t			name_len;
	size_t			path_len;
	size_t			link_len;
//	char			*user_name;
//	char			*group_name;
//	char			*month_and_day;
//	char			*time_or_year;
};

typedef struct s_item	t_item;

#endif
