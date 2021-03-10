#include <std.h>
inherit "/std/armour";
create() {
    ::create();
  set_name("damp robe");
  set_id(({"robe","damp robe","robes"}));
  set_short("damp robes");
    set_long(
  "  These nondescript robes seem wet and they smell terrible, sort of like a fishmarket after a long day in the sun."
  "  Slime gleams off the inside of the hood and overall this doesnt seem to be a very appetizing thing to wear."
    );
  set_weight(10);
  set_value(0);
    set_type("clothing");
     set_limbs(({"torso"}));
  set_ac(1);
}
