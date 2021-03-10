// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("t_camp");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("grasslands");
    set_travel("game track");
    set_climate("temperate");

    set_short("%^YELLOW%^Inside an %^RED%^Armed Camp%^RESET%^");

    set_long("This is the heart of the camp. There is a %^RESET%^%^ORANGE%^rough hewn dais%^RESET%^ in the center where some important person makes announcements and holds court. Before the dais and in the center o"
	"f the camp is a horrible %^BOLD%^%^RED%^pit%^RESET%^. Tents line the walls of the %^YELLOW%^pallisade%^RESET%^, leaving room in the middle for people to walk south to the Gate, west to some kind of %^"
	"GREEN%^pens%^RESET%^, and east to what appears to be %^CYAN%^kitchens%^RESET%^. Latrines are evidently outside the camp. Overall this appears to be a rather rough and tumble place, and hygiene is as g"
	"ood as it gets living outdoors. "
	);

    set_smell("default","
Something smells foul to the west, but better smells like food come from the east.");
    set_listen("default","You can hear camp sounds of people laughing, cursing, and drinking.");

    set_search("dais","The dais has a chair on it, but there isn't anything good on or around it. Whoever is in charge here must be smart enough to keep the good stuff on himself.");
    
set_items(([ 
	"dais" : "The dais is a platform made out of logs with a chair on it. Its not much, but serves the purpose of a military leader to get the attention of his troops.",
	"pens" : "Those looks like either pens for slaves or for keeping prisoners of war.",
	"kitchens" : "You can see smoke from a large camp-fire off to the east, and can smell something cooking. ",
	"pallisade" : "The wooden walls of the pallisade seem quite defensible and well-maintained for temporary structures.",
	"pit" : "That pit smells bad, and looks like anything up to the size of a horse could be thrown down inside. Worse yet, the cover is not serving the purpose to prevent people from falling in. It looks like it is keeping something from %^RED%^getting out!!!%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/myrkul/t_pens",
		"south" : "/d/av_rooms/myrkul/t_entrance",
		"east" : "/d/av_rooms/myrkul/t_kitchen",
		"pit" : "/d/av_rooms/myrkul/t_pit",
	]));

    set_door("spiked cover","/d/av_rooms/myrkul/t_pit","pit","pit key","bolt");
    add_lock("spiked cover","pit key","bolt","This is a heavy iron bolt with a rather uninspired lock.");
    set_locked("spiked cover",1,"bolt");
    lock_difficulty("spiked cover",-10,"bolt");
    set_open("spiked cover",0);
    set_string("spiked cover","knock","pounds desperately on the");
    set_string("spiked cover","open","The spiked cover squeals open.");
    set_string("spiked cover","close","The spiked cover squeals closed.");
    set_door_description("spiked cover","This is a heavy iron grate that covers the pit. It has spikes to keep whatever is down there inside.");
    set_door("Gate","/d/av_rooms/myrkul/t_entrance","south");
    set_open("Gate",0);
    set_string("Gate","knock","pounds on the");
    set_string("Gate","open","The gate swings open.");
    set_string("Gate","close","The gate swings closed");
    set_door_description("Gate","This gate is very large and bound with rope. It is hastily constructed.");
}