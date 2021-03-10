//silver horse_shoes LoKi 2011

#include <std.h>
#include "../horse.h"
inherit OBJ"horse_upgrade";

void create(){
    ::create();
    set_name("horse_upgrade");
    set_id(({"horse_upgrade","horse shoes", "shoes"}));
    set_short("%^RESET%^%^BOLD%^sil%^RESET%^v%^RESET%^%^BOLD%^er "+
	"h%^RESET%^o%^RESET%^%^BOLD%^rse s%^RESET%^h%^RESET%^%^BOLD%^oes%^RESET%^");
    set_long("%^RESET%^%^BOLD%^Forged of %^RESET%^silver%^RESET%^%^BOLD%^, "+
	"these horse shoes look to be a simple artistic item that would hang "+
	"over an inn door to ward off bad luck. They have a %^RESET%^%^CYAN%^"+
	"slight glimmer%^RESET%^%^BOLD%^ to them,  are quite well made and as "+
	"you look at them you sense a certain amount of power within them. "+
	"The sides of the shoes are covered with a %^BLACK%^%^BOLD%^thin line "+
	"of runes%^RESET%^%^BOLD%^ that are unreadable due to their tiny "+
	"characters. The four shoes are held together with a %^YELLOW%^golden "+
	"chain%^RESET%^%^BOLD%^ and a smaller %^RED%^ruby horseshoe "+
	"pendant%^RESET%^%^BOLD%^.%^RESET%^\n");
    set_weight(1);
    set_value(15000);
	value = 1;
	type = 1;
	set_property("lore difficulty",10);
	set_lore("%^RESET%^%^CYAN%^The addition of new courses after the "+
	"original Tharis Underground was added to, creating the circuit, "+
	"beckoned a new age for horse racing. A powerful family of paladins "+
	"in Antioch pushed the king to allow the creation of the course "+
	"there and purchased for him the best steed they could find. As a "+
	"token of the celebrations when the king acquiesced the family had "+
	"horseshoes created as gifts to several visiting nobles for the first "+
	"race. The shoes themselves have a small amount of magic in them that "+
	"would allow for their use on a racehorse and offer it more speed. "+
	"Little did the family know that by having these made and giving them "+
	"away, they would create the enchantment arms race that is plaguing "+
	"the circuit to this day.\n %^BOLD%^%^MAGENTA%^William Hickstead '"+
	"A History of the Circuit'%^RESET%^\n");
}