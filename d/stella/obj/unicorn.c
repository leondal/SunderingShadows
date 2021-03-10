
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
	set_id(({"statue","unicorn statue","unicorn"}));
        set_short("A Unicorn Statue");
        set_long("You see a beautiful statue of a unicorn.  "
		 "It is 10 feet tall and is carved in astounding detail. ");
	set_weight(100000);
	set_value(100000);
	}

