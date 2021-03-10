#include <std.h>
#include "../ogres.h"

inherit STORAGE"1st.c";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"1_9",
      "south" : ROOMS"1_7",
   ]));

}