#include "/d/attaya/seneca/short.h"
#include <daemons.h>

inherit OBJECT;

void init(){
	::init();
	add_action("read","read");
	}
	
void create(){
	::create();
	
	set_name("bookcase");
	set_id(({"bookcase","case"}));
       set_short("A solid oak bookcase");
        set_long("
    A tall oak bookcase filled with books.  You can 'read titles'
");
	set_weight(500);
	set_value(100);
	}
	
int read(string str){
	if(!str || str != "titles") return  0;
	
	tell_room(environment(TO),TPQCN+" reads the book titles!",TP);
    write("\n\%^ORANGE%^Stealthful Techniques.");
    write("\n\%^BOLD%^%^RED%^Picking Your Way To Freedom.");
    write("\n\%^GREEN%^Escape from Tharis With A Pocket Full Of Gold.");
    write("\n\%^BOLD%^%^BLUE%^Traps and How to Spring Them.");
    write("\n\%^YELLOW%^Know Your Prey.");
    write("\n\%^BOLD%^%^GREEN%^The 'Smell' Of An Easy Mark.");
    write("\n\%^BOLD%^Everyperson's Guide to Pleasing The Thief Within You.");
    write("\n\%^BOLD%^%^MAGENTA%^As The Dagger Beckons.");
    write("\n\%^BLUE%^Hail The Queen of Thieves: A Life in Profile.");
    write("\n\%^RED%^My Life as a Thief's Gigilo: Living Well With Little Effort.");
	return 1;
	}
	
