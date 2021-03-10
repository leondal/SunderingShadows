//tcliff1
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit CROOM;



void create(){
::create();
   set_property("light",2);
   set_travel(FOOT_PATH);
   set_terrain(ROCKY);
   set_name("%^RESET%^The top of a stairway");
   set_short("%^RESET%^The top of a granite stairway%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^RESET%^%^GREEN%^The smell of sweat, poorly kept animals and dirt mixes with the scent of the pines below.%^RESET%^");
   set_listen("default","%^RESET%^%^ORANGE%^Besides the noise of the wind, the occassional grunt, shout or howl echoes from somewhere around here.%^RESET%^");
   set_items(([
   "stairway":"The stairway is composed of huge slabs of %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^WHITE%^a%^BLACK%^n%^RESET%^i%^BOLD%^%^WHITE%^t%^BLACK%^e %^RESET%^and is built right into the cliff edge itself.  It descends to a path below.",
   "path":"%^RESET%^%^ORANGE%^At the base of the stairway you can see a path leading away to the southeast, probably back down the mountain.%^RESET%^",
   "buildings":"%^BOLD%^%^BLACK%^Two large buildings lay to the west and are each built by stacking very large stones.  They are built right up against the side of the mountain.%^RESET%^",
   "tents":"%^RESET%^%^ORANGE%^A few tents lay to the east along the cliff edge.  They are quite large but very simply made.  Large tree trunks have been leaned together and covered with various furs and skins for shelter.%^RESET%^",
   ]));
   set_search("default", "%^ORANGE%^Large footprints can be seen on the ground going in many directions, but it looks like most are heading east.%^RESET%^");
   set_exits((["down":INRMS+"stwy3","west":INRMS+"tcliff13","east":INRMS+"tcliff2"]));
}
string ldesc(string str){
   return("%^RESET%^This is the top of a %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^"
"%^WHITE%^a%^BLACK%^i%^RESET%^r%^BOLD%^%^BLACK%^w%^RESET%^a%^BOLD%^%^BLACK%^y"
" %^RESET%^that descends down the middle of the cliff to a path on a ledge below.  It"
" is perfectly flat up here and devoid of any plant life.  To the west, a few"
" buildings composed of %^BOLD%^%^BLACK%^r%^WHITE%^o%^RESET%^c%^BOLD%^%^BLACK%^k"
" %^RESET%^are built against the side of the %^BLUE%^mountain.  %^RESET%^To the east"
" there is nothing but a few giant sized %^ORANGE%^tents %^RESET%^made out of"
" %^ORANGE%^furs %^RESET%^spread along the cliffs edge.%^RESET%^\n");
} 
