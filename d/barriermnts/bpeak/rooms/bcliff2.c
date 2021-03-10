//bcliff2
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit ROOM;



void create(){
::create();
   set_property("light",2);
   set_travel(GAME_TRACK);
   set_terrain(ROCKY);
   set_name("%^RESET%^The bottom of a %^BOLD%^%^BLACK%^c%^RESET%^l%^BOLD%^%^WHITE%^i%^BLACK%^f%^%RESET%^f");
   set_short("%^RESET%^The bottom of a %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^WHITE%^c%^BLACK%^k%^RESET%^y c%^BOLD%^%^WHITE%^l%^BLACK%^i%^RESET%^f%^BOLD%^%^BLACK%^f%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","It smells of %^BOLD%^%^BLACK%^d%^RESET%^u%^BOLD%^%^BLACK%^st, %^RESET%^%^ORANGE%^dirt %^RESET%^and %^BOLD%^%^BLACK%^grime.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^The nearby howls of wolves can be heard from somewhere on the cliffs above you.");
   set_items(([
   "cliff":"%^BOLD%^%^BLACK%^The cliff towers more than five hundred feet above you and gives off an eerie feeling.  A darkened area in the cliff face looks as though it might actually be a cave opening of some sort.%^RESET%^",
   "shadow":"%^BOLD%^%^BLACK%^The shadow of the cliff gives this area plenty of shade.%^RESET%^",
   "rocks":"Large rocks line the path, making it difficult to maneuver around here.  Some are merely a few feet in diameter, while others stand to nearly six feet tall.",
   "path":"%^RESET%^%^ORANGE%^The path is worn out and looks to be seldom used.  In fact, it down right looks abandoned.%^RESET%^",
   ({"trees","pine trees","tree","pines"}):"%^RESET%^%^GREEN%^A few pine trees cling to life here as they attempt to grow amongst the rocks.  Their needles are weak and the branches fairly bare, but somehow they still grow to be quite tall.%^RESET%^",
   "cave":"%^BOLD%^%^BLACK%^As you take a closer look at the dark hole in the side of the cliff, you are certain that it is a cave.  Maybe you can climb up to it.%^RESET%^",
   ]));
   set_search("default", "%^ORANGE%^Nothing here really looks interesting.%^RESET%^");
   set_exits((["northeast":INRMS+"bcliff","southwest":INRMS+"bcliff3"]));
   set_climb_exits((["climb":({INRMS+"ce1",20,4,100})
]));

}
string ldesc(string str){
   return("%^RESET%^This is the bottom of a tall cliff that hovers over five hundred"
" feet above you.  The %^BOLD%^%^BLACK%^shadow %^RESET%^of the cliff lends plenty of"
" %^BOLD%^%^BLACK%^shade %^RESET%^to the area, but also gives you an eerie feeling."
"  Large rocks line the path and a few %^GREEN%^pine trees %^RESET%^cling to life"
" amongst them.  The path grows steeper as it hugs the cliff and continues up the"
" mountain where it not only looks to get continually steeper, but also much more"
" narrow.%^RESET%^\n");
} 

