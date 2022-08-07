#!/bin/sh
c++ -fsanitize=address -D NAMESPACE=std print.cpp modifier_main.cpp && ./a.out > real
c++ -fsanitize=address -D NAMESPACE=ft print.cpp modifier_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"
