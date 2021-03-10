#include <std.h>
#include <magic.h>
#include <daemons.h>
#include "../ud_ruins.h"

inherit WEAPONLESS;

void create() {
    ::create();
    set_name("Caller in Darkness");
    set_id(({"caller","darkness","caller in darkness","black cloud","screaming cloud", "cloud"}));
    set_short(
        "%^BOLD%^%^BLACK%^a "
        "s%^RESET%^c%^BOLD%^%^RED%^r%^RESET%^e%^BOLD%^%^BLACK%^a%^RED%^m"
        "%^RESET%^i%^BOLD%^%^BLACK%^ng b%^RESET%^l%^BOLD%^%^BLACK%^a"
        "%^RED%^c%^BLACK%^k c%^RESET%^l%^BOLD%^%^BLACK%^o%^RED%^u%^BLACK%^d"
        "%^RESET%^"
    );
    set_long(
        "%^BOLD%^%^BLACK%^This "
        "p%^RESET%^u%^BOLD%^%^BLACK%^l%^RESET%^s%^BOLD%^a%^RESET%^t"
        "%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^%^BLACK%^g "
        "m%^RESET%^a%^BOLD%^%^BLACK%^s%^RESET%^s %^BOLD%^%^BLACK%^of "
        "d%^RESET%^a%^BOLD%^%^BLACK%^rk "
        "e%^RESET%^n%^BOLD%^%^BLACK%^e%^WHITE%^r%^RESET%^g%^BOLD%^%^BLACK%^y "
        "seems to expand to fill the entire room, and the temperature plummets "
        "to nothing when it does. Its body is little more than a black cloud, "
        "with hundreds of small, tortured %^RESET%^%^ORANGE%^faces "
        "%^BOLD%^%^BLACK%^swirling about within, their expressions twisted into "
        "looks of %^RED%^pain %^BLACK%^and %^GREEN%^horror%^BLACK%^. The sound of "
        "%^ORANGE%^screaming %^BLACK%^pours forth from this creature at all "
        "times, and the ceaseless echoes of the slaughtered are painful as they "
        "reverberate through your mind.%^RESET%^"
    );
    set_race("undead");
    set_body_type("snake");
    set_hd(30,13);
    set_class("psion");
    set_mlevel("psion",25);
    set_guild_level("psion",25);
    add_search_path("/cmds/psion");
    set_all_stats(({12,12,12,24,24,24}));
    set_alignment(9);
    set_gender("neuter");
    set_size(4);
    set_property("swarm",1);
    set_property("no animate", 1);
    set_property("no dominate", 1);
    set_property("no death", 1);
    set_property("no bows", 1);
    set_property("no knockdown", 1);
    set_property("no paralyze", 1);
    set_property("no hold", 1);
    set_property("no web", 1);
    set_property("no trip", 1);
    set_property("no poison", 1);
    set_property("no random treasure", 1);
    set_property("weapon resistance", 1);
    set_exp(30000);
    set_overall_ac(-6);
    set_max_hp(1500);
    set_hp(1500);
    set_attack_limbs( ({"mouth"}) );
    set_attacks_num(6);
    set_base_damage_type("mental");
    set_damage(2,8);
    set_mob_magic_resistance("average");
    set("aggressive",35);
    set_funcs(({"do_round"}));
    set_func_chance(100);
}

void do_scream() {
    object *attackers;
    int i,j;
    if(!objectp(TO)) { return; }
    attackers = query_attackers();
    if(!sizeof(attackers)) { return 0; }
    j = sizeof(attackers);
    for(i=0;i<j;i++) {
        tell_object(attackers[i],
            "%^YELLOW%^An unearthly, agonized %^RED%^scream %^ORANGE%^rips "
            "through you!"
        );
        attackers[i]->cause_typed_damage(attackers[i],"head",roll_dice(3,8),"sonic");
    }
    call_out("do_scream",ROUND_LENGTH);
}

void do_round(object target) {
    // Possible actions per round:
    // 40% - "Melee" attacks (mental type, assuming it works like this)
    // 20% - Ultrablast
    // 20% - Recall death
    // 10% - Unravel psionics
    // 10% - Microcosm
    // Plus, 1d8 sonic damage per round
    if(find_call_out("do_scream") == -1) {
        do_scream();
    }
    switch(random(100)) {
        case 0..39:
            execute_attack();
            execute_attack();
            execute_attack();
            execute_attack();
            execute_attack();
            execute_attack();
            break;
        case 40..59:
            new("/cmds/spells/u/_ultrablast")->use_spell(TO,target,25,1000,"psion");
            break;
        case 60..79:
            new("/cmds/spells/r/_recall_death")->use_spell(TO,target,25,1000,"psion");
            break;
        case 80..89:
            new("/cmds/spells/d/_dispel_psionics")->use_spell(TO,0,25,1000,"psion");
            break;
        case 90..99:
            new("/cmds/spells/m/_microcosm")->use_spell(TO,target,25,1000,"psion");
            break;
    }
}

void die(object ob) {
    int dropped;
    if(!objectp(TO)) { return; }
    tell_room(ETO,
        "%^BOLD%^%^BLACK%^With a final deafening %^ORANGE%^scream%^BLACK%^, "
        "the Caller implodes upon itself, vanishing instantly!"
    );
    dropped = 0;
    if(!random(3)) {
        new(OBJ"attunement_clasp")->move(ETO);
        dropped = 1;
    }
    if(!random(3)) {
        new(OBJ"pugilists_robe")->move(ETO);
        dropped = 1;
    }
    if(!random(3)) {
        new(OBJ"illusion_powder")->move(ETO);
        dropped = 1;
    }
    if(dropped){
        tell_room(ETO,
            "%^BOLD%^%^BLACK%^There seems to be something left on the ground."
        );
    }
    TO->move("/d/shadowgate/void");
    TO->remove();
}
