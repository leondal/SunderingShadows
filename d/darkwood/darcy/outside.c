#include <std.h>
#include "darcy.h"

inherit ROOM;

void create(){
    ::create();
    set_property("light" , 2);
    set_short("Outside the Gates of the Chateau");
    set_long(
@DARCY
%^BOLD%^Outside the Gates of the Chateau%^RESET%^
  You are at the foot of small hill before the great Chateau d'Arcy.
Although it is well decorated and it's architecture is splendid, its
ramparts are quite functional looking.  This is a fortress as well
as the home of a rich noble.

  To the south, a short path appears to lead up the rise to the main
gates, which seem more ominous and dark than you might expect them
to be.  The guards look grim and out of place somehow.

  To the east of you, cut into the hillside, appears to the gate to
the d'Arcy family crypt.  Although you can't make out any details,
the crypt itself appears to be as well designed as the fortress.  A
heavy looking iron door to the crypt itself makes the imposing crypt
gates look almost decorative in comparison.

DARCY
);
    set_exits(([
        "south" : ROOMDIR+"gate",
        "east"  : ROOMDIR+"cgate"
    ]));
    set_smell("default","The smells of an active garrison overwhelm your senses.");
    set_listen("default","You hear remarkably little, given the activity on the walls.");
}
