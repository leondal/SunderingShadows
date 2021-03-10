#include <std.h>
inherit "/std/armour";

void create() {
    ::create();
    set_name("cloak");
    set_id(({"cloak", "skin cloak"}));
    set_short("Many skinned cloak");
    set_long(
   "     %^GREEN%^This cloak is made of many different colours of skin, all carefully sewn "+
   "together with thread.  The stitches are large in order to keep the pieces of "+
   "skin firmly together.  The skins are many different colors and it almost makes "+
   "you wonder from what types of beasts is this cloak made.  Strangely it would "+
   "seem to be the skin colors of the beastial inhabitants of these lands. Only "+
   "someone of great hunting skill could have made this cloak.");
    set_weight(4);
    set_value(50);
    set_type("clothing");
    set_limbs(({"neck"}));
    set_property("enchantment",2);
    set_size(3);
}


