//mage_sune.c - reward for Riddle Quest. Cythera 8/05
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("silkwhisper's coat");
	set_id(({ "robe", "coat","silkwhisper's coat","silk coat","crimson coat" }));
	set_obvious_short("%^RESET%^%^RED%^A deep crimson silk coat%^RESET%^");
	set_short("%^RESET%^%^RED%^S%^BOLD%^%^WHITE%^i%^RESET%^%^RED%^lkwh"+
		"%^BOLD%^%^WHITE%^i%^RESET%^%^RED%^sp%^BOLD%^%^WHITE%^e%^RESET%^"+
		"%^RED%^r's Coat%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^Crafted from soft but heavy silk, this"+
		" long full overcoat has been dyed a %^RESET%^%^RED%^deep "+
		"crimson%^BOLD%^%^WHITE%^ shade.  The coat is made to fit "+
		"close to the wearer's body, to show off their best features."+
		"  Lined with bright white silk, the soft coat proves to be "+
		"as comfortable as well as aesthetically pleasing. Inside the"+
		" coat a pair of pockets are tucked away in the lining, allowing"+
		" for someone to store some precious treasure close to them.  "+
		"Embroidered into the long coat and down each sleeve are tendrils"+
		" in a %^RESET%^%^RED%^v%^BOLD%^a%^MAGENTA%^r%^RESET%^%^RED%^i"+
		"%^BOLD%^e%^MAGENTA%^t%^RESET%^%^RED%^y%^BOLD%^%^WHITE%^ of "+
		"%^RESET%^%^RED%^r%^BOLD%^e%^RESET%^%^RED%^d%^BOLD%^%^WHITE%^ "+
		"hues.  Each tendril tapers off to a point that curls inwards.  "+
		"A pair of %^YELLOW%^gold%^BOLD%^%^WHITE%^ buttons encrusted with "+
		"%^RED%^rubies %^BOLD%^%^WHITE%^run up the front of the coat, allowing "+
		"it to be closed off when the wearer so chooses.%^RESET%^");
	set_lore("To become a Silkwhisper was once the greatest honor for "+
		"any mage devoted to Sune.  The Silkwhispers were largely made"+
		" up of enchanters who saw Sune at their patron goddess.  Within"+
		" the church of Lady Firehair, the Silkwhispers aiding in "+
		"protection of the temples from those that sought to destroy "+
		"or ruin the faith of Sune in the lands.  The Silkwhispers also"+
		" helped the faith of Sune become one of the richest during its "+
		"days, using their magical abilities to create magical items to "+
		"fill the coffers of the faith.  Upon being accepted into the "+
		"Silkwhispers, each mage was given a silk coat that was "+
		"embroidered with red tendrils.  Each tendril, it was said, "+
		"represented a lock of hair from Sune Firehair's divine head,"+
		" wrapping the mage in her loving embrace.");
	set_property("lore",12);
	set_remove("%^RED%^You slip out of the fine silk coat and feel"+
		" yourself missing the beauty of the sacred coat already.");
}
