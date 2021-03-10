#include <std.h>

inherit "/d/common/obj/armour/fullplate.c";

void create() {
   ::create();
   set_id(({"fullplate","full plate","large fullplate","plate","armor"}));
   set_value(12000);
   set_size(3);
}
