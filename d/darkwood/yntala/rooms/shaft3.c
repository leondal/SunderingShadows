//shaft3
#include <std.h>
#include <rooms.h>
#include "../yntala.h"
inherit CROOM;

void create(){
   switch(random(13)){
      case 0..5:
      break;
      case 6..10:
         set_monsters(({TMONDIR +"yuan-tip.c"}),({2}));
      break;
      case 11..12:
         set_monsters(({TMONDIR +"yuan-tih.c"}),({1}));
   }
   set_repop(40);

::create();
   set_property("indoors",1);
   set_property("light",-3);
   set_property("no teleport",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^RESET%^Within a small shaft");
   set_short("%^RESET%^The inside of a pyramid%^RESET%^");
   set_listen("default","Whispers and soft hisses seem to float up from below and mix with the sounds of dripping water.");
   set_long((:TO,"ldesc":));
   set_items(([
   "walls":"The walls here seem to be in better condition than the outside of the pyramid.  They are smooth to the touch and are covered with some sort of slimy substance.",
   ({"slime","slimy substance","substance"}):"The substance that covers the walls seems to have no color nor odor.  Here it is quite thick and could even pass for a type of jelly that has been smeared onto the walls.",
]));
   set_exits((["down":INRMS+"shaft4","up":INRMS+"shaft2","east":INRMS+"hall1"]));
}
string ldesc(string str){
   return("%^BOLD%^%^BLACK%^It gets even darker here and shadows dance off of the walls.  The slimy substance"
" glistens on the walls and seems to be moving, sort of like a thick jelly that has been smeared everywhere."
"  The shaft continues to make its way downwards, and a small hallway seems to split off to the east.%^RESET%^");
} 
