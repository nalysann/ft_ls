#ifndef FILE_H
# define FILE_H

# include <sys/stat.h>

typedef struct		s_file
{
	struct stat		st;
	char			*name;
//	char			*parent;
//	char			*user_name;
//	char			*group_name;
//	char			*month_and_day;
//	char			*time_or_year;
}					t_file;

#endif
