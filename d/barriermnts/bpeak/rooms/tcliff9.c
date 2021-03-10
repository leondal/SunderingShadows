//tcliff9
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
   "tents":"%^RESET%^%^ORANGE%^A few tents lay to the east along the cliff edge.  They are quite large but very simply made.  Large tree trunks have been leaned against one another and are covered with various furs and skins for shelter.%^RESET%^",
   ({"mountains","mountain","mountainside"}):"%^RESET%^%^BLUE%^The mountain wraps around the cliff to both the north and west.  The eastern side of the cliff drops down into a narrow rivine, while the southern edge seems to drop into a much larger one that almost borders on being a valley.%^RESET%^",
   "buildings":"Two large stone buildings lay to the west on the other side of the stairs.  They look to be built right against the mountainside.",
   ]));
   set_search("default", "%^ORANGE%^Large footprints can be seen on the ground going in many directions, but it looks like most are heading east.%^RESET%^");
   set_exits((["west":INRMS+"tcliff2","east":INRMS+"tcliff11"]));
}
string ldesc(string str){
   return("%^RESET%^The %^ORANGE%^dusty path %^RESET%^continues here along the edge"
" of the northern side of the cliff, hugging the %^BLUE%^mountain %^RESET%^that"
" looms above.  To the west, the shapes of two large %^BOLD%^%^BLACK%^s%^RESET%^t"
"%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^buildings are"
" %^BOLD%^%^BLACK%^shadowed %^RESET%^by the %^BLUE%^mountain %^RESET%^bordering"
" that side of the cliff.  To the south the %^GREEN%^green forest %^RESET%^that"
" grows within the %^GREEN%^valley %^RESET%^is visible, while to the east there is"
" nothing but %^ORANGE%^dirty tents %^RESET%^lining the cliffs edges.  The view"
" from up here is astounding, despite the fact that two sides of the cliff are"
" bordered by %^BLUE%^mountains.  %^RESET%^You can't help but get the feeling that"
" this area is well protected by both the shelter of the %^BLUE%^mountains"
" %^RESET%^and the fact that it overlooks virtually every other entry point, making"
" it nearly impossible to approach this area undetected.%^RESET%^\n");
} 
