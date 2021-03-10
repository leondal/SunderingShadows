//bkgroom
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit CROOM;



void create(){
   set_monsters(({TMONDIR +"hillg4.c"}),({random(4)+2}));
   set_repop(40);
::create();
   set_property("light",2);
   set_travel(FOOT_PATH);
   set_terrain(ROCKY);
   set_name("%^RESET%^At the base of another cliff");
   set_short("%^RESET%^At the base of another cliff%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^RESET%^%^GREEN%^The smell of sweat, poorly kept animals and dirt mixes with the scent of the pines below.%^RESET%^");
   set_listen("default","%^RESET%^%^ORANGE%^Besides the noise of the wind, the occassional grunt, shout or howl echoes from somewhere around here.%^RESET%^");
   set_items(([
   ({"mountains","mountain","mountainside"}):"%^RESET%^%^BLUE%^The mountain wraps around the cliff to the west.  The eastern side of the cliff drops down into a narrow ravine, while the southern edge seems to drop into a valley.%^RESET%^",
  "cliff":"The cliff here ascends to what looks like the highest point of this eastern edge of the mountain.",
   ]));
   set_search("default", "%^ORANGE%^Large footprints can be seen on the ground going in many directions, but it looks like most are heading west.%^RESET%^");
   set_exits((["west":INRMS+"tcliff11"]));
   set_climb_exits((["ascend":({INRMS+"kgroom",20,4,100})]));
}
string ldesc(string str){
   return("%^RESET%^The %^ORANGE%^path %^RESET%^ends abruptly at the base of yet"
" another tall cliff.  The cliff looks to reach the highest point of the eastern"
" side of this mountain and probably is a great lookout point.  The"
" %^BOLD%^%^BLACK%^shadow %^RESET%^of a building setting on top of the cliff can be"
" seen from here.  The ground is fairly stable, but this ledge is narrow, only being"
" about twenty feet across before it drops down to the %^ORANGE%^paths %^RESET%^in"
" the ravine below.  The %^BOLD%^%^BLACK%^howling %^RESET%^is even louder here and"
" sounds like it may be coming from directly above you somewhere.%^RESET%^\n");
} 
