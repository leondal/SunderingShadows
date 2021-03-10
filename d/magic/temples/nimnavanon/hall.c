#include <std.h>

inherit ROOM;

void create()
{
    ::create();

    set_property("indoors", 1);
    set_property("light", 2);

    set_climate("temperate");
    set_short("%^ORANGE%^common hall");
    set_long("%^ORANGE%^A " + query_short() + "\n" + "%^ORANGE%^Inside the mound the walls are made of stone and the ceiling of wooden logs. Vividly colored %^MAGENTA%^t%^MAGENTA%^a%^MAGENTA%^p%^BOLD%^%^BLACK%^est%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^ies%^RESET%^%^ORANGE%^ hang from the walls and creates small alocoves and compartments along the side of the building. A huge fire burns in the middle of the hall. Large %^ORANGE%^h%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s%^ORANGE%^ in the ceiling lets out the %^BOLD%^%^BLACK%^s%^RESET%^%^WHITE%^m%^BOLD%^%^BLACK%^ok%^RESET%^%^WHITE%^e%^BOLD%^%^BLACK%^,%^RESET%^%^ORANGE%^ and lights up the room in the daytime. %^BOLD%^%^BLACK%^Ben%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^h%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^ draped in fur and %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^h%^ORANGE%^a%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^r%^ORANGE%^s%^ORANGE%^ made of roots provides to sit and eat or talk. Drying herbs hang from the ceiling.
");
    set_smell("default", "%^ORANGE%^It smells of %^BOLD%^%^BLACK%^earth%^RESET%^%^ORANGE%^, %^BOLD%^%^BLACK%^a%^BLACK%^sh, %^BLACK%^s%^WHITE%^m%^BLACK%^oke%^ORANGE%^ and %^ORANGE%^c%^BOLD%^%^BLACK%^oo%^RESET%^%^ORANGE%^k%^ORANGE%^e%^ORANGE%^d %^BOLD%^%^BLACK%^m%^ORANGE%^e%^ORANGE%^a%^ORANGE%^t%^ORANGE%^.");
    set_listen("default", "%^CYAN%^You hear the faint sound of someone talking outside the mound, and some light snoring from one of the %^BOLD%^%^BLACK%^alcoves%^RESET%^%^CYAN%^.");
    set_exits(([
                   "west" : "/d/magic/temples/nimnavanon/mound",
                   ]));

    set_items(([
                   "chairs" : "The chairs are made of twisting roots or whole pieces of logs.",
                   "benches" : "The benches are draped in fur to make them more comfortable to sit on.",
                   "tapestries" : "The tapestries show a vibrant forest in summer green and autumn red colors. People and animals of various shapes and forms walk or turn from the sides towards the center of the image towards the contour of a huge black wolf beneath the trees.",
                   "fireplace" : "An open fireplace burns brightly in the center of the room.",
                   "holes" : "The holes in the ceiling let in the light during the day and can be closed with attached lids if the weather demands it.",
                   "alcoves" : "The alcoves behind the tapestries have soft furs and woven blankets for sleeping.",
                   "door" : "The door is made of dark wood.",
                   "smoke" : "%^ORANGE%^The smoke from the %^BOLD%^%^BLACK%^f%^RED%^i%^BLACK%^re%^RED%^p%^BLACK%^lace%^RESET%^%^ORANGE%^ escapes through holes in the ceiling.",
               ]));


}
