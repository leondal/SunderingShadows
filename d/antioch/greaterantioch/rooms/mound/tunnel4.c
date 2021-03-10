#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>

inherit VAULT;

int triggered, isrunning;
int do_boss(int mystate);
int is_running();

void create()
{
    ::create();
    set_name("mound1");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_short("%^RESET%^%^ORANGE%^Within a Mound%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^The tunnel here ends abruptly. The area is made similarly to the main preparation"+
            " room, however this is narrower as if some sort of hallway. The dirt on"+
            " the ground here looks disturbed and the area seems far less maintained then others in the area.");

    set_smell("default","\n%^BOLD%^%^BLACK%^The smell stench of old sweat here.%^RESET%^");
    set_listen("default","%^RESET%^%^RED%^You hear yips and barks from the arena nearby.%^RESET%^");

    set_exits(([
		"door"	: MOUND"mound8",
		"east"	: MOUND"mound13",
	]));
	set_door("secret door","/d/antioch/greaterantioch/rooms/mound/mound8","door",0);
    set_post_exit_functions(({"door"}),({"GoThroughDoor"}));
}

int GoThroughDoor() {
    object obj,key;
    if(query_verb() == "door") {
    if(obj=present("key",TP)){
    call_out("do_boss",1,0);
    return 0;}
    else;
    return 1;}
}

int do_boss(int mystate) {
   object thatroom;
   switch(mystate) {
     case 0:
       tell_room(TO,"%^BOLD%^%^RED%^%^As you walk of the area you, the male elf runs up to you.\n%^RESET%^");
     break;
     case 1:
       tell_room(TO,"%^BOLD%^%^YELLOW%^The male elf says%^BOLD%^%^CYAN%^'Why..why are you leaving them all locked in there?!'\n%^RESET%^");
     break;
     case 2:
       tell_room(TO,"%^BOLD%^%^YELLOW%^The male elf scowls angrily. %^BOLD%^%^WHITE%^'Fine. I will find another way to save them. Without you.'\n%^RESET%^");
     break;
     case 3:
       tell_room(TO,"%^BOLD%^%^CYAN%^Screams of terror and despair come from the cages within the hold, as you hear the secret door close - indefinately, behind you.\n%^RESET%^");
       TP->move(MOUND"mound8");
       if(member_array("%^BOLD%^%^CYAN%^Abandoned the Slaves",TP->query_mini_quests()) == -1) {
tell_object(TP,"%^CYAN%^You left the slaves to starve in their cages!%^RESET%^");
TP->set_mini_quest("Abandoned the Slaves",100500,"%^CYAN%^Abandoned the Slaves%^RESET%^");}
     break;
   }
   mystate++;
   call_out("do_boss",5,mystate);
   return 1;
   }

void init()
{
	::init();
	add_action("OpenDoor","open");
	add_action("CloseDoor","close");
}

void OpenDoor(string str)
{
	if(!str) return 0;
	if(str == "secret door") {
		if(doors[str]["open"]) {
			notify_fail("It is already open!\n");
			return 0;
		}
		else {
			tell_object(TP,"%^BOLD%^%^CYAN%^You push the secret door open.\n");
			tell_room(ETP,""+TP->query_cap_name()+" opens a secret door in the wall.\n",TP);
			doors[str]["destination"]->set_open(str,1);
			set_open(str,1);
			tell_room(doors[str]["destination"],"You notice the secret door"+
			" suddenly open from the other side.\n");
			remove_invis_exit("door");
			return 1;
		}
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
	if(str == "secret door") {
		if(!doors[str]["open"]) {
			notify_fail("The trap door is already closed!\n");
			return 0;
		}
		tell_object(TP,"%^BOLD%^%^CYAN%^You slide the secret door closed.\n");
		tell_room(ETP,""+TP->query_cap_name()+" closes the secret door.\n",TP);
		doors[str]["destination"]->set_open(str,0);
		set_open(str,0);
		tell_room(doors[str]["destination"],"The secret door is closed by"+
		" someone on the other side.\n");
		set_invis_exits(({"door"}));
		return 1;
	}
	return ::CloseDoor();
}

void reset_cinematics() { triggered = 0; }
int is_running() { return isrunning; }

