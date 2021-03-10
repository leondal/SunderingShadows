#include <std.h>
inherit "/std/armour";
create(){
  ::create();
  set_name("smock");
  set_id(({"smock","white smock","chefs smock","white chefs smock","robe"}));
  set_short("White smock");
  set_long(
  "  This loose fitting white overcoat has two sets of buttons running down the front and is gleaming white.  Dirt and filth (and blood) seem to slide off it as if in a hurry to be away from its surface."
  );
  set_weight(5);
  set_value(50);
  set_type("clothing");
  set_limbs(({"torso"}));
  set_ac(0);
  set_property("enchantment",2);
}
