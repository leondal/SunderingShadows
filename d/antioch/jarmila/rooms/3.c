#include <std.h>
#include "../jarmila.h"

inherit STORAGE"tentcity.c";

void create(){
   ::create();
   set_exits(([

	  "southeast" : ROOMS"2",


   ]));

}

void reset(){
   ::reset();
   if(!present("mathilda foster")){
      new(MOBS"mathilda.c")->move(TO);
   }
}
