#include <std.h>
#include "../defs.h"
inherit MONSTER;

void create()
{
    ::create();
    set_name("orc");
    set_id(({ "orc", "orc marauder", "marauder", "monster" }));
    set_short("An orc marauder");
    set_long("This orc stands about as tall as a human, even " +
             "though he slouches over as he walks.  Small, red eyes " +
             "sit above a snout-like nose.  Large teeth protrude " +
             "from his lower jaw, and look as if they could easily " +
             "tear into your flesh, should he lose his weapons.  " +
             "Dirty leather armor covers pale green flesh, while oily, " +
             "course hair hangs below his shoulders.  He leans against " +
             "his halberd when not moving.");
    set_race("orc");
    set_body_type("human");
    set_gender("male");
    set_hd(10, 2);
    set_level(11);
    set_size(2);
    set("aggressive", 25);
    set_class("fighter");
    set_mlevel("fighter", 10);
    set_stats("strength", 18);
    set_property("full attacks", 1);
    set_exp(1300);
    set_overall_ac(5);
    set_alignment(3);
    new("/d/common/obj/weapon/halberd")->move(TO);
    command("wield halberd");
    new(OBJ + "dstudded")->move(TO);
    command("wear studded");
    set_emotes(5, ({
        "The orc grunts:  %^RED%^You on our land, you die now.%^RESET%^",
        "The orc grunts:  %^RED%^You no should be here.%^RESET%^",
        "The orc grunts:  %^RED%^Me feed you to ogre friend.%^RESET%^"
    }), 1);
    add_money("gold", random(60));
}
