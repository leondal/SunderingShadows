//tcliff2
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
   ({"mountains","mountain","mountainside"}):"%^RESET%^%^BLUE%^The mountain wraps around the cliff to both the north and west.  The eastern side of the cliff drops down into a narrow ravine, while the southern edge seems to drop into a valley.%^RESET%^",
   "buildings":"Two large stone buildings lay to the west on the other side of the stairs.  They look to be built right against the mountainside.",
   "tent":"%^RESET%^%^ORANGE%^This is one of the tents that lines the cliffs edge.  It is very crudely made.  Large tree trunks have been leaned against one another as the structure and rough hides have been layered over to create shelter.%^RESET%^",
   ]));
   set_search("default", "%^ORANGE%^Large footprints can be seen on the ground going in many directions, but it looks like most are heading east.%^RESET%^");
   set_exits((["west":INRMS+"tcliff1","east":INRMS+"tcliff9","south":INRMS+"tcliff3","tent":INRMS+"tent1"]));
}
string ldesc(string str){
   return("%^RESET%^This is a %^ORANGE%^dusty path %^RESET%^that runs along the"
" northern edge of the cliff and hugs the %^BLUE%^mountainside.  %^RESET%^To the"
" south you can see the cliffs edge and the %^GREEN%^forested valley %^RESET%^that"
" it drops down to.  To the west lay two large %^BOLD%^%^BLACK%^s%^RESET%^t"
"%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^buildings built against the"
" %^BLUE%^mountainside.  %^RESET%^The path splits in two here. One path continues to"
" the south towards a few %^ORANGE%^tents %^RESET%^that are set up along the cliff"
" edges, while the other continues to the east and wraps around the edge of the"
" %^BLUE%^mountain %^RESET%^to continue northeast.  The %^BOLD%^%^BLACK%^howling"
" %^RESET%^you hear seems to be coming from somewhere over there.%^RESET%^\n");
} 
