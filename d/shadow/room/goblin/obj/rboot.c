//updated by Circe 6/1/04 with new desc, lore, etc by Shar
#include <std.h>

inherit ARMOUR;
void create() {
    ::create();
    set_name("boot");
    set_id(({"boot","right boot","fur boot","right fur boot"}));
    set_short("%^BOLD%^%^BLACK%^a right fur boot%^RESET%^");
    set_long(
@CIRCE
This is a single boot made from a %^BOLD%^%^BLACK%^shaggy black fur%^RESET%^.  The fur looks as if it might be flea infested and full of grime.  And let's not even mention the %^BOLD%^%^GREEN%^stench%^RESET%^ that comes from within the boot.  Only someone truly desperate would ever wear something this disgusting.
CIRCE
    );
    set_lore("The fur boot is crafted from the hide of a warg.  The "+
       "goblins, like most barbaric and primitive cultures, believe "+
       "that by wearing the creatures that they revere that they can "+
       "gain the creature's abilities.  The goblins idolize how the "+
       "wargs move with swift speed and strike with a savage "+
       "strength.  Thus by wearing boots made of warg hides, they "+
       "hope to gain speed and strength in battle.");
    set_property("lore difficulty",4);
    set_weight(1);
    set_value(1);
    set_type("clothing");
    set_limbs(({"right foot"}));
    set_ac(0);
}
