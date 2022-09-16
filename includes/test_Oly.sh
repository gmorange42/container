#!/bin/sh
c++ -Wall -Wextra -Werror -std=c++98 -fsanitize=leak -fsanitize=address main_real.cpp && ./a.out > real
c++ -Wall -Wextra -Werror -std=c++98 -fsanitize=leak -fsanitize=address main_mine.cpp && ./a.out > mine
diff -U 15 real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"
rm res real mine
