//Octothorpe (8/13/08)
//Underdark Mining Caverns, Hook Horror Hideaway, Neutral Cavern Room Zulu 1

#include <std.h>
#include "../defs.h"
inherit INH+"warrens";

object ob;
int item;

void create(){
   item = 1;
   :: create();
   set_long(::query_long() +"%^BOLD%^%^BLACK%^There is enough space "+
      "here to descend to the cavern floor below.%^RESET%^\n");
   set_exits(([
      "north":RMS"nucavernz2",
      "east":RMS"nucavernz4",
   ]));   
   set_climb_exits(([
      "descend" : ({RMS"nucavernb2",25,20,300}),
   ]));
}