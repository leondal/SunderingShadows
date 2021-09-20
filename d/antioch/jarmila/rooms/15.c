#include <std.h>
#include "../jarmila.h"
inherit STORAGE"hill.c";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"14",
      "northeast" : ROOMS"16",

   ]));
}

void reset(){
   ::reset();
   if(!present("chunk of sunstone")){
      new(OBJ"sunstone.c")->move(TO);
   }
}

