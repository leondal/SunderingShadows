#include <std.h>
#include "../tharis.h"
inherit STORAGE"trade";

void create(){
   ::create();
   set_long(::query_long()+" To the east lies a large, elegant building of considerable "
"age and prestige, structured with wooden walls and marble columns. It overshadows the far "
"simpler building to the west, which has a series of mannequins in the window, each "
"draped with what look to be fine and expensive garments.%^RESET%^\n");
   set_exits(([
      "east" : ROOMS"tharis_bank1",
      "west" : ROOMS"tharis_clothing",
      "south" : ROOMS"north4",
      "north" : ROOMS"north2",
   ]));
}