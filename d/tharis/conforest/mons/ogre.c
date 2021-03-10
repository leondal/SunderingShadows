#include <std.h>
#include "../defs.h"
inherit MONSTER;

void create()
{
    ::create();
    set_name("ogre");
    set_id(({ "ogre", "ogre mercenary", "monster" }));
    set_short("An ogre mercenary");
    set_long("An ogre stands before you, towering nearly ten " +
             "feet tall.  Pale yellow skin, riddled with brown warts, " +
             "partially covered in animal hide clothing.  Long, dark " +
             "hair hangs well past his shoulders, and looks as if it " +
             "has never been washed.  Somehow, he smells worse than " +
             "he looks.");
    set_race("ogre");
    set_body_type("human");
    set_gender("male");
    set_hd(10, 2);
    set_level(11);
    set_size(3);
    set("aggressive", 25);
    set_class("fighter");
    set_mlevel("fighter", 10);
    set_property("full attacks", 1);
    set_hp(random(25) + 100);
    set_exp(1300);
    set_overall_ac(2);
    set_alignment(9);
    set_stats("strength", 20);
    new(OBJ + "lclub")->move(TO);
    command("wield club");
    set_emotes(10, ({
        "The ogre drools hungrily at you.",
        "The ogre grunts:  %^RED%^Me hungry.  You food.%^RESET%^",
        "The ogre glares at you and says:  %^RED%^Me bash head in." +
        "%^RESET%^"
    }), 1);
}
