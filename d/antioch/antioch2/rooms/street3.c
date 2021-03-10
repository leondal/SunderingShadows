#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_short("%^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ Street");
    set_long(
        "%^GREEN%^You are on %^GREEN%^%^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ street%^RESET%^\nThis is close to the intersection of %^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ and %^ORANGE%^Crescent%^RESET%^. To the west there is a sign hanging over the entrance of a house. The sign is engraved with the symbol of a leather worker. The smell of leather is thick in the air here. The street continues up to the northwest. To the southeast you can see the intersection of %^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ and %^ORANGE%^Crescent%^RESET%^. There is a Healer and the guard %^ORANGE%^tower%^WHITE%^ that way.
"
        );
    set_smell("default", "The smell of leather is in the air.");
    if (query_night() == 1) {
        set_listen("default", "It is fairly quiet here at this" +
                   " time of night.");
    }else {
        set_listen("default", "The city is alive with the noises" +
                   " of citizens and shoppers.");
    }
    set_items(([
                   "street sign" : "This is %^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ Street.",
                   ({ "street", "cobblestones", "cobbles", "road", "path" }) : "The" +
                   " street is paved with cobblestones.",
                   "sign" : "This is a wooden sign with the symbol of a leather" +
                   " worker on it. It hangs above the doorway to the house on the" +
                   " west.",
                   ({ "tower", "guard tower" }) : "The stone guard tower is to" +
                   " the southeast.",
                   ]));
    set_exits(([
                   "southeast" : ROOMS + "street2",
                   "northwest" : ROOMS + "street4",
                   "west" : ROOMS + "leather",
               ]));
    set_door("door", ROOMS + "leather", "west", 0);
    if (query_night() == 1) {
        set_open("door", 0);
        "/d/antioch/antioch2/rooms/leather"->set_open("door", 0);
    }else if (query_night() != 1) {
        set_open("door", 1);
        "/d/antioch/antioch2/rooms/leather"->set_open("door", 1);
    }
}
