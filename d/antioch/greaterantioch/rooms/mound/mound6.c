#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>

inherit VAULT;
int items;

void create()
{
    items = 1;
    ::create();
    set_name("mound6");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_short("%^BOLD%^%^YELLOW%^A Back Office%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This room is significantly different then those previously seen within the"+
		" compound. The %^BOLD%^%^GREEN%^walls %^BOLD%^%^WHITE%^have been smoothed out and a large"+
		" sconce with candles is attached to the wall. A %^RESET%^%^ORANGE%^desk %^BOLD%^%^WHITE%^sits on the eastern wall"+
		" while a small %^RESET%^%^BLUE%^bed %^BOLD%^%^WHITE%^rests opposite. In the back of the room a"+
		" %^BOLD%^%^YELLOW%^bookshelf %^BOLD%^%^WHITE%^sits with a few books scattered about it.");

    set_smell("default","\n%^BOLD%^%^BLACK%^The subtle smell of sweat is observed here.%^RESET%^");
    set_listen("default","%^RESET%^%^RED%^You the faint sounds of barking and yelping in the halls.%^RESET%^");
    set_exits(([
		"south"	: MOUND"mound5",
		"up"	: MOUND"tunnel1"
	]));
	set_door("large wooden door","/d/antioch/greaterantioch/rooms/mound/mound5","south","somekey");
	set_door("trap door","/d/antioch/greaterantioch/rooms/mound/tunnel1","up",0);
	set_invis_exits(({"up"}));
	set_open("large wooden door",0);
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
    set_search("default",  (: TO, "searchroom" :) );
    set_search("desk",     (: TO, "searching" :) );
    set_search("bookshelf",(: TO, "searching" :) );
}

void searchroom()
{
    tell_object(TP,"%^BOLD%^%^YELLOW%^There are a few things here worth searching...pick one?");
    return;
}

void searching() {
   object ob;
   if(!items) {
      write("%^BOLD%^%^BLACK%^You find nothing.");
      return;
   }
   switch(random(10)){
      case 0..2:
        ob = new("/d/common/obj/potion/det_invis")->move(TO);
            tell_object(TP,"%^BOLD%^%^YELLOW%^You search carefully and find a potion!%^RESET%^");
            tell_room(ETP, "%^BOLD%^%^YELLOW%^"+TP->QCN+" searches around and finds something.%^RESET%^",TP);
            break;
      case 3..5:
        ob = new("/d/common/obj/potion/invisible")->move(TO);
            tell_object(TP,"%^BOLD%^%^YELLOW%^You search carefully and find a potion!%^RESET%^");
            tell_room(ETP, "%^BOLD%^%^YELLOW%^"+TP->QCN+" searches around and finds something.%^RESET%^",TP);
            break;
      case 6..9:
            ob = new("/d/magic/safe_scroll");
            if(!random(3))
            {
                ob = new("/d/magic/safe_scroll");
                ob->set_spell(random(3)+3);
                ob->move(TO);
            }
            ob->set_spell(random(3)+3);
            ob->move(TO);
            tell_object(TP,"%^BOLD%^%^BLUE%^You search carefully and find a scroll!%^RESET%^");
            tell_room(ETP, "%^BOLD%^%^BLUE%^"+TP->QCN+" searches around and finds something.%^RESET%^",TP);
            break;
      }
      items = 0;
      return;
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
	if(str == "trap door") {
		if(!doors[str]["open"]) {
			notify_fail("The trap door is already closed!\n");
			return 0;
		}
		tell_object(TP,"You reach up and close the trapdoor.\n");
		tell_room(ETP,""+TP->query_cap_name()+" closes the trap door.\n",TP);
		doors[str]["destination"]->set_open(str,0);
		set_open(str,0);
		tell_room(doors[str]["destination"],"The trap door is closed by"+
		" someone on the other side.\n");
		set_invis_exits(({"up"}));
		return 1;
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
