//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Sandling's stomach");
    set_short("Sandling's stomach");
    set_long(
    	"You are within the Sandling's stomach."
    );
    set_property("indoors",1);
    set_property("light",0);
    set_smell("default","Sand is filling your lungs!");
    set_listen("default","Shifting sand rattles in your ears.");
}
void init(){
    ::init();
    add_action("quit","quit");
    call_out("suffocate",15,TP);
}
void suffocate(object targ){
    int name;
    name=targ->query_name();
    if(present(name)){
	tell_object(targ,"%^BOLD%^RED%^You are suffocating!");
	targ->do_damage("torso",roll_dice(1,8));
	targ->add_attacker(TO);
	targ->continue_attack();
	call_out("suffocate",15,targ);
	set_property("full",1);
    }
    if(!present(name)){
	remove_property("full");
    }
}
void quit(){
    tell_object(TP,"You cant do that in here!");
    return 1;
}
