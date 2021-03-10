#include <std.h>
#include "../ogres.h"

inherit STORAGE"1st.c";

void create(){
   ::create();
   set_exits(([
        "out" : "/d/dagger/keep/road/entrance2",
      "north" : ROOMS"1_2",
   ]));

}
void reset(){
   ::reset();
   if(!present("escapee"))
      new(MOBS"escapee.c")->move(TO);
}
