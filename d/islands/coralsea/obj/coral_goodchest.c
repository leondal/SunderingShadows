#include <std.h>
#include "../defs.h"
inherit OBJECT;

// Coral Sea Area - Created January 2009 by Ari

/* This is the chest that the players get when they 
defeat the Ship's Guardian.  The chest can be picked
or broken, but this spawns a broken chest.  If this
chest is returned to the quest giver, they will recieve
XP and a gold reward of 20k for their efforts which
is twice the chest's value.  The chest can also be sold
to a shop for 10k. */

void init(){
	::init();
		add_action("break_hasp","break");
		add_action("break_hasp","pick");
}

void create(){
    ::create();
		set_name("treasure chest");
        set_id(({"chest","treasure chest","gold chest","coralgoodchest"}));
        set_short("%^YELLOW%^a golden treasure chest%^RESET%^");
        set_obvious_short("%^YELLOW%^a golden treasure chest%^RESET%^");
        set_long("%^RESET%^%^ORANGE%^This small treasure chest is "+
			"only as wide as a man's forearm.  %^YELLOW%^Solid gold"+
			"%^RESET%^%^ORANGE%^, and veined with several shades of "+
			"alternating gold tones, even the fastenings have been "+
			"cast from a type of gold.  Alone, without its contents, "+
			"this is a very valuable piece of treasure.  Though there "+
			"are no adornments, the veins of %^RESET%^white%^ORANGE%^, "+
			"%^YELLOW%^yellow %^RESET%^%^ORANGE%^, %^BOLD%^%^MAGENTA%^"+
			"rose%^RESET%^%^ORANGE%^, and %^BLACK%^%^BOLD%^black "+
			"%^RESET%^%^ORANGE%^gold give the small box an ornate "+
			"appearance all of its own.  In the front, a large lock "+
			"hooks through the chest's clasp keeping its contents "+
			"locked away.  As small as the chest is, not much could "+
			"fit inside and you wonder what sorts of %^BOLD%^"+
			"%^MAGENTA%^t%^BLACK%^r%^YELLOW%^e%^WHITE%^a%^YELLOW%^s"+
			"%^BLACK%^u%^MAGENTA%^re %^RESET%^%^ORANGE%^might be "+
			"inside.  As soft as gold is, you imagine it would be "+
			"very easy to %^RESET%^break %^ORANGE%^the %^RESET%^hasp "+
			"%^ORANGE%^clear off and get to the contents.%^RESET%^");
        set_weight(20);
        set_value(4000);
}

int break_hasp(string str){
	object nrmchest, newchest;
	    if(str != "chest" && str != "lock" && str != "gold chest" 
			&& str != "treasure chest" && str != "hasp"){
			notify_fail("%^YELLOW%^What were you trying to break "+
				"into?%^RESET%^");
        return 1;
		}
		newchest = new(OBJ"coral_badchest"); 
		newchest->move(ETP); 
		tell_room(EETO,"%^YELLOW%^As "+TP->QCN+" fiddles with the "+
				"lock, the hasp suddenly breaks, causing the chest "+
				"to fall to the ground and spill open...");
			nrmchest = TO;
			nrmchest->move("/d/shadowgate/void"); 
			nrmchest->remove();
	return 1;
}