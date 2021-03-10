// gnoll.c - Gnoll for newbietown

#include <std.h>
#include "../newbie.h"

inherit "/std/monster";

int count;

void create()
{
    ::create();
    set_name("gnoll");
    set_id(({ "gnoll" }));
    set_race("gnoll");
    set_gender("male");
    set_short("Hungry gnoll");
    set_long("%^GREEN%^This creature looks a lot like a huge hyena that stands upright at over 8 ft. tall.  Its greenish gray skin is darker near the muzzle and it has a scruffy, reddish gray mane.");
    set_hd(5, 2);
    set_level(5);
    set_class("fighter");
    set_mlevel("fighter", 5);
    add_search_path("/cmds/fighter");
    set_body_type("human");
    set("aggressive", 12);
    set_alignment(3);
    set_size(3);
    set_overall_ac(9);
    set_stats("intelligence", 10);
    set_stats("wisdom", 8);
    set_stats("strength", 16);
    set_stats("charisma", 5);
    set_stats("dexterity", 13);
    set_stats("constitution", 17);
    set_hp(random(15) + 30);
    set_max_hp(query_hp());
    set_property("swarm", 1);
    set_wielding_limbs(({ "right hand", "left hand" }));
    switch (random(3)) {
    case 0:
        new(CWEAP "morningstar")->move(TO);
        command("wield morningstar");
        new(ARMOR "shieldcrude")->move(TO);
        command("wear shield");
        new(FOREST "stuff/deadrat")->move(TO);
        break;

    case 1:
        new(CWEAP "khopesh")->move(TO);
        command("wield khopesh");
        new(ARMOR "shieldcrude")->move(TO);
        command("wear shield");
        new(FOREST "stuff/snakemeat")->move(TO);
        break;

    case 2:
        new(CWEAP "sickle")->move(TO);
        command("wield sickle");
        new(CMISC "climb_tool")->move(TO);
        new(ARMOR "lrobe")->move(TO);
        command("wear robe");
    }
    new(ARMOR "lhide")->move(TO);
    command("wear hide");
    set_exp(100);
    add_money("gold", random(110) + 30);
    add_money("silver", random(200));
    add_money("electrum", random(200));
    set_chats(2, ({ "%^GREEN%^The gnoll bares its teeth at you.", "%^GREEN%^The hungry gnoll seems to be sizing you up for a meal and drools disgustingly.", "%^GREEN%^The gnoll licks some fresh blood from its weapon and pulls some raw meat from a pouch to gnaw on as it eyes you hungrily." }));
    set_achats(3, ({ "%^GREEN%^The gnoll takes a brutal swing at you with its weapon.", "%^GREEN%^The gnoll snarls and lunges for your throat!!", "%^GREEN%^The gnoll crouches before lunging at you with its weapon again.", "%^GREEN%^The gnoll glances over its shoulder before closing to attack again.", "%^BOLD%^Maybe you should RUN and practice on bats and rats instead!" }));
}
