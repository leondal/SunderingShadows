//charm.c

#include <std.h>

inherit OBJECT;

int flag;

void start_charm();
void disable_me(int thing);

void create(){
	::create();
	set_name("blah");
	set_id(({"charmthingymadebyme"}));
	set_short("");
	set_long("");
	flag = 0;
	}

void init(){
	::init();
	
	add_action("stuff","");
}

int drop(){return 1;}

int stuff(){
	if(wizardp(TP)) return 0;
	if(flag) return 0;
	write("%^BOLD%^You are controlled by the satyr!");
	return 1;
}

void start_charm(){
	call_out("dest_me",400);
	}

void dest_me() { 
	tell_object(ETO,"%^BOLD%^Your mind clears as the power of the satyr receeds!");
	ETO->remove_property("charmed");
	remove();}

void save_me(string filename){return 1;}

void disable_me(int thing){flag = thing;}
