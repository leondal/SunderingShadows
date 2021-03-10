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
    set_short("%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ Street");
    set_long(
        "%^ORANGE%^You are on %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^\n" +
        "%^ORANGE%^Directly west is the intersection of %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ with %^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ and %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e%^RESET%^. The stables are also right there, and you can still smell the horses that are kept inside. %^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ street runs southeast, heading back towards the Antioch gates. %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^ travels to the northeast to intersect with Oak shortly before the palace. %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^  runs straight east and west. In the center of the street is a large %^BOLD%^%^CYAN%^foun%^RESET%^%^CYAN%^t%^BOLD%^%^CYAN%^ain.%^RESET%^%^ORANGE%^ At the far end is a very large stone church. There are many shops all along this street, including a bank just south of the fountain.
"
        );
    set_smell("default", "The breeze blows in the faint scent of" +
              " horses from the stables.");
    if (query_night() == 1) {
        set_listen("default", "You can hear the horses stomping" +
                   " about in their stalls.");
    }else {
        set_listen("default", "The street is alive with busy shoppers.");
    }
    set_items(([
                   ({ "street", "cobblestones", "cobbles", "road", "path" }) : "The" +
                   " street is paved with cobblestones.",
                   "street sign" : "This is %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^",
                   "fountain" : "There is a large fountain in the center of" +
                   " the street.",
                   "shops" : "There are many shops along this street.",
                   ]));
    set_exits(([
                   "west" : ROOMS + "street6",
                   "east" : ROOMS + "street19",
               ]));
    if (!find_object("/d/antioch/antioch2/mons/minstrel")) {
        find_object_or_load("/d/antioch/antioch2/mons/minstrel")->move(TO);
    }
//      new(MONS+"minstrel")->move(TO);
// the check above only works for the master object, we'll load the master *Styx* 8/21/03
}
