#include <std.h>
#include "../valley.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("pixie hat");
	set_id(({"odd hat","hat","pixie hat","pink hat","strange hat"}));
	set_obvious_short("%^BOLD%^%^MAGENTA%^An odd hat%^RESET%^");
	set_short("%^BOLD%^%^MAGENTA%^P%^YELLOW%^i%^MAGENTA%^x%^YELLOW%^i%^MAGENTA%^e Hat%^RESET%^");
	set_long(
	"%^BOLD%^%^MAGENTA%^This strange little hat is a bright pink"+
	" in color. Somehow this shade of pink wouldn't match"+
	" anything at all, even itself. The hat is round in shape"+
	" with a flat top and a little %^YELLOW%^gold%^MAGENTA%^"+
	" tassel that falls to the side.%^RESET%^"
	);
	set_lore("A pixie dreams of the day when they receive their"+
		" very own hat.  This hat is given to a pixie that "+
		"successful pulls thirty pixie pranks on a mortal.  "+
		"Known as the mischievous fey, the pixie delights in "+
		"pulling pranks and jokes on mortals, humans being their"+
		" favorite.  The day that a pixie earns the right to wear"+
		" the pink and gold hat is a day of great joy for all "+
		"pixies.");
	set_property("lore",8);
	set_weight(3);
	set_size(1);
	set_type("clothing");
	set_limbs(({"head"}));
	set_value(30);
}

void init()
{
	::init();
	add_action("nod","nod");
}

int nod(string str)
{
	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed() || ETO->query_tripped()) {
		ETO->send_paralyzed_message("info",ETO);
		return 1;
	}
	if(query_worn() && !str) {
		write("%^BOLD%^As you nod the %^YELLOW%^tassle%^WHITE%^"+
		" on your %^MAGENTA%^hat%^WHITE%^ falls forward comically.");
		say("%^BOLD%^"+ETO->query_cap_name()+" nods and the"+
		" %^YELLOW%^tassle%^WHITE%^ on "+ETO->query_possessive()+""+
		" %^MAGENTA%^hat%^WHITE%^ falls forward comically.");
		return 1;
	}
}
