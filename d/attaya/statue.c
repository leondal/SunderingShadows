//tstatue.c

#include <std.h>
#include <daemons.h>

inherit OBJECT;

void init(){
	::init();
	add_action("read","read");
	}
	
void create(){
	::create();
	
	set_name("Statue");
	set_id(({"statue","monument"}));
        set_short("%^BOLD%^%^BLUE%^The statue of an ancient warrior");
        set_long("
    It is a weathered statue nearly thirty feet tall.  It is a giant, proud warrior that is pointing west.
    A bronze plaque is set in the statues' base.
");
	set_weight(100000);
	set_value(10000);
	}
	
int read(string str){
	if(!str || str != "plaque") return  0;
	
	tell_room(environment(TO),TPQCN+" reads over the plaque!",TP);
	write("\n\n\t\%^BOLD%^%^YELLOW%^That which the world had never seen before...            The Kinnesaruda became the rulers of this world, with mighty armies and powerful magic.");
	write("%^BOLD%^%^BLUE%^\n\t\After a thousand years of slumber, when the world has all but forgotten the legasy of the Kinnesaruda, And the world is again at rest, the Island of Attaya shall open up, and the very earth itself shall cast out the crystalline tower of the Black Dawn");
        write("%^RESET%^%^BLUE%^\t\It shall once again be the center of the world, and the influence of all combatants...  This time, it will be eternal...\n"
              "%^BOLD%^%^RED%^TO LIFE IMMORTAL...  \n");
	return 1;
	}
	
