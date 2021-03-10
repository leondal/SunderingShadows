#include <std.h>
#include "../ogres.h"

inherit STORAGE"1st.c";

void create(){
   ::create();
   set_exits(([
      "northeast" : ROOMS"1_7",
      "south" : ROOMS"1_5",
   ]));

}