//updated by Circe with color, etc 5/30/04
// Grand Stairs of the Tower of the Arcane, Tabor
// Thorn@ShadowGate
// 010205
// Tabor
// tfloor1.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
    ::create();
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("Floor 1");
    set_short("Grand Stairs of the Tower of the Arcane, Tabor");
    set_long(
"%^BOLD%^Grand Stairs in the Tower of the %^CYAN%^A%^YELLOW%^r"+
"%^CYAN%^c%^YELLOW%^a%^CYAN%^n%^YELLOW%^e%^WHITE%^, Tabor%^RESET%^\n"+
"%^BOLD%^%^BLACK%^The room you are in is at the foot of the %^WHITE%^"+
"Grand Staircase %^BLACK%^of the %^CYAN%^Tower of the Arcane%^BLACK%^.  "+
"The staircase is made of %^RESET%^bl%^BOLD%^%^BLACK%^ac%^RESET%^k "+
"ma%^BOLD%^%^BLACK%^rb%^RESET%^le%^BOLD%^%^BLACK%^, and has numerous "+
"carvings of %^WHITE%^angels%^BLACK%^, demons, %^RED%^dragons%^BLACK%^, "+
"and other %^BLUE%^magical creatures %^BLACK%^in an appropriately "+
"colored marble.  Looking at the steps, you can see they are worn down "+
"and smoothed by centuries of %^CYAN%^magi %^BLACK%^walking up and "+
"down them.  A beam of %^YELLOW%^magical light %^BLACK%^shines down "+
"from high above, illuminating the stairs and producing a powerful "+
"effect.\n\n"+
"%^RESET%^You can go up these steps or enter the %^CYAN%^foyer"+
"%^RESET%^.  You also see a side entrance into Llewddyn's %^BOLD%^"+
"%^BLUE%^components shop.\n"
    );
    set_items(([
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
   ]));
    set_property("light",2);
    set_property("indoors",1);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    set_smell("default","You can smell fresh air blowing from somewhere.");
    set_listen("default","You can hear the shuffling of other mages.");
    set_exits( ([
        "store": ROOMDIR+"compstore1",
        "south": ROOMDIR+"tfoyer",
        "up":    ROOMDIR+"tfloor2"
    ]) );
}
