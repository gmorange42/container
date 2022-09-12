#!/bin/sh
//c++ -Wall -Wextra -Werror -std=c++98 -fsanitize=leak -fsanitize=address -D NAMESPACE=std main.cpp && ./a.out > real
//c++ -Wall -Wextra -Werror -std=c++98 -fsanitize=leak -fsanitize=address -D NAMESPACE=ft main.cpp && ./a.out > mine
c++ -Wall -Wextra -Werror -std=c++98 -D NAMESPACE=std main.cpp && ./a.out > real
c++ -Wall -Wextra -Werror -std=c++98 -D NAMESPACE=ft main.cpp && ./a.out > mine
diff -U 15 real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"
