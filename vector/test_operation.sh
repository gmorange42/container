#!/bin/sh
c++ -fsanitize=address -D NAMESPACE=std operation_main.cpp && ./a.out > real
c++ -fsanitize=address -D NAMESPACE=ft operation_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"
