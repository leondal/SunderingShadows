#include <std.h>
inherit WEAPON;

void create()
{
  ::create();
  set_property("monsterweapon",1);
  set_id( ({"claws"}) );
  set_name("claws");
  set_short("sharp claws");
  set_long("You cant tell what they are made of but they look disgusting and deadly!");
  set_weight(5);
  set("value", 10);
  set_type("slashing");
  set_wc(1,4);
  set_large_wc(1,8);
  set_size(1);
  set_wield("Your body shivers in disgust as you wield the claws.");
  set_hit("%^BOLD%^%^YELLOW%^You tear your opponet viciously as the claws sink deep into their flesh!");
  set_unwield("You feel cleaner now that you no longer wield the claws.");
}
