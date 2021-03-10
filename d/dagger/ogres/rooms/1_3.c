#include <std.h>
#include "../ogres.h"

inherit STORAGE"1st.c";

void create(){
   ::create();
   set_exits(([
      "southeast" : ROOMS"1_2",
      "west" : ROOMS"1_4",
   ]));

}