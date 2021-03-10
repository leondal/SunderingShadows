#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;
void init() {
    ::init();
    add_action("swing_fun","swing");
} 	
void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
	"The small and narrow hallway is made of the same %^BOLD%^"
	"blood-red%^RESET%^%^RED%^ stone as seen in other parts of the tower. "
	"The stone calls out to you as though it is alive and held captive in "
	"an endless state of torment. This part of the hallway is quite bare "
	"and and long strands of %^CYAN%^cobwebs%^RED%^ hang from the ceiling. "
	"Hanging from a hook on the wall is a long %^ORANGE%^rope%^RED%^. The rope "
	"disappears to the south, and up into the darkness."
	"%^RESET%^"
    ); 
    set_short("%^RED%^Tower Hallway%^RESET%^");
    set_listen("default",
        "A low cold howl rises from the south."
    );
    set_smell("default",
        "The air reeks of old mandrake."
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
	"material and seems to glow in it's blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
	"cobwebs":"%^CYAN%^The cobwebs seem to have been here for many years "
	"and their owners have long since died or left.",
	"rubbish":"Much of it is garbage, but some of it is decaying fecal matter.",
	"garbage":"Much of it is garbage, but some of it is decaying fecal matter.",
	"matter":"%^GREEN%^UGGH!! EECCHHH...why look through that disgusting stuff?!?%^RESET%^",
	"hook":"A rope hangs from the hook. The rope disappears to the south, up into the darkness.",
	"rope":"The rope appears to be secured to something up and to the south...perhaps it is for swinging on.",
    ]));
    set_exits(([
        "west": RPATH "d8",
	"east": RPATH "d10",
        "south": RPATH "d6",
    ]));

    set_pre_exit_functions(({"south"}),({"exitb_fun"}));
}
int exitb_fun() {
    if((int)TP->query_property("demongate flying") < 1) {
	write(
	    "%^BLUE%^You head south through the darkness..."
        );
        say(
	    "%^BLUE%^"+TPQCN+" heads south and you hear a shout of surprise followed by a loud painful scream!%^RESET%^"
        ,TP);
	TP->move_player( RPATH "d6" );
	write("%^BLUE%^"
	    "Suddenly you are falling due to the lack of a floor "
	    "beneath your feet!\n%^GREEN%^You fall through the darkness!%^RESET%^"
        );
        TP->move_player( RPATH "c5","falling from above!");
	write(
	    "%^GREEN%^You fall through the darkness!%^RESET%^"
        );
        TP->move_player( RPATH "b8","falling from above!");
	write(
	    "%^GREEN%^You fall through the darkness!%^RESET%^"
        ); 
       TP->move_player( RPATH "a7","falling from above!");
        write(
	    "%^RED%^You smack into a hard surface and are impaled by many sharp spikes!%^RESET%^"
	);
        TP->do_damage("torso",random(30)+30);
 	return 0;
    } else {
	write(
	    "%^BLUE%^You head south through the darkness and the floor vanishes beneath your feet!\n"
	    "%^CYAN%^However, your body remains floating and you find you can fly about the room with ease.%^RESET%^"
        );
	say(
	    "%^BLUE%^"+TPQCN+" heads south into the darkness.%^RESET%^"
        ,TP);
        return 1;
    }
}
int swing_fun(string str) {
    if(!str) {
	notify_fail("Swing on what?\n");
	return 0;
    }
    if(str != "on rope") {
	notify_fail("Swing on what?\n");
	return 0;
    }
    write(
	"%^ORANGE%^You grab ahold of the rope and take a giant leaping swing to the south!"
        "%^RESET%^"
    );
    say("%^ORANGE%^"
	+TPQCN+" grabs the rope and takes a giant leaping swing to the south!"
	"%^RESET%^"
    ,TP);
    TP->move_player( RPATH "d6","swinging on a rope" );
    write("%^ORANGE%^You go swinging through the room with no floor!%^RESET%^");
    TP->move_player( RPATH "d3","swinging like a monkey on a rope" );
    write("%^ORANGE%^You land safely on the other side of the chute room and let go of the rope!\nThe "
	"rope slides away to the north.%^RESET%^"
    );
    say("%^ORANGE%^The rope magically flies back in and hangs itself upon the hook!");
    return 1;
}	
