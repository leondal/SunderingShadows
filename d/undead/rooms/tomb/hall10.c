#include "../../undead.h"

inherit INH+"tomb_two.c";

void create() 
{
    ::create();

    set_long("%^RED%^You are inside a dark hallway.%^RESET%^\n"
        "%^BOLD%^%^BLUE%^You turn down this hallway, heading towards the "
        "faint light you see in the distance.  When you reach it you can "
        "see that it is coming from under the crack of a doorway.");

    set_exits(([
        "north"     :HALL+"hall8",
        "east"      :HALL+"chamber4"
             ]));

}

