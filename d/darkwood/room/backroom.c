//Updated descriptions with color - Octothorpe 6/15/09

#include <std.h>
inherit VAULT;

int count;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("Back room of the Rhapsody Inn");
	set_long("%^BOLD%^Back room of the Rhapsody Inn\n "+
	   "This room is mostly a storage area for beer and other alcohols, but"+
	   " it is also used as a sobering up room for the Rhapsody's drunks."+
 	   " It is dimly lit by a few oil lamps that are on the walls. %^RESET%^"+
         "%^ORANGE%^Kegs %^BOLD%^%^WHITE%^of beer are found around the "+
         "room, the upright ones make fair seats.  There are a few empty "+
         "kegs as well that have been turned on their sides and are "+
         "occasionally used as foot rests. There is a ladder leaning"+
	   " against the south wall. The floor is a little dusty and could use a"+
	   " good sweeping, but it's not a bad place. A little table has been set"+
	   " up in the corner with a couple of chairs around it. There is a pot of"+
	   " rather cold %^BOLD%^%^BLACK%^coffee %^WHITE%^on top of it and a few mugs.\n");
	set_smell("default","The scent of alcohol is strong in this room.");
	set_listen("default","You can hear the chatter of the customers in the"+
	" inn.");
	set_items(([
	"floor" : "The floor is in need of a good sweeping.",
	"ceiling" : "The ceiling seems fairly plain at first, but you notice"+
	" a square area on the southern wall that looks like a trap door. There"+
	" is a ladder that leads right up to it.",
	"ladder" : "There is a ladder leaning up against the south wall. It"+
	" doesn't seem to lead anywhere but to the ceiling.",
	({"wall","walls"}) : "The walls are plain, just a few oil lamps attached"+
	" to them for light. A ladder rests against the south wall.",
	({"lamps","lamp","oil lamps","oil lamp"}) : "A couple of oil lamps are"+
	" fixed to the walls. They are dimly lit so as not to hurt the eyes of"+
	" the drunks.",
	({"keg","kegs","upright kegs","empty kegs"}) : "Several large kegs are"+
	" scattered about the room, most are filled with beer. The upright ones"+
	" make fairly good seats. Some of the empty ones are on their sides and"+
	" make good foot stools on occasion.",
	({"table","little table"}) : "A little %^ORANGE%^wooden %^RESET%^table "+
         "has been placed in the corner of the room. A pot of rather cold "+
         "%^BOLD%^%^BLACK%^coffee %^RESET%^is set on top of it with a few mugs.",
	({"chair","chairs"}) : "A couple of rather old wooden chairs are seated"+
	" around the table.",
	"pot of coffee" : "A pot full of cold, %^BOLD%^%^BLACK%^black %^RESET%^"+
         "coffee is set out on the table.",
	({"mug","mugs"}) : "Some mugs are set out next to the coffee pot.",
	({"door","wooden door"}) : "The wooden door on the north wall leads"+
	" back to the rest of the inn.",
	]));
	set_exits(([
        "inn" : "/d/darkwood/room/rhapsody",
        "up" : "/d/darkwood/room/roof",
	]));
	set_door("wooden door","/d/darkwood/room/rhapsody","inn","rhapsody key");
	set_door("trap door","/d/darkwood/room/roof","up",0);
	set_invis_exits(({"up"}));
	count = 6;
}

void reset()
{
	::reset();
	if(count < 6) {
		tell_room(TO,"A servant comes in and places a coffee pot on the table.");
		count = 6;
		return 1;
	}
}

void init()
{
	::init();
	add_action("sit","sit");
	add_action("pour","pour");
	add_action("OpenDoor","open");
	add_action("CloseDoor","close");
}

