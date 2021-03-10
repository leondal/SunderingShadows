#include <std.h>
#include "darcy.h"

inherit ROOM;

void create(){
    ::create();
    set_property("light" , 2);
    set_short("Outside the Gates of the d'Arcy Family Crypt");
    set_long(
@DARCY
%^BOLD%^Outside the Gates of the d'Arcy Family Crypt%^RESET%^
  You are standing in front of what appears to have been a sturdy
door, meant to guard the d'Arcy family crypt from the ravages of
thieves or vandals.  This door appears to now be off of its hinges
and lays partially open.  No mere bandit could have done this while
the d'Arcy family lived securely in its home, you realize that
immediately.

  You can easily step though the open portal to the south and enter
the family crypt of the d'Arcy's.  To the west, you can see the main
path leading to the front gates of the chateau.

DARCY
);
    set_exits(([
        "south" : ROOMDIR+"crypt",
        "west"  : ROOMDIR+"outside"
    ]));
    set_smell("default","The smells of an active garrison overwhelm your senses.");
    set_listen("default","You hear remarkably little, given the activity on the walls.");
}
