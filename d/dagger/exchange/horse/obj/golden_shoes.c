//golden horse_shoes LoKi 2011

#include <std.h>
#include "../horse.h"
inherit OBJ"horse_upgrade";

void create(){
    ::create();
    set_name("horse_upgrade");
    set_id(({"horse_upgrade","horse shoes", "shoes"}));
    set_short("%^YELLOW%^gold%^RESET%^%^ORANGE%^e%^YELLOW%^n "+
	"ho%^RESET%^%^ORANGE%^rse shoes%^RESET%^");
    set_long("%^RESET%^%^YELLOW%^Made of %^RESET%^%^ORANGE%^pure "+
	"gold%^RESET%^%^YELLOW%^, these horse shoes are stunning in "+
	"their craftsmanship but cannot possibly be for extended use "+
	"on a horse due to how soft they must be. The work is masterful "+
	"and you ponder just how much such shoes would be worth to an art "+
	"collector. The bottom of the shoes are covered in %^BLACK%^%^BOLD%^"+
	"intricate runes%^RESET%^%^YELLOW%^ that seem to %^WHITE%^glow "+
	"softly%^RESET%^%^YELLOW%^ in the light. The four shoes are "+
	"collected together with a %^RESET%^%^ORANGE%^soft thin "+
	"cable%^RESET%^%^YELLOW%^ and a %^RESET%^small mithral "+
	"chunk%^RESET%^%^YELLOW%^.%^RESET%^\n");
    set_weight(1);
    set_value(15000);
	value = 3;
	type = 1;
	set_property("lore difficulty",10);
	set_lore("%^RESET%^%^CYAN%^Whenever the rich and powerful find a new "+
	"hobby, the merchants of the world attempt to find a way to make more "+
	"gold with it, so of course as the proliferation of enchanted gear for "+
	"horses rose, the dwarves of Kinaro were not far behind. Although the "+
	"rules of the circuit do not allow such enchantments, they also do not "+
	"prohibit their use. It is feared by some of the original horse owners "+
	"that the items will become more nefarious, but for now they have to use "+
	"the gear for fear of falling behind those who do. The creation of Kinaro "+
	"include golden shoes enchanted with a small measure of grumbar's power. "+
	"While a faith not known for speed, they are known for being an unstoppable "+
	"force and it can be seen in the change these shoes "+
	"create.\n %^BOLD%^%^MAGENTA%^William Hickstead 'A History of the Circuit'%^RESET%^\n");
}