#include "../../undead.h"

inherit INH+"tomb_three.c";

void create() 
{
    ::create();

    set_long("%^RED%^You are inside a dark hallway.%^RESET%^\n"
        "%^BLUE%^As you come out of the thick fog it is as though you have "
        "just passed through a physical barrier.  The hallway in which you "
        "now stand is clear.  As you look behind you you see an actual wall "
        "of fog covering the doorway you just passed through.  Unfortunately "
        "from what you now see before you you wish this room was covered in "
        "fog also.  Instead it is covered in %^RED%^blood.");
 
    set_exits(([
        "east"      :HALL+"hall13",
        "west"      :HALL+"hall12",
        "stairs"    :HALL+"stair2"
             ]));

}
