#include <std.h>
#include "../valley.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("pixie shoes");
	set_id(({"shoes","red shoes","pixie shoes","bright red shoes","curly shoes","curly toed shoes"}));
	set_short("%^BOLD%^%^RED%^Curly toed shoes%^RESET%^");
	set_long(
	"%^BOLD%^%^RED%^These shoes are a bright red in color and"+
	" the toes are curled up at the ends. This is the sort of"+
	" thing sultans are wearing in tales, but they're far too"+
	" small for any human to wear.%^RESET%^"
	);
	set_lore("A pixie's sense of style is strange to say the least."+
		"  With bright colors and odd silhouettes, the pixie clothes"+
		" themselves in gaudy attire.  A favorite of all pixies is a "+
		"pair of curly toe shoes, which they wear for more formal "+
		"occasion.  The shoes are said to give a pixie the ability to"+
		" %^BOLD%^%^RED%^strut%^RESET%^ about in style.");
	set_property("lore",8);
	set_weight(2);
	set_size(1);
        set_property("enchantment",1);
	set_type("clothing");
	set_limbs(({"right foot","left foot"}));
	set_value(60);
}

void init()
{
	::init();
	add_action("strut","strut");
}

int strut(string str)
{
	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed() || ETO->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
	if(query_worn() && !str) {
		write("%^BOLD%^You strut about in your %^RED%^curly"+
		" toed shoes.");
		say("%^BOLD%^"+ETO->query_cap_name()+" struts about in"+
		" "+ETO->query_possessive()+" %^RED%^curly toed shoes.");
		return 1;
	}
}
