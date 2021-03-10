#include <std.h>
#include "../githyanki.h"

inherit STORAGE"1floor.c";

void create(){
   ::create();
  set_long(::query_long()+"%^RESET%^%^ORANGE%^The hall continues north and south%^RESET%^.\n");
   set_exits(([
      "north" : ROOMS"1_48",
      "west" : ROOMS"1_36",
   ]));

}