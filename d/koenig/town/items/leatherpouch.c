#include <std.h>
inherit "/std/bag_logic";

void create()
{
  ::create();
  set_name("leather pouch");
  set_id( ({"leather pouch", "pouch"}) );
  set_short("%^RESET%^%^ORANGE%^A leather pouch%^RESET%^");
  set_long("%^RESET%^%^ORANGE%^This is a finely made pouch. It is very simple in design, featuring no adornments on its soft hide surface.%^RESET%^");
  set_open_long("It is open.");
  set_closed_long("It is closed.");
  set_no_clean(1);
  set_weight(5);
  set_value(30);
  set_max_internal_encumbrance(20);
  set_possible_to_close(1);
}
