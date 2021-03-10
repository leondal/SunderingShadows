#include <std.h>
#include "../defs.h"
inherit MONSTER;

void create()
{
    ::create();
    set_name("orc");
    set_id(({ "orc", "orc chief", "chief", "monster" }));
    set_short("The orc chief");
    set_long("This orc stands more upright than the others " +
             "in this region.  He walks with more confidence, and " +
             "barks commands in a guttural dialect to the smaller " +
             "orcs nearby.  Small, red eyes " +
             "sit above a snout-like nose.  Large teeth protrude " +
             "from his lower jaw, and look as if they could easily " +
             "tear into your flesh, should he lose his weapons.  " +
             "This orc looks like he takes care of himself better " +
             "than most.");
    set_race("orc");
    set_body_type("human");
    set_gender("male");
    set_hd(12, 2);
    set_level(13);
    set_size(2);
    set("aggressive", 25);
    set_class("fighter");
    set_mlevel("fighter", 12);
    set_property("full attacks", 1);
    set_exp(2000);
    set_overall_ac(5);
    set_stats("strength", 18);
    set_alignment(3);
    new("/d/common/obj/weapon/longsword")->move(TO);
    command("wield longsword");
    new("/d/common/obj/armour/mshield")->move(TO);
    command("wear shield");
    new(OBJ + "dstudded")->move(TO);
    command("wear studded");
    set_emotes(5, ({
        "The orc grunts:  %^RED%^You shouldn't have come here.%^RESET%^",
        "The orc grunts:  %^RED%^Guards!  Kill these fools!%^RESET%^",
        "The orc grunts:  %^RED%^We usually have to hunt people " +
        "to rob... how nice they come to us!%^RESET%^"
    }), 1);
    add_money("gold", random(60));
}
