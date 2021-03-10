#include <std.h>
#include "../githyanki.h"

inherit STORAGE"1floor.c";


void create(){
   ::create();
   set_long(::query_long()+"%^BLACK%^%^BOLD%^The passage continues to the north and west, off to the west the halls are darker...%^RESET%^\n");
   set_exits(([
      "east" : ROOMS"1_38",
      "north" : ROOMS"1_32",
      "west" : ROOMS"1_24",
]));   

}
