#include <std.h>
inherit "/std/armour";
create() {
    ::create();
  set_name("sandals");
  set_id(({
  "sandals",
  "cork sandals","sandal",
  }));
  set_short("cork sandals");
    set_long(
  "  These simple footwear are made of a length of cork wood with simple bindings to keep it from falling off."
  "  They form well to the foot, are very comfortable and stick well to the wet deck of a ship making them a favorite of the crews of the sailing vessels."
    );
  set_weight(1);
  set_value(5);
  set_type("clothing");
  set_limbs(({"left foot","right foot"}));
}
