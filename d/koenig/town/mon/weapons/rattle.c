#include <std.h>
inherit WEAPON;

void create()
{
  ::create();
  set_property("monsterweapon", 1);
  set_id( ({"rattle"}) );
  set_name("a rattle");
  set_short("This is a rattler.");
  set_weight(3);
  set_type("blundgeon");
  set_wc(1,6);
  set_large_wc(1,12);
  set_size(2);
}
