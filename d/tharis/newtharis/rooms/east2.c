#include <std.h>
#include "../tharis.h"
inherit STORAGE"slum";

void create(){
   ::create();
   set_long(::query_long()+" To the east, the road broadens and the buildings gain a more delicate quality, but the area grows eerily quiet. A dark alleyway leads off between the shabby houses here.%^RESET%^\n");
   set_exits(([
      "east" : ROOMS"east3",
      "west" : ROOMS"east1",
   ]));
   add_item("alleyway","%^BOLD%^%^BLACK%^A dark alleyway leads off between the shabby houses here, narrow and winding. At its end, stairs lead down towards one of the stone buildings that rise "
"up to either side, but they come to an abrupt dead end against a wall of stone.%^RESET%^");
   add_item("alley","%^BOLD%^%^BLACK%^A dark alleyway leads off between the shabby houses here, narrow and winding. At its end, stairs lead down towards one of the stone buildings that rise "
"up to either side, but they come to an abrupt dead end against a wall of stone.%^RESET%^");
}
