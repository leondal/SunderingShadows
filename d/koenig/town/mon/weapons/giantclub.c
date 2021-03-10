#include <std.h>
inherit WEAPON;

void create()
{
  ::create();
  set_id( ({"giant club", "club"}) );
  set_name("club");
  set_short("%^RESET%^%^ORANGE%^A large club%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This giant club looks to be made from an entire tree! It is even still %^GREEN%^gnarled%^RESET%^%^ORANGE%^ in places, but the handle is polished smooth to allow you to grip it firmly while you bash your opponent.%^RESET%^");
  set_weight(25);
  set_type("bludgeoning");
  set("value", 10);
  set_wc(1,20);
  set_prof_type("club");
  set_large_wc(1,10);
  set_size(3);
}
