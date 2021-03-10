#include <std.h>
inherit "/d/common/obj/weapon/knife.c";

void create()
{
  ::create();
  set_id( ({"knife", "kitchen knife"}) );
  set_name("kitchen knife");
  set_short("%^BOLD%^%^WHITE%^a kitchen knife%^RESET%^");
  set_long("%^BOLD%^%^WHITE%^This common knife is used to slice into %^RESET%^%^ORANGE%^steaks%^BOLD%^%^WHITE%^,"+
		" %^RESET%^%^ORANGE%^roasts%^BOLD%^%^WHITE%^, and other such cuts of %^RESET%^%^ORANGE%^meat%^BOLD%^%^WHITE%^. While not"+
		" strong enough to hack apart large chunks of meat,"+
		" this knife could easily be used to slice food into"+
		" more manageable pieces.");
 }
