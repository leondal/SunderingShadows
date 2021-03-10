// Coral Sea Area - Created January 2009 by Ari

/* This is totally swiped from something that
Circe created for me as an Avatar.  I did the
design lay out stuff and she did the code.  I 
liked the way this looked/worked, so swiped the
code from her and have redone the decoration 
stuff to be more in theme with stuff pulled up
from underwater.  Thanks Circe! - Ari*/

#include <std.h>

/* Following is define stuff that goes into the 
set_long() later on. */

#define TYPES ({"clay dish","clay cup","bronze plate","silver chalice","glass bottle","ivory map case","hand mirror"})

#define LUSTERS ({"%^BOLD%^%^WHITE%^silver","%^BOLD%^%^GREEN%^jade","%^YELLOW%^gold","%^BOLD%^%^CYAN%^sapphire","%^RESET%^%^ORANGE%^amber","%^BOLD%^%^RED%^ruby","%^RESET%^o%^CYAN%^p%^RESET%^al%^MAGENTA%^e%^RESET%^sce%^CYAN%^n%^RESET%^t","%^BOLD%^%^WHITE%^i%^CYAN%^r%^WHITE%^id%^MAGENTA%^e%^CYAN%^s%^WHITE%^cent",})

#define SIDES ({"%^RESET%^%^ORANGE%^polished","%^BOLD%^%^BLACK%^etched","%^RED%^painted","%^YELLOW%^filigreed","%^BOLD%^%^MAGENTA%^b%^RED%^e%^RESET%^%^ORANGE%^j%^YELLOW%^e%^RESET%^%^GREEN%^w%^CYAN%^e%^BOLD%^%^BLUE%^l%^RESET%^%^BLUE%^e%^MAGENTA%^d"})

/* That's the defines, now for the code to make it work. */
inherit OBJECT;

string MYTYPE,LUSTER,SIDE;

void create_valuables(object obj){

	MYTYPE = TYPES[random(sizeof(TYPES))];
	LUSTER = LUSTERS[random(sizeof(LUSTERS))];
	SIDE = SIDES[random(sizeof(SIDES))];

		obj->set_name("a piece of sea scrap");
		obj->set_short("a sea tarnished "+MYTYPE+"%^RESET%^");
		obj->set_id(({"object","item","treasure","scrap",
			"artifact","rubbish","sea scrap",""+MYTYPE+""}));
		obj->set_value((roll_dice(2,5)*20)+200);
		obj->set_weight(roll_dice(2,4)+3);

		obj->set_long("%^RESET%^%^CYAN%^This piece of shipwrecked "+
			"treasure appears to have been under the %^BLUE%^"+
			"%^BOLD%^Saakrune Sea %^RESET%^%^CYAN%^for a lengthy "+
			"amount of time.  Its once "+SIDE+" %^RESET%^%^CYAN%^"+
			"sides have %^BOLD%^%^BLACK%^tarnished %^RESET%^"+
			"%^CYAN%^and in some cases %^ORANGE%^rusted%^CYAN%^, "+
			"leaving little of the "+LUSTER+" %^RESET%^%^CYAN%^"+
			"luster behind.  A few %^BOLD%^%^BLACK%^barnacles "+
			"%^RESET%^%^CYAN%^have even made their homes upon "+
			"this "+MYTYPE+", but you imagine you could gain a "+
			"few %^ORANGE%^coins %^CYAN%^for polishing it up and "+
			"selling it to some gullible collector.%^RESET%^");
}

void create(){
	::create();
		create_valuables(TO);
}