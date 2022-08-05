#!/bin/sh
g++ -fsanitize=address -D NAMESPACE=std print.cpp modifier_main.cpp && ./a.out > real
g++ -fsanitize=address -D NAMESPACE=ft print.cpp modifier_main.cpp && ./a.out > mine
diff  -u5 real mine
rm real
rm mine
