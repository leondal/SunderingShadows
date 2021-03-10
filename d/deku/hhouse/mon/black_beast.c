#include <std.h>
#include "../inherits/area_stuff.h"
#include <daemons.h>
inherit WEAPONLESS;

object stomach;
int flag;

void create() 
{
    ::create();
    set_name("black beast");
    set_id(({"beast","black beast", "monstrous black beast"}));
    set_gender("neuter");
    set_race("monstrous black beast");

    set_short("%^BOLD%^%^BLACK%^M%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^"+
    "nstr%^BOLD%^%^WHITE%^ou%^BOLD%^%^BLACK%^s bl%^BOLD%^%^WHITE%^"+
    "a%^BOLD%^%^BLACK%^ck b%^BOLD%^%^WHITE%^ea%^BOLD%^%^BLACK%^st%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This creature is nothing short of "+
    "a nightmare incarnated. It has little solid form, with "+
    "eight monstrous arms attached to what might serve "+
    "as a torso but is mostly just a black mass. It sprawls out "+
    "in all directions, folds of what could be called "+
    "fat overlapping each other. Its head is extremely "+
    "bulbous with no obvious eyes. It does have a large, gaping "+
    "mouth, with rows of %^BOLD%^%^WHITE%^gleaming%^BOLD%^%^BLACK%^ "+
    "red teeth visible. Its mouth is easily large enough to "+
    "swallow many creatures. A %^BOLD%^%^CYAN%^rune%^BOLD%^%^BLACK%^ "+
    "of some sort, on its insides, is visible through the "+
    "layers of blackness, only because it constantly glows and "+
    "pulsates. The creature smells horrific, almost like "+
    "something dead has been eaten, regurgitated, and "+
    "then lay in the sun for too long, getting even riper. "+
    "It growls angrily from its open mouth constantly and "+
    "a thick %^BOLD%^%^GREEN%^acidic liquid%^BOLD%^%^BLACK%^ "+
    "sprays forth from it in streams.%^RESET%^");
  
    set_body_type("human");
    set_alignment(9);
    set_size(3);
    set_hd(34,2);
    set_stats("strength",19);
    set_stats("constitution",25);
    set_stats("wisdom",12);
    set_stats("intelligence",12);
    set_stats("dexterity",17);
    set_stats("charisma",4);
    add_limb("upper right arm","torso",0,0,0);
    add_limb("upper left arm","torso",0,0,0);
    add_limb("middle right arm", "torso", 0, 0, 0);
    add_limb("middle left arm", "torso", 0, 0, 0);
    add_limb("lower right arm","torso",0,0,0);
    add_limb("lower left arm","torso",0,0,0);
    add_limb("upper right hand","upper right arm",0,0,0);
    add_limb("upper left hand","upper left arm",0,0,0);
    add_limb("middle right hand", "middle right arm", 0, 0, 0);
    add_limb("middle left hand", "middle left arm", 0, 0, 0);
    add_limb("lower right hand","lower right arm",0,0,0);
    add_limb("lower left hand","lower left arm",0,0,0);

    set_attack_limbs(({
    "right hand",
    "left hand",
    "middle right hand", 
    "middle left hand",
    "upper right hand",
    "upper left hand",
    "lower left hand",
    "lower right hand",
    }));

    set("aggressive",26);
    set_overall_ac(-20);
    set_property("weapon resistance",100);
    set_mob_magic_resistance("average");
    set_property("damage resistance", 1000);
    set_property("no tripped", 1);
    set_hp(3570 + random(201));
    set_new_exp(30, "boss");
    set_damage(4,5);
    set_attacks_num(8);
    set_base_damage_type("bludgeoning");
    set_funcs(({"devour", "acidic_mist"}));
    set_func_chance(75);
}

