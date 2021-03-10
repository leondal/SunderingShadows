#include <std.h>
#include "../keep.h"
inherit KEEP;
void create() {
	::create();
	set_short("%^YELLOW%^Drawbridge to Keep Blacktongue%^RESET%^");
	set_long("You stand in front of the %^RED%^drawbridge%^RESET%^ to Keep Blacktongue.  The "+
		"%^BOLD%^%^WHITE%^walls%^RESET%^ of the keep are made of %^BOLD%^%^BLACK%^black brick%^RESET%^"+
		", they rise some twenty feet into the air and are well fortified.  There seems to be a lot "+
		"of movement coming from within the Keep.  In the middle of the Keep rises a %^YELLOW%^huge "+
		"tower%^RESET%^ with small %^BOLD%^%^WHITE%^buildings%^RESET%^ surrounding it.");
	set_exits(([
		"north" : KEEPR + "keep1",
		"south" : "/d/deku/forest/dforest8-9"
		] ));
	set_items(([
		({"brick walls","black brick walls", "walls"}) : "%^BOLD%^%^WHITE%^These walls are some twenty feet high and made from a "+
		"%^BOLD%^%^BLACK%^black brick%^BOLD%^%^WHITE%^, they are well fortified.%^RESET%^",
		({"black brick","brick","black bricks","bricks"}) : "%^BOLD%^%^BLACK%^These black bricks "+
		"construct the twenty feet high wall that surrounds the keep.  They are dull and seem "+
		"remarkably lifeless.%^RESET%^",
		"drawbridge" : "%^RED%^The drawbridge spans some thirty feet across.%^RESET%^",
		({"tower","huge tower"}) : "%^YELLOW%^This tower rises high above the walls of the keep, "+
		"it stands in the center of the keep, as an ominous omen overlooking its surroundings."+
		"%^RESET%^",
		({"small buildings","buildings"}) : "%^BOLD%^%^WHITE%^The buildings dot the landscape of "+
		"the keep, there must be at least ten of them.  Some of them rise higher than others, some "+
		"even as high as the walls.%^RESET%^",
		] ));
}
