#include <std.h>
inherit "/std/bag_logic";

void create()
{
  ::create();
  set_name("leather pack");
  set_id( ({"leather pack", "pack"}) );
  set_short("%^RESET%^%^ORANGE%^A leather pack%^RESET%^");
  set_long("%^RESET%^%^ORANGE%^This is a finely made bag. It is very simple in design, featuring no adornments on its soft hide surface. It does look as if it would hold a lot, though.%^RESET%^");
  set_open_long("It is open.");
  set_closed_long("It is closed.");
  set_no_clean(1);
  set_weight(10);
  set_value(100);
  set_max_internal_encumbrance(300);
  set_possible_to_close(1);
}
