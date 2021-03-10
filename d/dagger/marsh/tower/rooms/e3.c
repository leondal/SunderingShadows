#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;
int FLAG;
void init() {
    ::init();
    add_action("kneel_fun","kneel");
}
void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
	"The small chamber is made of the same %^BOLD%^"
	"blood-red%^RESET%^%^RED%^ stone as seen in other parts of the tower. "
	"The stone calls out to you as though it is alive and held captive in "
	"an endless state of torment. Old rusted torch brackets hang broken "
	"from the walls. Cobwebs fill the chamber, as though nothing has entered "
	"this area of the tower for years. A mysterious %^YELLOW%^holy light%^RESET%^%^RED%^ fills "
	"the entire chamber."
	"%^RESET%^" 
    );
    set_short("%^RED%^Cramped Chamber%^RESET%^");
    set_listen("default",
        "You hear angels singing within your head."
    );
    set_smell("default",
        "The smell of purity surrounds you."
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
	"material and seems to glow in it's blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
	"brackets":"%^ORANGE%^The brackets hang broken from the walls.",
	"cobwebs":"The cobwebs cover the ceiling and the walls of the chamber.",
	"light":"The entire chamber is bathed in a holy light.",
    ]));
    set_exits(([
        "south": RPATH "e1",
	"northeast": RPATH "e8",
	"northwest": RPATH "e6",
	"west": RPATH "e2",
	"east": RPATH "e4",
	"north": RPATH "e7",
    ]));
    set_pre_exit_functions(({"north"}),({"exita_fun"}));
    set_pre_exit_functions(({"south"}),({"exitb_fun"}));
    set_pre_exit_functions(({"west"}),({"exitc_fun"}));
    set_pre_exit_functions(({"east"}),({"exitd_fun"}));
    set_pre_exit_functions(({"northeast"}),({"exite_fun"}));
    set_pre_exit_functions(({"northwest"}),({"exitf_fun"}));
}
int kneel_fun() {
    if((int)TP->query_property("kneel") > 0) {
	write("You are already kneeling!");
	return 1;
    }
    if(!present("knight")) {
	return 0;
    }
    write(
	"%^CYAN%^You kneel before the knight proving humility to the gods!%^RESET%^"
    );
    say(
	"%^CYAN%^"+TPQCN+" kneels before the knight!"
	"%^RESET%^"
    ,TP);
    TP->set_property("kneel",1);
    return 1;
}
int exita_fun() {
    if((int)TP->query_property("demongate flying") < 1) {
	write(
	    "%^BLUE%^You head north through the darkness..."
        );
        say(
	    "%^BLUE%^"+TPQCN+" heads north and you hear a shout of surprise followed by a loud painful scream!%^RESET%^"
        ,TP);
	TP->move_player( RPATH "e7" );
	write("%^BLUE%^"
	    "Suddenly you are falling due to the lack of a floor "
	    "beneath your feet!\n%^GREEN%^You fall through the darkness!%^RESET%^"
        );
	TP->move_player( RPATH "d6","falling from above");
	write("%^GREEN%^You fall through the darkness!%^RESET%^");
	TP->move_player( RPATH "c5","falling from above");
	write("%^GREEN%^You fall through the darkness!%^RESET%^");
	TP->move_player( RPATH "b8","falling from above");
	write("%^GREEN%^You fall through the darkness!%^RESET%^");
        TP->move_player( RPATH "a7","falling from above!");
        write(
	    "%^RED%^You smack into a hard surface and are impaled by many sharp spikes!%^RESET%^"
	);
        TP->do_damage("torso",random(60)+60);
 	return 0;
    } else {
	write(
	    "%^BLUE%^You head north through the darkness and the floor vanishes beneath your feet!\n"
	    "%^CYAN%^However, your body remains floating and you find you can fly about the room with ease.%^RESET%^"
        );
	say(
	    "%^BLUE%^"+TPQCN+" heads north into the darkness.%^RESET%^"
        ,TP);
        return 1;
    }
}
int exitb_fun() {
    if(!present("knight")) return 1;
    if((int)TP->query_property("kneel") < 1) {
	write("%^CYAN%^The knight will not allow you to pass!%^RESET%^");
	return 0;
    }
    if((int)TP->query_alignment() != 2 &&
       (int)TP->query_alignment() != 4 &&
       (int)TP->query_alignment() != 5 &&
       (int)TP->query_alignment() != 6 &&
       (int)TP->query_alignment() != 8) {
	write(
	    "%^MAGENTA%^Knight says:%^RESET%^ You are not of that walk of life. You may not go that direction!"
	);
	return 0;
    } else {
	write(
	    "%^MAGENTA%^Knight says:%^RESET%^ You may pass "+TPQCN+".\n"
	    "%^CYAN%^The knight stands aside for you to pass.%^RESET%^"
	);
        TP->remove_property("kneel");
	return 1;
    }
} 	
int exitc_fun() {
    if(!present("knight")) return 1;
    if((int)TP->query_property("kneel") < 1) {
	write("%^CYAN%^The knight will not allow you to pass!%^RESET%^");
	return 0;
    }
    if((int)TP->query_alignment() != 1 &&
       (int)TP->query_alignment() != 4 &&
       (int)TP->query_alignment() != 7) {
	write(
	    "%^MAGENTA%^Knight says:%^RESET%^ You are not of that walk of life. You may not go that direction!"
	);
	return 0;
    } else {
	write(
	    "%^MAGENTA%^Knight says:%^RESET%^ You may pass "+TPQCN+".\n"
	    "%^CYAN%^The knight stands aside for you to pass.%^RESET%^"
	);
        TP->remove_property("kneel");
	return 1;
    }
}
int exitd_fun() {
    if(!present("knight")) return 1;
    if((int)TP->query_property("kneel") < 1) {
	write("%^CYAN%^The knight will not allow you to pass!%^RESET%^");
	return 0;
    }
    if((int)TP->query_alignment() != 9 &&
       (int)TP->query_alignment() != 6 &&
       (int)TP->query_alignment() != 3) {
	write(
	    "%^MAGENTA%^Knight says:%^RESET%^ You are not of that walk of life. You may not go that direction!"
	);
	return 0;
    } else {
	write(
	    "%^MAGENTA%^Knight says:%^RESET%^ You may pass "+TPQCN+".\n"
	    "%^CYAN%^The knight stands aside for you to pass.%^RESET%^"
	);
        TP->remove_property("kneel");
	return 1;
    }
}
int exite_fun() {
    if(!present("knight")) return 1;
    if((int)TP->query_property("kneel") < 1) {
	write("%^CYAN%^The knight will not allow you to pass!%^RESET%^");
	return 0;
    }
    if((int)TP->query_alignment() != 7 &&
       (int)TP->query_alignment() != 8 &&
       (int)TP->query_alignment() != 9) {
	write(
	    "%^MAGENTA%^Knight says:%^RESET%^ You are not of that walk of life. You may not go that direction!"
	);
	return 0;
    } else {
	write(
	    "%^MAGENTA%^Knight says:%^RESET%^ You may pass "+TPQCN+".\n"
	    "%^CYAN%^The knight stands aside for you to pass.%^RESET%^"
	);
        TP->remove_property("kneel");
	return 1;
    }
}
int exitf_fun() {
    if(!present("knight")) return 1;
    if((int)TP->query_property("kneel") < 1) {
	write("%^CYAN%^The knight will not allow you to pass!%^RESET%^");
	return 0;
    }
    if((int)TP->query_alignment() != 1 &&
       (int)TP->query_alignment() != 2 &&
       (int)TP->query_alignment() != 3) {
	write(
	    "%^MAGENTA%^Knight says:%^RESET%^ You are not of that walk of life. You may not go that direction!"
	);
	return 0;
    } else {
	write(
	    "%^MAGENTA%^Knight says:%^RESET%^ You may pass "+TPQCN+".\n"
	    "%^CYAN%^The knight stands aside for you to pass.%^RESET%^"
	);
        TP->remove_property("kneel");
	return 1;
    }
}
void reset() {
    ::reset();
    if(!present("knight")) {
	new( MPATH "knight.c")->move(TO);
    }
}
