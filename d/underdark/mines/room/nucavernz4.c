//Octothorpe (8/13/08)
//Underdark Mining Caverns, Hook Horror Hideaway, Neutral Cavern Room Zulu 4

#include <std.h>
#include "../defs.h"
inherit INH+"warrens";

object ob;
int item;

void create(){
   item = 1;
   :: create();
   set_exits(([
      "north":RMS"nucavernz3",
      "west":RMS"nucavernz1",
   ]));   
}