#include <std.h>
#include "/d/dagger/marsh/tomb/short.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
	"The long hallway looms all around you. You stand next to the west wall. To the "
	"east you can barely make out the east wall. The hallway stretches to the south and "
	"is shrouded in darkness. To the north lies the exit leading out of the tomb. "
	"Bright and brilliant colours can be seen painted upon the western wall and floor. "
	"The passage of time has not caused these visages to fade. "
	"The floor of the corridor is a colourful mosaic of stone. No stonework can be seen "
	"upon the walls or ceiling, for some sort of plaster has been smoothed over all of "
	"these surfaces and then illustrated."
	"%^RESET%^"
    ); 
    set_short("%^RED%^Inner Hallway%^RESET%^");
    set_listen("default",
        "Only your breathing disturbs the dead silence."
    );
    set_smell("default",
        "The air is stale and musty."
    );
    set_items(([
	"ceiling":" ",
	"floor":" ",
	"hallway":" ",
	(({"walls","wall"})):" ",
	(({"illustration","illustrations","plaster","surfaces","visages"})):" ",
        "stone":" ",
	"west wall":" ",
	"east wall":" ",
	"darkness":" ",
	"tomb":"The tomb is all around you. What part of the tomb do you wish to examine?",
	"mosaic":" ",
    ]));
    set_exits(([
        "north": RPATH "filler",
        "south": RPATH "h3",
	"east": RPATH "h2",
        "southeast": RPATH "h4"
    ]));

    set_pre_exit_functions(({"south","southeast"}),({"exitb_fun"}));
}
int exitb_fun() {
    message("info",
	"%^BOLD%^%^RED%^"
	"You head deeper into the Tomb of Horrors."
	"%^RESET%^"
    ,TP);
    message("info",
	"%^BOLD%^%^RED%^"
	+TPQCN+
	" takes a deep breath and heads deeper into the Tomb of Horrors."
	"%^RESET%^"
    ,ETP,TP);
    return 1;
}
