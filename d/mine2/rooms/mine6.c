#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("mine shaft");
    set_long(""
"%^BOLD%^YELLOW%^ "
"This mine has a goldish tint to it.  There are many pick marks on the wall "
"which you think must mean that this is a good place to mine in.  There is "
"small stream running through the center of the room, and then before it gets "
"to the end of the wall, it drains down a large hole.   "
"");

     set_listen("default","You hear water draining.");
     set_smell("default","You smell fresh water.");
    set_exits(([
       "south" : "/d/mine2/rooms/mine5",

    ] ));
    set_items(([
         "cavern" : "It is farly small, and is very stuffy.",
         "stream" : "The stream comes out of a small hole at one side of the room, and then drains into a hoel on the other side.",
         "marks" : "The marks are from picks from earlier tried to get gold.",
         "shaft" : "It is accually a small cavern, that has a godl tint.",
         "gold" : "There is no gold, that you can see, but the room has a gold tint to it.",
         "rock" : "There is several pieces of chiped rock on the ground.",
         "ground" : "it is covered with chiped rock.",
    ] ));
set_max_mining(1);
set_chance(1);
set_max_find(2);
set_nugget( ([ "1":1, ]) );
}
