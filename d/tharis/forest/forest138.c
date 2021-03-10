//forest138.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_short("A dank clearing");
    set_long("In the center of this clearing is an ancient and apparently "
	"%^BOLD%^%^BLACK%^decaying stump%^RESET%^.  The trees around the "
	"clearing are so thick as to prevent further passage through the "
	"forest other than the way you came."
    );
    set_exits(([
        "southeast":TFOREST"forest137",
        "enter":TFOREST"hole11"
    ]));
    set_items(([
        "grass":"The grass here seems dull and lifeless, as if something "
	    "prevents it from flourishing.",
        "stump":"This old stump looks and smells badly decayed but somehow "
	    "retains its shape and is more solid than you first thought.\n"
	    "As you look closer you see a hole in the base you can enter.",
        "hole":"It is quite dark in there but it is plainly made for humanoids to use."
    ]));
    set_invis_exits(({"enter"}));
}


