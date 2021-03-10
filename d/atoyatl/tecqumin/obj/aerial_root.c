//Coded by Lujke

#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/club";

void create(){
  ::create();
  set_name("aerial root");
  set_id(({ "root","aerial root"}));
  set_short("Orchevid root");
  set_obvious_short("An aerial root");
  set_long( "The aerial root of an orchevid plant");

  set_value(150000);
  set_property("enchantment", 6);
  set_weapon_speed(3);
  set_item_bonus("attack bonus",3);
  set_item_bonus("damage bonus",3);
}

