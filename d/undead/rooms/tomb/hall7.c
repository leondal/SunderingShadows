#include "../../undead.h"

inherit INH+"tomb_two.c";

void create() 
{
    ::create();

    set_long("%^RED%^You are inside a dark hallway.%^RESET%^\n"
        "%^BOLD%^%^BLUE%^You turn down this hallway, heading towards the "
        "faint light you see in the distance.  When you reach it you can "
        "see that it is coming from under the crack of a doorway.  To the "
        "south you can see the same kind of feint light, pale and flucuating.");

    set_exits(([
        "north"     :HALL+"hall5",
        "west"      :HALL+"chamber",
        "south"     :HALL+"hall9"
             ]));

}
