#include <std.h>
inherit "d/common/obj/weapon/katana.c";

void create() {
    ::create();
   set_property("enchantment",2);
}
