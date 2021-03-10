#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>

inherit VAULT;
object ob;

void create()
{
    ::create();
    set_name("village1");
    set_property("outdoors",1);
    set_property("light",1);
    set_short("%^RESET%^%^CYAN%^A small hamlet%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^Before you is a two-story house with white-washed wood planking and mixed"+
             " %^RESET%^%^RED%^mu%^BOLD%^%^YELLOW%^lt%^RESET%^%^RED%^i %^BOLD%^%^WHITE%^colored %^BOLD%^%^RED%^masonry"+
             " %^BOLD%^%^WHITE%^set in its base. Dark wooden planks form two large 'V's"+
             " across the front of the house, underarching %^BOLD%^%^YELLOW%^windows%^BOLD%^%^WHITE%^. A"+
             " small %^RESET%^%^GREEN%^path %^BOLD%^%^WHITE%^winds its way through a well-groomed"+
             " grass yard to a heavy oak door in the front. All"+
             " around this house are small %^BOLD%^%^YELLOW%^pens %^BOLD%^%^WHITE%^which have fences around them.");

    set_smell("default","\n%^BOLD%^%^YELLOW%^The smell of burning logs is noticeable here.%^RESET%^");
    set_listen("default","%^RESET%^%^RED%^You hear the sounds of dogs, chickens, and small chatter throughout this small area.%^RESET%^");

    set_exits(([
        "enter"  : HAMLET"merchanthouse1",
		"north"	: ROAD"road7",
	]));
	set_door("wooden door","/realms/klieth/greaterantioch/rooms/village/merchanthouse1","enter","somekey");
	set_open("wooden door",0);
	set_lock_description("door","lock","This is a fairly ineffective lock.");
    set_door_description("door","This large wooden door is fairly worn, with rot obvious along the edges.");
    lock_difficulty("gate",-2000,"lock");
    set_items(([
      "windows" : "%^BOLD%^%^WHITE%^The windows are high up, climbing would likely not be easy.",
      "path" : "%^RESET%^%^ORANGE%^The cobblestone path looks well kept.",
      "masonry" : "%^BOLD%^%^YELLOW%^The stonework here is exceptional. It looks like great care, and expense, was put into the creation of this home.",
      "pens"    : "%^BOLD%^%^GREEN%^The pens here are full of %^BOLD%^%^RED%^chickens %^BOLD%^%^GREEN%^and %^BOLD%^%^RED%^pigs %^BOLD%^%^GREEN%^which is obviously"+
                  " used for food at this location. You wonder how they survive unmolsested in a remote area like this.",
   ]) );
set_post_exit_functions(({"enter"}),({"GoThroughDoortest"}));
}

int GoThroughDoortest() {
object room;
  if(member_array("%^BOLD%^%^CYAN%^Rescued the Missing Wife%^RESET%^",TP->query_mini_quests())!=-1)  {
   if(TP->query_paralyzed() || TP->query_bound() ||
TP->query_unconscious()){
    return 0;
    }
    	room = find_object_or_load(HAMLET"merchanthouse1");
        if (present("gorge",room)){
        return 1;}
         else {
		new(MON"gorgemerchant")->move(room);}
    return 1;
    }
  else {
  if(member_array("%^BOLD%^%^CYAN%^Dispatch the Murderer%^RESET%^",TP->query_mini_quests())!=-1)  {
   if(TP->query_paralyzed() || TP->query_bound() ||
   TP->query_unconscious()){
   return 0;
    }
	write("%^BOLD%^%^MAGENTA%^You hear a female screaming in desperation from upstairs!");
    return 1;
  }
    else {
	room = find_object_or_load(HAMLET"merchanthouse1");
        if (present("faris",room)){
        return 1;}
         else {
		new(MON"farismerchant")->move(room);}
    return 1;
}
 }
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
