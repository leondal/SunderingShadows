//mage_oghma.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("robe");
	set_id(({ "robe", "robe of the sage's secrets","white linen robes"}));
	set_short("%^BOLD%^%^WHITE%^Robe of the %^YELLOW%^Sage's "+
		"%^BOLD%^%^BLACK%^S%^WHITE%^ec"+
		"%^BOLD%^%^BLACK%^r%^WHITE%^et%^BOLD%^%^BLACK%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A white linen robe%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This sleeveless white linen robe is cut full, to give plenty of room to the wearer.  The knee-length robe is not like other typical robes, in that one slips it on over their head much like a tunic.  A wide mantle circles around the upper body of the robe and across the arms.  The mantle is trimmed with a %^BOLD%^%^BLACK%^black silk%^WHITE%^ band.   %^YELLOW%^Golden braid%^BOLD%^%^WHITE%^ has been used to create various runes and sigils in this %^BOLD%^%^BLACK%^black%^WHITE%^ band.  Typically this robe is worn over a shirt.%^RESET%^

AVATAR
	);
	set_lore(
@AVATAR
The Robe of the Sage's Secrets has been seen in use of the Binder's faith for many years now.  Oghma's faith attracts a wide variety of people into his arms.  The sages and loremasters, who typically are mages, have come to adopt this robe as their symbol.  It is the sages and those who keep track of the knowledge and the information of the past that are the central core of the faith, if you ask them.  They are the ones who bring the artifice and craftsmen and women together with the entertainers.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" pulls the white robe off over "+ETO->QP+" head.  "+capitalize(ETO->QS)+" quickly begins to search around, looking for something important.",ETO);
	tell_object(ETO,"%^YELLOW%^You slip out of the robe, pulling it over your head.  The %^WHITE%^knowledge%^YELLOW%^ you have gained today must not beforgotten.  Now where did you put that quill and paper at?");
	return 1;
}
