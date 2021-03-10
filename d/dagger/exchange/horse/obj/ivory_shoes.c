//ivory horse_shoes LoKi 2011

#include <std.h>
#include "../horse.h"
inherit OBJ"horse_upgrade";

void create(){
    ::create();
    set_name("horse_upgrade");
    set_id(({"horse_upgrade","horse shoes", "shoes"}));
    set_short("%^RESET%^%^BOLD%^ivor%^RESET%^y%^RESET%^%^BOLD%^ "+
	"hor%^RESET%^s%^RESET%^%^BOLD%^e s%^RESET%^h%^RESET%^%^BOLD%^oes%^RESET%^");
    set_long("%^RESET%^%^BOLD%^These horseshoes seem to be "+
	"more of a work of art then functional shoes for a "+
	"%^BLACK%^%^BOLD%^warhorse%^RESET%^%^BOLD%^. They are formed "+
	"completely out of %^RESET%^ivory%^RESET%^%^BOLD%^ and along every "+
	"surface %^RESET%^%^ORANGE%^small runes%^RESET%^%^BOLD%^ have been "+
	"carved. The four shoes are collected together on a %^RESET%^fine "+
	"silver chain%^RESET%^%^BOLD%^ with an %^GREEN%^oakleaf "+
	"pendant%^RESET%^%^BOLD%^. They look to be very valuable, perhaps "+
	"to a collector, though you can also sense a certain amount of magic "+
	"in them making them perhaps more useful then they look.\n%^RESET%^");
    set_weight(1);
    set_value(25000);
	value = 5;
	type = 1;
	set_property("lore difficulty",10);
	set_lore("%^RESET%^%^CYAN%^Every edge they say, every edge you can get "+
	"in a tight race is one you use. I've seen jockeys encourage the "+
	"gelatinous cubes to attack the other horses they are racing against "+
	"and Ive watched owners make some pretty shady deals. Equipping your "+
	"horse with magical equipment was only a matter of time really. Horse "+
	"shoes are a requirement of course, but when I first saw the ivories "+
	"that Shining Star had I knew they were special. My sources say they "+
	"were blessed by Mielikki's priests to give the horse the gift of "+
	"speed.\n %^BOLD%^%^MAGENTA%^William Hickstead 'A History of the Circuit'%^RESET%^\n");
}
