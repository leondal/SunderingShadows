#include <std.h>
inherit "/std/armour";
create() {
    ::create();
  set_name("sailors trousers");
  set_id(({"pants","trousers","sailors trousers"}));
    set_short("sailor's trousers");
    set_long(
  "  These simple cloth pants are worn by many of the crewmen of the ships that sail the sea."
    );
  set_value(10);
  set_type("clothing");
  set_limbs(({"left leg","right leg"}));
}
