#include <std.h>
inherit MONSTER;
void create()
{
    ::create();

    set_name("amazon archer");
    set_id(({"archer","amazon","amazon archer","amazon patrol","patrol"}));
    set_short("Amazon Patrol");
    set_property("swarm",1);
    set_long(
    "This is an Amazon cliff patroller.  She stands at the cliffs and fires arrows at the monsters in the marsh.  She doesn't look as muscular as the rest of her kind, but she appears to be more agile and looks like she can move quickly."
    );
    set_race("human");
    set_class("ranger");
    set_gender("female");
    set_body_type("human");
    set_hd(26,8);
    set_guild_level("ranger", 26);
    set_mlevel("ranger", 26);
    set_new_exp(27, "normal");
    set_property("full attacks", 1);
    set_hp(675 + random(185));
    set_max_hp(query_hp());
    set_overall_ac(-7);
    set_monster_feats(({
       "point blank shot",
       "manyshot",
       "deadeye",
       "preciseshot",
       "shot on the run"
    }));
    add_money("gold",250 + random(1500));
    new("/d/common/obj/lrweapon/longbow")->move(TO);
    command("wield bow");
    new("/d/common/obj/lrweapon/larrows")->move(TO);
    set_stats("strength",17);
    set_stats("dexterity",27);
    set_stats("intelligence", 14);
    set_stats("wisdom", 14);
    set_stats("charisma", 12);
    set_stats("constitution", 18);
    set_mob_magic_resistance("none");
    set_emotes(2, ({
        "The archer fires a few arrows down at monsters in the marsh.",
    }),0);
}
