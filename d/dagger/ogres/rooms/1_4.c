#include <std.h>
#include "../ogres.h"

inherit STORAGE"1st.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"1_3",
      "west" : ROOMS"1_5",
   ]));

}