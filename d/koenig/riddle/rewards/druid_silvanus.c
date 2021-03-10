//druid_silvanus.c - reward for Riddle Quest. Circe 4/9/13
#include <std.h>
#include "../../nereid.h"
inherit WOODEN;

void create(){
	::create();
//	set_name("silvanus wooden armor");
	set_id(({"armor","wooden armor","bark armor","embrace of the oak father","embrace"}));
	set_short("%^RESET%^%^GREEN%^Emb%^YELLOW%^r%^RESET%^%^GREEN%^ac"
	   "%^BOLD%^e %^RESET%^%^GREEN%^of the %^BOLD%^%^GREEN%^O%^RESET%^"
	   "%^GREEN%^a%^BOLD%^k %^RESET%^%^GREEN%^F%^ORANGE%^a%^GREEN%^t"
	   "%^BOLD%^h%^RESET%^%^GREEN%^er%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^A suit of armor made from %^ORANGE%^ba%^GREEN%^r%^ORANGE%^k%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^Crafted from plates of o%^GREEN%^a"
	   "%^ORANGE%^k ba%^GREEN%^r%^ORANGE%^k reinforced through "
	   "enchantments, this suit of armor would make the wearer "
	   "virtually blend into an %^GREEN%^oa%^BOLD%^k %^RESET%^"
	   "%^GREEN%^fo%^YELLOW%^r%^RESET%^%^GREEN%^est%^ORANGE%^.  "
	   "The plates have been carefully chosen and molded to fit "
	   "perfectly, enabling the wearer to move with ease.  The "
	   "armor is sewn together with %^GREEN%^li%^YELLOW%^v%^RESET%^"
	   "%^GREEN%^ing vi%^BOLD%^n%^RESET%^%^GREEN%^es%^ORANGE%^ that "
	   "seem to shift and grow as you watch, making the armor a "
	   "truly wondrous item.%^RESET%^");
	set_lore("The Embrace of the Oak Father is prized by druids of Silvanus, who "
         "feel blessed by the embrace of nature itself.  Each bark plate is "
	   "carefully selected and gathered from a willing tree by a druid of "
	   "Silvanus.  Only a select few craftsmen know the secret to this "
	   "armor's creation, and they guard it with their lives.");
	set_property("lore difficulty",12);
	set_remove("%^BOLD%^You feel comfort in your faith as you remove the bark armor.");
}
