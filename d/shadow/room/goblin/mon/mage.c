//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include <daemons.h>
#include "/d/shadow/room/goblin/short.h"
inherit MONSTER;

int xx, dlevel;

void create()
{
    object ob;
    ::create();
    set_name("goblin sorcerer");
    set_id(({ "goblin", "sorceror", "goblin sorceror", "sorcerer" }));
    set_short("Goblin sorcerer");
    set("aggressive", 15);
    set_long("The Goblin before you is the sorcerer of the Goblin Army " +
             "of Shadow. He practices the black arts and is feared by all " +
             "the Goblins of the Goblin army of Shadow including the King " +
             "himself. It is often speculated that it is he who rules the " +
             "army through the King with his devious magical arts.");
    dlevel = random(3) + 4;    // lowered by one (5 to 4) *Styx*  6/5/05
    set_hd(dlevel, 1);
    set_level(dlevel);
    set_class("mage");
    set_guild_level("mage", dlevel);
    set_mlevel("mage", dlevel);
    set_class("fighter");
    set_mlevel("fighter", dlevel);
    set_body_type("human");
    set_alignment(9);
    set_race("goblin");
    set_gender("male");
    set_ac(6);
    set_stats("strength", 13);
    set_stats("dexterity", 13);
    set_stats("wisdom", 18);
    set_stats("intelligence", 18);
    //set_exp(dlevel*125);
    //  set_exp(700);
    set_new_exp(dlevel, "very high");
    set_max_hp((random(20) + 20 + (dlevel * 6)));
    set_hp(query_max_hp());
    set_achats(3, ({
        "%^CYAN%^Sorcerer squeaks: %^RESET%^No trifle wit me!",
        "%^CYAN%^Sorcerer squeaks: %^RESET%^Me burn you agin soon.",
        "%^CYAN%^Sorcerer screams: %^BOLD%^%^RED%^DAT YOU FAULT!!%^RESET%^",
        "%^CYAN%^Sorcerer yells: %^BOLD%^%^RED%^GET GONE!!",
        "%^CYAN%^Sorcerer whines: %^RESET%^ACK! WHY YOU STILL BE HERE?!?!",
        "%^RED%^Sorcerer nods lots and lots rapidly.%^RESET%^",
    }));
    set_emotes(3, ({
        "%^CYAN%^Sorcerer squeaks proudly: %^RESET%^Grazzt teached me what me know.",
        "%^CYAN%^Sorcerer squeaks proudly: %^RESET%^Diego learnt me sum new tricks.",
        "Sorcerer mutters an incantation.",
        "Sorcerer traces arcane runes in the air.",
        "Sorcerer cackles evilly.",
        "Sorcerer gesticulates wildly and a spell issues forth only to " +
        "%^YELLOW%^crackle%^RESET%^, %^BOLD%^%^RED%^spark%^RESET%^, and " +
        "%^BOLD%^%^MAGENTA%^fizzle %^RESET%^inches from his fingertips.",
        "Sorcerer raises an eyebrow.",
        "Sorcerer burps in the middle of an incantation ruining the spell.",
    }), 0);
    add_money("gold", random(200) + 50);
    add_money("silver", random(1200) + 150);
    add_money("copper", random(11500) + 500);
    set_spell_chance(50);
    set_func_chance(35);
    set_spells(({ "magic missile", "scorcher", "scorcher", "burning hands", "magic missile", "chill touch", "darkness" }));
    set_funcs(({ "special_spell" }));
    switch (random(4)) {
    case 0:
        new("/d/azha/obj/mr_ring")->move(TO);
        command("wear ring");

    case 1..2:
        ob = new("/d/magic/scroll");
        ob->set_spell(random(3) + 1);
        ob->move(TO);

    case 3:
        new(OPATH "robe.c")->move(TO);
        command("wear robe");
        break;
    }
    add_search_path("/cmds/fighter");
    add_search_path("/cmds/mage");
    set_max_level(9);
    set_property("full attacks", 1);
}

int special_spell()
{
    object me = TO;
    object vic = me->query_current_attacker();
    xx = random(5) + 1;
    switch (xx) {
    case 1:
        if (me->query_hp() < 10) {
            me->add_hp(random(5) + 3);
            tell_room(ETO, "%^MAGENTA%^Sorcerer's robe glows with " +
                      "an inner light.");
            return 1;
        }
        me->force_me("cackle");
        me->force_me("cast color spray at " + vic->query_name());
        return 1;

    case 2:
        if (me->query_hp() < 10) {
            me->add_hp(random(5) + 3);
            tell_room(ETO, "%^MAGENTA%^Sorcerer's robe glows " +
                      "with an inner light.");
            return 1;
        }
        me->force_me("grin");
        me->force_me("cast lightning bolt at " + vic->query_name());
        return 1;

    case 3:
        if (me->query_hp() < 10) {
            me->add_hp(random(5) + 3);
            tell_room(ETO, "%^MAGENTA%^Sorcerer's robe glows " +
                      "with an inner light.");
            return 1;
        }
        me->force_me("howl");
        tell_object(vic, "%^BOLD%^%^RED%^Sorcerer hurls a bolt of pure " +
                    "evil at you!");
        tell_room(ETO, "%^BOLD%^%^RED%^Sorcerer hurls a bolt of pure " +
                  "evil at " + vic->query_cap_name() + "!", vic);
        vic->do_damage("torso", random(20) + 3);
        return 1;

    case 4:
        if (me->query_hp() < 10) {
            me->add_hp(random(5) + 3);
            tell_room(ETO, "%^MAGENTA%^Sorcerer's robe glows with " +
                      "an inner light.");
            return 1;
        }
        me->force_me("scream");
        me->force_me("cast fireball at " + vic->query_name());
        return 1;

    case 5:
        tell_room(ETO, "%^MAGENTA%^Sorcerer's robe glows with an inner light.");
        me->add_hp(5);
        return 1;
    }
}

void init()
{
    string mrace = TP->query_race(), mname = TP->query_name();
    ::init();
    if (avatarp(TP) || TP->query_invis() || mrace == "goblin" || mname == "dryzil") {
        return;
    }
    call_out("coverass", 2, TP);
}

void coverass(object targ)
{
    force_me("block east");
    force_me("kill " + targ->query_name());
}
