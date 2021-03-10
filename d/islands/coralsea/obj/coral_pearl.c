#include <std.h>
#include "../defs.h"

// Coral Sea Area - Created January 2009 by Ari

#define COLORS ({"%^BOLD%^%^RED%^red","%^BOLD%^%^BLACK%^black","%^BOLD%^%^MAGENTA%^pink","%^RESET%^white","%^BOLD%^%^CYAN%^blue"})
#define SIZES ({"small","medium","large","tiny"})

inherit OBJECT;

string COLOR,SIZE;

void create_pearls(object obj){
	COLOR = COLORS[random(sizeof(COLORS))];
	SIZE = SIZES[random(sizeof(SIZES))];
	
		obj->set_name("pearl");
		obj->set_short("%^RESET%^a "+SIZE+" "+COLOR+" "+
			"%^RESET%^pearl");
		obj->set_id(({"pearl"}));
		obj->set_value((random(80)+200));
		obj->set_weight(1);
		
		obj->set_long("%^RESET%^%^CYAN%^This lovely pearl "+
			"is a glossy "+COLOR+" %^RESET%^%^CYAN%^color.  "+
			"Smooth for the most part, it would likely "+
			"fetch a nice price at a jeweler somewhere.%^RESET%^");
}

void create(){
	::create();
		create_pearls(TO);
}
		