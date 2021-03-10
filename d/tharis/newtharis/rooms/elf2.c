#include <std.h>
#include "../tharis.h"
inherit STORAGE"elf";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^\n");
   set_exits(([
      "east" : ROOMS"elf3",
      "west" : ROOMS"elf1",
   ]));
}