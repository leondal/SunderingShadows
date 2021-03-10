//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include <daemons.h>
#include "/d/shadow/room/goblin/short.h"
inherit MONSTER;

int FLAG, dlevel;
object ob;

void create()
{
    ::create();
    set_name("goblin");
    set_id(({ "goblin", "ranger", "goblin ranger" }));
    set_short("Goblin ranger");
    set("aggressive", 25);
//      set_wimpy(15);
//Stopping them from running as this makes it more difficult and
//less rewarding than it should be in a lowbie area. ~Circe~ 11/1/07
    set_long("This foul and ugly little creature is called a goblin ranger " +
             "though he bears no resemblance to the real rangers of the land. " +
             "They are Goblins of reknown ability to scout the lands for enemies " +
             "approaching the keep. They move with great stealth and can hear a " +
             "pin drop from a hundred yards. They also have impressive combat abilities.");
    dlevel = random(2) + 4;
    set_hd(dlevel, 2);
    set_class("fighter");
    set_mlevel("fighter", dlevel);
    add_search_path("/cmds/fighter");
    set_body_type("human");
    set_stats("intelligence", 8);
    set_stats("wisdom", 8);
    set_stats("strength", 15);
    set_stats("charisma", 3);
    set_stats("dexterity", 18);
    set_stats("constitution", 13);
    set_alignment(9);
    set_max_level(7);
    set_race("goblin");
    set_overall_ac(4);
    //set_exp(dlevel*40);
//        set_exp(500);
    set_new_exp(dlevel, "very high");
    set_max_hp((random(10) + 30 + (dlevel * 6)));
    set_hp(query_max_hp());
    set_achats(3, ({
        "%^CYAN%^Goblin squeaks: %^RESET%^Me messin' you up bad!  Yup!  Yup!",
        "Goblin ranger snarls and spits at you.",
        "Goblin ranger swings his bow wildly at you.",
        "%^CYAN%^Goblin: %^RESET%^You mommie, she be fat!",
        "%^CYAN%^Goblin: %^RESET%^You weak, me STRONG!",
        "Goblin ranger moves nearer the stairs and looks for a place to run.",
        "%^CYAN%^Goblin screams: %^BOLD%^%^RED%^GET OUT!!%^RESET%^",
    }));
    set_emotes(3, ({
        "Goblin ranger peers across the lands.",
        "Goblin ranger examines the forest closely.",
        "%^CYAN%^Goblin squeaks: %^RESET%^None make stronghold and be let to live!",
        "Goblin ranger nibbles on some elven bread.",
        "Goblin ranger sniffs the air for clean smells.",
    }), 0);
    add_money("gold", random(70) + 20);
    add_money("silver", random(150) + 35);
    add_money("copper", random(1500) + 150);
    switch (random(5)) {
    case 0..1:
        new(OPATH "bow")->move(TO);
        command("wield bow");
        break;

    case 2..3:
        new("/d/common/obj/weapon/longsword")->move(TO);
        command("wield sword");
        break;

    case 4:
        ob = new("/d/common/obj/weapon/longsword");
        ob->move(TO);
        ob->set_property("enchantment", 1);
        ob->set_long(ob->query_long() + "This particular sword seems sharper than most, and its"
                     " blade glitters in the light.");
        command("wield sword");
        break;
    }
    new("/d/dagger/drow/obj/bread")->move(TO);
//      set_property("full attacks",1);
    ob = new("/d/common/obj/potion/healing");
    ob->move(TO);
    ob->set_uses(random(2) + 3);
    FLAG = 0;
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
    if (!objectp(targ) || !objectp(TO)) {
        return;
    }
    force_me("kill " + targ->query_name());
    if (FLAG == 1) {
        return;
    }
    force_me("block down");
    force_me("parry");
    FLAG = 1;
}

void heart_beat()
{
    ::heart_beat();
    if (!objectp(TO)) {
        return;
    }
    if (present("kit") && query_hp() < query_max_hp() / 2) {
        command("open kit");
        command("quaff kit");
        command("offer bottle");
    }
    if (present("bottle", TO)) {
        command("offer bottle");
    }
    if (FLAG == 0) {
        return;
    }
    if (query_attackers() != ({})) {
        FLAG = 0;
    }
    return;
}
