//bcliff5
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
   set_smell("default","%^RESET%^%^GREEN%^The scent of pine from the forest below wafts up here.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLUE%^The roar of a nearby waterfall can be heard%^RESET%^.");
   set_items(([
   "cliff":"%^BOLD%^%^BLACK%^The cliff towers more than four hundred feet above you and gives off an eerie feeling.",
   "shadow":"%^BOLD%^%^BLACK%^The shadow of the cliff falls over the ravine below.%^RESET%^",
   "rocks":"Large rocks line the path, making it difficult to maneuver around here.  Some are merely a few feet in diameter, while others stand to nearly six feet tall.",
   "path":"%^RESET%^%^ORANGE%^The path is worn out and looks to be seldom used.  In fact, it down right looks abandoned.%^RESET%^",
   ({"trees","pine trees","tree","pines"}):"%^RESET%^%^GREEN%^A few pine trees cling to life here as they attempt to grow amongst the rocks.  Their needles are weak and the branches fairly bare, but somehow they still grow to be quite tall.%^RESET%^",
   "valley":"%^RESET%^%^GREEN%^The valley is filled with a lush forest that grows around a winding river.%^RESET%^",
   "forest":"%^RESET%^%^GREEN%^The forest grows around a winding river and looks to be quite healthy and peaceful.%^RESET%^",
   "river":"%^BOLD%^%^BLUE%^A river winds its way through the base of the valley.%^RESET%^",
   "waterfall":"%^BOLD%^%^CYAN%^The waterfall pours out of the cliff nearly fifty feet above you and drops over one hundred feet before it finally hits the ground below you.%^RESET%^",
   ]));
   set_exits((["north":INRMS+"bcliff4","southwest":INRMS+"bcliff6"]));
}
string ldesc(string str){
   return("%^RESET%^This is the furthest out you can get on this ledge that the"
" %^ORANGE%^path %^RESET%^is built on.  To the south, a"
" %^BOLD%^%^BLACK%^c%^RESET%^l%^BOLD%^%^BLACK%^i%^RESET%^f%^BOLD%^%^BLACK%^f"
" %^RESET%^drops down into the %^GREEN%^valley %^RESET%^below and another"
" %^BOLD%^%^BLACK%^c%^RESET%^l%^BOLD%^%^BLACK%^i%^RESET%^f%^BOLD%^%^BLACK%^f"
" %^RESET%^towers above you to the north.  The %^ORANGE%^path %^RESET%^continues"
" to the southwest, hugging the side of the mountain as it follows the"
" cliffs edge.  The roar of a nearby %^BOLD%^%^CYAN%^waterfall %^RESET%^fills the"
" air here and almost drowns out the sounds of the %^BOLD%^%^BLACK%^howling wolves"
" %^RESET%^you can still hear coming from the top of the cliff.  Below you, the"
" %^GREEN%^forest %^RESET%^looks surreal and peaceful and the %^BOLD%^%^BLUE%^blue"
" waters %^RESET%^of the %^BOLD%^%^BLUE%^winding river %^RESET%^look refreshingly"
" inviting.\n");
} 
