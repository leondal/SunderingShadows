#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid());
    set_name("Cub");
    set("id", ({"cub", "wolf"}) );
    set("short", "A tiny Dire Wolf cub");
    set("long", "The cub is newly born and still looks very weak.  Its "+
        "young coat of fur is very slick and almost shines in the dull "+
        "light of the den.  Its hard to believe that something so very "+
        "cute and playfull will someday be such a devilish horror.");
    set("race", "wolf");
    set_gender("male");
    set_body_type("quadruped");
    set_hd(1,4);
    set_level(5);
    set_hp(20);
    set_exp(200);
    set_overall_ac(3);
    set_size(1);
    set_property("swarm",1);
}
