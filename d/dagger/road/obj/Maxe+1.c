
#include <std.h>
inherit "/d/common/obj/weapon/battle_axe";


create() {
  ::create();
set_id(({ "axe","battleaxe","mithril axe","mithril dwarven battleaxe","dwarven battleaxe"}));
set_name("mithril dwarven battleaxe");
set_short("A mithril dwarven battleaxe");
set_long("This is a bright silvery mithril dwarven battleaxe.
It was forged by the Dwarves of Mt. Sholkum.
Dwarven runes line the shaft of the battleaxe and it glows with strength.
On the blade is the crest of the Army of the Dagger Reaches.");
//set_weight(8);
set_size(1);
set("value", 75);
//set_wc(1,8);
//set_large_wc(1,8);
//set_type("slash");
//set_prof_type("small axe");
set_property("enchantment", 1);
}
