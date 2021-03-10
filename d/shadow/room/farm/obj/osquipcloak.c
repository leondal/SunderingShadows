#include <std.h>
inherit ARMOUR;

void create(){
	::create();
      set_name("osquip leather cloak");
     	set_id(({ "cloak", "osquip cloak","osquip leather cloak","yellow cloak" }));
      set_short("%^YELLOW%^Osquip Leather Cloak%^RESET%^");
      set_obvious_short("%^YELLOW%^A yellow leather cloak%^RESET%^");
      set_long( "%^YELLOW%^Crafted from the soft yellow hide of"+
		" an osquip, this leather cloak is simple in design."+
		"  The pieced sections of the cloak are sew together "+
		"with complementary threads, giving a smooth look to "+
		"the leather.  Osquip leather is soft and flexible highly"+
		" prized by tanners and tailors for its strength.  Leather"+
		" cords are sewn onto the leather cloak, allowing it to be"+
		" tied around the wearer's neck.%^RESET%^\n");
      set_weight(5);
      set_value(300);
      set_lore("The osquip is a territorial creature that lives"+
		" in caves and basements.  Using its spade like teeth to "+
		"dig tunnels, the osquip creates a vast network to stash "+
		"its treasure.  The six legged osquip is thought by many to"+
		" be one of the ugliest creatures around.  Though their soft"+
		" leather hides are in high demand with tailors and tanners.");
      set_property("lore difficulty",6);
      set_type("clothing");
      set_limbs(({ "neck" }));
      set_size(random(3)+1);
      set_property("enchantment",1);
	set_ac(0);
}
