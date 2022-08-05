#!/bin/sh
g++ -fsanitize=address -D NAMESPACE=std operation_main.cpp && ./a.out > real
g++ -fsanitize=address -D NAMESPACE=ft operation_main.cpp && ./a.out > mine
diff  -u5 real mine
rm real
rm mine
