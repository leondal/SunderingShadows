//water_earrings.c - New object for Koenig.  Circe 11/22/03
#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("water earrings");
   set_short("%^BOLD%^%^CYAN%^Water Earrings%^RESET%^");
   set_id(({"water earrings","earrings"}));
   set_long("%^BOLD%^%^CYAN%^This breath-taking pair of earrings seems to be made "+
      "from water itself.  They are made in the shape of raindrops and feel wet "+
      "to the touch, yet they never dry out.  They can be slipped into pierced "+
      "ears with their golden hooks.");
   set_lore("These earrings sometimes appear in the watery "+
      "places of the world.  No one has been able to discover "+
      "the source of their creation, and the followers of "+
      "Istishia contend that they are gifts from the Lady "+
      "of Singing Waters.  They never dry out or drip, instead "+
      "remaining perfect, beautiful decorations.");
   set_property("lore difficulty",8);
   set_weight(1);
   set_type("ring");
   set_limbs(({"head"}));
   set_value(15);
   set_wear("You slip the golden hooks into your ears and feel the slight weight of the earrings.");
   set_remove("You slip the golden hooks out of your ears, removing your water earrings.");
}