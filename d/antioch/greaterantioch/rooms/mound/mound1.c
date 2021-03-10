#include <std.h>
#include "../../gantioch.h"

inherit MOUNDINH;

string roomlong, b_long, a_long;

void create(){
   ::create();
   set_long((: TO, "thislong" :));
   set_exits(([
      "out"   : FOOTHILLS"foothills12",
      "east"  : MOUND"mound2",
   ]));
   set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));
   roomlong = MOUNDINH->query_long();
   b_long = "%^RESET%^%^ORANGE%^As you enter the mound the%^BOLD%^%^BLACK%^"+
            " darkness %^RESET%^%^ORANGE%^quickly becomes apparent, quickly absorbing any"+
            " %^BOLD%^%^YELLOW%^light %^RESET%^%^ORANGE%^from the outside. ";
   a_long = "\n\n%^BOLD%^%^CYAN%^The tunnel continues to the east, slowly moving"+
            " deeper into the mound.%^RESET%^";
}

string thislong(){
   return b_long+roomlong+a_long;
}

int GoThroughDoor() {
object room;
if(member_array("%^BOLD%^%^CYAN%^Agreed to Save the Slaves!%^RESET%^",TP->query_mini_quests())!=-1)  {
   if(TP->query_paralyzed() || TP->query_bound() ||
TP->query_unconscious()){
    return 0;
    }
    write("%^BOLD%^%^YELLOW%^You realize that this must be the mound in which the man at the keep"+
          " must have been talking about. By his information, many people were taken here in recent"+
          " raids on the newly developing town. I wonder what could have happened to them?");
    room = find_object_or_load(MOUND"mound13");
    if (present("slave",room)){
        return 1;}
         else {
        new(MON"slave.c")->move(room);}
  return 1;
  } else {
	  return 1;
  }
}
