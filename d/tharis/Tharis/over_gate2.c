// /d/tharis/Tharis/over_gate2.c //
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
	You are on the causeway over the east gate. Below you, the drags 
of this community's citizens meander in and out. People travel freely through the gates. This is the only entrance that elves are really allowed to use. The guards look as if this duty is the utmost of possible punishments. To the north is a guard tower. To the south the wall runs into the mountain which this city is built into.
OLI
    );
   set_smell("default","Your senses are accosted by the normal smells of a city.");
   set_listen("default","The city seems to move sluggishly along below you.");
   set_exits(([
	       "north" : "/d/tharis/Tharis/tower9",
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