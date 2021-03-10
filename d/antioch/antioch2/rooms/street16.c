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
    set_short("%^ORANGE%^Crescent%^RESET%^ Street");
    set_long(
        "You are on %^BOLD%^%^ORANGE%^C%^RESET%^%^ORANGE%^re%^BOLD%^%^ORANGE%^s%^RESET%^%^ORANGE%^c%^BOLD%^%^ORANGE%^e%^RESET%^%^ORANGE%^n%^BOLD%^%^ORANGE%^t%^RESET%^ %^ORANGE%^street%^WHITE%^.\n" +
        "%^WHITE%^To the northeast %^ORANGE%^Crescent%^RESET%^ %^ORANGE%^street%^WHITE%^ continues to join with %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ and %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^ outside of the large %^BOLD%^%^ORANGE%^chur%^WHITE%^c%^ORANGE%^h.%^RESET%^%^WHITE%^ It also continues to the southwest, meeting with %^GREEN%^%^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ street%^RESET%^not far from the Antioch gates. On the southern side of the road there is a small %^ORANGE%^h%^ORANGE%^o%^BOLD%^%^BLACK%^use%^RESET%^%^WHITE%^ with a brown roof. There appears to be an entrance to it a little further down this street.
"
        );
    set_smell("default", "You smell the faint scent of dried" +
              " food.");
    if (query_night() == 1) {
        set_listen("default", "It's fairly quiet at this time of" +
                   " night.");
    }else {
        set_listen("default", "You can hear the sounds of a busy" +
                   " city.");
    }
    set_items(([
                   ({ "street", "cobblestones", "cobbles", "road", "path" }) : "The" +
                   " street is paved with cobblestones.",
                   "street sign" : "This is %^BOLD%^%^ORANGE%^C%^RESET%^%^ORANGE%^re%^BOLD%^%^ORANGE%^s%^RESET%^%^ORANGE%^c%^BOLD%^%^ORANGE%^e%^RESET%^%^ORANGE%^n%^BOLD%^%^ORANGE%^t%^RESET%^ %^ORANGE%^street%^WHITE%^.",
                   ({ "house", "building", "shop" }) : "It is a small little wooden" +
                   " house with a pretty brown roof. The entrance is a little" +
                   " southwest of here.",
                   "church" : "There is a very impressive stone church to the" +
                   " northeast.",
               ]));
    set_exits(([
                   "southwest" : ROOMS + "street17",
                   "northeast" : ROOMS + "street15",
               ]));
}

void reset()
{
    ::reset();
    if (!present("street_light")) {
        new(OBJ + "street_light")->move(TO);
    }
}
