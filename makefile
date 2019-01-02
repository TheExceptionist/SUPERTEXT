exe_name = deliverants
objects = defs.o room.o optiontypes.o entity.o skill.o main.o
flags = -c -Wc++11-extensions

$(exe_name) : $(objects)
	g++ -o $(exe_name) $(objects)
	make clean

$(objects) : defs.h

defs.o : defs.cpp 
	g++ $(flags) defs.cpp

main.o : main.cpp room.h player.h
	g++ $(flags) main.cpp

room.o : room.cpp room.h option.h player.h
	g++ $(flags) room.cpp

optiontypes.o : optiontypes.cpp optiontypes.h option.h room.h player.h
	g++ $(flags) optiontypes.cpp

entity.o : entity.cpp entity.h
	g++ $(flags) entity.cpp

skill.o : skill.cpp skill.h entity.h
	g++ $(flags) skill.cpp

.PHONY : clean reset

clean : 
	rm *.o

reset :
	rm *.o
	rm $(exe_name) 
