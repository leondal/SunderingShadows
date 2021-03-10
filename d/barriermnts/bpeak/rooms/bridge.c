//bridge
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit ROOM;




void create(){
::create();
   set_property("light",2);
   set_travel(FOOT_PATH);
   set_terrain(ROCKY);
   set_name("%^RESET%^%^ORANGE%^A wooden bridge%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^A wooden bridge%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^RESET%^%^CYAN%^A fine mist from the waterfall hangs in the air, soaking you and everything else on the bridge.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLUE%^The roar of the waterfall is deafening%^RESET%^.");
   set_items(([
   "cliff":"%^BOLD%^%^BLACK%^The cliff towers more than four hundred feet above you and gives off an eerie feeling.",
   "shadow":"%^BOLD%^%^BLACK%^The shadow of the cliff falls over the ravine below.%^RESET%^",
   "valley":"%^RESET%^%^GREEN%^The valley is filled with a lush forest that grows around a winding river.%^RESET%^",
   "forest":"%^RESET%^%^GREEN%^The forest grows around a winding river and looks to be quite healthy and peaceful.%^RESET%^",
   "river":"%^BOLD%^%^BLUE%^A river winds its way through the base of the valley.%^RESET%^",
   "waterfall":"%^BOLD%^%^CYAN%^The waterfall pours out of the cliff nearly fifty feet above you and drops over one hundred feet before it finally hits the ground below you.%^RESET%^",
   "pool":"%^BOLD%^%^BLUE%^The waterfall plummets down into a deep, turning pool below you.  The overflow feeds a river that winds its way through the forest.%^RESET%^",
   ({"trunks","treetrunks"}):"RESET%^%^ORANGE%^Large treetrunks have been used as the supports for this bridge.  They span from one side of the ledge to the other, and have other smaller pieces of wood tied crossways to them via vines.%^RESET%^",
   ({"branches","wood"}):"Various pieces of flattened wood have been used to form the part of the bridge you would walk on.  They are held together by strong vines and overall, the bridge looks to be quite sturdy.%^RESET%^",
   "vines":"%^RESET%^%^GREEN%^Large vines have been twisted together and then used to tie the pieces of branch and wood together.%^RESET%^",
   "algae":"%^RESET%^%^GREEN%^Algae grows along the cracks of the wood, coating them in a fuzzy green blanket.%^RESET%^",
   "mushrooms":"Odd looking mushrooms of various sizes grow from the more rotten pieces of the bridge.",
   ]));
   set_exits((["east":INRMS+"bcliff6","west":INRMS+"bcliff7"]));
}
string ldesc(string str){
   return("%^RESET%^%^ORANGE%^This is an old wooden bridge built to span the gap"
" between the two sides of the path.  Large tree trunks have been used to line"
" either side of the bridge and provide the support for the branches that act as"
" the cross pieces.  %^GREEN%^Vines %^ORANGE%^are used to bind the branches"
" together and are woven suprisingly tightly, adding plenty of support and strength."
"  Directly below you, the %^CYAN%^water %^RESET%^of the %^BOLD%^%^BLUE%^pool"
" %^RESET%^%^ORANGE%^turns violently as the %^BOLD%^%^CYAN%^waterfall"
" %^RESET%^%^ORANGE%^constantly pounds into it.  %^BOLD%^%^WHITE%^Sprays"
" %^RESET%^%^ORANGE%^of %^CYAN%^water %^ORANGE%^soak everything and the wood"
" %^RESET%^glistens %^ORANGE%^from the constant %^CYAN%^moisture.  %^GREEN%^Algae"
" %^ORANGE%^grows abundantly in the cracks of the wood and a few mushrooms manage"
" to spring forth from the more rotten places.  Overall the bridge looks fairly"
" sturdy and you do not get the feeling that you need to hurry across it.\n");
} 
