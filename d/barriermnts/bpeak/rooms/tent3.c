//tent3
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit CROOM;
int searched;
object ob;

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
   set_exits((["out":INRMS+"tcliff4"]));
   set_search("furs",(:TO,"search_furs":));
   searched = 1;
}
string ldesc(string str){
   return("%^RESET%^This is the inside of one of the tents that line the cliffs"
" edge.  Crude furs line the dirt floor and the smell is absolutely overwhelming."
"  There do not seem to be any personal items here and you wonder what these could"
" possibly be used for.  A little bit of light manages to filter in through some"
" of the holes in the furs that line the outside of this tent, creating a"
" surrealistic atmosphere.%^RESET%^ \n");
} 
void search_furs(){
   if(searched <= 0) {               
	tell_object(TP,"%^RESET%^%^ORANGE%^You carefully search through all the leathers in the room only to find nothing.%^RESET%^");
      return 1;
   } 
   tell_object(TP,"%^RESET%^%^ORANGE%^You carefully dig through the leather and find something crumpled in them!%^RESET%^");
   tell_room(ETP,"%^RESET%^%^ORANGE%^"+TPQCN+" digs through the leather and pulls out a crumpled old scroll.%^RESET%^",TP);
   ob = new("/d/magic/scroll");
   ob->set_spell(random(3)+2);
   ob->move(TO); 
   searched --;
   return 1;
}
void reset() {
   ::reset();
   searched = 1;
}
