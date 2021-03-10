#include <std.h>
#include <daemons.h>


inherit WEAPONLESS;

int tried_block;

void create() {
    ::create();
    set_name("Sword Spider");
    set_id(({"sword spider","spider","giant spider"}));
    set_short(
        "%^RESET%^"
        "%^ORANGE%^a giant %^BOLD%^%^BLACK%^blade-legged "
        "%^RESET%^%^ORANGE%^spider%^WHITE%^"
    );
    set_long(
        "%^ORANGE%^This giant spider is about twelve feet across from one end "
        "to the other, and almost as tall. It has a "
        "d%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^rk, "
        "c%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^a%^WHITE%^r%^GREEN%^s%^ORANGE%^e"
        "%^BOLD%^%^WHITE%^l%^RESET%^%^ORANGE%^y-f%^WHITE%^u%^ORANGE%^r"
        "%^BOLD%^%^BLACK%^re%^RESET%^%^ORANGE%^d body with "
        "%^BOLD%^%^BLACK%^black stripes %^RESET%^%^ORANGE%^running along its "
        "length, and each of its eight legs is tipped with a "
        "%^BOLD%^%^WHITE%^s%^BLACK%^e%^WHITE%^r%^BLACK%^r%^WHITE%^a%^BLACK%^t"
        "%^RESET%^e%^BOLD%^d c%^BLACK%^h%^WHITE%^i%^RESET%^t%^BOLD%^i%^BLACK%^n"
        "%^WHITE%^o%^BLACK%^u%^WHITE%^s p%^BLACK%^l%^WHITE%^a%^BLACK%^t%^WHITE%^e "
        "%^RESET%^%^ORANGE%^that looks more than capable of lopping off a "
        "limb. It seems to constantly scan its surroundings with its many "
        "watchful eyes, in search of its latest meal.%^WHITE%^"
    );
    set_race("spider");
    set_body_type("arachnid");
    set_hd(20,10);
    set_class("fighter");
    set_mlevel("fighter",20);
    set_guild_level("fighter",20);
    add_search_path("/cmds/fighter");
    set_all_stats(({18,18,20,1,14,10}));
    set_alignment(5);
    set_size(3);
    set_property("swarm",1);
    set_exp(15000);
    set_overall_ac(-10);
    set_max_hp(200+roll_dice(1,100));
    set_hp(query_max_hp());
    set_attack_limbs( ({"left foreleg","right foreleg"}) );
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_funcs(({"slash","slash","jumpattack"}));
    set_func_chance(30);
    set_damage(2,8);
    set("aggressive",35);
    if(random(4)) {
        set_hidden(20);
    }
    tried_block = 0;
}

void slash(object target) {
    object *players;
    int i,j;
    players = filter_array(all_inventory(ETO),"is_non_immortal_player",FILTERS_D);
    tell_room(ETO,
        "%^ORANGE%^The sword spider lashes out with one of its "
        "%^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^ad"
        "%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^d "
        "l%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^gs%^RESET%^%^ORANGE%^, swinging "
        "at all before it in a %^BOLD%^%^RED%^vicious %^RESET%^%^ORANGE%^arc!"
    );
    j = sizeof(players);
    for(i=0;i<j;i++) {
        object targ;
        targ = players[i];
        if (!targ->reflex_save(25)) {
            tell_object(targ,
                "%^BOLD%^%^BLACK%^The spider cuts a nasty %^RED%^gash %^BLACK%^in "
                "your chest!"
            );
            targ->cause_typed_damage(targ,"torso",20+random(31),"slashing");
        }
        else {
            tell_object(targ,
                "%^YELLOW%^You manage to dodge out of the way!"
            );
        }
    }
    execute_attack();
}

void jumpattack(object target) {
    tell_object(target,
        "%^ORANGE%^The sword spider leaps into the air and brings its frontmost "
        "two legs together as it comes down, forming a %^BOLD%^%^RED%^deadly "
        "spear %^RESET%^%^ORANGE%^aimed directly at you!"
    );
    tell_room(ETO,
        "%^ORANGE%^The sword spider leaps into the air and brings its frontmost "
        "two legs together as it comes down, forming a %^BOLD%^%^RED%^deadly "
        "spear %^RESET%^%^ORANGE%^aimed directly at "+target->QCN+"!"
    ,({target}));
    if(!target->reflex_save(25)) {
        tell_object(target,
            "%^BOLD%^You are %^RED%^impaled %^WHITE%^upon the spider's legs!"
        );
        tell_room(ETO,
            "%^BOLD%^"+target->QCN+" is %^RED%^impaled %^WHITE%^upon the "
            "spider's legs!"
        ,({target}));
        target->cause_typed_damage(target,"torso",70+random(61),"piercing");
    }
    else {
        tell_object(target,
            "%^BOLD%^You twist out of the way, taking only a scratch to "
            "your side!"
        );
        tell_room(ETO,
            "%^BOLD%^"+target->QCN+" twists out of the way, taking only a "
            "scratch to "+target->QP+" side!"
        ,({target}));
        target->cause_typed_damage(target,"torso",45+random(41),"piercing");
    }
}

void heart_beat() {
    ::heart_beat();
    if(!objectp(TO)) { return; }
    if(objectp(ETO) && !tried_block) {
        if(!random(2)){
            string *exits;
            int i,j;
            exits = ETO->query_exits();
            j = sizeof(exits);
            for(i=0;i<j;i++) {
                if(!ETO->query_blocked(exits[i])) {
                    force_me("block " + exits[i]);
                    break;
                }
            }
        }
        tried_block = 1;
    }
}
