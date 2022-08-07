#!/bin/sh
c++ -fsanitize=address -D NAMESPACE=std -D FOOFIRST=5 -D FOOSECOND=\"pouet\" -D BARFIRST=5 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > real
c++ -fsanitize=address -D NAMESPACE=ft -D FOOFIRST=5 -D FOOSECOND=\"pouet\" -D BARFIRST=5 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"

c++ -fsanitize=address -D NAMESPACE=std -D FOOFIRST=4 -D FOOSECOND=\"pouet\" -D BARFIRST=5 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > real
c++ -fsanitize=address -D NAMESPACE=ft -D FOOFIRST=4 -D FOOSECOND=\"pouet\" -D BARFIRST=5 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"

c++ -fsanitize=address -D NAMESPACE=std -D FOOFIRST=7 -D FOOSECOND=\"pouet\" -D BARFIRST=5 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > real
c++ -fsanitize=address -D NAMESPACE=ft -D FOOFIRST=7 -D FOOSECOND=\"pouet\" -D BARFIRST=5 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"

c++ -fsanitize=address -D NAMESPACE=std -D FOOFIRST=5 -D FOOSECOND=\"pouet\" -D BARFIRST=3 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > real
c++ -fsanitize=address -D NAMESPACE=ft -D FOOFIRST=5 -D FOOSECOND=\"pouet\" -D BARFIRST=3 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"

c++ -fsanitize=address -D NAMESPACE=std -D FOOFIRST=5 -D FOOSECOND=\"pouet\" -D BARFIRST=8 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > real
c++ -fsanitize=address -D NAMESPACE=ft -D FOOFIRST=5 -D FOOSECOND=\"pouet\" -D BARFIRST=8 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"

c++ -fsanitize=address -D NAMESPACE=std -D FOOFIRST=5 -D FOOSECOND=\"ouet\" -D BARFIRST=5 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > real
c++ -fsanitize=address -D NAMESPACE=ft -D FOOFIRST=5 -D FOOSECOND=\"ouet\" -D BARFIRST=5 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"

c++ -fsanitize=address -D NAMESPACE=std -D FOOFIRST=5 -D FOOSECOND=\"pouet\" -D BARFIRST=5 -D BARSECOND=\"puet\" relational_operators_main.cpp && ./a.out > real
c++ -fsanitize=address -D NAMESPACE=ft -D FOOFIRST=5 -D FOOSECOND=\"pouet\" -D BARFIRST=5 -D BARSECOND=\"puet\" relational_operators_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"

c++ -fsanitize=address -D NAMESPACE=std -D FOOFIRST=5 -D FOOSECOND=\"aouet\" -D BARFIRST=5 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > real
c++ -fsanitize=address -D NAMESPACE=ft -D FOOFIRST=5 -D FOOSECOND=\"aouet\" -D BARFIRST=5 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"

c++ -fsanitize=address -D NAMESPACE=std -D FOOFIRST=5 -D FOOSECOND=\"pouet\" -D BARFIRST=5 -D BARSECOND=\"aouet\" relational_operators_main.cpp && ./a.out > real
c++ -fsanitize=address -D NAMESPACE=ft -D FOOFIRST=5 -D FOOSECOND=\"pouet\" -D BARFIRST=5 -D BARSECOND=\"aouet\" relational_operators_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"

c++ -fsanitize=address -D NAMESPACE=std -D FOOFIRST=5 -D FOOSECOND=\"zouet\" -D BARFIRST=5 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > real
c++ -fsanitize=address -D NAMESPACE=ft -D FOOFIRST=5 -D FOOSECOND=\"zouet\" -D BARFIRST=5 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"

c++ -fsanitize=address -D NAMESPACE=std -D FOOFIRST=5 -D FOOSECOND=\"pouet\" -D BARFIRST=5 -D BARSECOND=\"zouet\" relational_operators_main.cpp && ./a.out > real
c++ -fsanitize=address -D NAMESPACE=ft -D FOOFIRST=5 -D FOOSECOND=\"pouet\" -D BARFIRST=5 -D BARSECOND=\"zouet\" relational_operators_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"

c++ -fsanitize=address -D NAMESPACE=std -D FOOFIRST=0 -D FOOSECOND=\"poue\" -D BARFIRST=5 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > real
c++ -fsanitize=address -D NAMESPACE=ft -D FOOFIRST=0 -D FOOSECOND=\"poue\" -D BARFIRST=5 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"

c++ -fsanitize=address -D NAMESPACE=std -D FOOFIRST=5 -D FOOSECOND=\"pouet\" -D BARFIRST=0 -D BARSECOND=\"poue\" relational_operators_main.cpp && ./a.out > real
c++ -fsanitize=address -D NAMESPACE=ft -D FOOFIRST=5 -D FOOSECOND=\"pouet\" -D BARFIRST=0 -D BARSECOND=\"poue\" relational_operators_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"

c++ -fsanitize=address -D NAMESPACE=std -D FOOFIRST=55 -D FOOSECOND=\"poouet\" -D BARFIRST=5 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > real
c++ -fsanitize=address -D NAMESPACE=ft -D FOOFIRST=55 -D FOOSECOND=\"poouet\" -D BARFIRST=5 -D BARSECOND=\"pouet\" relational_operators_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"

c++ -fsanitize=address -D NAMESPACE=std -D FOOFIRST=5 -D FOOSECOND=\"pouet\" -D BARFIRST=55 -D BARSECOND=\"poouet\" relational_operators_main.cpp && ./a.out > real
c++ -fsanitize=address -D NAMESPACE=ft -D FOOFIRST=5 -D FOOSECOND=\"pouet\" -D BARFIRST=55 -D BARSECOND=\"poouet\" relational_operators_main.cpp && ./a.out > mine
diff real mine > res
echo -n $0
cat res
[ -s res ] && echo " KO" || echo " OK"
