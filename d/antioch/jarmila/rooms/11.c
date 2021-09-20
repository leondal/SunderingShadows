#include <std.h>
#include "../jarmila.h"
inherit STORAGE"military.c";

void create(){
   ::create();
   set_exits(([
      "southeast" : ROOMS"10",

   ]));
}

void reset(){
   ::reset();
   if(!present("heavy iron brazier")){
      new(OBJ"brazier.c")->move(TO);
   }
}
