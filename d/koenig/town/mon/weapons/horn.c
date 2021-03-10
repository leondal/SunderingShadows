#include <std.h>
inherit WEAPON;

void create()
{
  ::create();
  set_property("monsterweapon", 1);
  set_name("horn");
  set_id( ({"horn"}) );
  set_short("a piercing horn");
  set_long("This is the golden spiral horn of a unicorn.");
  set_weight(10);
  set("value", 1000);
  set_type("piercing");
  set_wc(1,6);
  set_large_wc(1,12);
  set_size(3);
}
