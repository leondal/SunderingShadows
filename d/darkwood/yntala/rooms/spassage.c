//spassage west
#include <std.h>
#include <rooms.h>
#include "../yntala.h"
inherit CROOM;

void create(){
::create();
   set_property("indoors",1);
   set_property("light",-3);
   set_property("no teleport",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^RESET%^Within a hidden passage");
   set_short("%^RESET%^Within a hidden passage%^RESET%^");
   set_listen("default","Your footsteps echo on down the stone corridor.");
   set_long((:TO,"ldesc":));
   set_items(([
   "walls":"The walls here are completely bare and smooth to the touch.",
   "floor":"The floor is as bare as the walls.  The lack of any sort of padding makes your footsteps echo through the hall.",
]));
   set_exits((["west":INRMS+"spassage2","east":INRMS+"study"]));
   set_pre_exit_functions(({"east"}),({"go_out"}));
}
string ldesc(string str){
   return("%^BOLD%^%^BLACK%^This is a long, dark corridor that is devoid of any sort of ornamentation.  The walls"
" and floor are made of hard, cold stone.  A bit of dust has accumulated on the floors, indicating that this"
" part of the building has not been used in quite some time.  The stones have a few pressure cracks in them, but"
" not much else.  It looks like the passage ends just to the west.%^RESET%^");
} 
int go_out() { 
   if(find_object_or_load(INRMS+"study")->query_property("unmoved")) {
      tell_room(find_object_or_load(INRMS+"study"),"%^BOLD%^%^BLUE%^The western tapestry sudden shifts slightly to the side as "+TPQCN+" comes tumbling in over the couch!%^RESET%^",TP);
      tell_object(TP,"%^RESET%^%^BLUE%^You move the tapestry to the side without a care in the world and attempt to move forward.   Oops! A couch was in the way and you tumble over it into the other room!%^RESET%^");
   return 1;
   }
   return 1;
}
