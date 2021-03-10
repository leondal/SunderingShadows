//tcliff11
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
   ({"mountains","mountain","mountainside"}):"%^RESET%^%^BLUE%^The mountain wraps around the cliff to both the north and west.  The eastern side of the cliff drops down into a narrow ravine, while the southern edge seems to drop into a much larger one that almost borders on being a valley.%^RESET%^",
   "buildings":"Two large stone buildings lay to the west on the other side of the stairs.  They look to be built right against the mountainside.",
   "rivine":"%^RESET%^%^ORANGE%^The rivine to the east is dry and devoid of most plantlife, save a few spindly %^GREEN%^pine trees.  %^ORANGE%^From here, you can see the path that grants access through the mountains and into the larger and more prosperous %^GREEN%^valley %^ORANGE%^to the south.%^RESET%^",
   ]));
   set_search("default", "%^ORANGE%^Large footprints can be seen on the ground going in many directions, but it looks like most are heading east.%^RESET%^");
   set_exits((["west":INRMS+"tcliff9","east":INRMS+"bkgroom"]));
}
string ldesc(string str){
   return("%^RESET%^The %^ORANGE%^path %^RESET%^seems to narrow here a bit as the"
" ground begins to look slightly more unstable.  There is still a little bit of"
" cliff edge to the south, but not much.  From here you can see into the ravine that"
" marks the eastern edge of the cliff and also makes entry to the southern and"
" larger %^GREEN%^valley %^RESET%^to the south possible.  The %^ORANGE%^path"
" %^RESET%^continues to the east where it looks to abruptly stop at the base of yet"
" another cliff along the northern %^BLUE%^mountain.  %^RESET%^The"
" %^BOLD%^%^BLACK%^howling %^RESET%^is much louder here and sounds as though it may"
" be coming from somewhere above you.%^RESET%^\n");
} 
