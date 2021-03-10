//gloves.c - for Lothwaite, Circe 12/19/04
#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_id(({"gloves","leather gloves","thick leather gloves"}));
   set_name("leather gloves");
   set_short("%^RESET%^%^ORANGE%^leather gloves%^RESET%^");
   set_long(
      "%^RESET%^%^ORANGE%^This pair of gloves is made of thick "+
      "leather lined with %^RESET%^wool %^ORANGE%^to provide "+
      "warmth and protection for your hands.  The wool is very "+
      "soft, and the thickness of the gloves would probably "+
      "prevent you from doing delicate tasks.%^RESET%^"
   );
   set_value(10);
   set_size(3);
   set_type("clothing");
   set_limbs(({"right arm","left arm"}));
}