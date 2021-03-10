//Octothorpe (8/13/08)
//Underdark Mining Caverns, Hook Horror Hideaway, Neutral Cavern Room Zulu 3

#include <std.h>
#include "../defs.h"
inherit INH+"warrens";

object ob;
int item;

void create(){
   item = 1;
   :: create();
   set_exits(([
      "south":RMS"nucavernz4",
      "west":RMS"nucavernz2",
   ]));   
}

void reset(){
   ::reset();
   item = 1;
   if(!present("hook horror queen")){
      new(MON+"hookqueen")->move(TO);
   }
}