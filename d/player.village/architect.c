#include "pvillage.h"
#define VOID "/d/shadowgate/void"
inherit MONSTER;

//   objects
object player;
object home;

//   strings
string player_name;
string temp;
string exit_dir;

//   intigers
int house,builder;

//   strings
string newcfile;
string newofile;

//   functions
int check_dir(string dir);
void get_long_desc();
void get_short_desc();
void get_entrance_desc();

void create() {
    ::create();
	set_name("the architect");
	set_id( ({ "architect","man" }) );
	set("race", "human");
	set_gender("male");
	set_level(20);
	set_short("An architect");
	set_long("He looks like an old and wise wizard.\n");
	set_body_type("human");
	set_class("mage");
  	set("aggressive", 0);
  	set_alignment(8);
  	set_size(2);
   	set_stats("intelligence",18);
   	set_stats("wisdom",18);
   	set_stats("strength",18);
   	set_stats("charisma",18);
   	set_stats("dexterity",18);
   	set_stats("constitution",18);
   	set_max_mp(500);
   	set_mp(query_max_mp());
	set_hd(20, 1);
	add_money("electrum",random(10));
	add_money("silver",random(10));
	add_money("gold",random(5));
	add_money("copper",random(20));
}


void init(){
    ::init();
	if((string)TPQCN != player_name)
		return;
	add_action("house","house"); 
	add_action("add_room","addroom"); 
	add_action("description","describe"); 
	add_action("done","done"); 

}

int house(string dir){
    string return_dir;
	newcfile = VILLAGE+TPQN+".c";
        if(builder) {
                write("Hmmmph! Now look at what you've done.");
                write("You have interupted my spell. Now I'll have to start over!!!");
                builder = 1;return 1;
        }

	if(file_size(newcfile) != -1) return notify_fail("You already have a house!\n");
	if((return_dir = check_dir(dir)) == "not!") 
		return notify_fail("Sorry, but > "+dir+" < is not a valid direction...\n");
	dir = exit_dir;
	if((string)environment(TP)->query_exit(dir) != VOID) {
	    return notify_fail("I can't build your house to the "+dir+"!\n There is already something there...\n");
	}
	if ((int)this_player()->query_money("gold")<HOUSECOST) {
        write("%^MAGENTA%^The Architect says:%^RESET%^ You need more money to buy a house.\n");
        return 1;
	}
	if(geteuid(environment(TP)) != "Player.village") {
	write("%^MAGENTA%^The Architect says:%^RESET%^ Sorry, I am only allowed to build in the player village!");
	return 1;
	}
	if((file_name(environment(TP)) == MAIN+"office") || 
	   (file_name(environment(TP)) == MAIN+"lockoffice")) 
		return notify_fail("I cannot build a house in here!!!\n");
	newofile = HOMES+TPQN;
	environment(TP)->add_exit(newcfile,dir);
	environment(TP)->saveit();
	cp(MAIN+"house.c",VILLAGE+TPQN+".c");
	home = VILLAGE+TPQN+".c";
	home->add_exit(file_name(environment(TP)),return_dir);
	home->saveit(HOMES+TPQN);
	TP->add_money("gold",-HOUSECOST);
	get_entrance_desc();
	return 1;	

}
int description(){
        if(builder) {
                write("Hmmmph! Now look at what you've done.");
                write("You have interupted my spell. Now I'll have to start over!!!");
                builder = 1;return 1;
        }
	if ((int)this_player()->query_money("gold")<DESCCOST) {
        write("%^MAGENTA%^The Architect says:%^RESET%^ You need more money to change the description.\n");
        return 1;
	}
	if(geteuid(environment(TP)) != "Player.village") {
	write("%^MAGENTA%^The Architect says:%^RESET%^ Sorry, I am only allowed to work in the player village!");
	return 1;
	}
	if(strsrch(file_name(environment(TP)),TPQN) == -1){
	write("%^MAGENTA%^The Architect says:%^RESET%^ Sorry, you may only change your own house!");
	return 1;
	}
	sscanf(file_name(environment(TP)),"/%*s/%*s/%*s/%s",tmp);
	newofile = HOMES+tmp;	
	home = environment(TP);
	TP->add_money("gold",-DESCCOST);
	get_long_desc();
	return 1;
}
int add_room(string dir){
    string return_dir, thisofile,tmp;
    int x;
        if(builder) {
                write("Hmmmph! Now look at what you've done.");
                write("You have interupted my spell. Now I'll have to start over!!!");
                builder = 1;return 1;
        }
	if((return_dir = check_dir(dir)) == "not!") 
		return notify_fail("Sorry, but > "+dir+" < is not a valid direction...\n");
	dir = exit_dir;
	if((string)environment(TP)->query_exit(dir) != VOID) {
	    return notify_fail("I can't build your room to the "+dir+"!\n There is already something there...\n");
	}
	if ((int)this_player()->query_money("gold")<ROOMCOST) {
        write("%^MAGENTA%^The Architect says:%^RESET%^ You need more money to add a room.\n");
        return 1;
	}
	if(geteuid(environment(TP)) != "Player.village") {
	write("%^MAGENTA%^The Architect says:%^RESET%^ Sorry, I am only allowed to build in the player village!");
	return 1;
	}
	exit_dir = dir;	
	x=0;
	while(x < 20){
		newcfile = VILLAGE+TPQN+x+".c";
		if(file_size(newcfile) < 0) {
		    cp(MAIN+"house.c",newcfile);
		    newofile = HOMES+TPQN+x;
		    break;
		}
		x++;
	}
	if(x == 20){
		return notify_fail("Sorry, but you already have all the rooms your allowed.\n");

	}
		
	sscanf(file_name(environment(TP)),"/%*s/%*s/%*s/%s",tmp);
	thisofile = HOMES+tmp;	
	rm(thisofile+".o");
	environment(TP)->add_exit(newcfile,dir);
	environment(TP)->saveit(thisofile);
	home = newcfile;
	home->add_exit(file_name(environment(TP)),return_dir);
	home->saveit(newofile);
	TP->add_money("gold",-ROOMCOST);
	get_long_desc();
	return 1;	

}

