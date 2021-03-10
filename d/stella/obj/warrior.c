
#include <std.h>
#include <daemons.h>
#include "/d/stella/short.h"

inherit OBJECT;

void init(){
	::init();
	}
	
void create(){
	::create();
	
	set_name("A Statue");
	set_id(({"statue","warrior statue","warrior"}));
        set_short("A Warrior Statue");
        set_long("You behold the statue of a great warrior carrying a shield and sword.  "
		 "It is 10 feet tall and is carved in astounding detail. ");
	set_weight(100000);
	set_value(100000);
	}

