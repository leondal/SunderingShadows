// Grand Stairs of the Marble Academy, Tonovi
// Tonovi
// tfloor1.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("Floor 1");
    set_short("Grand Stairs of the Marble Academy, Tonovi");
    set_long(
"Generic description for the Grand Stairs of the Marble Academy, Tonovi. There seems to be a lot of construction going on here.\n\n"+
"%^RESET%^You can go up these steps or enter the %^CYAN%^foyer"+
"%^RESET%^.  You also see a side entrance into the %^BOLD%^"+
"%^BLUE%^components shop.\n"
    );
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
    set_property("light",2);
    set_property("indoors",1);
    set_smell("default","You can smell fresh air blowing from somewhere.");
    set_listen("default","You can hear the shuffling of other mages.");
    set_exits( ([
        "store": "compstore1",
        "south": "tfoyer",
        "up":    "tfloor2"
    ]) );
}
