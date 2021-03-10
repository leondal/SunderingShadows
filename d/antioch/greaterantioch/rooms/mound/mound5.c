#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>

inherit VAULT;
int lastsearch = 0;

void create()
{
    ::create();
    set_name("mound5");
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",1);
    set_short("%^RESET%^%^ORANGE%^A Well-Lit Passage%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^The tunnel ends here with a large wooden door blocking off the tunnel to"+
		" the north. An %^BOLD%^%^RED%^alcove %^RESET%^%^ORANGE%^rests in the eastern portion of the wall"+
		" and seems to not be naturally made. The floor is made up of hard packed dirt. There are far fewer claw"+
		" marks here, as if it is not as well-travelled as other areas in the lair. Oddly,"+
		" %^BOLD%^%^YELLOW%^torches %^RESET%^%^ORANGE%^sit outside the door, which are not seen anywhere"+
		" else in the lair at this point. \n\n%^BOLD%^%^CYAN%^The tunnel ends here, stopped by the door"+
		" to the north or having to proceed back to the southwest.");

    set_smell("default","\n%^BOLD%^%^BLACK%^The smell of rotting foods begins to disappear here.%^RESET%^");
    set_listen("default","%^RESET%^%^RED%^You the faint sounds of barking and yelping in the halls.%^RESET%^");

    set_exits(([
		"southwest"	: MOUND"mound4",
		"north"	: MOUND"mound6"
	]));
	set_door("large wooden door","/d/antioch/greaterantioch/rooms/mound/mound6","north","somekey");
	set_door("trap door","/d/antioch/greaterantioch/rooms/mound/tunnel1","up",0);
	set_open("large wooden door",0);
	set_lock_description("door","lock","This is a fairly ineffective lock.");
    set_door_description("door","This large wooden door is fairly worn, with rot obvious along the edges.");
    lock_difficulty("gate",-2000,"lock");
    set_items(([
      "alcove" : "%^BOLD%^%^BLACK%^The alcove has a tight curve to it, hiding its contents from view.",
      "torches" : "%^BOLD%^%^YELLOW%^The torches here light this portion of the tunnel well.",
   ]) );
   set_search("default","%^BOLD%^%^YELLOW%^What do you want to search?");
   set_search("alcove",(:TO,"searching":));
}

void searching() {
    if (time() - lastsearch < 4) {
        write("%^BOLD%^%^BLACK%^You are still searching!");
        return;
    }
    write("%^BOLD%^%^BLACK%^You move into the alcove to search it and something leaps out and attacks you!");
    tell_room(TO,"%^BOLD%^%^BLACK%^"+TPQCN+" searches the alcove and then jumps back as they are attacked!",TP);
    lastsearch = time();
    new(MON+"gnollthief")->move(TO);
}

void init()
{
	::init();
	add_action("OpenDoor","open");
	add_action("CloseDoor","close");
}

void OpenDoor(string str){

	if(str == "large wooden door") {
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
	if(str == "large wooden door") {
		if(!doors[str]["open"]) {
			notify_fail("The large wooden door is already closed!\n");
			return 0;
		}
		tell_object(TP,"%^RESET%^%^ORANGE%^The door creaks as you shut the door.\n");
		tell_room(ETP,""+TP->query_cap_name()+" closes the wooden door.\n",TP);
		doors[str]["destination"]->set_open(str,0);
		set_open(str,0);
		tell_room(doors[str]["destination"],"The large wooden door is closed by"+
		" someone on the other side.");
		return 1;
	}
	return ::CloseDoor();
}
