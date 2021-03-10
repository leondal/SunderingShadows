// /d/tharis/Tharis/over_gate.c //
#include <std.h>
inherit ROOM;
void create() {
     ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
    set_light(2);
    set_indoors(0);
   set_short("The ramparts of the wall around Tharis");
    set_long(
@OLI
	You are on the causeway over the north gate. Below 
you, as always, the north gates stand open. People travel freely 
through the gates. The exception being the occasional elf that 
attempts to pass. The guards vigorously repel him. To either 
side of you are the towers flanking the north gate.
OLI
    );
   set_smell("default","Your senses are accosted by the normal smells of a city.");
   set_listen("default","The city bustles below you.");
    set_exits(([
"east" : "/d/tharis/Tharis/tower6",
"west" : "/d/tharis/Tharis/tower1"
    ] ));
}

void reset(){
int num;
int i;
 ::reset();
  if(!present("patrol") && !random(4)) {
num=random(4);

for(i=0;i<num;i++){
  new("d/tharis/monsters/wall_patrol")->move(TO);
}
}
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/