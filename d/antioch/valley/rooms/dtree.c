#include <std.h>
#include "../valley.h"
inherit ROOM;

void create()
{
        ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(FOOT_PATH);
        set_property("outside", 2);
        set_property("light",3);
        set_short("A tree");
        set_long(
        "%^RESET%^%^BLUE%^A large %^GREEN%^tree%^RESET%^%^BLUE%^ is growing right in the middle of"+
        " the path and it looks as though woodsmen tried"+
        " and failed to chop it down. The tree stretches"+
        " up high into the %^BOLD%^sky%^RESET%^%^BLUE%^, towering over everything"+
        " in the area. It appears to be some sort of elm"+
        " that has thick %^ORANGE%^branches%^RESET%^%^BLUE%^ that would most certainly"+
        " be able to support your weight."
        );
        set_smell("default",
        "You smell the faint scent of pine."
        );
        set_listen("default",
        "You hear a few birds chirping from above."
        );
        set_items( ([
        "trail" : "The trail ends at the tree, the forest"+
        " is too close about to continue further.",
        "elm" : "This elm tree looks like it would be easy"
        " to climb.",
        "tree" : "This is an elm tree.",
        ]) );
        set_exits( ([
        "northwest" : ROOMS+"dt17",
        ]) );
}

void init()
{
        ::init();
        add_action("climb", "climb");
}

int climb(string str)
{
	if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
        if(!str) {
                write("Climb what?");
                return 1;
        }
        if(str != "tree" && str != "elm") {
                write("The only thing to climb here is a tree.");
                return 1;
        }
        else {
                write("%^GREEN%^You grasp the lower branches and"+
                " begin to climb up the tree.");
                say(
                "%^GREEN%^"+TP->query_cap_name()+" grasps the"+
                " tree's lower branches and begins to climb.");
                this_player()->move_player(ROOMS+"tree1");
                return 1;
        }
}
