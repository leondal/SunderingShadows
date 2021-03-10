#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_short("%^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ Street");
    set_long(
        "%^GREEN%^You are on %^GREEN%^%^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ street%^RESET%^\n" +
        "To the north is the intersection of %^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ with %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e%^RESET%^ and" +
        " %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^. There is also a sign with the symbol of a stables" +
        " on it, hanging over the doorway of a building on the west" +
        " side. To the east of that %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^continues into the" +
        " main part of town. %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^ runs off to the northeast." +
        " To the southwest %^GREEN%^%^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ street%^RESET%^continues back to intersect" +
        " with %^ORANGE%^Crescent%^RESET%^."
        );
    set_smell("default", "You smell the scent of horses.");
    set_listen("default", "The sounds of horses stomping about" +
               " in their stalls drifts in from the north.");
    set_items(([
                   ({ "street", "cobblestones", "cobbles", "road", "path" }) : "The" +
                   " street is paved with cobblestones.",
                   "street sign" : "This is %^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ Street.",
                   "sign" : "There is a wooden sign to the north with the" +
                   " symbol of a stables on it.",
               ]));
    set_exits(([
                   "north" : ROOMS + "street6",
                   "southeast" : ROOMS + "street4",
               ]));
}
