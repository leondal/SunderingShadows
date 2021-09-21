
#include <std.h>
#include "../jarmila.h"
inherit STORAGE"hill.c";

void create(){
   ::create();
   set_exits(([
      "southwest" : ROOMS"19",
      "east" : ROOMS"21",

   ]));
}

void reset(){
   ::reset();
   if(!present("chunk of sunstone")){
      new(OBJ"sunstone.c")->move(TO);
   }
}



