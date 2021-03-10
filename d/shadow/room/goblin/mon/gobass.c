//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//Added feats to fix scramble - Octothorpe 6/22/10
//added max_level *Styx* 7/20/01

#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit MONSTER;

void create()
{
    ::create();
    set_name("harthugg");
    set_id(({ "goblin", "assassin", "goblin assassin" }));
    set_short("Harthugg, the Goblin Royal Assassin");
    set_hd(10, 4);
    set_level(10);
    set_long("This sinewy little thug is the King's loyal assassin. "
             "He is reserved for missions that require stealth, cunning and instant death. "
             "Wielding a glowing dagger in one hand and a bone knife in the other, he looks ready "
             "and willing to kill. He is clothed in a full suit of bone armour. A fierce snarl bleeds "
             "through his bony grin."
             );
    set_class("thief");
    set_mlevel("thief", 10);
    set_body_type("human");
    set_alignment(9);
    set("race", "goblin");
    set_overall_ac(8);
    set_stats("strength", 18);
    set_stats("dexterity", 18);
    set_max_hp(70 + random(20));
    set_hp(query_max_hp());
//    set_exp(1500);
    set_new_exp(10, "very high");
    set_max_level(11);
    set("aggressive", "aggfun");
    set_emotes(5, ({
        "%^BOLD%^%^GREEN%^You wonder if he's used poison on you!%^RESET%^",
        "%^CYAN%^Goblin assassin says: %^RESET%^It will soon be over little one!",
        "%^BOLD%^%^WHITE%^Goblin assassin whirls about you!\nYour back is exposed!",
    }), 1);
    TO->add_money("gold", random(150) + 100);
    TO->add_money("silver", random(500) + 55);
    TO->add_money("copper", random(3500) + 150);
    new(OPATH "gdagger")->move(TO);
    command("wield dagger in right hand");
    new(OPATH "gknife")->move(TO);
    command("wield knife in left hand");
    if (!random(2)) {
        new(OPATH "bone")->move(TO);
        command("wear bone");
    }
    if (!random(3)) {
        new(OPATH "boots")->move(TO);
        command("wear boots");
    }
    add_search_path("/cmds/thief");
    set_hidden(1);
    set_scrambling(1);
    set_monster_feats(({
        "dodge",
        "evasion",
        "mobility",
        "scramble",
        "spring attack",
        "combat reflexes"
    }));
}

void aggfun(object targ)
{
    if (TP->query_invis()) {
        tell_room(TP, "A shadow snickers at you.");
    } else {
        set_hidden(0);
        TO->force_me("say I have waited patiently for you to come!");
        TO->force_me("say And now I slay you, as you slay my people!");
        TO->force_me("stab " + TP->query_name());
    }
}

void reset()
{
    ::reset();
    set_hidden(1);
}
