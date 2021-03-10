#include <std.h>
#include "../tharis.h"
inherit STORAGE"sewer";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^\n");
   set_exits(([
      "west" : SEWERS"sewer2",
      "south" : SEWERS"sewer1b",
   ]));
}
