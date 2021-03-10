#include <std.h>
inherit WEAPON;

void create()
{
  ::create();
  set_property("monsterweapon", 1);
  set_id( ({"fangs"}) );
  set_name("fangs");
  set_short("terrifying fangs");
  set_long("These are the razor sharp jaws from a piranha bird.");
  set_weight(2);
  set("value", 5);
  set_type("piercing");
  set_wc(1,4);
  set_large_wc(1,8);
  set_size(1);
}
