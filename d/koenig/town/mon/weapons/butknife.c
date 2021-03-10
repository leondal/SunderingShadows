#include <std.h>
inherit "/d/common/obj/weapon/knife.c";

void create()
{
  ::create();
  set_id( ({"knife", "butcher knife"}) );
  set_name("butcher knife");
  set_short("%^BOLD%^%^WHITE%^a butcher knife%^RESET%^");
  set_long("%^RESET%^This huge knife is used to hack into"+
		" cuts of %^ORANGE%^meat%^RESET%^ and %^ORANGE%^bone%^RESET%^. The wide square blade is "+
		"attached to a maple wood handle. The blade is "+
		"%^GREEN%^dirty%^RESET%^ and coated with %^RED%^dried blood%^RESET%^.");
  set_weight(5);
  set_value(10);
  set_type("slashing");
  set_wc(1,8);
  set_large_wc(1,8);
  set_size(2);
}
