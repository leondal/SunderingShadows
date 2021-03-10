//shaft2
#include <std.h>
#include <rooms.h>
#include "../yntala.h"
inherit ROOM;

void create(){
::create();
   set_property("indoors",1);
   set_property("light",-2);
   set_property("no teleport",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^RESET%^Within a small shaft");
   set_short("%^RESET%^The inside of a pyramid%^RESET%^");
   set_listen("default","Whispers and soft hisses seem to float up from below and mix with the sounds of dripping water.");
   set_long((:TO,"ldesc":));
   set_items(([
   "walls":"The walls here seem to be in better condition than the outside of the pyramid.  They are smooth to the touch and are covered with some sort of slimey substance.",
   ({"slime","slimey substance","substance"}):"The substance that covers the walls seems to have no color nor odor.  It could pass for a very thick water, or even perhaps some type of lacquer.",
]));
   set_exits((["down":INRMS+"shaft3","up":INRMS+"shaft1"]));
}
string ldesc(string str){
   return("%^BOLD%^%^BLACK%^The shaft continues to slope downwards towards the base of the inside of the pyramid"
" and seems to get even more dark the deeper you go.  The walls here are smooth to the touch and seem to be covered"
" with some sort of slimey substance.  The substance has no color nor odor and looks somewhat like thick,"
" clear water, or maybe even a lacquer of some sort.%^RESET%^");
} 
