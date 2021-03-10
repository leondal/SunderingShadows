//tcliff3
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
   "tents":"%^RESET%^%^ORANGE%^A few tents lay to the east along the cliff edge.  They are quite large but very simply made.  Large tree trunks have been leaned together and covered with various furs and skins for shelter.%^RESET%^",
   "tent":"%^RESET%^%^ORANGE%^This is one of the tents that lines the cliffs edge.  It is very crudely made.  Large tree trunks have been leaned against one another as the structure and rough hides have been layered over to create shelter.%^RESET%^",
   ]));
   set_search("default", "%^ORANGE%^Large footprints can be seen on the ground going in many directions, but it looks like most are heading east.%^RESET%^");
   set_exits((["north":INRMS+"tcliff2","south":INRMS+"tcliff4","tent":INRMS+"tent2"]));
}
string ldesc(string str){
   return("%^RESET%^This is a %^ORANGE%^dusty path %^RESET%^along the top of the"
" cliff.  A few %^ORANGE%^tents %^RESET%^lay strewn about near the cliffs edge, but"
" other than that there really isn't much else up here.  Built right against the"
" %^BLUE%^mountainside, %^RESET%^you can see two large %^BOLD%^%^BLACK%^s%^RESET%^"
"t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^buildings to the west."
"  To the south there is another set of stairs leading down the southern edge of"
" the cliff.%^RESET%^\n");
} 
void reset(){
   ::reset();
   if(!present("hill giant")){
      new(TMONDIR+"hillg4.c")->move(TO);
      new(TMONDIR+"hillg4.c")->move(TO);
  }
}

