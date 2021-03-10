//obsidian spurs LoKi 2011

#include <std.h>
#include "../horse.h"
inherit OBJ"horse_upgrade";

void create(){
    ::create();
    set_name("horse_upgrade");
    set_id(({"horse_upgrade","spurs", "horse spurs"}));
    set_short("%^BLACK%^%^BOLD%^obsidi%^RESET%^a%^BLACK%^%^BOLD%^n spurs%^RESET%^");
    set_long("%^BLACK%^%^BOLD%^Forged from %^RESET%^iron%^BLACK%^%^BOLD%^ "+
	"and tipped with finely cut %^RESET%^obsidian points%^BLACK%^%^BOLD%^, "+
	"these spurs are a work of art. They would attach to a rider's boots "+
	"and with proper application to the flanks of a horse would encourage "+
	"the horse to greater speeds. There are a %^RESET%^series of "+
	"runes%^BLACK%^%^BOLD%^ etched carefully along the iron but are "+
	"unreadable. They look like they would be quite useful on a horse "+
	"bred for speed, if you knew how to use them properly.%^RESET%^");
    set_weight(1);
    set_value(15000);
	value = 5;
	type = 2;
	set_property("lore difficulty",10);
	set_lore("%^RESET%^%^CYAN%^Although the government of Tharis was "+
	"woefully ignorant of the existence of the Tharis Underground course, "+
	"the church of Mask was not. Religious interference is not tolerated "+
	"but that did not stop the church from profiting greatly on betting on "+
	"the right horses, and providing gifts to the owners of the horses they "+
	"favored. It is rumored they picked one horse as their favorite and "+
	"bought it. A series of spurs were made by the priests of the temple "+
	"to equip as needed.\n %^BOLD%^%^MAGENTA%^William "+
	"Hickstead 'A History of the Circuit'%^RESET%^\n");
}