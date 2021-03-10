
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "south" : ROOMS"ogremaze35",
   ]));
}
void reset(){
   ::reset();
   if(!present("corpse"))
      new(OBJ"corpse2.c")->move(TO);
}
