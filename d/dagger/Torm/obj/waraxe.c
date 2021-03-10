#include <std.h>
inherit WEAPON;

void create()
{
  ::create();
  set_id( ({"waraxe", "axe"}) );
  set_name("Waraxe");
  set_short("Waraxe");
  set_long("It is a rather nasty looking Axe...well cared for...looks pretty sharp...sharp enough to decapitate or dismember...");
  set_weight(20);
  set("value", 10);
  set_type("slashing");
  set_size(3);
  set_prof_type("large axe");
  set_wc(2,5);
  set_large_wc(3,6);
  set_size(2);
}
