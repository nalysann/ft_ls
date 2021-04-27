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
        include/cmp.h
        include/error.h
        include/file.h
        include/init.h
        include/options.h
        include/parse.h
        include/process.h
        src/cmp.c
        src/error.c
        src/init.c
        src/main.c
        src/parse.c
        src/process_absent.c
        src/process_files.c)

target_link_libraries(ft_ls ft)
