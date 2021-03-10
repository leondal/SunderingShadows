#include <std.h>
#include "../dragon.h";

inherit BTOWN;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_short("Crumbled Guardhouse");
   set_long(
      "%^BOLD%^%^BLACK%^Most of the walls in the city lay in ruins, and the thick walls that"+
      " once repelled invasions have been reduced to piles of rubble by the"+
      " passage of time. A broken door lies amidst the crumbled stonework,"+
      " while the collapsed remains of an upper level can be seen above."
    );
    set_exits(([
       "west" : "/d/deku/plains/road35"
    ] ));
    set_items(([
    ] ));
}

