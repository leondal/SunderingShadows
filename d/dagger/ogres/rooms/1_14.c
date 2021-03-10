#include <std.h>
#include "../ogres.h"

inherit STORAGE"1st.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"1_15",
      "northeast" : ROOMS"1_13",
   ]));

}