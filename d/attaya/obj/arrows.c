//updated by Circe 1/1/05 with new desc and lore.
//Added +1 enchantment to prevent animate object cheese Octothorpe (5/4/09)
#include <std.h>

inherit "/std/ammo";

void create() {
    ::create();
    set_id(({ "arrows","quiver","ethereal arrows" }));
    set_name("ethereal arrows");
    set_obvious_short("a quiver of shimmering arrows");
    set_short("%^BOLD%^%^CYAN%^A quiver of powerful ethereal arrows%^RESET%^");
    set_long(
      "%^BOLD%^%^CYAN%^These are glowing arrows of condensed "+
      "light and energy.  They utilize a rapidly changing "+
      "matrix to generate heat when they collide with their target.%^RESET%^"
    );
    set_lore("Crafted by the might of the Kinnesaruda, the creation "+
       "of these arrows is by a process unknown to the rest of the realms.  "+
       "No one yet has been able to master energy in the way these "+
       "powerful undead have.  Many people rumor that the Magus "+
       "Prime was involved in their creation, though this rumor "+
       "is hard to verify - as she is often unwilling to talk first.");
    set_property("lore difficulty",15);
    set_shots(-1);
    set_wc(2,10);
    set_large_wc(3,12);
    set_ammo_type("ethereal arrows");  //added by Circe
}
