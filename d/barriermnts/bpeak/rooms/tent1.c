//tent1
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit CROOM;

void create(){
::create();
   set_property("indoors",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^RESET%^Inside a crudely made tent");
   set_short("%^RESET%^The inside of a crudely made tent%^RESET%^");
   set_smell("default","The smells of the stinking hides is overwhelming.");
   set_long((:TO,"ldesc":));
   set_items(([
   "furs":"%^RESET%^%^ORANGE%^The furs are old and dirty.  Some line the dirt floor for comfort while others line the exterior of the tent for shelter.%^RESET%^",
 ]));
   set_exits((["out":INRMS+"tcliff2"]));
   set_search("furs","%^RESET%^%^ORANGE%^The furs here are all disgusting.  Boy, you're sorry you even touched them.");
}
string ldesc(string str){
   return("%^RESET%^This is the inside of one of the tents that line the cliffs"
" edge.  Crude furs line the dirt floor and the smell is absolutely overwhelming."
"  There do not seem to be any personal items here and you wonder what these could"
" possibly be used for.  A little bit of light manages to filter in through some"
" of the holes in the furs that line the outside of this tent, creating a"
" surrealistic atmosphere.%^RESET%^ \n");
} 
