#include <std.h>
#include "../ud_ruins.h"

inherit MONSTER;

void create() {
    ::create();
    set_name("Kuo-toa");
    set_id(({"kuo-toa","kuo toa","kuo","toa"}));
    set_short(
        "%^RESET%^"
        "%^CYAN%^a s%^GREEN%^t%^BOLD%^o%^BLACK%^c%^RESET%^%^GREEN%^k%^CYAN%^y "
        "k%^BOLD%^%^GREEN%^u%^RESET%^%^CYAN%^o%^BOLD%^-%^RESET%^%^CYAN%^t"
        "%^GREEN%^o%^CYAN%^a%^WHITE%^"
    );
    set_long(
        "%^GREEN%^This humanoid creature stands at about five feet tall, and is "
        "of roughly the same build as a dwarf, if that dwarf had a hunched back, "
        "w%^CYAN%^e%^GREEN%^bb%^CYAN%^e%^GREEN%^d f%^CYAN%^e%^GREEN%^et and a "
        "bizarre %^BOLD%^%^CYAN%^fish head %^RESET%^%^GREEN%^with "
        "%^CYAN%^b%^BOLD%^u%^RESET%^%^ORANGE%^l%^BOLD%^b%^RESET%^%^ORANGE%^o"
        "%^BOLD%^%^CYAN%^u%^RESET%^%^CYAN%^s%^GREEN%^, %^CYAN%^three-lidded "
        "eyes%^GREEN%^. It is surprisingly agile for its stature, and with its "
        "imposing, muscular physique, looks like it could more than hold its own "
        "both in and out of water.%^WHITE%^"
    );
    set_race("kuo-toa");
    set_body_type("human");
    set_hd(20,10);
    set_class("monk", 20);
    set_all_stats(({18,18,18,10,12,6}));
    set_alignment(8);
    set_size(2);
    set_property("swarm",1);
    set_exp(10000);
    set_overall_ac(-10);
    set_max_hp(300 + random(201));
    set_hp(query_max_hp());
    set_attacks_num(4);
    set_damage(2,6);
    set("aggressive",35);
    set_monster_feats(({
        "unarmed combat",
        "spinning kick",
        "rapid strikes",
        "improved rapid strikes",
        "unarmed parry",
        "knockdown",
    }));
    set_funcs(({"do_feats"}));
    set_func_chance(30);
    add_money("gold",random(500));
}

void do_feats(object target) {
    object *attackers;
    attackers = query_attackers();
    if(!sizeof(attackers)) { return; }
    if(sizeof(attackers) >= 2 && !query_property("using spinning kick") ) {
        force_me("spinning_kick");
    }
    else {
        object targ;
        targ = attackers[random(sizeof(attackers))];
        targ->add_id("kuo_knockdown");
        force_me("knockdown kuo_knockdown");
        targ->remove_id("kuo_knockdown");
    }
    TO->execute_attack();
    TO->execute_attack();
    TO->execute_attack();
}