string check_dir(string dir){

	switch(dir){
		case "e"	: 
		case "east"	: {
			exit_dir = "east";
			return "west";
		}
		case "w"	: 
		case "west"	: {
			exit_dir = "west";
			return "east";
		}
		case "n"	: 
		case "north"	: {
			exit_dir = "north";
			return "south";
		}
		case "s"        : 
		case "south"    : {
			exit_dir = "south";
			return "north";
		}
		case "up"       : 
		case "u"        : {
			exit_dir = "up";
			return "down";
		}
		case "d"        : 
		case "down"     : {
			exit_dir = "down";
			return "up";
		}
		case "se"	: 
		case "southeast": {
			exit_dir = "southeast";
			return "northwest";
		}
		case "sw"	: 
		case "southwest": {
			exit_dir = "southwest";
			return "northeast";
		}
		case "ne"	: 
		case "northeast": {
			exit_dir = "northeast";
			return "southwest";
		}
		case "nw"	: 
		case "northwest": {		
		  	exit_dir = "northwest";
		 	return "southeast";
		}
		default: return "not!";
	}
}
void get_entrance_desc()  {
    write("%^MAGENTA%^The Architect says:%^RESET%^ Please enter your entrance description below: ");
    write("                   (60 char max) ( \"**\" or \".\" to quit)");
    temp = "";
    input_to("enter_entrance");
}
enter_entrance(string str)    {
  object obj;
  if(str != "**" && str != ".")    {
    temp += str;input_to("enter_entrance");
  }  
  else  
  {
	if(strlen(temp) > 60){
	    write("%^MAGENTA%^The Architect says:%^RESET%^ That would be too much work! Please try again.\n\n");
	    temp = "";
	    get_entrance_desc();
	} else if(strlen(temp) < 3){
	    write("%^MAGENTA%^The Architect says:%^RESET%^ It must contain at least one word! Please try again.\n");
	    temp = "";
	    get_entrance_desc();
	} else {
	    temp = replace_string(temp,"@","");
	    temp = replace_string(temp,"\n","");
	    temp += (" ("+exit_dir+")");
  	    environment(TP)->add_long(temp);
  	    environment(TP)->saveit();
  	    obj = new(MAIN+"housecontract");
	    obj->set_player(TPQN);
	    obj->move(TP);
	    get_long_desc();
	}
  }

}

