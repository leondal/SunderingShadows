// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void init() {
    ::init();
    add_action("squeeze_func", "squeeze");
}

void create()
{
    ::create();
    set_name("maze_out");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^RESET%^%^BLUE%^A dark underground corridor%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This underground corridor twists and turns in on itself, creating passages that lead in every direction but the one you need.  %^RESET%^%^BLUE%^Dark %^BOLD%^%^BLACK%^and %^RESET%^%^CY"
	"AN%^dank%^BOLD%^%^BLACK%^, the brick and mortar walls are rounded into a dome at the ceiling only a few feet above your head.  The floor is lost in an endless %^RESET%^%^GREEN%^swamp %^BOLD%^%^BLACK%^"
	"of old, stagnate %^RESET%^%^BLUE%^water %^BOLD%^%^BLACK%^that smells of %^RESET%^%^CYAN%^rot %^BOLD%^%^BLACK%^and %^RESET%^%^GREEN%^worse %^BOLD%^%^BLACK%^things.  An occasional %^RESET%^%^RED%^red ey"
	"ed %^BOLD%^%^BLACK%^rat pokes its nose out at you from a crevice in the wall, but quickly scampers off, leaving you to your own devices.%^RESET%^"
	);

    set_smell("default","
A horrific smell pervades this tunnel.");
    set_listen("default","You can hear water dripping and rats squeaking.");

    set_search("ceiling","%^RESET%^%^ORANGE%^You carefully feel along the ceiling of the brick wall and discover a spot where a chunk of brick is missing. Looking closer you notice that the ceiling is cleverly made to disguise a hidden shelf.  One you might be able to squeeze up onto.");
    set_search("water","%^RESET%^%^ORANGE%^ You search around in the scummy water and pull up a chunk of brickwork.  Wonder where it could have come from, maybe you should search the ceiling.%^RESET%^");
    
set_items(([ 
	({ "crevice", "rat", "red eyes", "red eyed rat", "rats" }) : "%^BOLD%^%^BLACK%^You can hear them more then see them, but every now and again a little black creature will poke its head out of a grate or hole in the wall to look about, vanishing as soon as it notices you nearby.%^RESET%^",
	({ "rot", "water", "things" }) : "%^BOLD%^%^BLUE%^You peer down into the muck that covers your feet and wonder what might be down there worth finding.  Searching might come up with something interesting, but likely whatever it is will be foul and horrible.%^RESET%^",
	({ "bricks", "brick walls", "mortar" }) : "%^BOLD%^%^BLACK%^Thankfully the bricks here seem to be in good enough repair that you don't fear they'll collapse any time soon.  You'd almost call it dwarven work, but would a dwarf make such an horrible maze such as this?%^RESET%^",
	"ceiling" : "%^RESET%^%^ORANGE%^You carefully feel along the ceiling of the brick wall and discover a spot where a chunk of brick is missing. Looking closer you notice that the ceiling is cleverly made to disguise a hidden shelf.  One you might be able to squeeze up onto.",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/maze_in",
		"northeast" : "/d/av_rooms/lurue/maze_a3",
		"ledge" : "/d/av_rooms/lurue/lich_01",
	]));



    set_invis_exits(({ "ledge" }));
}

int squeeze_func(string str) {
    if(!str) {
        tell_object(TP,"Squeeze into what?");
    return 1;
    }
    if((str == "onto shelf") || (str == "shelf") || (str == "onto ledge") || (str == "ledge")){
            tell_object(TP,"%^RESET%^%^ORANGE%^You pull yourself up onto the shelf%^RESET%^ \n");
            tell_room(ETP,"%^RESET%^%^ORANGE%^"+TPQCN+"%^RESET%^%^ORANGE%^ Pulls themselves up onto the shelf!\n",TP);
            TP->move_player("/d/av_rooms/lurue/lich_01");
    return 1;
    }
        tell_object(TP,"Squeeze into what?");
    return 1;
}