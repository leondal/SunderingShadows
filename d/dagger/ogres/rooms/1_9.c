#include <std.h>
#include "../ogres.h"

inherit STORAGE"1st.c";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"1_10",
      "east" : ROOMS"1_8",
   ]));

}