void get_long_desc()    {
    write("%^MAGENTA%^The Architect says:%^RESET%^ Please enter your long description below:");
    write("                   (6 lines recommended) ( \"**\" or \".\" to quit)");
    temp = "";
    input_to("enter_long");
}
enter_long(string str)    {
  if(str != "**" && str != ".")    {
    temp = replace_string(temp,"\n","");
    temp += str + "\n";
    input_to("enter_long");
  } else if(strlen(temp) < 3){
	write("%^MAGENTA%^The Architect says:%^RESET%^ It must contain at least one word! Please try again.\n");
	temp = "";
	get_long_desc();
  } else  {
	temp = replace_string(temp,"@","");
	home->set_long(temp);
	home->saveit(newofile);
	get_short_desc();	
  }
}
void get_short_desc()    {
    write("%^MAGENTA%^The Architect says:%^RESET%^ Please enter your short description below:");
    write("                   (30 char max) ( \"**\" or \".\" to quit)");
  temp = "";
  input_to("enter_short");
}
 enter_short(string str)    {
  if(str != "**" && str != ".")    {
    temp += str;
    input_to("enter_short");
  } else if(strlen(temp) < 3){
	write("%^MAGENTA%^The Architect says:%^RESET%^ It must contain at least one word! Please try again.\n");
	temp = "";
	get_short_desc();
  } else {
	if(strlen(temp) > 30){
	    write("%^MAGENTA%^The Architect says:%^RESET%^ Too long! This is a brief description! Please try again.\n\n");
	    temp = "";
	    get_short_desc();
	} else {
	    temp = replace_string(temp,"@","");
	    temp = replace_string(temp,"\n","");
	    home->saveit(newofile);
	    builder = 1;
	    return 1;
	}
  }
}


int done() {
	if((string)TPQCN != player_name) return notify_fail("What?\n");
        if(builder) {
                write("Hmmmph! Now look at what you've done.");
                write("You have interupted my spell. Now I'll have to start over!!!");
                builder = 1;return 1;
        }
	write("%^MAGENTA%^The Architect says:%^RESET%^ Thank you for using our services, sir.\n");
	tell_room(environment(TP),"The architect leaves.\n");
	move_object(this_object(),VOID);
	destruct(this_object());
	return 1;
}

void set_player(object obj){
    if(!obj) {
	write("%^MAGENTA%^The Architect says:%^RESET%^ Bug alert!!! Please notify Melnmarn! (set_player)");
	return;
    }
    player = obj;
    player_name = player->query_cap_name();
}


void start_heart() {
	set_heart_beat(1);
}

void heart_beat() {
	string tmp;
	if (builder) {
		builder++; 
		if (builder == 1) 
		say("The architect makes some magical gestures.\n");
		if (builder == 2) {
			say("The architect starts to mumble some strange and powerful words.\n");
			set_long("He is mumbling some strange words.\n"+"He looks very concentrated.\n");
		}
		if (builder == 3) {
			say("The architect starts to glow with a magic blue light.\n");
			set_long("He is glowing with a blue light.\n");
		}
		if (builder == 4) {
			say("The architect starts to sing a song, but you can't understand the words.\n");
			set_long("He is glowing with a blue light.\n"+
			"He is also singing some old and strange song.\n");
		}
		if (builder == 5) {
			say("The architect stoops singing and says: It is Done!\n");
			set_long("He looks like an old wizard.\n");
			builder = 0;
		}
	   	return 1;
	}
	if (!player || !query_ip_number(player)) {
		tell_room(environment(),"The architect leaves.\n");
		move_object(this_object(),"room/void");
		destruct(this_object());
		return 1;
	}
	if (!sscanf(file_name(environment()),MAIN+"%s",tmp)) {
		tell_room(environment(),"%^MAGENTA%^The architect says:%^RESET%^ I'm not leaving Melnmarn's realm.\n");
		tell_room(environment(),"The architect leaves.\n");
		move_object(this_object(),"room/void");
		destruct(this_object());
		return 1;
	}
	if (environment(player) != environment(this_player())) {
		tell_room(environment(),"The architect leaves.\n");
		move_object(this_object(),environment(player));
		tell_room(environment(),"The architect arrives.\n");
	}
}

