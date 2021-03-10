#include <std.h>
inherit "/std/armour";
create() {
    ::create();
  set_name("dirty rags");
  set_id(({"rags","dirty rags"}));
  set_short("dirty rags");
    set_long(
    "  You can hardly tell what this might have once been, it's too spoiled and ripped now."
    "  It's really hardly worth even touching with the bugs and filth that acompany it."
    );
  set_weight(10);
  set_value(0);
    set_type("clothing");
     set_limbs(({"torso"}));
  set_ac(1);
}
