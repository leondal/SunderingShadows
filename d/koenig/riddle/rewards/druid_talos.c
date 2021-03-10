//druid_talos.c - reward for Riddle Quest. Circe 1/1/16
#include <std.h>
#include "../../nereid.h"
inherit WOODEN;

void create(){
	::create();
	set_id(({"armor","wooden armor","wood armor","armor of the raging storm","blackened armor"}));
	set_short("%^BOLD%^%^BLACK%^Armor of the R%^BOLD%^%^WHITE%^a%^YELLOW%^g"
         "%^RESET%^i%^BOLD%^%^BLACK%^n%^WHITE%^g %^BLACK%^S%^RESET%^t%^BOLD%^o"
         "%^YELLOW%^r%^BLACK%^m%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A suit of blackened armor%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^Beginning with a dark wood base, the crafter "
         "who made this armor has applied %^RESET%^%^RED%^f%^BOLD%^i%^YELLOW%^r"
         "%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^ to blacken it further. Rather than "
         "smelling like %^RESET%^smoke%^BOLD%^%^BLACK%^, the fragrance of "
         "%^RESET%^%^CYAN%^ozone %^BOLD%^%^BLACK%^wafts from the wood, bringing "
         "to mind the %^RESET%^stormy sky %^BOLD%^%^BLACK%^after a %^YELLOW%^"
         "lightning strike%^BLACK%^. Between the overlapping wooden plates, flashes "
         "of %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^l%^RESET%^%^ORANGE%^d %^BOLD%^"
         "%^BLACK%^and %^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r "
         "%^BLACK%^are revealed as the wearer moves. The armor bears no other ornamentation, "
         "helping it to blend into the natural world.%^RESET%^");
	set_lore("There is a rumor within the church of the Storm Lord that clerics of "
         "the faith take each set of armor into the storm and wait for a lightning "
         "strike to bless it. While the truth of the rumor is in question, the hint "
         "of ozone lends credence to the idea.");
   set_property("lore difficulty",12);
	set_remove("%^BOLD%^You feel comfort in your faith as you remove the wooden armor.");
}
