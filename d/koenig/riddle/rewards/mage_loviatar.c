//mage_loviatar.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("black leather robe");
	set_id(({ "robe", "black leather robe" }));
	set_short("%^BOLD%^%^BLACK%^Black Leather Robe%^RESET%^");
	set_obvious_short("A black leather robe");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^These robes are.... intersting, one could say.  The body of the robes is actually a leather harness-type garment.  A series of buckles and straps allows one to bind the leather harness around one's waist.  A strap comes over each shoulder to fasten to the harness.  The harness is set low, beginning right at one's waist.  If you were a male you might be able to go bare-chested without many problems, but few females will bear themselves so...openly in public. (At least decent ones!)  Attached to the lower portion of the harness is a more traditional looking robe.  The lower section is made of leather as well and falls below one's ankles.  The leather has been cut to be full and flare out.  Slits and tears in the leather reveal a brilliant %^RED%^crimson satin%^BLACK%^ underneath the robes, giving a flash in intense %^RED%^red%^BLACK%^ as one walks.

AVATAR
	);
	set_lore(
@AVATAR
These Black Leather Robes are often used by enchantresses of Loviatar to seduce helpless men into their manipulative games, though there are a few stories about about handsome males wearing similar robes who have made a noble lady or three betray their husbands.  The robes are by no means for the ample of figure or those who have any shread of modesty!

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" sighs heavily",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You already long for the bliss filled anguish the robes provided!");
	return 1;
}
