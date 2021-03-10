#include <std.h>
#include "../../undead.h"

inherit INH+"tomb_five.c";

void create() 
{
    ::create();

    set_long("%^BOLD%^BLACK%^You stand in a chamber shaped like a perfect cube.  "
        "As you pass through the metal gates you enter your worst nightmares.  "
        "Bodies of men and women hang from the ceiling, some with missing "
        "body parts which you find laying on the floor around them. Some "
        "with puncture wounds in their necks, others with no necks left at "
        "all. Blood covering the entire floor, in some times up to several "
        "inches deep. You realize that only a creature of the greatest "
        "evil could have done such a thing. At the other end of the chamber "
        "you see such a being. Lying upon an altar, hands crossed upon his "
        "chest, you see the one the evil beings of this realms have referred "
        "to as, The Master. Although over the centuries he has certainly gone "
        "by many names, you are most familiar with the name, Kartakass.  "
        "After a second you see his head turn towards you and his eyes flash "
        "open. If the eyes are a window to the soul, then his soul would be "
        "complete and utter rage.");
 
    set_exits(([
        "door":HALL+"chamber6"
             ]));

}

void reset() 
{
    ::reset();
    if(!present("kartakass")) { new(MON"kartakass")->move(TO); }
    return;
}
