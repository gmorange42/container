#!/bin/sh
g++ -fsanitize=address -D NAMESPACE=std print.cpp swap_main.cpp && ./a.out > real
g++ -fsanitize=address -D NAMESPACE=ft print.cpp swap_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
[ -s res ] && echo " KO" || echo " OK"