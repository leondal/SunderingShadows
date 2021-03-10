#include <std.h>
inherit WEAPON;

void create()
{
  ::create();
  set_property("monsterweapon",1);
  set_id( ({"claws"}) );
  set_name("claws");
  set_short("sharp claws");
  set_long("You cant tell what they are made of but they look deadly!");
  set_weight(1);
  set("value", 10);
  set_type("slashing");
  set_wc(1,4);
  set_large_wc(1,8);
  set_size(1);
}
