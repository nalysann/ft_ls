# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/09 19:01:03 by nalysann          #+#    #+#              #
#    Updated: 2020/10/09 19:01:04 by nalysann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.17)
project(ft_ls C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -O2 -march=native -ftree-vectorize -pipe")

include_directories(include)
include_directories(libft/include)

add_subdirectory(libft)

add_executable(ft_ls
        include/args.h
        include/error.h
        include/ft_ls.h
        include/init.h
        include/parse.h
        src/error.c
        src/init.c
        src/main.c

        src/parse.c
 include/options.h src/cmp.c include/cmp.h src/process.c include/process.h src/process_long.c)

target_link_libraries(ft_ls ft)