void sit(string str)
{
	if(str == "keg") {
		if(TP->query_intox() > 500) {
			tell_object(TP,"%^BOLD%^You attempt to sit down on one of the"+
			" kegs but somehow miss and fall to the floor.");
			tell_room(ETP,"%^BOLD%^"+TP->query_cap_name()+" tries to sit"+
			" down on thin air and falls hard to the floor.",TP);
			return 1;
		}
		tell_object(TP,"%^ORANGE%^You seat yourself on one of the kegs.");
		tell_room(ETP,"%^ORANGE%^"+TP->query_cap_name()+" seats"+
		" "+TP->query_objective()+"self on one of the kegs.",TP);
		return 1;
	}
	if(str == "chair") {
		if(TP->query_intox() > 500) {
			tell_object(TP,"%^BOLD%^You barely manage to stumble over to"+
			" one of the chairs and fall in it.");
			tell_room(ETP,"%^BOLD%^"+TP->query_cap_name()+" stumbles over"+
			" to one of the chairs and tumbles into it.",TP);
			return 1;
		}
		tell_object(TP,"You sit down on the wooden chair.");
		tell_room(ETP,""+TP->query_cap_name()+" sits down on the wooden"+
		" chair.",TP);
		return 1;
	}
}

void pour(string str)
{
	if(str != "coffee") {
		tell_object(TP,"Pour what?\n");
		return 1;
	}
	if(count < 1) {
		tell_object(TP,"The coffee pot is empty!");
		return 1;
	}
	else {
		tell_object(TP,"You pour yourself a mug of coffee.");
		tell_room(ETP,""+TP->query_cap_name()+" pours "+TP->query_objective()+"self"+
		" a mug of coffee.",TP);
		new("/d/darkwood/obj/coffee.c")->move(TO);
		count -= 1;
		if(count < 1) {
			add_item("pot of coffee","An empty pot of coffee.");
		}
		return 1;
	}
}

void OpenDoor(string str)
{
	if(!str) return 0;
	if(str == "trap door") {
		if(doors[str]["open"]) {
			notify_fail("It is already open!\n");
			return 0;
		}
		else {
			tell_object(TP,"You carefully open the trap door in the ceiling.\n");
			tell_room(ETP,""+TP->query_cap_name()+" opens a trap door in the ceiling.\n",TP);
			doors[str]["destination"]->set_open(str,1);
			set_open(str,1);
			tell_room(doors[str]["destination"],"You notice the trap door"+
			" suddenly open from the other side.\n");
			remove_invis_exit("up");
			return 1;
		}
	}
	if(str == "wooden door") {
		if(doors[str]["open"]) {
			notify_fail("It is already open!\n");
			return 0;
		}
		if(doors[str]["locked"]) {
			notify_fail("It is locked.\n");
			return 0;
		}
		tell_object(TP,"You open the wooden door.\n");
		tell_room(ETP,""+TP->query_cap_name()+" opens the wooden door.\n",TP);
		doors[str]["destination"]->set_open(str,1);
		set_open(str,1);
		tell_room(doors[str]["destination"],"You notice the wooden door suddenly"+
		" open from the other side.\n");
		return 1;
	}
	else {
		return ::OpenDoor();
	}
}

void CloseDoor(string str)
{
	if(!str) {
		notify_fail("Close what?\n");
		return 0;
	}
	if(str == "trap door") {
		if(!doors[str]["open"]) {
			notify_fail("The trap door is already closed!\n");
			return 0;
		}
		tell_object(TP,"You close the trap door.\n");
		tell_room(ETP,""+TP->query_cap_name()+" closes the trap door.\n",TP);
		doors[str]["destination"]->set_open(str,0);
		set_open(str,0);
		tell_room(doors[str]["destination"],"The trap door is closed by"+
		" someone on the other side.\n");
		set_invis_exits(({"up"}));
		return 1;
	}
	if(str == "wooden door") {
		if(!doors[str]["open"]) {
			notify_fail("The wooden door is already closed!\n");
			return 0;
		}
		tell_object(TP,"You close the wooden door.\n");
		tell_room(ETP,""+TP->query_cap_name()+" closes the wooden door.\n",TP);
		doors[str]["destination"]->set_open(str,0);
		set_open(str,0);
		tell_room(doors[str]["destination"],"The wooden door is closed by"+
		" someone on the other side.");
		return 1;
	}
	return ::CloseDoor();
}
