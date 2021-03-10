#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>

inherit VAULT;
object ob;

void create()
{
    ::create();
    set_name("village2");
    set_property("outdoors",1);
    set_property("light",1);
    set_short("%^RESET%^%^CYAN%^A small hamlet%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^The building here is the largest in the village, comprising of a massive"+
             " cylindrical structure with wooden planks jutting out the side. Two massive oak doors are closed in"+
             " the front which has a worn path coming from the front door of the structure to the road. The path is"+
             " sparsely covered with hay and in some places piles of manure.  On the right side of the structure"+
             " is a silo which has been mostly erected but still under construction.");

    set_smell("default","\n%^BOLD%^%^BLACK%^The subtle smell of manure can be smelt here.%^RESET%^");
    set_listen("default","%^RESET%^%^RED%^You the faint sounds of animal noises come from inside the structure.%^RESET%^");

    set_exits(([
        "door"  : HAMLET"mill1",
		"east"	: HAMLET"village4",
		"north"	: HAMLET"village1",
	]));
	set_door("wooden door","/realms/klieth/greaterantioch/rooms/village/house1","mill","somekey");
	set_open("wooden door",0);
	set_lock_description("door","lock","This is a fairly ineffective lock.");
    set_door_description("door","This large wooden door is fairly worn, with rot obvious along the edges.");
    lock_difficulty("gate",-2000,"lock");
    set_items(([
      "walls" : "%^BOLD%^%^WHITE%^The walls here are much different then elsewhere in the mound, as they are clean and smooth, with the exception of a crack that runs up to the ceiling.",
      "bookshelf" : "%^RESET%^%^ORANGE%^This cedar bookshelf looks to have many, boring books on it.",
      "bed" : "%^BOLD%^%^YELLOW%^This soft bed is not made or well kept but still somehow looks comfortable.",
      "desk" : "%^RESET%^%^ORANGE%^This solid oak desk looks very unkept, perhaps if you %^BOLD%^%^YELLOW%^search %^RESET%^%^ORANGE%^it you may find something of interest.",
      "crack" : "%^BOLD%^%^WHITE%^The crack continues up to the ceiling and you notice it is from moisture as if there is an opening in the ceiling somewhere.",
      "ceiling" : "%^BOLD%^%^GREEN%^You search carefully around the ceiling and find a %^BOLD%^%^YELLOW%^trap door%^BOLD%^%^GREEN%^!",
   ]) );
   set_search("default","%^BOLD%^%^YELLOW%^Perhaps there is something on the desk?");
   set_search("alcove",(:TO,"searching":));
}

void searching() {
         write("%^BOLD%^%^BLUE%^You rummage through the papers and knock one to the ground!%^RESET%^");
         tell_room(TO,"%^BOLD%^%^YELLOW%^"+TPQCN+" knocks a %^BOLD%^%^WHITE%^paper%^BOLD%^%^BLUE%^ on the floor.%^RESET%^",TP);
      ob = new(MON+"gnollthief")->move(TO);
   }

void init()
{
	::init();
	add_action("OpenDoor","open");
	add_action("CloseDoor","close");
}

void OpenDoor(string str)
{

	if(str == "wooden door") {
		if(doors[str]["open"]) {
			notify_fail("It is already open!\n");
			return 0;
		}
		if(doors[str]["locked"]) {
			notify_fail("It is locked.\n");
			return 0;
		}
		tell_object(TP,"%^RESET%^%^ORANGE%^The door creaks as you open it.\n");
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
	if(str == "wooden door") {
		if(!doors[str]["open"]) {
			notify_fail("The large wooden door is already closed!\n");
			return 0;
		}
		tell_object(TP,"%^RESET%^%^ORANGE%^The door creaks as you shut the door.\n");
		tell_room(ETP,""+TP->query_cap_name()+" closes the wooden door.\n",TP);
		doors[str]["destination"]->set_open(str,0);
		set_open(str,0);
		tell_room(doors[str]["destination"],"The wooden door is closed by"+
		" someone on the other side.");
		return 1;
	}
	return ::CloseDoor();
}
