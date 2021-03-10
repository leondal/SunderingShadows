#include <std.h>
inherit WEAPON;

void create()
{
  ::create();
  set_name("Claymore");
  set_id( ({"Claymore", "claymore"}) );
  set_short("A claymore");
  set_long("This is a large and deadly weapon in the right hands.");
  set_weight(10);
  set_value(25);
  set_size(2);
  set_type("slashing");
  set_wc(2,4);
  set_large_wc(2,8);
  set_wield("You feel empowered and undefeatable as you wield this weapon.");
  set_hit("You slice and dice as you hit your opponet.");
  set_unwield("You feel vulnerable as you unwield the claymore.");
}
