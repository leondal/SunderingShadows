//thief_auppenser.c - reward for Riddle Quest. Cythera 8/05
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("kiira of the mind's eyes");
	set_id(({"eye","mind's eye","bronze kiira","kiira of the mind's eye","kiira"}));
	set_short("%^RESET%^%^ORANGE%^Kiira of the %^CYAN%^M%^BOLD%^"+
		"%^BLACK%^i%^RESET%^%^CYAN%^n%^BOLD%^%^BLACK%^d%^RESET%^"+
		"%^CYAN%^'%^BOLD%^%^BLACK%^s Eye%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A gem encrusted bronze kiira%^RESET%^");
	set_long(
@CYTHERA
%^ORANGE%^Shaped out of bronze, this kiira has been made to look like an eye.  A round %^BOLD%^%^BLACK%^onyx%^RESET%^%^ORANGE%^ is inlaid into the eye shaped bronze sections, creating the pupil of the eye.  Around the onyx slivers of %^BOLD%^%^BLUE%^lapis lazuil%^RESET%^%^ORANGE%^, %^BOLD%^%^CYAN%^aquamarine%^RESET%^%^ORANGE%^, %^BOLD%^%^CYAN%^blue topaz%^RESET%^%^ORANGE%^, and %^CYAN%^cyan jasper%^RESET%^%^ORANGE%^ create a detail iris.  %^BOLD%^%^WHITE%^Mother of pearl %^RESET%^%^ORANGE%^is set around the iris of the eye to make the serene blue shades stand out.  The reverse side of the bronze gem encrusted eye is flat and smooth, allowing it to easily be fixed to the owner's forehead.
CYTHERA
	);
	set_lore(
@CYTHERA
A kiira was once seen a gem of enlightnment when Auppenser's faith once thrived in the lands.  Usually shaped from a smooth stone, the kiira mystically attached to the wearer's forehead.  It was said that a kiira allowed one to open up their mind's eye and see the world with clarity and enlightenment.  As Auppenser's faith dwindled off, the use of kiira's fell out of use.  Now with a revitalized faith, many are reclaiming the traditions of yesterday and wearing a kiira once more.
CYTHERA
	);
	set_remove((:TO,"remove_func":));
	set_wear((:TO,"wear_func":));
}
int wear_fun(){
	tell_object(ETO,"%^CYAN%^You place the kiira on your forehead and"+
		" feel a sense of enlightenment fall over you.");
     	return 1;
}
int remove_func(){
	tell_object(ETO,"%^CYAN%^You pry the kiira off your forehead, "+
		"feeling the enlightenment vanish from your mind.");
	return 1;
}
