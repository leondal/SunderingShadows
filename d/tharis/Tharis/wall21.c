// /d/tharis/Tharis/wall21.c //
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_light(2);
    set_indoors(0);
   set_short("The ramparts of the wall around Tharis");
    set_long(
@OLI
        You are on the ramparts of the wall. To the west is
the inside of the bustling city of Tharis.  You notice that 
below you is the elf section, made fabulous despite the 
city's best efforts. The stone battlements have been worn 
by the weather but still show their fine craftsmanship. The wall 
is patrolled sparsely. To your north is the East Wall and to 
your south is the northern tower for the east gate.
OLI
    );
   set_smell("default","Your senses are accosted by the normal smells of a city.");
   set_listen("default","The city bustles below you.");
    set_exits(([
"north" : "/d/tharis/Tharis/wall20",
"south" : "/d/tharis/Tharis/tower9",
    ] ));
}
void reset(){
 ::reset();
if(!present("patrol")){
	new("d/tharis/monsters/wall_patrol")->move(TO);
new("d/tharis/monsters/wall_patrol")->move(TO);
}
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/