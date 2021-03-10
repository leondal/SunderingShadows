#include <std.h>
inherit "/d/common/obj/armour/chain";

#define COLORS ({"%^RESET%^%^BLUE%^cold iron%^RESET%^",\
"%^YELLOW%^gold%^RESET%^",\
"%^RESET%^%^ORANGE%^bronze%^RESET%^",\
"%^BOLD%^%^CYAN%^silver%^RESET%^",\
"%^RESET%^%^CYAN%^steel%^RESET%^"})

void create(){
     	int j;
	string str, COLOR;
	::create();
	j = random(sizeof(COLORS));
      COLOR = COLORS[j];
	set_name("chain shirt");
	set("id", ({ "chain", "armor", "shirt", "chainmail","chainmail shirt"}) );
	set_short("%^BOLD%^%^WHITE%^A %^RESET%^"+COLOR+" %^BOLD%^%^WHITE%^chain"+
		" shirt%^RESET%^");
     	set_long("%^BOLD%^This shirt has been crafted from "+COLOR+" %^BOLD%^"+
		"%^WHITE%^metal links.  The shirt is evenly weighted, to provide"+
		" some comfort.  Though not as protective as plated armor, the "+
		"chainmail appears as if it would provide a good defense.%^RESET%^\n");
	set_value(450);
	set_property("enchantment",1);
}
