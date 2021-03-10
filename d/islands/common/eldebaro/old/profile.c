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
	
	set_name("profile");
	set_id(({"profile","area profile"}));
       set_short("%^BOLD%^%^MAGENTA%^Area profile");
        set_long("
    %^BOLD%^%^MAGENTA%^This is a general profile of this island.  It will tell you important information about it.
");
	set_weight(100000);
	set_value(10000);
	}
	
int read(string str){
	if(!str || str != "profile") return  0;
	
	tell_room(environment(TO),TPQCN+" reads the area profile!",TP);
    write("%^CYAN%^Area Name: %^RESET%^%^BOLD%^Eldebaro.\n");
    write("%^CYAN%^Area Type: %^RESET%^island.\n");
    write("%^CYAN%^Climate: %^RESET%^desert.\n");
    write("%^CYAN%^Location: %^RED%^<07'51>.\n\n");
    write("%^CYAN%^Difficulty Ranking: %^RESET%^moderate.\n");
    write("%^CYAN%^Monster Frequency: %^RESET%^random/low.\n");
    write("%^CYAN%^Suggested Level to Adventure Here: %^GREEN%^22+.\n\n");
    write("%^CYAN%^Sphere of Influence: %^BOLD%^%^BLUE%^Kinnesaruda Empire.\n");
	return 1;
	}
	
