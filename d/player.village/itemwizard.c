#include "pvillage.h"

inherit MONSTER;

//   objects
object item;
object player;

//   strings
string player_name;
string temp;
string item_filename;

//   intigers
int builder;

//   functions
void get_long_desc();
void get_short_desc();
void set_player(object obj);

void create() {
    ::create();
	set_name("the item wizard");
	set_id( ({ "wizard","man","toymaker" }) );
	set("race", "human");
	set_gender("male");
	set_level(20);
	set_short("A toy maker");
	set_long("He looks like an old and wise toymaker.\n");
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
	add_action("done","done");
	add_action("makeitem","make");
	add_action("removeitem","remove");
}

int done(){
	if(builder) { 
		write("Hmmmph! Now look at what you've done.");
		write("You have interupted my spell. Now I'll have to start over.");
		builder = 1; return 1;
	}
	write("The toymaker says: Thank you for using our services, sir.\n");
	tell_room(environment(TP),"The Toymaker leaves.\n");
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

int removeitem(string str){
	string thisfile,called;
	object name;
	called = str;
	if(!str) return notify_fail("Remove what!");
	if(builder) { 
		write("Hmmmph! Now look at what you've done.");
		write("You have interupted my spell. Now I'll have to start over.");
		builder = 1;return 1;
	}
	if(geteuid(environment(TP)) != "Player.village") {
		write("Sorry, I am only allowed to work in the player village!");
		return 1;
	}
	temp = file_name(environment(TP));
	if(strsrch(temp,(string)TPQN) == -1)
		return notify_fail("This is not your house!\n");
	thisfile = file_name(environment(TP));
	sscanf(thisfile,"/%*s/%*s/%*s/%s",temp);	
	item_filename = OBJ+str+temp;
	if(!(item = present(str,environment(TP)))) return notify_fail("There is no "+str+" here.");
	else {
		rm(item_filename+".o");
		destruct(item);
		environment(TP)->remove_an_item(str+temp);
		environment(TP)->reinitiate();
		write("%^MAGENTA%^The Toymaker says: %^RESET%^The "+called+" has been removed.");
	}
	return 1;


}
int makeitem(string str){
	string thisfile;
	if(!str) return notify_fail("Make what!");
	if(builder) { 
		write("Hmmmph! Now look at what you've done.");
		write("You have interupted my spell. Now I'll have to start over.");
		builder = 1;return 1;
	}
	if(geteuid(environment(TP)) != "Player.village") {
		write("Sorry, I am only allowed to build in the player village!");
		return 1;
	}
	temp = file_name(environment(TP));
	if(strsrch(temp,(string)TPQN) == -1)
		return notify_fail("This is not your house!\n");
	if ((int)this_player()->query_money("gold")<ITEMCOST) {
	        write("You need more money to make that.\n");
	        return 1;
	}
	thisfile = file_name(environment(TP));
	sscanf(thisfile,"/%*s/%*s/%*s/%s",temp);	
	item_filename = OBJ+str+temp;
	if(present(str,environment(TP))) return notify_fail("You already have a "+str+" here. \n");
	item = new(MAIN+"item.c");
	item->set_id(({str,str+temp}));
	TP->add_money("gold",-ITEMCOST);
	environment(TP)->set_itemlist(str+temp);
	environment(TP)->saveit();
	get_long_desc();
	return 1;


}
void get_long_desc()    {
    write("%^MAGENTA%^The Toymaker says:%^RESET%^ Please enter your long description below:");
    write("                   ( \"**\" or \".\" to quit)");
    temp = "";
    input_to("enter_long");
}
enter_long(string str)    {
  if(str != "**" && str != ".")    {
    temp = replace_string(temp,"\n","");
    temp += str + "\n";
    input_to("enter_long");
  }  
  else  {
	temp = replace_string(temp,"@","");
	item->set_long(temp);
	get_short_desc();	
  }
}
void get_short_desc()    {
    write("%^MAGENTA%^The Toymaker says:%^RESET%^Please enter your short description below:");
    write("                   (30 char max) ( \"**\" or \".\" to quit)");
  temp = "";
  input_to("enter_short");
}
 enter_short(string str) {
  if(str != "**" && str != ".") {
    	temp += str;
    	input_to("enter_short");
  }  
  else {
	if(strlen(temp) > 30){
	    write("%^MAGENTA%^The Toymaker says:%^RESET%^ Too long! This is a brief description! Please try again.\n\n");
	    temp = "";
	    get_short_desc();
	    return 1;
	}
	temp = replace_string(temp,"@","");
	temp = replace_string(temp,"\n","");
	item->set_short(temp);
	item->saveit(item_filename);
	item->move(environment(TP));
	builder = 1;
	return 1;
  }
}


void start_heart() {
	set_heart_beat(1);
}

void heart_beat() {
	string tmp;
	if (builder) {
		builder++; 
		if (builder == 2) 
		say("The Toymaker makes some magical gestures.\n");
		if (builder == 4) {
			say("The Toymaker starts to mumble some strange and powerful words.\n");
			set_long("He is mumbling some strange words.\n"+"He looks very concentrated.\n");
		}
		if (builder == 6) {
			say("The Toymaker starts to glow with a magic blue light.\n");
			set_long("He is glowing with a blue light.\n");
		}
		if (builder == 8) {
			say("The Toymaker starts to sing a song, but you can't understand the words.\n");
			set_long("He is glowing with a blue light.\n"+
			"He is also singing some old and strange song.\n");
		}
		if (builder == 10) {
			say("The Toymaker stops singing and says: Be Done!\n");
			set_long("He looks like an old wizard.\n");
			builder = 0;
		}
	   	return 1;
	}
	if (!player || !query_ip_number(player)) {
		tell_room(environment(),"The Toymaker leaves.\n");
		move_object(this_object(),"room/void");
		destruct(this_object());
		return 1;
	}
	if (!sscanf(file_name(environment()),MAIN+"%s",tmp)) {
		tell_room(environment(),"The Toymaker says: I'm not leaving Melnmarn's realm.\n");
		tell_room(environment(),"The Toymaker leaves.\n");
		this_object()->move(VOID);
		destruct(this_object());
		return 1;
	}
	if (environment(player) != environment(this_player())) {
		tell_room(environment(),"The Toymaker leaves.\n");
		this_object()->move(environment(player));
		tell_room(environment(),"The Toymaker arrives.\n");
	}
}

