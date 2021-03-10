#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("breastplate");
   set_id(({"armor","armour","breastplate","breast plate","plate","heavy breastplate"}));
   set_short("a heavy breastplate");
   set_long("The breastplate is commonly used by those not wishing to be encumbered by an entire set of "
"plate.  It consists of a plain, slightly dented breastplate and backing, that are secured at the sides of "
"the wearer.  A simple shoulderplate has been secured at either side, to protect the upper arms from harm.  "
"A thick layer of padding rests below the metal, keeping it from rubbing against the skin.");
   set_ac(7);
   set_weight(45);
   set_value(350);
   set_type("armor");
   set_limbs(({"torso"}));
}
