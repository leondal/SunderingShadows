#include "pvillage.h"

inherit ROOM;

void master_key(string str);

void create()
{
    ::create();
	set_property("light",1);
	set_property("indoors",1);
	set_short( "The locksmith shop");
	set_long("%^GREEN%^A small shop.\n%^RESET%^"
		"There seems to be stuff everywhere.\n"
		"There is an old man standing here looking at you.\n"
		"You notice a small sign on the left wall.\n"
	);
	set_items(([ "shop":"It looks very messy",
		"stuff":"It seems to be only junk",
		"junk":"Junk is junk",
		"walls":"They are dirty",
		"wall":"There is a sign on it"
	]));
	set_exits((["west":VILLAGE+"nroad1.c"]));
}

init()
{
	::init();
	add_action("read_sign","read");
	add_action("make_key","make");
}
int read_sign(string str){
	if(!str) return notify_fail("Read what?\n");
	say(TPQCN+" reads the sign.");
	write(  "%^BOLD%^%^GREEN%^      Welcome to the Player Village Locksmith.\n");
	write("%^RESET%^%^YELLOW%^        Here is a list of available options.");
	write(   "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	write(   "%^BOLD%^%^CYAN%^   'Make key for <doorname>'                       "+KEYCOST+" gold.");
	write(   "%^BOLD%^%^CYAN%^   'Make master key'                               "+(KEYCOST*3)+" gold.");
	write(   "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	return 1;

}
int make_key(string str){
	string doorname;
	if(!str) return notify_fail("Make What?\n");
	if(sscanf(str,"key for %s",doorname)) {
		write("%^BOLD%^%^CYAN%^The doorname is %^RED%^"+doorname+"%^CYAN%^?\nIs this correct?");
		write("%^BOLD%^%^CYAN%^ <yes> or <no>");
		input_to("make_the_key",0,doorname);
		return 1;
	}
	else if(sscanf(str,"%s key",doorname)){
		master_key(doorname);
		return 1;
	}
	
	return notify_fail("Try 'make key for <doorname>'.\nOr 'make master key'."); 
}


make_the_key(string str,string doorname){
    object obj;
	if(!str) input_to("make_the_key");
	if((str == "no") || (str == "n")) return 1;
	if((str != "yes")  && (str != "y")) input_to("make_the_key");
	else{ 
	   tell_object(TP,"The locksmith tells you: Ok, here is your key.");
	   tell_room(environment(TP),"The locksmith hands "+TPQCN+" a key.",TP);
	   obj = new(MAIN+"key");
	   obj->set_id(({"key",TPQN+doorname}));
	   obj->set_short("A room key");
	   obj->set_long("This is the "+doorname+" door key.");
	   obj->move(TP);
	   TP->add_money("gold",-KEYCOST);
	}

}
void master_key(string str){
	string *doornames;
	string *keyname;
	int total_doors;
	int inc;
	object obj;

	if(obj = present("housecontract",TP)){
		doornames = keys(obj->query_keynames());
		total_doors = sizeof(doornames);
		total_doors += 3;
		keyname = allocate(total_doors);
		inc = 0;
		while( inc < (total_doors - 3) ) {
			keyname[inc] = doornames[inc];
			inc++;
		}
		keyname[inc++] = "master";
		keyname[inc++] = "key";
		keyname[inc++] = "master key";
		   tell_object(TP,"The locksmith tells you: Ok, here is your key.");
		   tell_room(environment(TP),"The locksmith hands "+TPQCN+" a key",TP);
 		obj = new(MAIN+"key");
		obj->set_id(keyname);
		obj->set_short("A master key");
		obj->set_long("This is a master door key.");
		obj->set_player(TPQN);
		obj->move(TP);
		TP->add_money("gold",-(KEYCOST*3));
	}
	else return notify_fail("You need to have a valid contract, to get a master key!\n");

}
