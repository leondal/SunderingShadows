
#include <std.h>
inherit "/d/common/obj/weapon/broad.c";

create() {
  ::create();
set_id(({ "sword", "broadsword", "broad sword", "broad","mithril sword","mithril broadsword","mithril broad sword" }));
set_name("mithril broadsword");
set_short("A mithril broadsword");
set_long("%^BOLD%^This is a bright silvery mithril broadsword.
It was forged by the Dwarves of Mt. Sholkum.
Dwarven runes line the center of the blade and it glows with strength.
On the hilt is the crest of the Army of the Dagger Reaches.");
//set_weight(8);
set_size(2);
set("value", 55);
//set_wc(2,4);
//set_large_wc(2,6);
//set_type("slashing");
set_property("enchantment", 1);
}

