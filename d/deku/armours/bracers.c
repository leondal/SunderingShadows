#include <std.h>
inherit "/d/common/obj/armour/bracers.c";
void create()
{
    ::create();
    if(!random(2)) set_property("enchantment", 1+random(3));
}
