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
	"an endless state of torment. This part of the hallway is decorated "
	"only by splashes of blood, long dried, on the floor. Low murmurs "
	"fill the room which seem to speak to you, grasping at your true thoughts. Ancient "
	"%^WHITE%^middle crosses%^RED%^ made of %^ORANGE%^wood%^RED%^ "
	"hang upon the walls and strange %^GREEN%^herbs%^RED%^ "
	"and %^MAGENTA%^flower petals%^RED%^ "
	"litter the floor as though a wierd ritual was preformed here."
	"%^RESET%^" 
    );
    set_short("%^RED%^Tower Hallway%^RESET%^");
    set_listen("default",
        "The silence here rests on a cliffside waiting to be shattered by the rocks below."
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
	"crosses":"The ancient middle crosses are from some old culture.",
	"herbs":"%^GREEN%^The herbs are of an unknown type and nature.%^RESET%^",
	"petals":"%^MAGENTA%^The petals are of an unknown type and nature.%^RESET%^",
    ]));
    set_exits(([
        "northeast": RPATH "d11",
        "east": RPATH "d9",
    ]));

    set_pre_exit_functions(({"east"}),({"exitb_fun"}));
    set_pre_exit_functions(({"northeast"}),({"exita_fun"}));
}
int exita_fun() {
    if(present("child")) {
        write("The child's strange power holds you back!");
        return 0;
    }
    write("%^CYAN%^As you head to the northeast, a "
	"%^BOLD%^series of chilled icedarts%^RESET%^%^CYAN%^ "
	"strike you!%^RESET%^"
    );
    say("%^CYAN%^As "+TPQCN+" heads northeast, a "
	"%^BOLD%^series of chilled icedarts%^RESET%^%^CYAN%^ "
	"strike "
	+TP->query_possessive()+" "
	"body!%^RESET%^"
    ,TP);
    TP->do_damage(TP->return_target_limb(),35+random(35));
    return 1;
}
int exitb_fun() {
    write("%^RED%^As you head to the east, a "
	"%^BOLD%^pillar of fire%^RESET%^%^RED%^ "
	"engulfs you!%^RESET%^"
    );
    say("%^RED%^As "+TPQCN+" heads east, a "
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
    if(!present("child")) {
        new( MPATH "child1.c" )->move(TO);
    }
}
