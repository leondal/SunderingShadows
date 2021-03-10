#include <std.h>
#include "../tharis.h"
inherit STORAGE"trade";

void create(){
   ::create();
   set_long(::query_long()+" Enticing smells emanate from the buildings at either "
"side of the street, though the one to the west looks decidedly more dark and dingy "
"than the establishment that lies opposite. Just a little further south, the main "
"city bazaar opens up into a scene of semi-organized %^MAGENTA%^chaos%^CYAN%^.%^RESET%^\n");
   set_exits(([
      "west" : ROOMS"tharis_dwarf",
      "east" : ROOMS"mbar",
      "south" : ROOMS"square1",
      "north" : ROOMS"north3",
   ]));
}