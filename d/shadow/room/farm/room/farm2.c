#include <std.h>
#include "../farm.h"

inherit BARNYARD;

void create(){
   ::create();
   set_long(::query_long()+"\nThe %^BOLD%^%^BLUE%^stream %^RESET%^"+
      "rushes by on the north, while the farm opens "+
      "back up to the south.\n");
   set_exits(([
      "west" : PATHS"farm1",
      "southwest" : PATHS"farm5",
      "south" : PATHS"farm6",
      "east" : PATHS"farm3"
   ]));
}

void reset(){
   ::reset();
   if(!present("goose") && !random(3)){
      new(MON"goose")->move(TO);
   }
}