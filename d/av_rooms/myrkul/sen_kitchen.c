// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sen_kitchen");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Guard Barracks Kitchen, %^CYAN%^S%^RESET%^%^CYAN%^e%^BOLD%^neca%^RESET%^");

    set_long("%^YELLOW%^Pots, %^BLACK%^pans%^RESET%^, and %^BOLD%^%^CYAN%^c%^RESET%^%^CYAN%^o%^BOLD%^oking %^RED%^fires%^RESET%^ fill the kitchen of the %^BOLD%^%^WHITE%^Seneca Guards%^RESET%^. There is enough food"
	" here to feed an army -- which it does. Sacks of potatoes are peeled in the back, usually as punnishment, with the peelings dropped down a large %^BOLD%^%^CYAN%^drain%^RESET%^. "
	);

    set_smell("default","
It smells like potatoes and cooking stew.");
    set_listen("default","You hear water boiling and the clanking of pots and pans.");

    set_search("drain","The drains are large enough to actually climb down here.");
    
set_items(([ 
	"drain" : "The drain is very large pipe where kitchen refuse can be poored down into the sewers. ",
	"pans" : "There appears to be some stew getting cooked here.",
	"pots" : "There appears to be some stew getting cooked here.",
	]));

    set_exits(([ 
		"down" : "/d/av_rooms/myrkul/sen_sewer4",
		"east" : "/d/attaya/newseneca/rooms/barracks_dining",
	]));

    set_door("lid","/d/av_rooms/myrkul/sen_sewer4","down");
    set_open("lid",0);
    set_string("lid","knock","knocks on the");
    set_string("lid","open","The lid clanks open.");
    set_string("lid","close","The lid clanks closed.");
    set_door_description("lid","This lid is a floor drain cover.");
}