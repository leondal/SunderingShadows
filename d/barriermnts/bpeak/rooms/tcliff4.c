//tcliff4
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit CROOM;



void create(){
   set_monsters(({TMONDIR +"bogre.c",TMONDIR +"dwolf3.c",TMONDIR +"hillg4.c"}),({2,random(10),random(4)}));
   set_repop(40);
::create();
   set_property("light",2);
   set_travel(FOOT_PATH);
   set_terrain(ROCKY);
   set_name("%^RESET%^Around the well");
   set_short("%^RESET%^Around the well%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^RESET%^%^GREEN%^The smell of sweat, poorly kept animals and dirt mixes with the scent of the pines below.%^RESET%^");
   set_listen("default","%^RESET%^%^ORANGE%^Besides the noise of the wind, the occassional grunt, shout or howl echoes from somewhere around here.%^RESET%^");
   set_items(([
   "tents":"%^RESET%^%^ORANGE%^A few tents are scattered around the area. Most are located on the eastern side of the path along the cliffs edge, but a few are near the western edge of the path, overlooking the stairway leading up here.  They are quite large but very simply made.  Large tree trunks have been leaned against one another and are covered with various furs and skins for shelter.%^RESET%^",
   "well":"%^BOLD%^%^BLACK%^Large cut stones are fitted perfectly in a circle around what looks to be a large well.  Curiously enough, there are no buckets near it.%^RESET%^",
   "valley":"%^RESET%^%^GREEN%^The valley to the south can hardly be called a valley.  Instead it is much more like a large ravine filled with a thriving forest.  Meandering casually through the center of the forest is a slow moving river.%^RESET%^",
   "river":"%^RESET%^%^CYAN%^A slow moving river can be seen moving through the forest to the south.  Its sparkling waters are obviously the force that gives life to the inhabitants of the ravine.%^RESET%^",
   "hole":"%^BOLD%^%^BLACK%^The hole in the ground is dark and foreboding.%^RESET%^",
   ]));
   set_search("default", "%^ORANGE%^This area seems farely bare with the exception of the large well in the center of the path.%^RESET%^");
   set_search("well", "%^BOLD%^%^BLACK%^Upon closer inspection you realize that this is no well at all.  The stones circle a large hole in the ground, but no water is visible nor is there evidence of any.%^RESET%^");
   set_exits((["north":INRMS+"tcliff3","south":INRMS+"tcliff5","tent":INRMS+"tent3"]));
}
string ldesc(string str){
   return("The %^ORANGE%^path %^RESET%^opens up here to the center of another living"
" area.  %^ORANGE%^Tents %^RESET%^lay strewn about and what looks like a large well"
" sets in the center of the area.  The %^ORANGE%^path %^RESET%^circles around the"
" well before heading south towards the stairway leading down the cliffs edge."
"  The view from here is astonishing, as the cliff overlooks the entire area leading"
" up to it as well as the %^GREEN%^valley %^RESET%^to the south.%^RESET%^\n");
} 
void reset() {
  ::reset();
  if(!present("ugly ogre warrior")){
     new(TMONDIR+"ogre2.c")->move(TO);
  }
}
