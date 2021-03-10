#include <std.h>
inherit WEAPON;

void create()
{
  ::create();
  set_property("monsterweapon", 1);
  set_name("hook");
  set_id( ({"hook"}) );
  set_short("nasty hook");
  set_long("Nasty hooks from a decapus.");
  set_weight(1);
  set("value", 1);
  set_type("slashing");
  set_wc(1,6);
  set_large_wc(1,12);
  set_size(1);
}
