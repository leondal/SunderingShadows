//ranger_cyric.c - reward for Riddle Quest. Circe 7/12/05
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
	set_name("hide");
	set_id(({"hide","glamered hide","illusory hide"}));
	set_short("%^BOLD%^%^BLACK%^I%^RESET%^l%^BOLD%^l%^RESET%^u"+
         "%^BOLD%^%^BLACK%^s%^RESET%^o%^BOLD%^r%^RESET%^y %^BOLD%^"+
         "%^BLACK%^Hide%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^v%^RESET%^a%^BOLD%^r"+
         "%^RESET%^i%^BOLD%^%^BLACK%^e%^RESET%^g%^BOLD%^a%^RESET%^t"+
         "%^BOLD%^%^BLACK%^e%^RESET%^d %^BOLD%^%^BLACK%^gray hide%^RESET%^");
	set_long(
@CIRCE
%^BOLD%^%^BLACK%^This armor is made of thin hide originally a deep black color.  The hide has been carefully worked with lighter patches and strips, giving it a shifting appearance.  Somehow, it seems quite difficult to focus on the armor for long.  The hide is quite thin, allowing it to be worn under clothes if desired.%^RESET%^
CIRCE
	);
	set_lore(
@CIRCE
The Illusory Hide was created by an unknown ranger of Cyric who spent much of his time skulking in the woods.  While not many understand how a ranger could follow Cyric, a few do find this path to be of their liking.  They often cause strife throughout the woodlands by murdering those humanoids who traverse there and can occasionally be found creating problems just to create them.  Still, Cyric's fold does not hold many rangers, for the ideals of a ranger often are at odds with the teachings of Cyric.
CIRCE
	);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^BLACK%^The variegated armor seems to grow still as you remove it, making it easier to look at.%^RESET%^");
	return 1;
}
