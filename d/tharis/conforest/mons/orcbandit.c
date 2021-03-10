#include <std.h>
#include "../defs.h"
inherit MONSTER;

void create()
{
    ::create();
    set_name("orc");
    set_id(({ "orc", "orc bandit", "bandit", "monster" }));
    set_short("An orc bandit");
    set_long("This orc stands about as tall as a human, even " +
             "though he slouches over as he walks.  Small, red eyes " +
             "sit above a snout-like nose.  Large teeth protrude " +
             "from his lower jaw, and look as if they could easily " +
             "tear into your flesh, should he lose his weapons.  " +
             "Dirty leather armor covers pale green flesh, while oily, " +
             "course hair hangs below his shoulders.");
    set_race("orc");
    set_body_type("human");
    set_gender("male");
    set_hd(10, 2);
    set_level(11);
    set_size(2);
    set("aggressive", 25);
    set_class("fighter");
    set_mlevel("fighter", 10);
    set_property("full attacks", 1);
    set_exp(1200);
    set_overall_ac(4);
    set_stats("strength", 18);
    set_alignment(3);
    new("/d/common/obj/weapon/shortsword")->move(TO);
    command("wield shortsword");
    new("/d/common/obj/armour/sshield")->move(TO);
    command("wear shield");
    new(OBJ + "dstudded")->move(TO);
    command("wear studded");
    set_emotes(5, ({
        "The orc grunts:  %^RED%^You on our land, you die now.%^RESET%^",
        "The orc grunts:  %^RED%^Give up, you look like good slave.%^RESET%^"
    }), 1);
}
