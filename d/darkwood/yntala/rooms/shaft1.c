//shaft1
#include <std.h>
#include <rooms.h>
#include "../yntala.h"
inherit ROOM;

void create(){
::create();
   set_property("indoors",1);
   set_property("light",-1);
   set_property("no teleport",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^RESET%^Within a small shaft");
   set_short("%^RESET%^The inside of a pyramid%^RESET%^");
   set_listen("default","Whispers and soft hisses seem to float up from below and mix with the sounds of dripping water.");
   set_long((:TO,"ldesc":));
   set_items(([
   "walls":"The walls here seem to be in better condition than the outside of the pyramid.  They are smooth to the touch and quite cold.",
]));
   set_exits((["hole":INRMS+"top","down":INRMS+"shaft2"]));
}
string ldesc(string str){
   return("%^BOLD%^%^BLACK%^This is a steep sloping shaft that leads further into the depths of the pyramid."
"  It is not very big and the cold granite of the walls seem to close in around you, almost as if it were a"
" living being trying to strangle the last bits of life from your body.  No life is here at all, no rats,"
" no mice, no birds, not even the vines that climb the outside of the structure dare poke even a single leaf"
" into this dank hole.%^RESET%^");
} 
