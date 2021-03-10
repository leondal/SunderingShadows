#include <std.h>
inherit WEAPON;

void create()
{
  ::create();
  set_property("monsterweapon",1);
  set_id( ({"pan", "frying pan"}) );
  set_name("pan");
  set_short("frying pan");
  set_long("It is made of cast iron.");
  set_weight(5);
  set("value", 0);
  set_type("blunt");
  set_wc(1,4);
  set_large_wc(1,8);
  set_size(1);
}
