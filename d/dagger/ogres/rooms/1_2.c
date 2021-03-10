#include <std.h>
#include "../ogres.h"

inherit STORAGE"1st.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"1_1",
      "northwest" : ROOMS"1_3",
   ]));

}