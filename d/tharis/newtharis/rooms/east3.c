#include <std.h>
#include "../tharis.h"
inherit STORAGE"slum";

void create(){
   ::create();
   set_long(::query_long()+" To the east, the road broadens and the buildings gain a more delicate quality, but the area grows eerily quiet. You notice a door swinging open and closed to the "
"south without any sign over it.%^RESET%^\n");
   set_exits(([
      "east" : ROOMS"elf1",
      "west" : ROOMS"east2",
      "south" : ROOMS"thief_tailor",
   ]));
   set_invis_exits(({"south"}));
}
