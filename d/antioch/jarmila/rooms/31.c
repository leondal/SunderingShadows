
#include <std.h>
#include "../jarmila.h"
inherit STORAGE"hill.c";

void create(){
   ::create();
   set_exits(([
      "southeast" : ROOMS"30",
      "west" : ROOMS"32",
   ]));
}

void reset(){
   ::reset();
   if(!present("chunk of sunstone")){
      new(OBJ"sunstone.c")->move(TO);
   }
}



