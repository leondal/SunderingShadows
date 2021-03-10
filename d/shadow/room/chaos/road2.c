#include "chaos.h"
inherit ROOM;

void create(){
    ::create();
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("On a dark road");
    set_long(
@MELNMARN
%^BOLD%^You are walking on a dark road.%^RESET%^
You can see nothing but the road. There is nothing to the
sides of the road. Just blackness, darkness, nothingness, like 
a void.  The road forks here, either to the northwest or northeast
There is a chill in the air.
MELNMARN
    );

    set_items(([
	"road":"A road through the void.",
	"void":"Darkness, total and complete."
	]));
 
    set_exits(([
	"northwest" : CHAOSDIR+"road3",
	"south" : CHAOSDIR+"road1"
   	]));
    set_smell("default","You can smell nothing.");
   set_listen("default","There is a deathly silence here.");

}
