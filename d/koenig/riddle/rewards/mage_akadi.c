//mage_akadi.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("windblown vest");
	set_id(({ "vest", "windblown vest" }));
	set_short("%^RESET%^%^BOLD%^%^BLACK%^W%^WHITE%^i%^BLUE%^n%^BLACK%^d%^BLUE%^b%^WHITE%^l%^BLUE%^o%^BLACK%^w%^WHITE%^n %^BLUE%^Vest%^RESET%^");
	set_obvious_short("A sky blue silk vest");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^A silken vest cut into a fashionable style.  The torso section of the vest is made from thin sky blue silk and fitted close to the body.  A high collar rises up from the neckline, though not in a manner that would be too binding.  Electrum buttons in the shape of birds alternate from left to right, giving the vest a bit of added flare.  Along the side seams of the vest a pair of pockets have been sewn into the silk.  Strips of %^BOLD%^%^BLACK%^storm gray%^BLUE%^ and %^WHITE%^cloud white%^BLUE%^ silk have been twisted together to form a slight padded roll at each shoulder.  The ends of the silken fabrics remain untethered and free to blow in the winds.

AVATAR
	);
	set_lore(
@AVATAR
The Windblown Vest was fashioned and used by a transmuter of the Queen of the Winds, Delerdiela.  Delerdiela's vest was so loved by the faithful of Akadi that her fellow Akadians begged her to create more vests for them.  Delerdiela did indeed sew a few more vests, until she grew bored with the task and went off to find something else that found her intrest.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}

int remove_func(){
	tell_object(ETO,"%^BOLD%^%^BLUE%^You slip the vest off carefully, as not to damage the thin silk.");
	return 1;
}
