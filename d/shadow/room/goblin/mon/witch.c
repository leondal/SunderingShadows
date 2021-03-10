//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//beefed up and made more evil by Diego & Styx after Newbietown opened 7/14/01
//last change had been 12/98

#include <std.h>
#include <daemons.h>
#include "/d/shadow/room/goblin/short.h"
inherit MONSTER;

int xx, dlevel;

void create()
{
    object ob;
    ::create();
    set_name("witch");
    set_id(({ "goblin", "witch", "goblin witch" }));
    set_short("Goblin witch");
    set("aggressive", 15);
    set_long("The female Goblin before you is the witch of the Goblin " +
             "Army of Shadow.  She practices the ancient art of the witches " +
             "and has a strong bind to the witchen coven.  Her eyes blaze " +
             "with an inner power.");
// tuned again after a newbie got blased 70+ dam in 2 rounds *Styx* 10/11/05
    dlevel = random(3) + 4;
    set_hd(dlevel, 3);
    set_level(dlevel);
    set_class("mage");
    set_guild_level("mage", dlevel);
    set_mlevel("mage", dlevel);
    set_class("fighter");
    set_mlevel("fighter", dlevel);
    set_property("no steal", 1);
    set_body_type("human");
    set_alignment(9);
    set_race("goblin");
    set_gender("female");
    set_ac(6);
    set_stats("dexterity", 17);
    set_stats("wisdom", 18);
    set_stats("intelligence", 18);
    //set_exp(dlevel*100);
//        set_exp(700);
    set_new_exp(7, "very high");
    set_max_hp((random(20) + 5 + (dlevel * 7)));
    set_hp(query_max_hp());
    set_achats(3, ({
        "Witch points at you with her bony finger.",
        "Witch claws at your eyes.",
        "Witch licks her lips and looks at you hungrily.",
        "Witch screams something you don't understand and then glares at you.",
        "%^CYAN%^Witch cackles: %^RESET%^Me give you da hot bath mebbe?!?!\n" +
        "%^CYAN%^Witch cackles: %^RESET%^Into cauldron you goes!\n" +
        "Witch giggles insanely",
    }));
    set_emotes(3, ({
        "Witch cackles gleefully.",
        "%^CYAN%^Witch cackles: %^RESET%^Mandrake root...need mo' mandrake!",
        "Witch mutters a short phrase.",
        "%^CYAN%^Witch cackles: %^RESET%^Me cook you up in da pot methinks!",
        "%^BLUE%^A black cat strolls into the room, looks the witch "
        "over, and then leaves.%^RESET%^",
    }), 0);
    add_money("gold", random(200) + 50);
    add_money("silver", random(1200) + 150);
    add_money("copper", random(11500) + 500);
    switch (random(5)) {
    case 0:
        new(OPATH "necklace.c")->move(TO);
        command("wear necklace");

    case 1..2:
        ob = new("/d/magic/scroll");
        ob->set_spell(3);
        ob->move(TO);

    case 3:
        new(OPATH "insanity.c")->move(TO);
        break;

    case 4:
        new(OPATH "whip.c")->move(TO);
        command("wield whip");
        break;
    }
    set_spell_chance(50);
    set_spells(({ "burning hands", "magic missile", "color spray", "scorcher" }));
    set_funcs(({ "special_spell" }));
    set_func_chance(35);
    add_search_path("/cmds/fighter");
    add_search_path("/cmds/mage");
    set_max_level(9);
}

int special_spell(object targ)
{
    object me = TO;
    object vic = me->query_current_attacker();
    if (!objectp(TO)) {
        return 1;
    }
    if (!objectp(ETO)) {
        return 1;
    }
    xx = random(4) + 1;
    switch (xx) {
    case 1:
        tell_object(vic, "%^BOLD%^%^RED%^Witch hurls a bolt of pure " +
                    "evil at you!");
        tell_room(ETO, "%^BOLD%^%^RED%^Witch hurls a bolt of pure " +
                  "evil at " + vic->query_cap_name() + "!", vic);
        vic->do_damage("torso", random(20) + 3);
        return 1;

    case 2..3:
        tell_object(vic, "%^GREEN%^Witch cackles and a swarm of " +
                    "spiders cover you!");
        tell_room(ETO, "%^GREEN%^Witch cackles and a swarm of " +
                  "spiders cover " + vic->query_cap_name() + "!\n%^BLUE%^You " +
                  "mutter a small word of thanks that it was not you.", vic);
        vic->do_damage("torso", random(10) + 10);
        return 1;

    case 4:
        tell_object(vic, "%^BOLD%^%^BLUE%^Witch invokes fear within you!");
        tell_room(ETO, "%^BOLD%^%^BLUE%^" + vic->query_cap_name() + " runs " +
                  "screaming from the room!", vic);
//              vic->force_me("west");
        vic->run_away();
        vic->run_away();
        vic->run_away();
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
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(targ)) {
        return;
    }
    force_me("block west");
    force_me("kill " + targ->query_name());
}
