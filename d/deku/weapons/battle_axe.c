#include <std.h>
inherit "/d/common/obj/weapon/battle_axe.c";

void create() {
    ::create();
   set_long(
	"This is a shiny, well kept battle axe."
   );
  set_property("enchantment",1);
}
