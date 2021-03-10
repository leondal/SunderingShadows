#include <std.h>
inherit WEAPON;

void create()
{
  ::create();
  set_property("monsterweapon",1);
  set_id( ({"fangs"}) );
  set_name("fangs");
  set_short("terrifying fangs");
  set_long("These are the disgusting fangs from a Bhut's mouth!.");
  set_weight(5);
  set("value",10);
  set_type("piercing");
  set_wc(1,4);
  set_large_wc(1,8);
  set_size(1);
set_hit((:this_object(), "weapon_hit" :));
}

int weapon_hit(object attacker) {
if((string)attacker->set_paralyzed(10));
}
