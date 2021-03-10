#include <std.h>
#include "../githyanki.h"

inherit STORAGE"1floor.c";

void create(){
   ::create();
  set_long(::query_long()+"%^RESET%^%^ORANGE%^The hall continues west and south%^RESET%^.\n");
   set_exits(([
      "south" : ROOMS"1_44",
      "west" : ROOMS"1_42",
   ]));

}