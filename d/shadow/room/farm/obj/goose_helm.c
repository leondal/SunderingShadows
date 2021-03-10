#include <std.h>
inherit "/d/common/obj/armour/helm";

void create(){
	::create();
      set_name("helmet");
     	set_id(({"helm","goose helmet","helmet","crash helmet","dented helmet"}));
      set_short("%^BOLD%^%^RED%^Crash %^WHITE%^Helmet%^RESET%^");
      set_obvious_short("a dented metal helmet");
      set_long("This small helmet is crafted from steel and "+
         "padded with hay-stuffed muslin.  A %^BOLD%^%^BLACK%^"+
         "black leather %^RESET%^strap has been attached for "+
         "a chin strap.  The metal of the helmet is riddled "+
         "with %^BOLD%^dings %^RESET%^and %^ORANGE%^dents%^RESET%^, "+
         "giving it an aged, worn appearance.  It would "+
         "clearly fit only someone with a very small head.");
      set_lore("Crated by the gnomish inventor Piaf Huffelmuffin, "+
         "helmet was intended to protect the head of a goose.  "+
         "Piaf noticed the natural tendency of the geese to "+
         "dive down for food, and he thought they might could "+
         "use a little added protection.  Strangely, once the "+
         "helmet was on the geese, they seemed to develop "+
         "an affinity for diving into other things. - An "+
         "Observation of Piaf - Theadora Illonium");
      set_property("lore difficulty",7);
      set_ac(0);
      set_property("enchantment",1);
}