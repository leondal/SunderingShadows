
#include <std.h>
inherit "/std/guilds/members.c";

void create()
{
	object obj;
	::create();
	set_property("indoors",1);
	set_property("light",3);
	set_property("no sticks",1);
	set_property("no teleport",1);
    set_guild_name("Iron Fist");
    set_guild_object("/d/guilds/fist/obj/tatoo.c");
	set_short("A Great Hall");
	set_long("
%^ORANGE%^You are in the great hall of the Iron Fist. This torch-lit room gives the impression of austerity and great age, while feeling comfortable despite it's great size.  There is a long, massive table dominating the center of the room, surrounded by hulking great chairs. There are torches lining the walls, and braziers at each end of the table for light. Suits of plate armor stand in each corner, like silent guardians. Dominating one wall is an iron bas-relief sculpture of a clenched fist, surrounded by a silver circle.  
	");
	set_smell("default","%^BLUE%^The room smells of aged wood, and stale wine.");
	set_listen("default","It is silent here, peaceful.");
	set_items((["sculpture" : "This is a huge bas-relief sculpure of an iron fist, it seems to give you strength as you gaze upon it.","armor" : "The suits of armor in the corners of the room are suits of Full Plate, from various lands throughout the realms.","torches" : "The torches light the room, and thier smoke rises up under the high vaulted ceiling.","braziers" : "The braziers sit at either end of the table, casting a pleasant light on the room","table" : "This massive oaken table is long and rectangular in shape, it's top is scared and stained from many years of service, and the legs are sculpted in the shape of lion's paws.","chairs" : "The table is surrounded by large chairs, made of iron-bound oak, yet strangly comfortable. The chair at the head of the table is even larger than the others, and it's ironwork is chased with silver."
	]));
	set_exits(([
	"out" : "/d/guilds/fist/hall/hall2.c",
	]));
	set_pre_exit_functions(({"out"}),({"go_stairs"}));
	obj = new("std/bboard");
	obj->set_name("board");
	obj->set_id(({"board","bulletin board","regents board"}));
	obj->set_board_id("fist_board");
	obj->set_short("The Iron Fist Board");
	obj->set_long("This is a large board that the members of the Iron Fist may post on.");
	obj->set_max_posts(50);
	obj->set_location("/d/guilds/fist/hall/hall3.c");

}

int go_stairs()
{
	write("%^RED%^You turn, and walk purposefully towards the sculpted Iron Fist."
"\n%^RED%^You find yourself back in the tomb.");
	return 1;
}

void init()
{
	::init();
	add_action("sit","sit");
    // add_action("get_stuff","call");
}

void sit(string str)
{
	if(str == "floor") {
		tell_object(TP,"%^YELLOW%^You sit down on the cold stone floor.");
		tell_room(ETP,"%^YELLOW%^"+TP->query_cap_name()+" sits down on the cold stone floor.",TP);
		return 1;
	}
	if(str == "chair") {
		tell_object(TP,"%^GREEN%^You sit down in one of the huge chairs surrounding the table. You feel ready to help plan a great battle.");
		tell_room(ETP,"%^GREEN%^"+TP->query_cap_name()+" sits down in one of the huge chairs around the table. It looks surprisingly comfortable.",TP);
		return 1;
	}
	if(str == "head chair" || str == "throne") {
		tell_object(TP,"%^BOLD%^%^RED%^You sit in the huge chair at the head of the table, reserved for the leader of the Iron Fist.");
		tell_room(ETP,"%^BOLD%^%^RED%^"+TP->query_cap_name()+" gravely seats himself in the huge chair at the head of the table, and looks ready to lead the Iron Fist.",TP);
		return 1;
	}
	}

/*
void get_stuff(string str)
{
	if(str == "tattoo artist") {
		if(present("tattoo",TP)) {
			tell_object(TP,"It hurt to get the first one, why would you want two?");
			return 1;
		}
		else {
			tell_object(TP,"The tattoo artist scurries in from the shadows, and quickly tattoos the words 'quo bello et gloria ducunt' on the inside of your left bicep.");
			tell_room(ETP,""+TP->query_cap_name()+" is tattooed with the mark of the Iron Fist.",TP);
			new("/d/guilds/fist/obj/tattoo.c")->move(TP);
			return 1;
		}
	}
}
*/


