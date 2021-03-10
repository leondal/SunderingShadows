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
	
	set_name("sign");
	set_id(({"warning sign","sign"}));
        set_short("%^BOLD%^%^RED%^A haphazardly struck wooden sign%^RESET%^");
        set_long("
It is a fairly large painted wooden sign. It sits lopsided along the path. There seems to be a warning painted on it.
");
	set_weight(100000);
	set_value(10000);
	}
	
int read(string str){
	if(!str || str != "sign") return  0;
	
	tell_room(environment(TO),TPQCN+" reads the warning!",TP);
write("%^RED%^%^BOLD%^This area is full peril. As you go in a southerly direction you are getting closer to the Crafter Empire. BEWARE! They will steal your soul and either kill you or make you one of their own. Level suggestion 30+. Parties containing elves are highly recommended.\n");
	return 1;
	}
	
