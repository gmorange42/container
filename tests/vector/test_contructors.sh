#!/bin/sh
c++ -Wall -Wextra -Werror -std=c++98 -fsanitize=leak -fsanitize=address -D NAMESPACE=std ../../srcs/vector/constructor_main.cpp && ./a.out > real
c++ -Wall -Wextra -Werror -std=c++98 -fsanitize=leak -fsanitize=address -D NAMESPACE=ft ../../srcs/vector/constructor_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"