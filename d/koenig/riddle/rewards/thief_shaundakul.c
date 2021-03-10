//thief_beshaba.c - reward for Riddle Quest. Cythera 8/05
#include <std.h>
#include "../../nereid.h"
inherit NBOOTS;

void create(){
	::create();
	set_name("boots");
	set_id(({"boots","windwalker boots","blue-gray leather boots","leather boots"}));
	set_short("%^RESET%^%^CYAN%^W%^MAGENTA%^i%^CYAN%^ndw%^BOLD%^%^BLACK%^a"+
		"%^RESET%^%^CYAN%^lk%^MAGENTA%^e%^CYAN%^r Boots%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^A pair of blue-gray leather boots%^RESET%^");
	set_long(
@CYTHERA
Sturdy and tough leather has been used to create this pair of traveler's boots.  While the leather is tough it still retains a supple flexibility, allowing them to adjust to a variety of climates and environments.  The leather has been dyed a soft neutral shade of %^CYAN%^blue-gray%^RESET%^.  The thick leather soles of the boots provide plenty of protection while still retaining their comfort.  Embroidered into the leather are rippling lines of %^BOLD%^%^BLACK%^deep black%^RESET%^ and %^MAGENTA%^dark violet%^RESET%^, symbolizing gusts of wind.%^RESET%^
CYTHERA
	);
	set_lore(
@CYTHERA
One of the greatest dreams and joys for any follower of Shaundakul is the blessing of being able to walk on the winds, traveling above the lands.  This experience is seen as a great honor and a special gift.  There were tales at one time of a band of rogues dedicated to Shaundakul who each received a pair of boots that allowed them to walk on the winds.  The boots allowed the rogues to explore new heights and discover new adventures that few had ever dreamed of.  Though as others found pairs of these ancient boots, they found that the legendary ability to walk on the winds seemed lost. 
CYTHERA
	);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^BLACK%^You find yourself already"+
		" missing the comfort of the boots.");
	return 1;
}
