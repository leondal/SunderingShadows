#include <std.h>
#include "../tharis.h"
inherit "/std/comp_vend.c";

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Tharis Crystal Shop Remodle - Created in February 2009 by Ari

void create() {
	::create();
	set_name("ralsh");
	set_id(({"ralsh","small man","greasy man","man","proprietor"}));
	set_short("Ralsh, a small greasy man");
	set_long("%^RESET%^%^CYAN%^Ralsh is an unsanitary man, much "+
		"like his shop.  Greasy black hair tops his head and drips "+
		"rivulets of sweat and oil down his pasty face.  Wide, "+
		"bulging eyes, nearly pop from his thin, rat-like face "+
		"and never seem to blink.  A thin mustache grows over a "+
		"thin set of lips and seems to have the same issue as his "+
		"hair, as it gleams with oil and sweat.  His body is "+
		"dressed in grimy clothing that has probably never seen "+
		"a bar of soap, in fact you wonder if he's ever even "+
		"removed the scraps of cloth or if he just adds another "+
		"layer when the first becomes too tattered to remain "+
		"intact.  A cold, toothless grin anoints his face as soon "+
		"as anyone dares enter his shop and you can easily see "+
		"the hungry greed in his black eyes.%^RESET%^");
	
	set_level(19);
	set_gender("male");
	set_race("human");
	set_body_type("human");
	set_class("mage");
	set_alignment(6);
	set_mp(300);
	set_hd(25,2);
	set_exp(10);
	set_guild_level("psion",30);
    set_property("no bump", 1);
    set_shop_type("psion");
    set_components(100);
    set_spell_chance(100);
    set_spells(({"mind thrust","mind thrust","mind thrust","microcosm",
       "energy bolt","energy bolt","wall of ectoplasm",
	   "breath of the black dragon","breath of the black dragon",
	   "ultrablast","ultrablast"}));
}
