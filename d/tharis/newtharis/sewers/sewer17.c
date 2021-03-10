#include <std.h>
#include "../tharis.h"
inherit STORAGE"sewer.c";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^\n");
   set_exits(([
      "north" : SEWERS"sewer16",
      "south" : SEWERS"sewer18",
   ]));
}