#include <std.h>
inherit "/d/common/obj/weapon/longsword";

void create() {
   	::create();
   	set_id(({ "sword", "longsword", "long sword", "long" }));
   	set_name("longsword");
   	set_short("A long sword");
   	set_value(100);
   	set_property("enchantment",3);
}