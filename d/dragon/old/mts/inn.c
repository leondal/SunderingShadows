#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("Gustaf's lonely Inn");
    set_long("%^BOLD%^%^RED%^
Inside this structure the cool air gives way to blasting heat.  A raging
fire burns in the fireplace within the east wall.  Patrons sit at long
oak tables.  Their benches are upholstered with faded red cloth.  The
decore knows no restraint: plates, paintings, empty vases, and other bric-
a-brac cover every square inch of the walls and mantlepiece.  A dark
wooden bar gleams in front of you.
  ");
    set_exits(([
       "out" : "/d/dragon/mts/forest06"
    ] ));
    set_items(([
    ] ));
}
