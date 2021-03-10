#include <std.h>
#include "../ogres.h"

inherit STORAGE"1st.c";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"1_6",
      "east" : ROOMS"1_4",
   ]));

}