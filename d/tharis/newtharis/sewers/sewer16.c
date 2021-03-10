#include <std.h>
#include "../tharis.h"
inherit STORAGE"sewer";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^\n");
   set_exits(([
      "north" : SEWERS"sewer3",
      "south" : SEWERS"sewer17",
   ]));
}