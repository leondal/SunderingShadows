
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "portal" : ROOMS"0_2",
   ]));
}
void reset(){
   ::reset();
   if(!present("ahstuz"))
      new(MOBS"ahstuz.c")->move(TO);
}

void pick_critters(){ }
