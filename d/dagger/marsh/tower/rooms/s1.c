#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;

void init() {
::init();
add_action("fly_fun","fly");
add_action("climb_fun","climb");
}


void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no teleport",1);
set_short("%^BLUE%^The Shadowland");
    set_long("%^CYAN%^"
	"The strange %^GREEN%^land%^CYAN%^ before you is extremely hard "
	"to see clearly due to the swirling %^MAGENTA%^mist%^CYAN%^ "
	"and numerous "
	"%^BLUE%^shadowy shapes%^CYAN%^ which surround you. Things "
	"seem to come into focus then "
	"fade away again. Moving %^BLUE%^shadows%^CYAN%^ "
	"roam and wander, swaying wildly in the "
	"howling %^ORANGE%^wind%^CYAN%^ in all directions. The %^ORANGE%^wind%^CYAN%^ "
	"never remains constant, it rises in tempo and shifts in "
	"direction with every heartbeat. The %^WHITE%^sky%^CYAN%^ is grey and filled with a "
	"%^MAGENTA%^smoky mist%^CYAN%^. %^BLUE%^Shadowy shapes%^CYAN%^ "
	"fly overhead in random "
	"erratic patterns. The two %^BOLD%^%^MAGENTA%^purple moons "
	"%^RESET%^%^CYAN%^fill the land with a faint eerie incandescent %^YELLOW%^light"
	"%^RESET%^%^CYAN%^.\n%^BOLD%^%^BLUE%^You stand at the base of a tall black tower.%^RESET%^"
    );
    set_listen("default",
        "The wind blows hard against your face, and a faint whispering coupled with a hollow moaning fills the mist."
    );
    set_smell("default",
        "There is a very foul and evil smell to this new land around you."
    );
    set_items(([
	"moon":"%^MAGENTA%^The two purple moons are very eerie to gaze upon and light the area with an "
	"incandescent glow.%^RESET%^",
 	"land":"You would have to enter the %^BLUE%^Shadowland%^RESET%^ to examine "
	"it closer.",
	"moons":"%^MAGENTA%^The two purple moons are very eerie to gaze upon and light the area with an "
	"incandescent glow.%^RESET%^",
	"shadows":"%^BLUE%^The shadows fill the land below and dance and stir in the wind.",
	"shapes":"%^CYAN%^The shapes move around you occasionally and are hard to make out. Every now and "
	"then a shadowy shape flies overhead.",
	"wall":"The outer tower wall looks climbable if you had some climbing tools.",
    ]));
    set_exits(([
        "north": RPATH "s2",
    ]));
    set_pre_exit_functions(({"north"}),({"exita_fun"}));
}
int exita_fun() {
    write(
        "%^BLUE%^You slowly wander through the mist and walk among the shadows."	
    );
    say(
 	"%^BLUE%^"+TPQCN+" slowly wanders through the mist and walks among the shadows."
    ,TP);
    return 1;
}
int fly_fun(string str) {
    if(!str) {
	notify_fail("Fly where?\n");
	return 0;
    }
    if(str != "up") {
	notify_fail("Fly where?\n");
	return 0;
    }
    if(TP->query_property("demongate flying") == 0) {
	notify_fail("You can't fly...your not a bird are you???\n");
	return 0;
    }
    write(
        "%^CYAN%^You slowly fly up the side of the tower.%^RESET%^"
    );
    say(
	"%^CYAN%^"+TPQCN+" slowly flys up the side of the tower.%^RESET%^"
    ,TP);
    TP->move_player( RPATH "drop4.c","flying in the air");
    return 1;
}
int climb_fun(string str) {
    int success;
    if(!str) {
	notify_fail("Climb where?\n");
	return 0;
    }
    if(str != "up") {
	notify_fail("Climb where?\n");
	return 0;
    }
    if(!present("climbing tools",TP)) {
	notify_fail("You have nothing to climb with!\n");
	return 0;
    }
    write(
        "%^CYAN%^You slowly begin to climb up the side of the tower.%^RESET%^"
    );
    say(
	"%^CYAN%^"+TPQCN+" utilizes some climbing tools and begins to "
	"climb up the side of the tower.%^RESET%^"
    ,TP);
if(TP->is_class("thief")) {
        success = random(100);
    } else {
 	success = random(10);
    }
    if(success < 1) {
	write("You make a mistake climbing and begin fall...");
	say(""+TPQCN+" makes a mistake climbing and begins to fall...",TP);
	write("You hit the cold hard ground with a dull thud!");
        TP->do_damage("torso",random(10)+10);
	return 1;
    } else {
	    write("You succeed in climbing ten feet or so up the tower's outer wall.");
	    TP->move_player( RPATH "drop4.c","climbing up the tower wall");
	    return 1;
    }
}

  
