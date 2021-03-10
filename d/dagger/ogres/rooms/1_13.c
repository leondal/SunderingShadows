#include <std.h>
#include "../ogres.h"

inherit STORAGE"1st.c";

void create(){
   ::create();
   set_exits(([
      "southwest" : ROOMS"1_14",
      "north" : ROOMS"1_12",
   ]));

}