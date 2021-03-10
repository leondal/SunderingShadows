//Updated to bring in line with area difficulty - Octothorpe 4/15/10

#include <std.h>
inherit "/d/common/obj/armour/chain";

void create(){
   ::create();
   set_name("chain shirt");
   set_id(({"chain","chain shirt","armor","cobalt chain shirt"}));
   set_short("%^BOLD%^%^BLUE%^Cobalt Chain Shirt%^RESET%^");
   set_obvious_short("chain shirt");
   set_long(
      "%^BOLD%^%^BLUE%^This chain shirt is made from interlocking"+
	" links of what would appear to be metal."+
      " The shirt has a thin layer of %^WHITE%^cushion%^BLUE%^ under"+
	" it to prevent discomfort"+
     	" from the chaffing of the armor. The armor itself is very thin"+
      ", but heavy. In summary the design allows for it to be worn"+
      " under clothing while providing the protection of heavier armor.");
   set_property("enchantment",3+random(2));
   set_value(6000);
   set_lore(
      "This chain shirt is rumored to be made from the scales of a "+
	"Blue dragon, but others think it is only magically colored steel."+
	" It is unlikely that scales from a blue dragon can be turned into"+
	" chain links, as such a task would require a master, but the idea "+
	"can not be entirely dismissed, since no one knows who made the armor.");
   set_property("lore",9);
}
