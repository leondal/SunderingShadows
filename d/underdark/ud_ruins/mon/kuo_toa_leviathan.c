#include <std.h>
#include <magic.h>
#include <daemons.h>
#include "../ud_ruins.h"

inherit MONSTER;

int grab_count;

void create() {
    ::create();
    set_name("Kuo-toa Leviathan");
    set_id(({"kuo-toa","kuo toa","kuo","toa","leviathan"}));
    set_short(
        "%^RESET%^"
        "%^CYAN%^a "
        "g%^GREEN%^a%^BOLD%^r%^RESET%^%^GREEN%^g%^CYAN%^a%^BOLD%^%^BLACK%^n"
        "%^RESET%^%^GREEN%^t%^BOLD%^u%^RESET%^%^GREEN%^a%^CYAN%^n "
        "k%^BOLD%^%^GREEN%^u%^RESET%^%^CYAN%^o-t%^GREEN%^o%^CYAN%^a "
        "l%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^v%^BOLD%^%^BLACK%^i"
        "%^RESET%^%^GREEN%^a%^CYAN%^t%^GREEN%^h%^BOLD%^a%^RESET%^%^CYAN%^n"
        "%^WHITE%^"
    );
    set_long(
        "%^GREEN%^This hulking %^BOLD%^%^RED%^behemoth %^RESET%^%^GREEN%^of a "
        "kuo-toa is at least twenty five feet tall, and boasts a massive frame "
        "that would dwarf even some giants! Its head is that of a large "
        "%^BOLD%^%^CYAN%^fish%^RESET%^%^GREEN%^, with "
        "%^ORANGE%^b%^WHITE%^u%^YELLOW%^l%^RESET%^b%^ORANGE%^o%^BOLD%^u"
        "%^RESET%^%^ORANGE%^s%^GREEN%^, "
        "%^ORANGE%^t%^WHITE%^h%^YELLOW%^r%^RESET%^e%^ORANGE%^e-l%^BOLD%^i"
        "%^RESET%^%^ORANGE%^d%^WHITE%^d%^YELLOW%^e%^RESET%^%^ORANGE%^d "
        "e%^BOLD%^y%^RESET%^e%^ORANGE%^s %^GREEN%^that stare emptily out at its "
        "surroundings, and its mouth is lined with hundreds of "
        "%^BOLD%^%^WHITE%^razor sharp teeth %^RESET%^%^GREEN%^ideal for chewing "
        "up the rare creatures it could not swallow whole. A single, sharp fin "
        "runs down its back, and its giant webbed hands certainly do not look "
        "like something you would want to be caught within.%^WHITE%^"
    );
    set_race("kuo-toa");
    set_body_type("giant");
    set_hd(20,10);
    set_class("monk", 30);
    set_all_stats(({24,18,24,10,16,6}));
    set_alignment(7);
    set_size(3);
    set_property("swarm",1);
    set_property("swarm",1);
    set_property("no animate", 1);
    set_property("no dominate", 1);
    set_property("no bows", 1);
    set_property("no knockdown", 1);
    set_property("no paralyze", 1);
    set_property("no hold", 1);
    set_property("no web", 1);
    set_property("no trip", 1);
    set_property("no poison", 1);
    set_mob_magic_resistance("average");
    set_property("no random treasure", 1);
    set_exp(50000);
    set_overall_ac(-12);
    set_max_hp(900 + random(201));
    set_hp(query_max_hp());
    set_damage(2,10);
    // set_property("full attacks",1);
    set_attacks_num(6);
    set("aggressive",35);
    set_monster_feats(({
        "unarmed combat",
        "rapid strikes",
        "improved rapid strikes",
        "unarmed parry",
    }));
    set_funcs(({"grab","wave","wave"}));
    set_func_chance(30);
    add_money("gold",100+random(1000));
    add_money("platinum",100+random(1000));
    grab_count = -1;
}

