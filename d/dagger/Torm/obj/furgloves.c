#include <std.h>
inherit "/std/armour";
create() {
    ::create();
  set_name("fur gloves");
  set_size(roll_dice(1,3));

  set_id(({"gloves","fur gloves"}));
  set_short("fur gloves");
    set_long(
  "  These heavy fur gloves would be nice wandering around the wilds in winter."
   "  They're smooth as silk to the touch and have been expertly made."
    );
  set_weight(10);
  set_value(100);
    set_type("clothing");
   set_limbs(({"right arm","left arm"}));
}
