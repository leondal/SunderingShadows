#include "pvillage.h"

inherit MONSTER;

//   objects
object home;
object other;
object player;

//   strings
string player_name;
string thiscfile;
string thisofile;
string thatcfile;
string thatofile;
string exit_dir;
string return_dir;

//   intigers
int builder;

//   functions
void makedoor(string str);
void removedoor(string str);
int check_dir(string dir);
void get_long_desc();
void get_short_desc();

void create() {
    ::create();
	set_name("the doormaker");
	set_id( ({ "doormaker","man" }) );
	set("race", "human");
	set_gender("male");
	set_level(20);
	set_short("A doormaker");
	set_long("He looks like an old and wise carpenter.\n");
	set_body_type("human");
	set_class("ranger");
  	set("aggressive", 0);
  	set_alignment(9);
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
	add_action("add_door","add"); 
	add_action("remove_door","remove"); 
	add_action("done","done"); 

}

int add_door(string dir){
    string temp;
	if(builder) { 
		write("Hmmmph! Now look at what you've done.");
		write("You have interupted my spell. Now I'll have to start over.");
		builder = 1;return 1;
	}
	if(strsrch(file_name(environment(TP)),TPQN) == -1) return notify_fail("This isn't your house!\n");
	if(!sscanf(dir,"door %s",dir)) return notify_fail("Try add door <dir>\n");
	if((return_dir = check_dir(dir)) == "not!") 
		return notify_fail("Sorry, but "+dir+" is not a valid direction...\n");
	if ((int)this_player()->query_money("gold")<DOORCOST) {
	        write("You need more money to install a door.\n");
	        return 1;
	}
	if(geteuid(environment(TP)) != "Player.village") {
		write("Sorry, I am only allowed to build in the player village!");
		return 1;
	}
	if( (thatcfile = (string)environment(TP)->query_exit(dir)) == VOID)
		return notify_fail("There isn't an exit in that direction!\n");
	if(environment(TP)->query_door(dir)) return notify_fail("There is a door there, already!\n"); 
	other = thatcfile;
	sscanf(thatcfile,"/%*s/%*s/%*s/%s.c",temp);
	thatofile = HOMES+temp;		
	rm(thatofile+".o");
	thiscfile = file_name(environment(TP));
	sscanf(thiscfile,"/%*s/%*s/%*s/%s",temp);	
	thisofile = HOMES+temp;	
	rm(thisofile+".o");
	TP->add_money("gold",-DOORCOST);
	write("I need a name for the door. May only be one word.");
	write("IE: \"closet\" for a closet door.");
	input_to("get_doorname");		
	return 1;	

}

string check_dir(string dir){

   switch(dir){
	case "e"  	: 
 	case "east" 	: {exit_dir = "east";return "west";}
	case "w"  	: 
	case "west" 	: {exit_dir = "west";return "east";}
	case "n"	: 
	case "north"	: {exit_dir = "north";return "south";}
	case "s"        : 
	case "south"    : {exit_dir = "south";return "north";}
	case "up"       : 
	case "u"        : {exit_dir = "up";return "down";}
	case "d"        : 
	case "down"     : {exit_dir = "down";return "up";}
	case "se"	: 
	case "southeast": {exit_dir = "southeast";return "northwest";}
	case "sw"	: 
	case "southwest": {exit_dir = "southwest";return "northeast";}
	case "ne"	: 
	case "northeast": {exit_dir = "northeast";return "southwest";}
	case "nw"	: 
	case "northwest": {exit_dir = "northwest";return "southeast";}
	default: return "not!";
    }
}

int done() {
	if(builder) { 
		write("Hmmmph! Now look at what you've done.");
		write("You have interupted my spell. Now I'll have to start over.");
		builder = 1;return 1;
	}
	write("the doormaker says: Thank you for using our services, sir.\n");
	tell_room(environment(TP),"The doormaker leaves.\n");
	move_object(this_object(),VOID);
	destruct(this_object());
	return 1;
}

void set_player(object obj){
    if(!obj) {
	return;
    }
    player = obj;
    player_name = player->query_cap_name();
}

