#!/bin/sh
g++ -fsanitize=address -D NAMESPACE=std print.cpp assign_main.cpp && ./a.out > real
g++ -fsanitize=address -D NAMESPACE=ft print.cpp assign_main.cpp && ./a.out > mine
diff real mine
