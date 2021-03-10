#include <std.h>
inherit WEAPON;

void create()
{
  ::create();
  set_property("monsterweapon", 1);
  set_id( ({"stinger"}) );
  set_name("stinger");
  set_short("A Sharp Stinger");
  set_long("Sharp and nasty.");
  set_weight(5);
  set("value", 5);
  set_type("piercing");
  set_wc(1,4);
  set_large_wc(1,8);
  set_size(2);
}
