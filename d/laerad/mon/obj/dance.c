//Dance for Leprachaun by Bane//
//Taken from charm.c by Tristan//

#include <std.h>

inherit OBJECT;

int flag;

void start_dance();
void disable_me(int thing);

void create(){
    ::create();
    set_name("dancething");
    set_id(({"dancything"}));
    set_short("");
    set_long("");
    flag = 0;
    }

void init(){
    ::init();
	
    add_action("things","");
}

int drop(){return 1;}

int things(){
    if(wizardp(TP)) return 0;
    if(flag) return 0;
    write("%^BOLD%^You are busy dancing with the Leprachaun!");
    return 1;
}

void start_dance(){
    call_out("dest_me",150);
    }

void dest_me() { 
    tell_object(ETO,"%^BOLD%^You start to tire and you stop dancing.");
    ETO->remove_property("transfixed");
    remove();}

void save_me(string filename){return 1;}

void disable_me(int thing){flag = thing;}
