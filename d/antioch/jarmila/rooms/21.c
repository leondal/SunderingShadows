
#include <std.h>
#include "../jarmila.h"
inherit STORAGE"hill.c";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"20",

   ]));
}

void reset(){
   ::reset();
   if(!present("dragon")){
      new(MOBS"silverd.c")->move(TO);
   }
}

