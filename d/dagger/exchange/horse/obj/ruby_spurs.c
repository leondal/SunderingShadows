//ruby spurs LoKi 2011

#include <std.h>
#include "../horse.h"
inherit OBJ"horse_upgrade";

void create(){
    ::create();
    set_name("horse_upgrade");
    set_id(({"horse_upgrade","spurs", "horse spurs"}));
    set_short("%^RED%^%^BOLD%^ru%^RESET%^%^RED%^b%^BOLD%^y "+
	"sp%^RESET%^%^RED%^u%^BOLD%^rs%^RESET%^");
    set_long("%^RESET%^%^RED%^Forged from %^YELLOW%^gold %^RESET%^%^RED%^and tipped "+
	"with finely cut %^RESET%^%^RED%^ruby points%^RESET%^%^RED%^, these spurs are "+
	"a work of art. They would attach to a rider's boots and with proper application "+
	"to the flanks of a horse would encourage the horse to greater speeds. There "+
	"are a %^BLACK%^%^BOLD%^series of runes%^RESET%^%^RED%^ etched carefully "+
	"along the %^YELLOW%^gold%^RESET%^%^RED%^ but are unreadable. They look "+
	"like they would be quite useful on a horse bred for speed, if you knew "+
	"how to use them properly.%^RESET%^");
    set_weight(1);
    set_value(15000);
	value = 3;
	type = 2;
	set_property("lore difficulty",10);
	set_lore("%^RESET%^%^CYAN%^There were originally three owners of the Tharis "+
	"Underground which was the first course. However after the expansion past "+
	"that and the Antioch course two of the owners had their information stripped "+
	"from the records and were last reported leaving for Laerad. Shortly after "+
	"that, the Asgard course opened and a flood of new horses joined the circuit. "+
	"Several of these new owners had with them ruby tipped spurs that were supposedly "+
	"gifts from unknown benefactors. These gifts were seen as tacit approval of "+
	"enchantments on the horses and the debate on their use simmered.\n %^BOLD%^%^MAGENTA%^"+
	"William Hickstead 'A History of the Circuit'%^RESET%^\n");
}