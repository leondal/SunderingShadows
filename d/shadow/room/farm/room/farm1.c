#include <std.h>
#include "../farm.h"

inherit BARNYARD;

void create(){
   ::create();
   set_long(::query_long()+"\nThe %^BOLD%^%^BLUE%^stream %^RESET%^"+
      "rushes by on the north and west, while the farm opens "+
      "back up to the south and east.\n");
   set_exits(([
      "east" : PATHS"farm2",
      "southwest" : PATHS"farm4",
      "south" : PATHS"farm5",
      "southeast" : PATHS"farm6"
   ]));
}

void reset(){
   ::reset();
   if(!present("goose") && !random(3)){
      new(MON"goose")->move(TO);
   }
}