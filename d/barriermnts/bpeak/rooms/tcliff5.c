//tcliff5
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit CROOM;



void create(){
::create();
   set_property("light",2);
   set_travel(FOOT_PATH);
   set_terrain(ROCKY);
   set_name("%^RESET%^A path through a camp");
   set_short("%^RESET%^A path through a camp%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^RESET%^%^GREEN%^The smell of sweat, poorly kept animals and dirt mixes with the scent of the pines below.%^RESET%^");
   set_listen("default","%^RESET%^%^ORANGE%^Besides the noise of the wind, the occassional grunt, shout or howl echoes from somewhere around here.%^RESET%^");
   set_items(([
   "tents":"%^RESET%^%^ORANGE%^A few tents are scattered around the area. Most are located on the eastern side of the path along the cliffs edge, but a few are near the western edge of the path, overlooking the stairway leading up here.  They are quite large but very simply made.  Large tree trunks have been leaned against one another and are covered with various furs and skins for shelter.%^RESET%^",
   "valley":"%^RESET%^%^GREEN%^The valley to the south can hardly be called a valley.  Instead it is much more like a large ravine filled with a thriving forest.  Meandering casually through the center of the forest is a slow moving river.%^RESET%^",
   "river":"%^RESET%^%^CYAN%^A slow moving river can be seen moving through the forest to the south.  Its sparkling waters are obviously the force that gives life to the inhabitants of the ravine.%^RESET%^",
   "steps":"Steps have been carved into the cliff itself and lead down to a ledge below.",
   ]));
   set_search("default", "%^ORANGE%^This area seems empty enough, all that really seems to be here is dirt, rocks and more dirt.%^RESET%^");
   set_exits((["north":INRMS+"tcliff4","steps":INRMS+"steps"]));
}
string ldesc(string str){
   return("The %^ORANGE%^path %^RESET%^here ends at a set of steps that lead down"
" the cliffs edge or continues to the north towards a large well.  From here you"
" can see the %^ORANGE%^path %^RESET%^that leads up to the cliff as well as the"
" %^GREEN%^forest %^RESET%^that grows within the %^GREEN%^valley %^RESET%^below."
"  A large %^BOLD%^%^CYAN%^waterfall %^RESET%^can be seen pouring out of the"
" side of the cliff further down and empties itself into a %^BLUE%^deep pool"
" %^RESET%^at the base of the cliff.  The %^BLUE%^pool %^RESET%^runs off"
" and feeds the %^CYAN%^river %^RESET%^that can be seen winding its way through the"
" %^GREEN%^forest.%^RESET%^\n");
} 
