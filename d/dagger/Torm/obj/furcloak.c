#include <std.h>
inherit "/std/armour";
create() {
    ::create();
  set_name("fur cloak");
  set_id(({"fur cloak","cloak"}));
  set_short("fur cloak");
    set_long(
  "  This massive shaggy cloak is made from an old bear pelt." 
  "  It looks very warm and so soft."
    );
  set_weight(10);
  set_value(100);
    set_type("clothing");
   set_limbs(({"neck"}));
  if (!random(5)) set_property("enchantment",1);
  set_size(roll_dice(1,3));
}
