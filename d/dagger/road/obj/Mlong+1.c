#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
    set_id(({ "sword", "longsword", "long sword", "long","mithril sword","mithril longsword","mithril long sword" }));
    set_name("mithril longsword");
    set_short("A mithril longsword");
    set_long("%^BOLD%^This is a bright silvery mithril longsword.
It was forged by the Dwarves of Mt. Sholkum in the Dagger Reaches.
Dwarven runes line the center of the blade and it glows with strength.
On the hilt is the crest of the Army of the Dagger Reaches.");
set_weight(7);
set_size(2);
set("value", 100);
set_wc(1,8);
set_large_wc(1,12);
set_type("slashing");
   if(!random(2)) {
set_property("enchantment", 1);
   }
}
