#include <std.h>
#include "../antioch.h"

inherit CVAULT;

void create()
{
    set_monsters(({ "/d/antioch/antioch2/mons/patrol_guard", }), ({ roll_dice(1, 4) + 1, }));
    ::create();
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_property("indoors", 0);
    set_property("light", 2);
    set_short("%^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ Street");
    set_long(
        "%^GREEN%^%^You are on %^GREEN%^%^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ street%^RESET%^\nFurther to the northwest you can+ see it intersects with %^RED%^%^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^%^RESET%^ To the southeast is+ the intersection with %^BOLD%^%^ORANGE%^C%^RESET%^%^ORANGE%^re%^BOLD%^%^ORANGE%^s%^RESET%^%^ORANGE%^c%^BOLD%^%^ORANGE%^e%^RESET%^%^ORANGE%^n%^BOLD%^%^ORANGE%^t%^RESET%^ %^ORANGE%^street%^WHITE%^. There is also a+ a leather shop there, and it leads to the Healer and the+ guard tower. You smell the faint scent of a stables and+ can hear the sound of horses up to the northwest. The+ smell of leather is also still in the air."
        );
    set_smell("default", "There is a faint scent of leather mixed" +
              " with the smell of a stable on the breeze.");
    set_listen("default", "You hear the faint sound of horses" +
               " in the distance.");
    set_items(([
                   ({ "street", "cobblestones", "cobbles", "road", "path" }) : "The" +
                   " street is paved with cobblestones.",
                   "street sign" : "This is %^GREEN%^%^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ street%^RESET%^",
                   ]));
    set_exits(([
                   "northwest" : ROOMS + "street5",
                   "southeast" : ROOMS + "street3",
                   ]));
}

void reset()
{
    ::reset();
    if (!present("street_light")) {
        new(OBJ + "street_light")->move(TO);
    }
}
