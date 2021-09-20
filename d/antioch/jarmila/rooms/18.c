
#include <std.h>
#include "../jarmila.h"
inherit STORAGE"hill.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"17",
      "northwest" : ROOMS"19",

   ]));
}

void reset(){
   ::reset();
   if(!present("chunk of sunstone")){
      new(OBJ"sunstone.c")->move(TO);
   }
}


