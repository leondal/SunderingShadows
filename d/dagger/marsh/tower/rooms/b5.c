#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;
int LEVER;

void init() {
    ::init();
    add_action("look_fun","look");
    add_action("pull_fun","pull");
    add_action("pour_fun","pour");
}
void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
	"The small and narrow chamber is made of the same %^BOLD%^"
	"blood-red%^RESET%^%^RED%^ stone as seen in other parts of the tower. "
	"The stone calls out to you as though it is alive and held captive in "
	"an endless state of torment. The room is quite bare except for a large "
	"%^BLUE%^vat of substance%^RED%^ set into a %^ORANGE%^rack%^RED%^ "
	"beside an %^CYAN%^opening%^RED%^ in the floor of the room. A %^GREEN%^steel "
	"funnel%^RED%^ inset in the ceiling hangs above the %^BLUE%^vat%^RED%^. "
	"Upon the north wall is located a %^ORANGE%^small lever%^RED%^."  
	"%^RESET%^" 
    );
    set_short("%^RED%^Tower Room%^RESET%^");
    set_listen("default",
        "The floor creaks as you walk on it."
    );
    set_smell("default",
        "The smell of oil fills the room."
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
	"material and seems to glow in it's blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
	"funnel":"The strange funnel has an opening located directly above the "
	"vat.",
	"opening":"The opening leads down into the darkness.",
	"rack":"The rack allows the vat's substance to be poured through the opening "
	"in the floor.",
	"substance":"The substance seems to be oil.", 
    ]));
    set_exits(([
        "down": RPATH "a12",
	"northwest": RPATH "b2",

    ]));
    set_pre_exit_functions(({"northwest"}),({"exitb_fun"}));
    set_pre_exit_functions(({"down"}),({"exitb_fun"}));
}
int exita_fun() {
    if(present("vampyre")) {
        write("The vampyre blocks your way!\n");
        return 0;
    }
    write(
	"%^BLUE%^You jump down through the hole and land in the room below.%^RESET%^"
    );
    say(
	"%^BLUE%^"+TPQCN+" jumps through the hole in the floor!%^RESET%^"
    ,TP);
    return 1;
}
int exitb_fun() {
   if(present("vampyre")) {
        write(
	    "%^BOLD%^%^RED%^Vampyre shouts: Run in fear, "+TPQCN+" you maggot child!%^RESET%^"
	    "\n%^RED%^Vampyre swipes you across the back with his claws as you flee!%^RESET%^"
	);
	say(
	    "%^BOLD%^%^RED%^Vampyre tells you: %^RESET%^You would be wise to "
	    "flee as "+TPQCN+" the maggot child just did!"
	,TP);
	TP->do_damage(TP->return_target_limb(),random(40));
        return 1;
    }
    return 1;
}
int look_fun(string str) {
    if(!str) {
	notify_fail("Look what?\n");
	return 0;
    }
    if(str != "lever" && str != "vat") {
	notify_fail("look what?\n");
	return 0;
    }
    if(str == "lever") {
        if(LEVER == 0) {
	    write(
	        "%^ORANGE%^The lever on the wall is in the upright position.%^RESET%^"
 	    );
	    say(
		"%^ORANGE%^"+TPQCN+" looks over the lever."
	    ,TP);
	    return 1;
	} else {
            write(
	        "%^ORANGE%^The lever on the wall is in the down position.%^RESET%^"
 	    );
	    say(
		"%^ORANGE%^"+TPQCN+" looks over the lever."
	    ,TP);
	    return 1;
	}
    }
    if(str == "vat") {
       if(LEVER == 1) {
	    write(
	        "%^ORANGE%^The vat stands full of oil.%^RESET%^"
 	    );
	    say(
		"%^ORANGE%^"+TPQCN+" looks over the vat."
	    ,TP);
	    return 1;
	} else {
            write(
	        "%^ORANGE%^The vat is empty and has been tilted over as if someone poured "
	        "it's contents through the opening in the floor.%^RESET%^"
 	    );
	    say(
		"%^ORANGE%^"+TPQCN+" looks over the vat."
	    ,TP);
	    return 1;
	}
    }
}
int pull_fun(string str) {
    if(!str) {
	notify_fail("Pull what?\n");
	return 0;
    }
    if(str != "lever") {
	notify_fail("Pull what?\n");
	return 0;
    }
    if(LEVER != 0) {
	notify_fail("The lever has already been pulled!\n");
	return 0;
    }
    write("%^ORANGE%^"
	"You pull the lever!\nThe vat slowly turns upright.\n%^RED%^Flaming "
	"oil pours out of the funnel and fills the vat!"
    );
    say("%^ORANGE%^"
	+TPQCN+" pulls the lever!\nThe vat slowly turns upright.\n%^RED%^Flaming "
	"oil pours out of the funnel and fills the vat!"
    ,TP);
    LEVER = 1;
    return 1;
}
int pour_fun(string str) {
    int num_p,x;
    object *players;
    object sucker;
    object here;
    string PLACE;
    if(!str) {
	notify_fail("Pour what?\n");
	return 0;
    }
    if(str != "vat") {
	notify_fail("Pour what?\n");
	return 0;
    }
    if(LEVER != 1) {
	notify_fail("The vat is empty and has been poured already!\n");
	return 0;
    }    
    write("%^ORANGE%^You tilt the vat of %^RED%^flaming oil%^ORANGE%^ and the "
	"%^RED%^oil%^ORANGE%^ flows through the opening in the floor!%^RESET%^"
    );
    say("%^ORANGE%^"+TPQCN+" tilts the vat of %^RED%^flaming oil%^ORANGE%^ and the "
	"%^RED%^oil%^ORANGE%^ flows through the opening in the floor!%^RESET%^"
    ,TP);
    LEVER = 0;
    PLACE = "down";
    here = environment(TP)->query_exit(PLACE);
    here = find_object_or_load(here);
    message("info",
        "%^BOLD%^%^RED%^Suddenly, flaming oil comes pouring down through "
	"the hole in the ceiling!%^RESET%^"
    ,here);
    players=all_inventory(here);
    num_p=sizeof(players);
    for(x=0;x<num_p;x++) {
        sucker=players[x];
        if((living(sucker)) && 
        (string)sucker->query_name() != "vampyre") {
        tell_object(sucker,
            "%^RED%^The flaming oil covers your body burning you badly!%^RESET%^"
        );
        tell_room(environment(sucker),
            "%^RED%^"+sucker->query_cap_name()+
            " screams out as flaming oil covers "
	    +sucker->query_possessive()+
	    " body!%^RESET%^"
        ,sucker);
            if((string)sucker->query_name() == "bat") {
	        sucker->remove();
	    } else {
                sucker->do_damage(sucker->return_target_limb(),roll_dice(4,6));
            }
        }
    }
    return 1;
}
    	