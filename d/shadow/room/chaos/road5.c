#include "chaos.h"
inherit ROOM;

void create(){
    ::create();
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("On a dark road");
    set_long(
@MELNMARN
:%^BOLD%^You are walking on a dark road.%^RESET%^
You can see nothing but the road. There is nothing to the
sides of the road. Just blackness, darkness, nothingness, like 
a void. To the north, you see a tower, looming high into
the void. There is a chill in the air.
MELNMARN
    );

    set_items(([
	"road":"A road through the void.",
	"tower":"A dark, black tower.",
	"void":"Darkness, total and complete."
	]));
 
    set_exits(([
	"north" : CHAOSDIR+"south1",
	"east"  : CHAOSDIR+"road4"
   	]));
    set_smell("default","You can smell nothing.");
   set_listen("default","There is a deathly silence here.");

}
