#include <std.h>
inherit WEAPON;


void create()
{
  ::create();
  set_property("monsterweapon",1);
  set_id( ({"fangs"}) );
  set_name("fangs");
  set_short("terrifying fangs");
  set_long("These fangs are long and nasty to behold.");
  set_weight(1);
  set("value",10);
  set_type("slashing");
  set_wc(1,4);
  set_large_wc(1,8);
  set_size(1);
}
