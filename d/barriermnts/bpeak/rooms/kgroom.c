//kgroom
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit CVAULT;
int move;


void create(){
::create();
   set_property("light",2);
   set_travel(GAME_TRACK);
   set_terrain(ROCKY);
   set_name("%^RESET%^The top of a %^BOLD%^%^BLACK%^c%^RESET%^l%^BOLD%^%^WHITE%^i%^BLACK%^f%^RESET%^f");
   set_short("%^RESET%^The top of a %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^WHITE%^c%^BLACK%^k%^RESET%^y c%^BOLD%^%^WHITE%^l%^BLACK%^i%^RESET%^f%^BOLD%^%^BLACK%^f%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","It smells of %^BOLD%^%^BLACK%^d%^RESET%^u%^BOLD%^%^BLACK%^st, %^RESET%^%^ORANGE%^dirt %^RESET%^and %^BOLD%^%^BLACK%^grime.%^RESET%^");
   set_listen("default","%^RESET%^The nearby howls of wolves can be heard.");
   set_items(([
   "city":"The city of Torm is but a spec in the distance.",
   ({"sea","ocean"}):"%^RESET%^%^CYAN%^The waters of the sea can be seen to the east.%^RESET%^",
   "mountains":"%^RESET%^%^BLUE%^The Barrier Mountains loom over you towards both the east, west and further to the south.%^RESET%^",
   ({"fence","fenced area"}):"The fence is composed of large rocks, wood, and other odd things stuffed here and there.  A few dark shadows can be seen pacing around through a few cracks though.  A large gate is in the fence.",
   "gate":"A large gate can be seen and looks heavy, but not impossible to move.",
   "rocks":"These things range in size from very small rocks to boulders that reach ten feet in height.",
   "building":"This building is made of the very largest rocks, some of them fourteen feet in height.  Slabs of rocks have been stood together to make the walls, while more rocks have been placed on top to create a roof.",
   ({"plants","bushes"}):"%^RESET%^%^GREEN%^The few plants here struggle for life as they cling to the crevices in the rocks.%^RESET%^",
   "cliff":"%^BOLD%^%^BLACK%^The cliff to the north is a sheer drop off.  It would really hurt to go down that way...%^RESET%^",
   ]));
   set_search("default", "%^ORANGE%^Nothing here really looks interesting.%^RESET%^");
   set_exits((["west":INRMS+"wolfpen","building":INRMS+"bldg3"]));
   set_climb_exits((["descend":({INRMS+"bkgroom",20,4,100})]));
   set_door("gate",INRMS+"wolfpen","west",0);

}
string ldesc(string str){
   return("%^RESET%^This looks to be the highest peak of a tall cliff"
" that overlooks the city of"
" %^BLUE%^Torm %^RESET%^to the north and the %^CYAN%^Sakrune Sea %^RESET%^to the"
" east.  This part of the cliff towers over the rest of the compound to the"
" southwest and probably serves as a perfect lookout point to see everything"
" that happens both here and in the paths leading to the area.  More"
" %^BLUE%^mountains loom %^RESET%^over even this cliff in the distance,"
" but you wouldn't dare venture there.  A fenced area lies to the west and the"
" sounds of howling wolves can be heard from within.  Large"
" %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^WHITE%^c%^RESET%^k%^BOLD%^%^BLACK%^s"
" %^RESET%^are scattered throughout the area and a building composed of giant rocks"
" is set to the south.  Few plants grow on this cliff, and those that do grow here"
" look as though they are struggling.%^RESET%^\n");
}

void reset() {
  ::reset();
  set_open("gate",0);
  if(!present("giant")){
     new(TMONDIR+"hillg1.c")->move(TO);
  }
  if(!present("wolf")){
     new(TMONDIR+"dwolf2.c")->move(TO);
  }
}
