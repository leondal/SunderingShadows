//bcliff8
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit ROOM;




void create(){
::create();
   set_property("light",2);
   set_travel(GAME_TRACK);
   set_terrain(ROCKY);
   set_name("%^RESET%^At the base of a stairway");
   set_short("%^RESET%^The base of a stairway leading up the cliff%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^RESET%^%^GREEN%^The scent of pine from the forest below wafts up here.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^The howling of wolves is even louder here%^RESET%^.");
   set_items(([
   "cliff":"%^BOLD%^%^BLACK%^The cliff towers more than four hundred feet above you and gives off an eerie feeling.",
   "shadow":"%^BOLD%^%^BLACK%^The shadow of the cliff falls over the ravine below.%^RESET%^",
   "rocks":"Large rocks line the path, making it difficult to maneuver around here.  Some are merely a few feet in diameter, while others stand to nearly six feet tall.",
   "path":"%^RESET%^%^ORANGE%^The path is worn out and looks to be seldom used.  In fact, it down right looks abandoned.%^RESET%^",
   ({"trees","pine trees","tree","pines"}):"%^RESET%^%^GREEN%^A few pine trees cling to life here as they attempt to grow amongst the rocks.  Their needles are weak and the branches fairly bare, but somehow they still grow to be quite tall.%^RESET%^",
   "ravine":"%^RESET%^%^GREEN%^The ravine is filled with a lush forest that grows around a winding river.%^RESET%^",
   "forest":"%^RESET%^%^GREEN%^The forest grows around a winding river and looks to be quite healthy and peaceful.%^RESET%^",
   "river":"%^BOLD%^%^BLUE%^A river winds its way through the base of the ravine.%^RESET%^",
   "stairway":"The stairway leads up the cliff and is composed of large slabs of granite.  Whoever built this must have been huge.",
   ]));
   set_exits((["stairway":INRMS+"stwy1","southeast":INRMS+"bcliff7"]));
}
string ldesc(string str){
   return("%^RESET%^A large granite stairway is carved into the cliff to the"
" north, and seems to lead to the top.  To the south, the %^GREEN%^valley"
" %^RESET%^beneath the cliff %^BOLD%^%^GREEN%^flourishes %^RESET%^with life."
"  A winding %^BOLD%^%^BLUE%^river %^RESET%^snakes its way through the"
" %^GREEN%^forest %^RESET%^and looks to be quite calm and inviting.  The sounds of"
" a %^BOLD%^%^CYAN%^waterfall %^RESET%^can be heard from here, but even that is"
" not as loud as the banging and howls coming from the cliff above.  There is"
" little life here on the cliff itself, but a few"
" scraggly %^GREEN%^pine trees %^RESET%^manage to cling to a somewhat pathetic"
" existence along the ledge this path is built on.\n");
} 
