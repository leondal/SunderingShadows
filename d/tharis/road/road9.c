// d/tharis/road/road8.c//

#include <std.h>
#include "../tharis.h"

inherit ROOM;
void create() {
    room::create();	
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
    set_light(2);
    set_indoors(0);
   set_short("You are before the city of Tharis");
    set_long(
@OLI
   Before you towers the grand city of Tharis. The majesty 
of Dwarvish stonework is epitomized by the glorious gate you 
stand before. The large wooden doors stand open and the double 
portcullises are raised welcoming all comers. The walls of the city 
stretch distantly in either direction. The ramparts seem to be 
manned only superficially, but there are two very real guards before 
the gates wielding halberds. Traffic, however, seems to flow freely 
through the gates. The road continues south into the city and there 
is a crossroad running east and west following the wall.
OLI
    );
set_smell("default","The fragrances of the forest are lost to the typical smells of a city
here.");
set_listen("default","The sounds of the bustle of the city extend to you here.");
    set_exits(([
"south" : ROOMS"main1",
"north" : "/d/tharis/road/road8",
"east": "/d/tharis/road/road11",
"west": "/d/tharis/road/road10"
    ] ));
    set_items(([
       "road" : "The road is deeply rutted by the eons of travel by heavily laden wagons of trade.",
"gate": "The gate stands open with a welcoming appearance. One guard stands on eitherside of the gate.",
"wall" : "The wall stands about 20 feet tall and is topped with ramparts which are mannedsparsely."
    ] ));
set_pre_exit_functions(({"south"}),({"try_south"}));
}

void reset(){
	::reset();
 	if(!present("guard")){
		new("d/tharis/monsters/gguard")->move(TO);
 		new("d/tharis/monsters/gguard")->move(TO);
}
}
int try_south(){
	string race;
   if(!present("guard")) return 1;
   if(avatarp(TP)) return 1;
   if(TP->query_invis()) return 1;
	race = TP->query_race();
	switch(race){
   case "drow":

case "elf":
tell_room(ETP,"Elves can't use this gate. Use the east gate.");
			return 0;
break;
case "half-elf": tell_room(ETP,"The guards look at "+TPQCN+" evilly.");
			return 1;
break;
		default: return 1;
}
}
