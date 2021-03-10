#include <std.h>
#include "../arctic.h"
inherit CREATURE;

int FLAG;

void create() {
        
    ::create();
    set_name("Stomach Lining");
    set_id(({"stomach lining", "lining","arcticmon"}));
    set_race("stomach lining");
    set_body_type("snake");
    set_gender("neuter");
    set_size(2);
    set_short("%^RED%^stomach lining%^RESET%^");
    set_long("%^BOLD%^%^RED%^The stomach lining of the shark is "
        "bulbous and pasty pink.  Acidic secretions spew forth in "
        "small quantities, burning into your flesh and making "
        "it very difficult to breathe here.%^RESET%^");
    set_hd(30, 1);
    set_level(30);
    set_class("fighter");
    set_mlevel("fighter", 30);
    set_hp(500);
    set_exp(5000);
    set_property("swarm", 1);
    set_overall_ac(0);
    set_attacks_num(1);
    set_mob_magic_resistance("average");
    set_base_damage_type("piercing");
    add_limb("bulbous protrusion", "head", 0, 0, 0);
    set_attack_limbs(({"bulbous protrusion"}));
    remove_limb("head");
    remove_limb("mouth");
    remove_limb("tail");
    remove_limb("torso");
    set("aggressive", 25);
    set_funcs(({"burn"}));
    set_func_chance(100);
    set_property("water breather", 1);
    set_invis();
    FLAG = 0;
}


void burn()
{
    object *live;
    object *fodder;
    object targ;
    int i = 0;
    int x;
 
    live = all_inventory(ETO);
    fodder = live;

    fodder = filter_array(fodder, "is_fodder",CREATURE);
    live = filter_array(live, "is_non_immortal_player", FILTERS_D);
    live += fodder;

    for(i=0;i<sizeof(live);i++)
    {
        targ = live[i];
        if(!objectp(targ)) continue;

        if(!ROLLSAVE(targ, BW ))
        {
            tell_object(targ,"%^BOLD%^%^GREEN%^The churning "
                "stomach juices burn into you, blistering your "
                "flesh!%^RESET%^");
            tell_room(ETO,"%^BOLD%^%^GREEN%^"+targ->QCN+" "
                "is burned by the churning stomach juices!%^RESET%^",targ);
            TO->set_property("magic", 1);
            targ->do_damage("torso", roll_dice(3,6));
            TO->set_property("magic", -1);
            continue;
        }

        tell_object(targ,"%^BOLD%^%^GREEN%^The churning "
            "stomach juices burn into you, blistering your "
            "flesh!%^RESET%^");
        tell_room(ETO,"%^BOLD%^%^GREEN%^"+targ->QCN+" "
            "is burned by the churning stomach juices!%^RESET%^",targ);
        TO->set_property("magic", 1);
        targ->do_damage("torso", roll_dice(3,6)/2);
        TO->set_property("magic", -1);
        continue;

        if(i > 1000) { tell_room(ETO,"loop error burn() "
            "in "+MON+"stomach_lining.c"); break; } 

    }

}

void die(object ob)
{
    object obj,*shark;

    tell_room(ETO, "%^RED%^The mangled stomach lining rips apart and "
        "a gash forms in the side of the shark!%^RESET%^");
    ETO->add_exit(UW"bottom", "gash");
    ETO->set_functions();
    obj = find_object_or_load(UW"bottom.c");
    obj->add_exit(UW"shark_stomach", "crawl");
    obj->set_invis_exits(({"crawl"}));
    obj->set_functions();

    if(shark=present("dire shark",obj))
    {
        tell_room(UW"bottom", "%^MAGENTA%^The shark thrashes madly about "
            "as if in great pain!\n%^RESET%^");
        shark->do_damage("torso", 500);
        shark->add_attacker(TO);
        shark->continue_attack();
        shark->remove_attacker(TO);
    }

    tell_room(obj, "%^RED%^A gash large enough to crawl into "
        "forms on the stomach of the shark as something inside cuts its "
        "way out!\n%^RESET%^");
    remove();
    return;
}

