#include <std.h>
#include "../githyanki.h"

inherit STORAGE"1floor.c";

void create(){
   ::create();
  set_long(::query_long()+"%^RESET%^%^ORANGE%^The hall continues east and west%^RESET%^.\n");
   set_exits(([
      "east" : ROOMS"1_28",
      "west" : ROOMS"1_14",
   ]));

}