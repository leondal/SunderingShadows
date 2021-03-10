#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>

inherit VAULT;
object ob;

int items;

void create()
{
    ::create();
    set_name("merchanthouse1");
    set_property("indoors",1);
    set_property("light",3);
    set_short("%^RESET%^%^CYAN%^A Large House%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This large room is the first story of this well-made and fairly large house."+
             " The room is adorned with various %^BOLD%^%^CYAN%^items %^BOLD%^%^WHITE%^across shelves lining the walls."+
             " A large counter sits on the right side of the room, which is made of heavy oak."+
             " This room is obviously made up to be a shop, however, a set of %^BOLD%^%^YELLOW%^stairs"+
             " %^BOLD%^%^WHITE%^leads up to what is obviously the live-in area of this house. The floor is covered by"+
             " a large %^RESET%^%^ORANGE%^bear rug %^BOLD%^%^WHITE%^which gives it, along with many other decorations,"+
             " an all around rustic feel.");

    set_smell("default","\n%^BOLD%^%^YELLOW%^The smell of burning logs is noticeable here.%^RESET%^");
    set_listen("default","%^RESET%^%^RED%^You hear the sounds of dogs, chickens, and small chatter throughout this small area.%^RESET%^");
    set_items(([
      "items" : "%^BOLD%^%^CYAN%^There are numerous jars, sacks, pouchs, rations, and other things lining the shelves on the wall. Perhaps if noone is looking you could %^BOLD%^%^RED%^search %^BOLD%^%^CYAN%^them.",
      "stairs" : "%^RESET%^%^GREEN%^These stairs are made of wood but have a soft carpet covering them for ease of step.",
      "bear rug" : "%^RESET%^%^ORANGE%^The heavy bear rug is obviously taken from a massive bear. It's %^BOLD%^%^WHITE%^fangs %^RESET%^%^ORANGE%^are bare and looks quite intimidating.",
    ]));
    set_exits(([
        "out"  : HAMLET"village1",
		"stairs"	: HAMLET"merchanthouse2",
	]));
	set_door("wooden door","/realms/klieth/greaterantioch/rooms/village/merchanthouse1","out","somekey");
	set_open("wooden door",0);
	set_lock_description("door","lock","This is a fairly ineffective lock.");
    set_door_description("door","This large wooden door is fairly worn, with rot obvious along the edges.");
    lock_difficulty("gate",-2000,"lock");
    items=1;
    set_search("items", (: TO, "searching" :) );
    set_pre_exit_functions(({"stairs"}),({"GoThroughDoor"}));
}

void searching() {
    object ob;

    if(present("faris")){
        write("You're pretty sure the merchant would not really allow you to get over there.");
        return;}
    if(present("gorge")){
        write("You're pretty sure the merchant would not really allow you to get over there.");
        return;}
    if(!items){
        write("Ah, looks like someone robbed the place before you got here! Tough luck.");
        return;}

    tell_object(TP,"%^BOLD%^%^RED%^You climb over the counter, move over to the shelves, and gain access to the things on the shelves.");
    tell_room(ETP,""+TP->query_cap_name()+" climbs over the counter, gaining access to the things on the shelves.\n",TP);
    ob = new("/d/common/obj/misc/backpack.c")->move(TO);
    ob = new("/d/common/obj/misc/bandoleer.c")->move(TO);
    ob = new("/d/common/obj/misc/canvas.c")->move(TO);
    ob = new("/d/common/obj/misc/climb_tool.c")->move(TO);
    ob = new("/d/common/obj/misc/lantern.c")->move(TO);
    ob = new("/d/common/obj/misc/flint.c")->move(TO);
    ob = new("/d/common/obj/misc/lantern.c")->move(TO);
    ob = new("/d/common/obj/misc/sbasket.c")->move(TO);
    ob = new("/d/common/obj/misc/oil.c")->move(TO);
    ob = new("/d/common/obj/misc/pipe.c")->move(TO);
    items= 0;
    return;}


void init(){
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
		return 1;
	}
	return ::CloseDoor();
}


int GoThroughDoor(){
     if(query_verb() == "out") {
            return 1;}

    if(query_verb() == "stairs") {
    if(member_array("%^BOLD%^%^CYAN%^Rescued the Missing Wife%^RESET%^",TP->query_mini_quests())!=-1){
        write("You do not really find the need to go up there at this time.");
        return 0;}
        else;{
    if(member_array("%^BOLD%^%^CYAN%^Dispatch the Murderer%^RESET%^",TP->query_mini_quests())!=-1){
    write("You proceed up the stairs.");
            return 1;}
        else;{
    write("You do not really find the need to go up there at this time.");
            return 0;}
        }}}

