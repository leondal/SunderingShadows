
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "southwest" : ROOMS"ogremaze8",
   ]));
}
void reset(){
   ::reset();
   if(!present("corpse"))
      new(OBJ"corpse.c")->move(TO);
}

