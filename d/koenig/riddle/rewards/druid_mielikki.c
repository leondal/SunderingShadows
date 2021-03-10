//druid_mielikki.c - reward for Riddle Quest. Circe 3/25/13
#include <std.h>
#include "../../nereid.h"
inherit WOODEN;

void create(){
	::create();
//	set_name("mielikki wooden armor");
	set_id(({"armor","wooden armor","vine armor","living armor","suit of vine armor","a suit of armor made from living vines"}));
	set_short("%^RESET%^%^GREEN%^L%^BOLD%^i%^RESET%^%^GREEN%^vi"
         "%^ORANGE%^n%^GREEN%^g A%^ORANGE%^r%^GREEN%^mo%^BOLD%^r%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^A suit of armor made from living vines%^RESET%^");
	set_long("%^RESET%^%^GREEN%^This armor is not so much crafted "
         "as grown.  It is composed of %^BOLD%^t%^RESET%^%^GREEN%^"
         "rai%^ORANGE%^l%^GREEN%^ing i%^BOLD%^v%^RESET%^%^GREEN%^y "
         "trained and enchanted to wrap around the wearer's body.  "
         "The thick %^BOLD%^vines %^RESET%^%^GREEN%^are covered with "
         "slender leaves in %^RESET%^s%^BOLD%^i%^RESET%^lv%^BOLD%^e"
         "%^RESET%^r%^GREEN%^, %^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^"
         "ld%^GREEN%^, and gr%^BOLD%^e%^RESET%^%^GREEN%^en that seem to "
         "shift with the light, fading into %^BOLD%^%^BLACK%^sh%^RESET%^"
         "a%^BOLD%^%^BLACK%^dows %^RESET%^%^GREEN%^when need demands.  "
         "The armor is resilient, both with blocking blows and with "
         "sprouting new growth when any part is damaged, making it as "
         "functional as it is fantastic.%^RESET%^");
	set_lore("This Living Armor is prized by druids of Mielikki, who "
         "feel blessed by the embrace of nature itself.  The method of "
         "enchanting the living vines is a closely guarded secret, though "
         "many have attempted to learn it for their own personal gain.  The "
         "enchantment on the ivy ensures that it will never die.");
	set_property("lore difficulty",12);
	set_remove("%^BOLD%^You feel comfort in your faith as you remove the living armor.");
}