int get_doorname(string str){
	string temp;
	string *names;
	if(!str){
		input_to("get_doorname");
		return 1;
	}
	if(sscanf(str,"%*s %s",temp)){
		write("Hey, I said one word! Try again!");
		input_to("get_doorname");
		return 1;
	}
	str = replace_string( str,"@","");
	names = keys(environment(TP)->query_doornames());
	if(sizeof(names) < 1) {}
	else if(member_array(str,names) != -1){
		write("There is already a door here with the name: "+str);
		write("Try it again, with a different name.");
		input_to("get_doorname");
		return 1;
	}
	builder = 1;
	makedoor(str);
}

void makedoor(string str){
	string keyname = TPQN+str;
	present("housecontract",TP)->set_keynames(keyname);
	rm(thisofile+".o");
	environment(TP)->set_door(str,thatcfile,exit_dir,keyname);
	environment(TP)->set_doornames(str);
	environment(TP)->set_dooritem(exit_dir,str);
	environment(TP)->saveit(thisofile);
	environment(TP)->reinitiate();
	other->set_door(str,thiscfile,return_dir,keyname);
	other->set_doornames(str);
	other->saveit(thatofile);
}

int remove_door(string str){
    string dir;
    string temp,temp2;
    string keyname = TPQN+str;
	if(builder) { 
		write("Hmmmph! Now look at what you've done.");
		write("You have interupted my spell. Now I'll have to start over.");
		builder = 1;return 1;
	}
	present("housecontract",TP)->remove_keynames(keyname);
	thiscfile = file_name(environment(TP));
	sscanf(thiscfile,"/%*s/%*s/%*s/%s",temp);	
	thisofile = HOMES+temp;	
	rm(thisofile+".o");
	rm(thatofile+".o");
	dir = environment(TP)->remove_doornames(str);
	environment(TP)->saveit(thisofile);
	environment(TP)->reinitiate();
	thatcfile = (string)environment(TP)->query_exit(dir);
	sscanf(thatcfile,"/%*s/%*s/%*s/%s",temp2);
	thatofile = HOMES+temp2;	
	other = thatcfile;
	other->remove_doornames(str);
	other->saveit(thatofile);
	other->reinitiate();
	return 1;

}
void start_heart() {
	set_heart_beat(1);
}
void heart_beat() {
	string tmp;
	if (builder) {
		builder++; 
		if (builder == 2) 
			say("%^BOLD%^%^CYAN%^The doormaker makes some magical gestures.\n");
		if (builder == 3) {
			say("%^BOLD%^%^CYAN%^The doormaker starts to mumble some strange and powerful words.\n");
			set_long("He is mumbling some strange words.\n"+"He looks very concentrated.\n");
		}
		if (builder == 4) {
			say("%^BOLD%^%^CYAN%^The doormaker starts to glow with a magic blue light.\n");
			set_long("He is glowing with a blue light.\n");
		}
		if (builder == 5) {
			say("%^BOLD%^%^CYAN%^The doormaker starts to sing a song, but you can't understand the words.\n");
			set_long("He is glowing with a blue light.\n"+
			"He is also singing some old and strange song.\n");
		}
		if (builder == 6) {
			say("%^BOLD%^%^CYAN%^The doormaker stoops singing and says: It Is Done!\n");
			set_long("He looks like an old wizard.\n");
			builder = 0;
		}
	   	return 1;
	}
	if (!player || !query_ip_number(player)) {
		tell_room(environment(),"The doormaker leaves.\n");
		move_object(this_object(),"room/void");
		destruct(this_object());
		return 1;
	}
	if (!sscanf(file_name(environment()),MAIN+"%s",tmp)) {
		tell_room(environment(),"The doormaker says: I'm not leaving Melnmarn's realm.\n");
		tell_room(environment(),"The doormaker leaves.\n");
		move_object(this_object(),"room/void");
		destruct(this_object());
		return 1;
	}
	if (environment(player) != environment(this_player())) {
		tell_room(environment(),"The doormaker leaves.\n");
		move_object(this_object(),environment(player));
		tell_room(environment(),"The doormaker arrives.\n");
	}
}

