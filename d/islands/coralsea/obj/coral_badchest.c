#include <std.h>
inherit OBJECT;

// Coral Sea Area - Created January 2009 by Ari

/* This is the chest that spawns if the players attempt
to get into the chest and not return it "untampered with"
to our quest giver.  If they give it to the quest giver he
will grouch and return it to them as well as give them the
"failed deed".  The chest can be sold for some gold.  The
only reward they get for not listening and being greedy. 
Silly players! */

void create(){
    ::create();
		set_name("treasure chest");
        set_id(({"chest","treasure chest","gold chest","coralbadchest"}));
        set_short("%^YELLOW%^a broken treasure chest%^RESET%^");
        set_obvious_short("%^YELLOW%^a broken treasure chest%^RESET%^");
        set_long("%^RESET%^%^ORANGE%^This small treasure chest is "+
			"only as wide as a man's forearm.  %^YELLOW%^Solid gold"+
			"%^RESET%^%^ORANGE%^, and veined with several shades of "+
			"alternating gold tones, even the fastenings have been "+
			"cast from a type of gold.  Alone, without its contents, "+
			"this is a very valuable piece of treasure.  Though "+
			"there are no adornments, the veins of %^RESET%^white"+
			"%^ORANGE%^, %^YELLOW%^yellow %^RESET%^%^ORANGE%^, "+
			"%^BOLD%^%^MAGENTA%^rose%^RESET%^%^ORANGE%^, and "+
			"%^BLACK%^%^BOLD%^black %^RESET%^%^ORANGE%^gold give "+
			"the small box an ornate appearance all of its own. In "+
			"the front, the remains of the chest's hasp can be "+
			"seen.  Damaged, it looks like someone broke it clear "+
			"off.  If there was anything of valuable within, it has "+
			"long since vanished, leaving only a few scraps of "+
			"useless paper within.  Too bad, but maybe you could "+
			"get a few %^YELLOW%^coins%^RESET%^%^ORANGE%^ for "+
			"selling it.%^RESET%^");
        set_weight(20);
        set_value(1500);
}
