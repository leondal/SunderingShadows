//fighter_tyr.c - reward for Riddle Quest. Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
//	set_name("tyr hide");
	set_id(({"hide","bane","chaos bane","studded","armor","studded leather"}));
	set_short("%^BOLD%^%^RED%^C%^YELLOW%^h%^CYAN%^a%^BLUE%^o%^GREEN%^s %^RED%^Bane%^RESET%^");
	set_obvious_short("Studded leather armor");
	set_long(
@CIRCE
This suit of armor is made in the typical fashion, although it is clearly of very high quality.  The thick leather is padded and reinforced with steel rivets.  The shirt falls past the waist in a protective skirt for the wearer's hips, while the breeches protect all the way to the ankles.  Burned into each shoulder is a symbol - a set of %^YELLOW%^scales %^RESET%^ balanced upon an upright %^RED%^warhammer%^RESET%^.  The symbol has been detailed in %^YELLOW%^gold %^RESET%^and %^BOLD%^silver%^RESET%^, the only adornment on this otherwise plain armor.  Oddly, the armor has two gloves, although they do not match.  The left glove is a pristine %^BOLD%^white%^RESET%^, while the right is a deep %^BOLD%^%^BLACK%^black%^RESET%^.
CIRCE
	);
	set_lore(
@CIRCE
The unusual name from this armor alludes to the legend of the Chaos Hound, which chased Tyr as he worked to prove his strength of spirit and resilience.  The Chaos Hound is said to have bitten off the god's right hand, leaving him with a stump he never covers.  Many proud warriors in the service of the Just God wear a black glove on their right hands to honor Tyr.  This particular armor is often gifted to warriors who have proven their worth in Tyr's service. 
CIRCE
	);
   set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^RED%^Your right hand tingles briefly as you remove the armor.");
	return 1;
}