void destroy_rune()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    tell_room(ETO, TO->query_short() + "%^BOLD%^%^GREEN%^ suddenly "+
    "vomits forth all of its stomach contents!%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This creature is nothing short of "+
    "a nightmare incarnated. It has little solid form, with "+
    "eight monstrous arms attached to what might serve "+
    "a torso but is mostly just a black mass. It sprawls out "+
    "in all directions, folds of what could be called "+
    "fat overlapping each other. Its head is extremely "+
    "bulbous with no obvious eyes. It does have a large, gaping "+
    "mouth, with rows of %^BOLD%^%^WHITE%^gleaming%^BOLD%^%^BLACK%^ "+
    "red teeth visible. Its mouth is easily large enough to "+
    "swallow many creatures. The creature smells horrific, almost like "+
    "something dead has been eaten, regurgitated, and "+
    "then lay in the sun for too long, getting even riper. "+
    "It growls angrily from its open mouth constantly and "+
    "a thick %^BOLD%^%^GREEN%^acidic liquid%^BOLD%^%^BLACK%^ "+
    "sprays forth from it in streams.%^RESET%^");
    remove_property("weapon resistance");
    remove_property("magic resistance");
    remove_property("damage resistance");
    set_funcs(({"acidic_mist"}));
    set_func_chance(40);
}

void die(object ob) 
{
    if(strsrch(base_name(ETO), "ff") != -1) SAVE_D->remove_array("hhouse_first_floor_boss");
    if(strsrch(base_name(ETO), "sf") != -1) SAVE_D->remove_array("hhouse_second_floor_boss");
    ::die();
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(random(10)) return;
    if(TO->query_max_hp() > TO->query_hp()) 
    {
        tell_room(ETO, TO->query_short() + "%^BOLD%^%^BLACK%^ draws power from "+
        "the darkness on the ceiling!%^RESET%^");
        TO->heal(roll_dice(4, 20));
    }
}    

void devour(object targ)
{
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    me = TO->query_short();

    tell_object(targ, me + "%^BOLD%^%^BLACK%^ grabs you with all "+
    "eights of its arms and you watch in horror as it tosses "+
    "you into its mouth, swallowing you whole!%^RESET%^");

    tell_room(ETO, me + "%^BOLD%^%^BLACK%^ grabs "+targ->QCN+
    "%^BOLD%^%^BLACK%^ with all eights of its arms and tosses "+
    targ->QO +" into its mouth, swalling "+targ->QO+" whole!%^RESET%^", targ);

    if(!objectp(stomach)) 
    {
        stomach = new(HHOB+"black_beast_belly");
        stomach->set_my_beast(TO);
    }
    targ->move(stomach);
    targ->force_me("look");
}

void acidic_mist(object targ)
{
    object *vics;
    string me;
    int x, dam;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    vics = all_living(ETO);
    vics -= ({TO});
    me = TO->query_short();
    tell_room(ETO, me + "%^BOLD%^%^GREEN%^ belches loudly, a thick "+
    "stream of acidic m%^BOLD%^%^WHITE%^i%^BOLD%^%^GREEN%^st "+
    "spraying from its mouth!%^RESET%^");
	
    for(x = 0;x < sizeof(vics);x++)
    {
        if(vics[x]->query_true_invis()) continue;
		dam = roll_dice(10, 20);
		if(vics[x]->reflex_save(28)) 
        {
            tell_object(vics[x], "%^BOLD%^%^RED%^You are able to quickly move out "+
            "of the path of the acidic m%^BOLD%^%^WHITE%^i%^BOLD%^%^RED%^"+
            "st and only are slightly burned by it!%^RESET%^");
			
            tell_room(ETO, vics[x]->QCN + "%^BOLD%^%^RED%^ is able to quickly move "+
            "out of the path of the acidic m%^BOLD%^%^WHITE%^i%^BOLD%^%^RED%^"+
            "st and is only slightly burned by it!%^RESET%^", vics[x]);
            vics[x]->cause_typed_damage(vics[x], 0, (dam/2), "acid");
            continue;
        }
        tell_object(vics[x], "%^BOLD%^%^GREEN%^You are unable to move in time and "+
        "are %^BOLD%^%^RED%^COATED%^BOLD%^%^GREEN%^ by the thick acidic "+
        "m%^BOLD%^%^WHITE%^i%^BOLD%^%^GREEN%^st!%^RESET%^");
		
        tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^GREEN%^ is unable to move in time "+
        "and is %^BOLD%^%^RED%^COATED%^BOLD%^%^GREEN%^ by the thick acidic "+
        "m%^BOLD%^%^WHITE%^i%^BOLD%^%^GREEN%^st!%^RESET%^", vics[x]);
		
        vics[x]->cause_typed_damage(vics[x], 0, (dam), "acid");
        continue;
    }
    return;
}
   
