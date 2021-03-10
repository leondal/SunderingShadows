#include <std.h>
#include "../../gantioch.h"

inherit MOUNDINH;

string roomlong, b_long, a_long;

void create(){
   ::create();
   set_long((: TO, "thislong" :));
   set_exits(([
      "north"  : MOUND"mound9",
      "east"  : MOUND"mound11",
   ]));
   set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));
   roomlong = MOUNDINH->query_long();
   b_long = "%^RESET%^%^ORANGE%^The tunnel continues deeper into the mound"+
            " winding through the hill. ";
   a_long = "\n\n%^BOLD%^%^CYAN%^The tunnel continues to the east, sloping,"+
            " deeper into the mound, however it looks to widen to the east.";
}

/*int GoThroughDoor() {
    if(member_array("Freed the Slaves",TP->query_mini_quests())!=-1)  {
    return 1;}
    else;{
    write("You feel like there is nothing worth your time that way.");
    return 0;
    }
    return 1;
}
*/
int GoThroughDoor() {
object room;
  if(member_array("%^BOLD%^%^CYAN%^Freed the Slaves%^RESET%^",TP->query_mini_quests())!=-1)  {
   if(TP->query_paralyzed() || TP->query_bound() ||
TP->query_unconscious()){
    return 0;}
    write("You feel like there is nothing worth your time that way.");
    return 0;}
    else; {
  return 1;}
}

string thislong(){
   return b_long+roomlong+a_long;
}
