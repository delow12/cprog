all:
	g++ $(f).cpp && ./a.out < $(f).inp > $(f).tmp && diff $(f).tmp $(f).outp
	rm -f $(f).tmp

p:
	g++ -DDEBUG $(f).cpp && ./a.out < $(f).inp

t: 
	g++ $(f).cpp && ./a.out 

d:
debug:
	g++ -g -gdwarf-3 $(f).cpp && gdb ./a.out
