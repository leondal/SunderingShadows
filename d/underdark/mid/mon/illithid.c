// adapted from laerad illithids
#include <std.h>
#include <daemons.h>
#include "../../defs.h"
inherit WEAPONLESS;
int hailed, done, nocone, stoned, stoning;

void create() {
    object ob;
    int num,droll;
    ::create();
    set_id(({"illithid","mind flayer","flayer"}));
    set_name("illithid");
    set_short("%^RESET%^%^MAGENTA%^A fearsome illithid%^RESET%^");
    set_long("%^CYAN%^Before you stands an ugly beast feared by surfacers and underdark travellers alike. "
"Known as illithids, or mind flayers, they are renowned for their psionic abilities. This specimen stands just "
"short of five feet tall, with skin of a %^MAGENTA%^dull violet hue%^CYAN%^, covered partially by a %^BLUE%^"
"dark robe%^CYAN%^. His round, hairless head bears two beady, intelligent eyes and four tentacles where there "
"would normally be a mouth. Despite his fragile appearance, an aura of %^RED%^power %^CYAN%^surrounds him."
"%^RESET%^");
    set_race("illithid");
    set_body_type("human");
    set_gender("male");
    set_alignment(9);
    set_nogo(({MID+"tunnel09","/d/dagger/kinaro/mines/lower2q"}));
    set_speed(60);
    set_moving(1);
    add_limb("first tentacle","head", 0, 0, 0);
    add_limb("second tentacle","head", 0, 0, 0);
    add_limb("third tentacle","head", 0, 0, 0);
    add_limb("fourth tentacle","head", 0, 0, 0);
    set_class("psion");
    set_hd(20,12);
    set_guild_level("psion",20);
    set_mlevel("psion",20);
    set_max_hp(400);
    set_hp(400);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_property("magic",1);
    set_stats("strength",19);
    set_stats("dexterity",18);
    set_exp(7000);
    set_overall_ac(-7);
    set("aggressive",25);
    set_spells(({"mind thrust","swarm of crystals","energy cone","energy cone","power leech","power leech","ultrablast"}));
    set_spell_chance(70);
    set_attack_limbs(({"first tentacle","second tentacle","third tentacle","fourth tentacle"}));
    set_attacks_num(4);
    set_base_damage_type("bludgeoning");
    set_damage(2,4);
    set_funcs(({"cone"}));
    set_func_chance(40);
    set_stabbed_func((:TO,"stabbed":));
    stoned = 0;
    stoning = 0;
    ob = new("/d/magic/scroll");
    ob->set_av_spell(random(3)+4);
    ob->move(TO);
}

void stabbed() {
    if(TO->query_hp() <= 0) return;
    force_me("emote screams in pain, and lashes out in retalliation.");
    execute_attack();
    return;
}

int kill_ob(object victim, int which) {
    int hold;
    hold = ::kill_ob(victim, which);
    if(hold) {
        if(nocone) return hold;
        call_out("cone",0,victim);
        nocone = 1;
        call_out("check_me",12);
    }
    return hold;
}

void cone(object targ) {
    if(!objectp(TO) || !objectp(targ)) return;
    if(!present(targ->query_name(),ETO)) return;
    if(targ->query_paralyzed()) {
        set_func_chance(0);
        execute_attack();
        set_func_chance(30);
        return 1;
    }
    tell_object(targ,"The illithid turns to you, and a mighty force assaults your mind!");
    tell_room(ETO,"The illithid turns its attention upon "+targ->QCN+".",targ);
    if(!SAVING_D->saving_throw(targ,"paralyzation_poison_death",-4)) {
        tell_object(targ,"You feel your body freeze up!");
        tell_room(ETO,targ->QCN+"'s body freezes up!",targ);
        targ->set_paralyzed(20+(random(10)),"Your muscles won't budge.");
        return 1;
    }
    tell_object(targ,"You struggle and throw off the psionic attack!");
    tell_room(ETO,targ->QCN+"'s eyes glaze over momentarily, before "+targ->QS+" seems to come back to "+targ->QP+" senses.",targ);
    return 1;
}

void heart_beat() {
    ::heart_beat();
    if(!objectp(TO) || !objectp(ETO)) return;
    if(TO->query_paralyzed()) return;
    if(!stoned) {
//        new("/cmds/psionics/_iron_body.c")->use_spell(TO,TO,22);
        stoned = 1;
    }
    if(!query_property("amorpha")) {
        new("/cmds/spells/c/_concealing_amorpha.c")->use_spell(TO,TO,22,100,"psion");
    }
    if(!sizeof(TO->query_attackers()) && !TO->query_stoneSkinned() && !stoning) {
//        new("/cmds/psionics/_iron_body.c")->use_spell(TO,TO,22);
        call_out("check_me",12,TP);
        stoning = 1;
    }
    if(!present("illithid summoned",ETO) && random(20) < 3) {
        if(done) return 1;
        new("/cmds/spells/c/_call_crystals.c")->use_spell(TO,0,22,100,"psion");
        done = 1;
        call_out("check_me",12,TP);
    }
    if(TO->query_hp() < 200 && present("kit",TO)) {
        force_me("quaff kit");
        force_me("quaff kit");
        force_me("quaff kit");
    }
    if(TO->query_hp() < 20 && sizeof(TO->query_attackers())) {
        TO->run_away();
    }
    if(!ETO->query_property("crystal_hailed") && !random(5) && sizeof(TO->query_attackers())) {
        if(hailed) return 1;
        new("/cmds/spells/h/_hail_of_crystals.c")->use_spell(TO,0,28,100,"psion");
        hailed = 1;
        call_out("check_me",12,TP);
    }
    return;
}

void check_me() {
    if(!objectp(TO)) return;
    done = 0;
    nocone = 0;
    hailed = 0;
    stoning = 0;
    return;
}

void set_paralyed(string message, int time) {
    return 1;
}
