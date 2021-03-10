#include "./pvillage.h"

inherit OBJECT;

string skrap,login_file;
string playername,filename;
mapping keynames;

void set_keynames(string str);
void remove_keynames(string str);
void set_player(string str);
void restoreit();
void saveit();

void create(){
    ::create();
	set_name("contract");
	set_id(({"contract","housecontract"}));
	set_long("This is a contract between you and the Player Village."
		" This contract merely states that you own property in the"
		" Player Village. \n This contract allows you to set where"
		" you logon in your home. Type 'login here' to set it."  	
	);	
	set_short("A contract");
	keynames = (([]));
}

set_me_up() {
    restoreit();
    if(login_file != 0){
	this_player()->move(login_file);
	write("%^YELLOW%^You login in your house.\n");
	say(TPQCN+" Appears.");
    }
}
restore_me(){ return 1; }
save_me() { return 1; }

mixed *query_auto_load() { return ({ MAIN+"housecontract",({}) }); }
int init_args(mixed *arg) { set_me_up(); }

void init() {
    ::init();
	add_action("login","login");
	restoreit();
}

int login(string str) {
    if (str) {
	sscanf(file_name(environment(TP)),"/%*s/%*s/%*s/%s",skrap);
	if(strsrch(skrap, TPQN) != -1)
  	{
		login_file = file_name(environment(TP));
		write("You will now login here.\n");
		environment(TP)->saveit(HOMES+skrap);
		return 1;
	}
	else
	{
		write("You can`t set your login to this place.\n");
		return 1;
	}
    }
    write("You will now login at the Main Hall.\n");
    login_file = "";
    return 1;
} 

get() { return 1;}

drop() { return 1;}

void set_player(string str){
	playername = str;
	filename = CONTRACT+playername+"contract";	
}

void set_keynames(string str){
	keynames[str] = 1;
}
void remove_keynames(string str){
	map_delete(keynames,str);
}

mixed query_keynames(){
	return keynames;
}

void saveit(){
	if(!filename) return;
	save_object(filename,1);
}
void restoreit(){
	if(!filename) filename = CONTRACT+TPQN+"contract";
	restore_object(filename,1);
}


