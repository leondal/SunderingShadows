//updated by Circe 6/13/04 with new desc, lore, etc.
#include <std.h>
inherit "/d/common/obj/weapon/longsword";

void create() {
    ::create();
    set_id(({ "falchion", "sword", "dark falchion", "dark sword" }));
    set_name("dark falchion");
    set_obvious_short("a darkened sword");
    set_short("%^BOLD%^%^BLACK%^Dark Falchion%^RESET%^");
    set_long("This aged sword has a curving blade made of %^BOLD%^"+
       "%^BLACK%^blackened steel %^RESET%^that never seems to "+
       "lighten.  It would seem, almost, that ash or some other "+
       "agent was added to the steel at the time of creation.  "+
       "The blade is curves to a piercing point, though it would "+
       "seem the virtue of this blade lies in slashing.  The hilt "+
       "is wrapped in %^ORANGE%^cracked leather %^RESET%^that "+
       "looks as though it might disentigrate at any moment, though "+
       "it feels strangely supple to the touch.");
    set_lore("This blade is said to have survived for countless "+
       "centuries without ever rusting.  It can show normal wear, "+
       "but it can always be repaired and never seems to diminish.  "+
       "Sages speculate that it is the strange magic of the "+
       "Kinnesaruden that keeps the blade this way.");
    set_weight(10);
    set_size(2);
    set_value(200);
    set_property("enchantment",1+random(2));
    set_type("slashing");
    set_wield("You grasp the leather wrapped handle firmly.");
    set_unwield("You release your grasp on the Dark Falchion.");
}
