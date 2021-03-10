#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
	"The small chamber is made of the same %^BOLD%^"
	"blood-red%^RESET%^%^RED%^ stone as seen in other parts of the tower. "
	"The stone calls out to you as though it is alive and held captive in "
	"an endless state of torment. The chamber is decorated "
	"only by splashes of %^BOLD%^blood%^RESET%^%^RED%^, long dried, on the floor."
	"%^RESET%^" 
    );
    set_short("%^RED%^Tower Chamber%^RESET%^");
    set_listen("default",
        "It is dead silent, as though sound itself fears to roam here."
    );
    set_smell("default",
        "You smell the decaying blood splattered about the room."
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
	"material and seems to glow in it's blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
	"blood":"%^RED%^The blood seems to have been here for many years "
	"and it's origin is a mystery.",
    ]));
    set_exits(([
        "west": RPATH "c8",
    ]));

    set_pre_exit_functions(({"west"}),({"exitb_fun"}));
}

int exitb_fun() {
    if(present("reaver")) {
        write("The reaver blocks your way!");
        return 0;
    }
    write("%^RED%^As you head to the west, a "
	"%^BOLD%^pillar of fire%^RESET%^%^RED%^ "
	"engulfs you!%^RESET%^"
    );
    say("%^RED%^As "+TPQCN+" heads west, a "
	"%^BOLD%^pillar of fire%^RESET%^%^RED%^ "
	"engulfs "
	+TP->query_possessive()+" "
	"body!%^RESET%^"
    ,TP);
    TP->do_damage(TP->return_target_limb(),50+random(50));
    return 1;
}
void reset() {
    ::reset();
    if(!present("reaver")) {
        new( MPATH "reaver5.c" )->move(TO);
    }
}
