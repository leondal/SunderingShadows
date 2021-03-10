// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("t_pit");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^Inside a %^BOLD%^%^RED%^Festering%^GREEN%^ Pit!%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^You stand knee deep in %^CYAN%^stagnant water%^RESET%^%^ORANGE%^ and %^YELLOW%^filth%^RESET%^%^ORANGE%^ in a %^GREEN%^disgusting%^ORANGE%^ pit. The walls are slick, and sheer. %^BOL"
	"D%^%^WHITE%^Fractured bones%^RESET%^%^ORANGE%^ stick out of the water, and you can swear you can feel the %^BOLD%^%^RED%^evil%^RESET%^%^ORANGE%^ that lives down here just waiting to %^BOLD%^%^RED%^fea"
	"st%^RESET%^%^ORANGE%^ on you, body and soul!%^RESET%^ "
	);

    set_smell("default","
It smells like filth and death!");
    set_listen("default","Something splashes just a little bit -- what could be in the water??");

    set_search("bones","Something has definately chewed on these bones. ");
    set_search("water","%^BOLD%^%^CYAN%^You reach into the water... %^RED%^And you swear something grasped at your hand!!%^YELLOW%^ What the hell is this place?!%^RESET%^");
    
set_items(([ 
	"dais" : "The dais is a platform made out of logs with a chair on it. Its not much, but serves the purpose of a military leader to get the attention of his troops.",
	"pens" : "Those looks like either pens for slaves or for keeping prisoners of war.",
	"kitchens" : "You can see smoke from a large camp-fire off to the east, and can smell something cooking. ",
	"bones" : "The bones look like they come from humans. Theres some scraps of clothing -- the garb of commoners.",
	"walls" : "You might be able to go back up. The only trouble will be that damn cover.",
	"water" : "The water moves every so often.. something might be lurking down here!",
	"pit" : "That pit smells bad, and looks like anything up to the size of a horse could be thrown down inside. Worse yet, the cover is not serving the purpose to prevent people from falling in. It looks like it is keeping something from %^RED%^getting out!!!%^RESET%^",
	"pallisade" : "The wooden walls of the pallisade seem quite defensible and well-maintained for temporary structures.",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/myrkul/t_camp",
	]));

    set_door("Gate","/d/av_rooms/myrkul/t_entrance","south");
    set_open("Gate",0);
    set_string("Gate","knock","pounds on the");
    set_string("Gate","open","The gate swings open.");
    set_string("Gate","close","The gate swings closed");
    set_door_description("Gate","This gate is very large and bound with rope. It is hastily constructed.");
    set_door("spiked cover","/d/av_rooms/myrkul/t_camp","up","pit key","bolt");
    add_lock("spiked cover","pit key","bolt","This is a heavy iron bolt with a rather uninspired lock.");
    set_locked("spiked cover",1,"bolt");
    lock_difficulty("spiked cover",-10,"bolt");
    set_open("spiked cover",0);
    set_string("spiked cover","knock","pounds desperately on the");
    set_string("spiked cover","open","The spiked cover squeals open.");
    set_string("spiked cover","close","The spiked cover squeals closed.");
    set_door_description("spiked cover","This is a heavy iron grate that covers the pit. It has spikes to keep whatever is down there inside.");
}