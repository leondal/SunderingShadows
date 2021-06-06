// Level 2 Landing in the Marble Academy, Tonovi
// Tabor
// tfloor2.c

#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_name("Floor 2");
    set_short("Level 2 Landing in the Marble Academy, Tonovi");
    set_long("Generic description for the second floor landing in the Marble Academy, Tonovi.");
    set_property("light",2);
    set_property("indoors",1);
    set_smell("default","A number of strange smells are coming from the east.");
    set_listen("default","You hear a cacaphony of sound to the east.");
    set_items(([
/*
       "angels" : "%^BOLD%^The angels have been carved from "+
                  "brilliant white ivory.  They are shown in "+
                  "several poses - some in flight while others "+
                  "kneel in prayer.",
       "demons" : "%^BOLD%^%^BLACK%^The demons are carved from "+
                  "glittering black marble, deeper than the "+
                  "black of the staircase.  They have %^RED%^"+
                  "rubies %^BLACK%^for eyes and are shown in "+
                  "all manner of poses, most often tormenting "+
                  "mortals.",
       "dragons" : "The dragons are shown in "+
                   "various colors - %^BOLD%^%^RED%^red%^RESET%^, "+
                   "%^BOLD%^%^BLUE%^blue%^RESET%^, %^BOLD%^%^BLACK%^"+
                   "black%^RESET%^, %^BOLD%^%^GREEN%^green%^RESET%^,"+
                   " %^YELLOW%^gold%^RESET%^, and even %^BOLD%^"+
                   "silver%^RESET%^!  Each is depicted in flight.",
       ({"creatures","magical creatures"}) : "In addition to the "+
                   "demons, dragons, and angels, there are many "+
                   "other creatures that are connected to magical "+
                   "lore.  The fae creatures stand alongside the "+
                   "phoenix, roc, and darker creatures such as the "+
                   "illithid.",
       ({"steps","stairs"}) : "This grand staircase has been worn "+
          "by countless feet.  It is made of deep black marble, and "+
          "it still glitters like new.",
       "light" : "The strange light is bright as sunlight, but it "+
          "seems to have a bluish glow.  There seems to be no source "+
          "for it, but it permeates the area and seems to come from "+
          "somewhere above."
*/
    ]));
    set_exits( ([
        "north" : "tlib",
        "east"  : "compstore2",
        "down"  : "tfloor1",
        "up"    : "tfloor3",
    ]) );
}
