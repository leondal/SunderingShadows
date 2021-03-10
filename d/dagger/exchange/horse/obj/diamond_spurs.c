//diamond spurs LoKi 2011

#include <std.h>
#include "../horse.h"
inherit OBJ"horse_upgrade";

void create(){
    ::create();
    set_name("horse_upgrade");
    set_id(({"horse_upgrade","spurs", "horse spurs"}));
    set_short("%^RESET%^%^BOLD%^di%^CYAN%^a%^RESET%^%^BOLD%^"+
	"mond s%^CYAN%^p%^RESET%^%^BOLD%^urs%^RESET%^");
    set_long("%^RESET%^%^BOLD%^Forged from %^RESET%^"+
	"silver%^RESET%^%^BOLD%^ and tipped with finely cut "+
	"diam%^CYAN%^o%^RESET%^%^BOLD%^nd points, these "+
	"spurs are a work of art. They would attach to a "+
	"rider's boots and with proper application to the "+
	"flanks of a horse would encourage the horse to "+
	"greater speeds. There are a %^BLACK%^%^BOLD%^series "+
	"of runes%^RESET%^%^BOLD%^ etched carefully along "+
	"the %^RESET%^silver%^RESET%^%^BOLD%^ but are "+
	"unreadable. They look like they would be quite "+
	"useful on a horse bred for speed, if you knew how "+
	"to use them properly.%^RESET%^");
    set_weight(1);
    set_value(15000);
	value = 1;
	type = 2;
	set_property("lore difficulty",10);
	set_lore("%^RESET%^%^CYAN%^Speed is the name of the game. "+
	"Speed, and skill, and luck, and a thousand other things "+
	"well beyond the control of jockey or owner. Really though "+
	"the nobles who play enjoy the fact that they can't control "+
	"all of the race because it sets a level playing field for "+
	"all of the horses. They do however use all of the tools "+
	"available to them to get an edge. Fine spurs make a great "+
	"gift for jockeys to not only aid them in the race, but to "+
	"improve their loyalty. This becomes even more important as "+
	"more owners join the circuit.\n %^BOLD%^%^MAGENTA%^William "+
	"Hickstead 'A History of the Circuit'%^RESET%^\n");
}