#include <std.h>

inherit VAULT;


void create() { ::create(); }

int confirm(string str,object obj)
{
	if(!objectp(obj)) { return 1; }
	switch(str)
	{
	case "yes":
	case "Yes":
	case "y":
	case "Y":
		tell_object(obj,"Confirmed, moving you to a new location.");
		TP->move("/d/shadow/room/pass/passn9");
		TP->force_me("look");
		return 1;
	default:
		tell_object(obj,"Aborting...");
		return 1;
	}
	return 1;
}

int ooc_escape()
{
	if(!objectp(TP)) { return 1; }
	tell_object(TP,"%^B_BLUE%^%^WHITE%^OOC?:  This is an ooc command used to escape "
		"from a plot room if you have become stuck there and are unable to get an "
		"immortal's help.  It is not to be used as an easy means of transportation "
		"around the realms.  Only use this command if you are truly stuck.%^RESET%^");
	tell_object(TP,"Are you sure you want to escape from this room?  "
		"Enter yes or no.");
	input_to("confirm",TP);
	return 1;
}

string get_av_name(object room)
{
	string str;
	int num;

	if(!objectp(TO)) { return 0; }

	str = base_name(room);
	str = replace_string(str,"/d/av_rooms/","");
	num = strsrch(str,"/");
	str = str[0..(num - 1)];
	return str;
}

int no_quit()
{
	if(!objectp(TP)) { return 1; }
	if(avatarp(TP)) { return 1; }
	tell_object(TP,"%^B_BLUE%^%^WHITE%^You are not allowed to quit here.%^RESET%^");
	tell_object(TP,"Moving you to a safe room.");
	TP->move("/d/shadow/room/pass/passn9");
	TP->force_me("look");
	return 1;
}

void init()
{
	string name;
    ::init();

	if(!objectp(TP)) { return; }
	if(!interactive(TP)) { return; }
	if(avatarp(TP)) { return; }

	name = get_av_name(TO);
	if(!find_player(name))
	{
		tell_object(TP,"%^B_BLUE%^%^WHITE%^OOC:  The avatar who was controlling this area is "
			"no longer avaliable.  Moving you to another location.%^RESET%^");
		TP->move("/d/shadow/room/pass/passn9");
		TP->force_me("look");
		log_file("avatar_rooms",""+ctime(time())+" "+capitalize(TP->query_true_name())+" was moved out "
			"of "+base_name(TO)+"\n");
		return;
	}

	add_action("ooc_escape","oocescape");
	add_action("no_quit","quit");

}
