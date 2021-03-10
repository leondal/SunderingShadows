// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("gdungeon");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Horrid %^BOLD%^%^GREEN%^D%^BLACK%^u%^GREEN%^n%^BLACK%^g%^GREEN%^e%^BLACK%^o%^GREEN%^n%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This dungeon is little more than a %^RESET%^%^RED%^brick%^BOLD%^%^BLACK%^ square room with a %^RESET%^%^ORANGE%^rickety set%^BOLD%^%^BLACK%^ of %^RESET%^%^ORANGE%^stairs%^BOLD%^%^BLAC"
	"K%^ going up in one corner. %^CYAN%^Shackles%^BLACK%^ line the walls, and skeletal bones hang from the chains, a %^BOLD%^%^RED%^g%^RESET%^%^RED%^r%^BOLD%^i%^RESET%^%^RED%^m%^BOLD%^%^BLACK%^ reminder o"
	"f the fate that awaits prisoners here. The floor is damp with some kind of %^GREEN%^disgusting fluid%^BLACK%^. Rats have the run of the place, and it is an open question whether prisoners dine on rats"
	", or the rats on the prisoners.%^RESET%^"
	);

    set_smell("default","
It smells of urine and decaying corpses.");
    set_listen("default","The scurrying or rats echos through this dank chamber.");

    set_search("skeletons","The skeletons might have had finery but nothing has lasted that is of any value.");
    set_search("floor","Searching through the muck is useless, and quite disgusting. All the sewage goes through the grate eventually.");
    set_search("skeleton","The skeletons might have had finery but nothing has lasted that is of any value.");
    set_search("bones","The skeletons might have had finery but nothing has lasted that is of any value.");
    set_search("grate","The grate looks a little flimsy, perhaps you could squeeze through <grate> if you wanted.");
    
set_items(([ 
	"floor" : "The floor is disgusting with human waste, rats, urine, and decaying corpses all sliding down the drain.",
	"ceiling" : "The ceiling is a crumbly looking brick, but it has held up well enough over the years.",
	"shackles" : "The shackles look plenty weak with rust. Of course the prisoners who hang here now, or the bones of those who were here, did not have the strength to free themselves. Doubtless they were badly beaten before getting left in the prison to rot.",
	"walls" : "The walls are a crumbly looking brick, but it has held up well enough over the years.",
	"stairs" : "The stairs have no guard rail and lead straight up to freedom, or at the very least, fresh air.",
	"drain" : "The drain is covered by a grate.",
	"stair" : "The stairs have no guard rail and lead straight up to freedom, or at the very least, fresh air.",
	"bones" : "The bones look to be human, and well chewed on by the rats.",
	"grate" : "The grate looks very flimsy, perhaps you could take a closer look?",
	"sewage" : "Nasty!!!",
	"rats" : "Many look small and rather undernourished. Perhaps there hasn't been a dying prisoner in a while?",
	]));

    set_exits(([ 
		"grate" : "/d/av_rooms/myrkul/tunnel2",
	]));



    set_invis_exits(({ "grate" }));

}