void grab(object target) {
    // Grabs the target player and attempts to drown them.
    // Fort save or damage equal to 1/2 max HP if unable to breathe water.
    // (This may need tuning down - try 1/3 max hp damage if this proves too harsh.)
    // 25d4 bludgeoning damage if target is breathing water.
    tell_object(target,
        "%^BOLD%^%^CYAN%^The leviathan swings one of its massive webbed hands "
        "in front of itself, attempting to catch you in its grasp!"
    );
    tell_room(ETO,
        "%^BOLD%^%^CYAN%^The leviathan swings one of its massive webbed hands "
        "in front of itself, attempting to catch "+target->QCN+" in its grasp!"
    ,({target}));
    if(!target->fort_save(25)) {
        tell_object(target,
            "%^BOLD%^%^RED%^You are caught in the leviathan's grasp and "
            "dragged under the water!"
        );
        tell_room(ETO,
            "%^BOLD%^%^RED%^"+target->QCN+" is caught in the leviathan's grasp "
            "and dragged under the water!"
        ,({target}));
        if(target->query_property("water breather")){
            tell_object(target,
                "%^BOLD%^%^RED%^You immunity to drowning saves you from fatal "
                "damage, but you are still bruised badly as you wrench "
                "yourself free!"
            );
            tell_room(ETO,
                "%^BOLD%^%^RED%^"+target->QCN+" wrenches "+target->QO+"self free!"
            ,({target}));
            target->cause_typed_damage(target,"torso",roll_dice(25,4),"bludgeoning");
            return;
        }
        tell_object(target,
            "%^BOLD%^%^BLUE%^After many moments of struggle you run out of "
            "breath, and your body %^WHITE%^convulses %^BLUE%^as your lungs "
            "fill with water!"
        );
        tell_room(ETO,
            "%^BOLD%^%^BLUE%^"+target->QCN+" struggles under the leviathan's grasp, "
            "but soon begins to %^WHITE%^drown%^BLUE%^!"
        ,({target}));
        target->set_hp((int)target->query_hp() - ((int)target->query_max_hp() / 2));
        target->do_damage("head",0);
        return;
    }
    else {
        tell_object(target,
            "%^BOLD%^You are able to avoid the leviathan's grasp!"
        );
        tell_room(ETO,
            "%^BOLD%^"+target->QCN+" is able to avoid the leviathan's grasp!"
        ,({target}));
        return;
    }
}

void wave(object target) {
    // Deals 10d10 bludgeoning damage to every attacker.
    // Fort 25 save or paralyze for 1d2 rounds.
    object *players;
    int i,j;
    tell_room(ETO,
        "%^BOLD%^%^BLUE%^The leviathan smashes one hand into the water, "
        "conjuring a %^CYAN%^massive wave %^BLUE%^that crashes down upon all "
        "before it!"
    );
    players = filter_array(all_inventory(ETO),"is_non_immortal_player",FILTERS_D);
    j = sizeof(players);
    for(i=0;i<j;i++) {
        object targ;
        targ = players[i];
        targ->cause_typed_damage(targ,"torso",roll_dice(10,10),"bludgeoning");
        if (!targ->fort_save(25)) {
            tell_object(targ,
                "%^BOLD%^%^CYAN%^You are knocked off your feet!"
            );
            tell_room(ETO,
                "%^BOLD%^%^CYAN%^"+targ->QCN+" is knocked off "+targ->QP+" feet!"
            ,({targ}));
            targ->set_paralyzed(
                ROUND_LENGTH * roll_dice(1,2),
                "%^BOLD%^%^CYAN%^You are floundering about in the water!"
            );
        }
    }
}

void die(object ob) {
    if(!random(3)) {
        new(OBJ"mistblade")->move(TO);
    }
    if(!random(3)) {
        new(OBJ"kuo_bow")->move(TO);
    }
    if(!random(3)) {
        new(OBJ"fomorian_leather")->move(TO);
    }
    ::die();
}
