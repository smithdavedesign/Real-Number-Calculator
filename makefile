Real.out : Real.o smithH6.o
	g++ -ggdb -std=c++11 Real.o smithH6.o -o Real.out -g

Real.o : Real.h Real.cpp
	g++ -ggdb -std=c++11 -c -o Real.o Real.cpp -g  

smithH6.o : Real.h smithH6.cpp 
	g++ -ggdb -std=c++11 -c -o smithH6.o smithH6.cpp -g

run:
	./Real.o

clean:
	rm Real.out Real.o smithH6.o

submit: smithH6.cpp makefile README.txt Real.cpp Real.h
	rm -rf smithH6
	mkdir smithH6
	cp smithH6.cpp smithH6
	cp makefile smithH6
	cp README.txt smithH6
	cp Real.cpp smithH6
	cp Real.h smithH6
	tar cfvz smithH6.tgz smithH6
	cp smithH6.tgz ~tiawatts/cs460drop
