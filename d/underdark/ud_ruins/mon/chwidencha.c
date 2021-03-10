#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

int is_dead;

void create() {
    ::create();
    set_name("Chwidencha");
    set_id(({"chwidencha","spider","abomination"}));
    set_short(
        "%^BOLD%^%^BLACK%^a h%^RESET%^o%^BOLD%^%^BLACK%^rr%^RESET%^i%^BOLD%^b"
        "%^BLACK%^le "
        "s%^RESET%^p%^RED%^i%^WHITE%^d%^BOLD%^e%^BLACK%^r-l%^WHITE%^i"
        "%^RESET%^k%^BOLD%^%^BLACK%^e "
        "a%^RESET%^b%^BOLD%^%^BLACK%^o%^WHITE%^m%^RED%^i%^RESET%^n"
        "%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^i%^RED%^o"
        "%^BLACK%^n%^RESET%^"
    );
    set_long((:TO,"look_func":));
    set_race("abomination");
    set_body_type("arachnid");
    set_gender("female");
    set_hd(25,10);
    set_class("fighter",25);
    add_search_path("/cmds/fighter");
    set_all_stats(({20,20,20,18,18,24}));
    set_alignment(5);
    set_size(2);
    set_property("swarm",1);
    set_exp(20000);
    set_overall_ac(-12);
    set_max_hp(600);
    set_hp(600);
    set_attack_limbs( ({"right foreleg","left foreleg",
                        "right mid leg","left mid leg",
                        "right tertiary leg", "left tertiary leg",
                        "right rear leg","left rear leg",
                    }) );
    set_attacks_num(8);
    set_base_damage_type("slashing");
    set_damage(2,6);
    set_mob_magic_resistance("average");
    set("aggressive",18);
    is_dead = 0;
}

void look_func(){
    string res;
    res =
    "%^BOLD%^%^BLACK%^This horrifying abomination appears to be little "
    "more than a writhing, skittering mass of hairy, flexible tarantula "
    "legs, each tipped with a deadly-looking barb. Roughly as long as a "
    "human from one end to the other, it is difficult to predict this "
    "bizarre creature's movements.";
    if (is_dead) {
        res += " Underneath the tangle of spider legs, you can just make out the "
        "humanoid form of what used to be a %^MAGENTA%^drow%^BOLD%^%^BLACK%^, "
        "her expression twisted into an image of utter agony and sadness.";
    }
    res += "%^RESET%^";
    return res;
}

void frenzy() {
    object *players;
    int i,j;
    tell_room(ETO,"test");
    players = filter_array(all_inventory(ETO),"is_non_immortal_player",FILTERS_D);
    j = sizeof(players);
    if (j) {
        tell_room(ETO,
            "%^BOLD%^%^RED%^The creature attacks everything nearby in a frenzy "
            "of razor-sharp slashes!"
        );
    }
    for(i=0;i<j;i++) {
        object targ;
        int x,rnd;
        targ = players[i];
        rnd = random(6) + 1;
        for(x=0;x<rnd;x++) {
            tell_object(targ,
                "%^BOLD%^%^RED%^A wild slash cuts into you!"
            );
            targ->cause_typed_damage(targ,"torso",roll_dice(1,8),"slashing");
        }
    }
}

void die(object ob) {
    is_dead = 1;
    tell_room(ETO,
        "%^BOLD%^%^BLACK%^The spider begins %^RESET%^%^MAGENTA%^sobbing "
        "%^BOLD%^%^BLACK%^as its legs collapse beneath the weight of its own "
        "body. It falls into a motionless heap, and its mournful cries are "
        "gradually replaced by gutteral choking, and then silence as the "
        "creature dies."
    );
    return ::die(ob);
}
