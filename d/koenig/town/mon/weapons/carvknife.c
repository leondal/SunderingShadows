#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";

void create()
{
  ::create();
  set_id( ({"knife", "carving knife"}) );
  set_name("carving knife");
  set_short("%^BOLD%^%^WHITE%^a carving knife%^RESET%^");
  set_long("%^RESET%^This knife is used to carve into roasted"+
		" %^ORANGE%^meats%^RESET%^ and %^GREEN%^vegetables%^RESET%^. The thin blade is"+
		" made from flexible steel, helping it to cut"+
		" around joints and bones. The blade has a "+
		"slight curve to it. Mounted on to a maple handle,"+
		" the knife seems sturdy.");
  set_weight(2);
  set_value(5);
  set_type("slashing");
  set_wc(1,6);
  set_large_wc(1,6);
  set_size(1);
}
