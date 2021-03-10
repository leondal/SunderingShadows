#include <std.h>
inherit "/std/armour";

void create() {
   ::create();
set_name("mithril chainmail coif");
set("id", ({ "mithril coif", "coif","mithril chainmail coif","helmet","helm" }) );
set("short", "A mithril chainmail coif");
set("long", "%^BOLD%^This is a Mithril chainmail coif.
It was forged by the Dwarves of Mt. Sholkum.
This is the standard head protection for the Army of the Dagger Reaches.");
set_weight(5);
set("value", 40);
set_type("chain");
set_limbs( ({ "head" }) );
set_ac(1);
   if(!random(2)) {
set_property("enchantment", 1);
   }
}
