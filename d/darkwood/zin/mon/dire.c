#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid());
    set_name("Wolf");
    set_id(({"wolf","dire","dire wolf","Dire Wolf"}));
    set("short", "A Dire Wolf");
    set_long("This is a large Dire Wolf that does not look pleased to see you here.");
    set("race", "wolf");
    set_gender("male");
    set_body_type("quadruped");
    set_hd(1,4);
    set_level(10);
    set_hp(100);
    set_exp(500);
    set_overall_ac(3);
    set_size(2);
    set("aggressive",15);
    set_property("swarm",1);
    set_emotes(5, ({
      "The Dire Wolf growls at you.",
      "The Dire Wolf moves between you and the cubs."
    }),0);
}
