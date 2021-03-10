#include <std.h>
#include "../tharis.h"
inherit STORAGE"sewer";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^\n");
   set_exits(([
      "east" : SEWERS"sewer8",
      "north" : SEWERS"sewer10",
      "south" : SEWERS"sewer11"
   ]));
}