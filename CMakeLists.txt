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
        include/item.h
        include/init.h
        include/options.h
        include/parse.h
        include/print.h
        include/process.h
        src/cmp.c
        src/error.c
        src/init.c
        src/main.c
        src/parse.c
        src/print.c
        src/process_absent.c
        src/process_present.c)

target_link_libraries(ft_ls ft)
