#include "../../undead.h"

inherit INH+"tomb_two.c";

void create() 
{
    ::create();

    set_long("%^RED%^You are inside a dark hallway.%^RESET%^\n"
        "%^BOLD%^%^BLUE%^You just passed a tall, twisting, stairwell and "
        "have entered a new hallway going to the west.  You think you "
        "might see %^BOLD%^%^WHITE%^light%^BOLD%^%^BLUE%^ coming from "
        "the south but just like everything else in this accursed tomb, "
        "it is a sickly light, pale and flucuating.");

    set_exits(([
        "west"      :HALL+"hall4",
        "south"     :HALL+"hall8"
             ]));

}
