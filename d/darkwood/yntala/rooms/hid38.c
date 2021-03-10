//hid38
#include <std.h>
#include <rooms.h>
#include "../yntala.h"
inherit ROOM;
inherit IHRMS+"endhid.c";

void create(){
::create();
  set_name("%^ORANGE%^Within an underground cavern%^RESET%^");
  set_short("%^ORANGE%^Within an underground cavern%^RESET%^");
  set_long("%^RESET%^%^ORANGE%^This is a narrow, %^BOLD%^%^BLACK%^dark, %^RESET%^%^ORANGE%^cavern that twists"
" it's way beneath the earth's surface, and appears to have been made by natural causes.  No dig marks or signs"
" of shoring can be seen on the smooth walls.  %^BLUE%^Cold water %^ORANGE%^constantly drips from the high ceilings"
" whose lowest points are the only parts visible through the %^BOLD%^%^BLACK%^dark shadows %^RESET%^%^ORANGE%^that are"
" more than abundant down here.   The stagnate air leaves no room for growth, and the lack of any signs of life leads"
" one to believe that hanging around too long might not be such a good idea.  A %^BLUE%^cold, moist chill"
" %^ORANGE%^runs through the corridor, though it's origin is nearly impossible to detect.  The cavern comes to an"
" abrupt end here at a spectacular underground %^CYAN%^waterfall.\n");
   set_pre_exit_functions(({"ascend"}),({"GoThroughDoor"}));
   set_climb_exits((["ascend":({INRMS+"scave",15,4,100})]));
set_exits(([
"north":INRMS+"hid35"
]));
  set_items(([
     ({"floor","cave floor"}):"%^RESET%^%^ORANGE%^The cave floor is rocky and uneven. Puddles of water fill small holes in the %^BOLD%^%^BLACK%^rocks.%^RESET%^",
     ({"shadow","shadows"}):"%^BOLD%^%^BLACK%^Shadows line the edges of the cave, making it difficult to see what may be hiding there.",
      "cracks":"%^RESET%^Cracks line the floor and walls here, making a good place for small creatures to hide.",
      ({"puddles","puddles of water"}):"%^BLUE%^Puddles of stagnant, smelly water fill small holes in the cave floor.",
      "rocks":"%^RESET%^Rocks and large boulders of various sizes lay about the cave.",
      ({"walls","cave walls"}):"%^RESET%^%^BLUE%^The cavern walls are smooth to the touch.  Small %^RESET%^stalagnites %^RESET%^can be seen hanging from the ceiling.",
      "ceiling":"%^BOLD%^%^BLACK%^It is difficult to see the ceiling from here, and the %^RESET%^faint glow %^BOLD%^%^BLACK%^%^of %^RESET%^stalagnites %^BOLD%^%^BLACK%^can barely be made out.%^RESET%^",
      "waterfall":"%^RESET%^%^CYAN%^A magnificent underground waterfall rolls over a steep bank to the northwest before swiftly turning to the west and disappearing over yet another sharp ledge.%^RESET%^",
      "bank":"%^RESET%^%^ORANGE%^It looks like you may be able to ascend the steep bank if you can make it over the water!%^RESET%^",
]));
}
int GoThroughDoor() {
   if((random(20)-5) > TP->query_stats("dexterity")||(random(10)+10) > TP->query_stats("strength")) {
	tell_object(TP,"%^RESET%^%^CYAN%^You try to scramble up the rocks but get swept away by the strong current!");
      tell_room(TO,"%^CYAN%^"+TPQCN+" tries to scramble up the rocks but gets overcome by the current and gets swept away!", TP);
      if (!TP->query_ghost()){
         tell_room(find_object_or_load(INRMS+"hid3"),"%^BOLD%^%^CYAN%^"+TPQCN+" screams as "+TP->query_subjective()+" is washed in with the waterfall and deposited on the caverns floor!%^RESET%^",TP);
         TP->move_player(INRMS+"hid3");
         TP->do_damage("torso",roll_dice(5,5));                 
      }
   return 0;
   } 
   else {
	tell_object(TP,"%^RESET%^%^CYAN%^You scramble up the rocks despite the strong current tugging at you.");
      tell_room(TO,"%^RESET%^%^CYAN%^"+TPQCN+" scrambles up the rocks despite the strong current.", TP);
   return 1;
   }
}
