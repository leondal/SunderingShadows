// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("arena_09");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^A Hidden Compartment%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^You scramble through the crawlspace provided by the %^RESET%^%^ORANGE%^plaque %^BOLD%^%^BLACK%^and find yourself in a cramped hidden compartment.  Here large %^RESET%^%^CYAN%^metal tu"
	"bes %^BOLD%^%^BLACK%^once held the water that supplied the wash room.  Piles of tubes and metal joints fill this place haphazardly, making it difficult to move or explore. %^RESET%^Dust %^BOLD%^%^BLAC"
	"K%^and %^RESET%^%^ORANGE%^grime%^BOLD%^%^BLACK%^ cover this chamber and the devices have not worked in some time.%^RESET%^"
	);

    set_smell("default","
Dust is thick here, as is the smell of rusty metal.");
    set_listen("default","You hear an occasional ping deep within the bowels of one of these devices.");

    
set_items(([ 
	({ "metal", "devices", "device" }) : "%^RESET%^%^CYAN%^There are three devices here.  Each one a little different then the next.  You could probably look at %^RESET%^device1%^CYAN%^, %^RESET%^device2 %^CYAN%^and %^RESET%^device3 %^CYAN%^if you were so inclined.%^RESET%^",
	"device2" : "%^CYAN%^This device is wide and tall, taking up most of the space of this room.  The pinging seems to come from deep within it, making you wonder if there isn't still water or something lurking inside.  A metal door is located on one side, but the rust is too thick to allow it to be opened.%^RESET%^",
	"instructions" : "%^BOLD%^%^WHITE%^Written upon the wall is some sort of writing.  At first you think they are instructions for the devices, but as you look at them closer you realize they have nothing to do with this area.  It looks like graffiti in fact.  Like someone carved it into the wall after this room was built.%^RESET%^",
	"device1" : "%^CYAN%^This device is squat and thickly built.  A large tube enters it from the top, while two smaller ones feed out into the other two devices through copper tubes.   Behind it you can see some writing on the wall, maybe instructions on how to use them.  Maybe you could look closer and read them.%^RESET%^",
	"device3" : "%^CYAN%^More a series of tubes, this device is comprised of a junction at each end which feeds into a dozen parallel tubes that ripple up and down over what appears to be a furnace of some sort.  The furnace is cold, but likely any water in those tubes would have been quite warm.%^RESET%^",
        "graffiti" : "%^BOLD%^%^BLACK%^You peer closely and try to make out what it says under all that dirt and grime.  What you can make out of the first line is mention about a beach under wooden planks.  The next line seems to have some references to a fire or fireplace.  It's really hard to figure it out, the wall is so dirty.  Maybe you could %^RESET%^clean the"
" wall%^BOLD%^%^BLACK%^ off and make out what it says, because this last one makes no sense at all.  A cliff wall on a shore?  What do all those have to do with each other?%^RESET%^",
	]));

    set_exits(([ 
		"out" : "/d/av_rooms/lurue/arena_07",
	]));

}

void init() {
   ::init();
   add_action("remove_stuff","clean");
}

int remove_stuff(string str) {
   if(!str) return notify_fail("What do you want to remove?\n");
   if(str != "the wall") return notify_fail("You can't clean that.\n");

   tell_room(TO,"%^BOLD%^%^CYAN%^"+TP->QCN+" begins to dust away at the wall, "
"wiping away dust and the words that were once written there!%^RESET%^",TP);
   tell_object(TP,"%^BOLD%^%^CYAN%^As you begin to dust away the grime and dust "
"that covers the wall and makes it difficult to read the words written there, "
"you notice that you're also wiping away the graffiti on the wall as well!");
   remove_item("graffiti");
   return 1;
}
