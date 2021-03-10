#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;

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
	"and and long strands of %^CYAN%^cobwebs%^RED%^ hang from the ceiling. There is much "
	"%^GREEN%^rubbish%^RED%^ and %^GREEN%^garbage%^RED%^ strewn about the floor."
	"%^RESET%^"
    ); 
    set_short("%^RED%^Tower Hallway%^RESET%^");
    set_listen("default",
        "A low cold moan rises from the north."
    );
    set_smell("default",
        "You smell vile filth and bile strewn about the hallway."
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
    ]));
    set_exits(([
        "east": RPATH "b8",
        "northeast": RPATH "b4",
	"southeast": RPATH "b12",
	"west": RPATH "b6",
    ]));

    set_pre_exit_functions(({"west"}),({"exita_fun"}));
    set_pre_exit_functions(({"east"}),({"exitb_fun"}));
}
int exita_fun() {
    if(present("daggershadow0")) {
        write("%^BLUE%^The shadows thicken and block the way to the west.%^RESET%^");
        return 0;
    }
    write("%^BOLD%^%^CYAN%^You hear a faint whisper behind you!%^RESET%^"
    );
    return 1;
}
int exitb_fun() {
    if((int)TP->query_property("demongate flying") < 1) {
	write(
	    "%^BLUE%^You head south through the darkness..."
        );
        say(
	    "%^BLUE%^"+TPQCN+" heads south and you hear a shout of surprise followed by a loud painful scream!%^RESET%^"
        ,TP);
	TP->move_player( RPATH "b8" );
	write("%^BLUE%^"
	    "Suddenly you are falling due to the lack of a floor "
	    "beneath your feet!\n%^GREEN%^You fall through the darkness!%^RESET%^"
        );
        TP->move_player( RPATH "a7","falling from above!");
        write(
	    "%^RED%^You smack into a hard surface and are impaled by many sharp spikes!%^RESET%^"
	);
        TP->do_damage("torso",random(10)+10);
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

void reset() {
    ::reset();
    if(!present("daggershadow0")) {
        new( MPATH "shadow.c" )->move(TO);
        new( MPATH "shadow.c" )->move(TO);
        new( MPATH "shadow.c" )->move(TO);
        new( MPATH "shadow.c" )->move(TO);
// changed from say(...) to tell_room() to stop bugging *Styx* 11/1/03, last chg. 7/98	tell_room(TO,"%^RED%^The shadows seem to dance on the walls as you enter.%^RESET%^");
    }
    tell_room(TO,"%^RED%^You notice a slight quiver of movement within the shadows.%^RESET%^");
}
