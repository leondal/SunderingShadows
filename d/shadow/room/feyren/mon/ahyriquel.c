#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;

void create() 
{
    object ob;
    ::create();
    set_name("Ahyriquel");
    set_id(({"spider","monstrous spider", "queen spider",
    "ahyriquel", "queen"}));
    set_short("%^BOLD%^%^GREEN%^A%^BOLD%^%^YELLOW%^hyr"+    
    "%^BOLD%^%^GREEN%^i%^BOLD%^%^YELLOW%^q%^BOLD%^%^GREEN%^ue"+
    "%^BOLD%^%^YELLOW%^l, Monstrous Spider Queen%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^This spider is massive, perhaps "+
    "ten feet in diameter, and it looks old. Its eight legs are covered "+
    "in a thick, course bright green fuzz that extends to the rest of its "+
    "body and becomes thicker and coarser. Most of its body is "+
    "a very brilliant green. Its body has many "+
    "scrapes and tears and several of its legs look "+
    "oddly bent as if they never fully healed right. "+
    "Multitudes of eggsacs are clumped together on its "+
    "back, each one of them pulsating wildly as "+
    "if having a heartbeat of their own. "+
    "Its eyes are a deep %^BOLD%^%^RED%^fiery"+
    "%^BOLD%^%^GREEN%^ red. Its speckled black "+
    "mandibles open very wide to reveal two vicious "+
    "fangs. A steady stream of acidic "+
    "%^BOLD%^%^YELLOW%^goo%^BOLD%^%^GREEN%^ drips from them. %^RESET%^");

    set_gender("female");
    set_race("arachnid");
    set_body_type("arachnid");
    set_alignment(5);
    set_size(2);
    set_hd(16,5);
    set("aggressive", 25);
    set_stats("strength",10);
    set_stats("dexterity",20);
    set_hp(225 + random(76)); 
    set_max_hp(query_hp());
    set_new_exp(14, "very high");
    set_attacks_num(3);
    set_base_damage_type("piercing");
    set_base_damage_type("piercing");
    set_damage(3,6);
    //need to fix poisons so that they work 
    //like we were playing D&D - Saide
    set_property("natural poisoner", 1);
    set_property("natural poison", "medium spider venom");
    set_property("poison chance", 30);
    set_funcs(({"poison_bite", "acidic_blast", "hatchlings"}));
    set_func_chance(40); 
    set_property("death effects", "splash");
    set_overall_ac(-4);
}

void poison_bite(object targ)
{
    string limb;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;

    limb = targ->return_target_limb();

    tell_object(targ, TOQCN+"%^BOLD%^%^GREEN%^"+
    " sinks its fangs deep into your "+limb+", "+
    "pumping poison into the wound!%^RESET%^");

    tell_room(ETO, TOQCN+"%^BOLD%^%^GREEN%^ "+
    "sinks its fangs deep into "+targ->QCN+
    "%^BOLD%^%^GREEN%^'s "+limb+"!%^RESET%^", targ);

    tell_object(targ, "%^BOLD%^%^GREEN%^"+
    "You feel woozy as the poison begins to "+
    "take effect!%^RESET%^");

    tell_room(ETO, targ->QCN+"%^BOLD%^%^GREEN%^"+
    " stumbles around crazily for a moment as "+
    "the "+TOQCN+"%^BOLD%^%^GREEN%^ releases "+targ->QP+" "+
    limb+"!%^RESET%^", targ);

    POISON_D->ApplyPoison(targ, "medium spider venom", TO, "injury");
    return;
}

void acidic_blast(object targ)
{
    string limb, num;
    int hits;
    hits = 2 + random(2);
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    switch(hits)
    {
        case 2:
            num = "two";
            break;
        case 3:
            num = "three";
            break;
    }

    tell_object(targ, TOQCN+"%^BOLD%^%^GREEN%^"+
    " launches "+num+" globs of acidic spit at you!%^RESET%^");

    tell_room(ETO, TOQCN+"%^RESET%^%^GREEN%^"+
    " launches "+num+" globs of acidic spit at "+targ->QCN+
    "%^RESET%^%^GREEN%^!%^RESET%^", targ);

    while(hits--)
    {
        if(targ->reflex_save(20))
        {
            tell_object(targ, "%^BOLD%^%^WHITE%^You "+
            "easily avoid the glob of spit and "+
            "it collides with a wall behind you!%^RESET%^");
                
            tell_room(ETO, targ->QCN+"%^BOLD%^%^WHITE%^ "+
            "easily avoids the glob of spit and it collides "+
            "with a wall behind "+targ->QO+"!%^RESET%^", targ);
            continue;
        }
        limb = targ->return_target_limb();

        tell_object(targ, "%^BOLD%^%^GREEN%^The glob of "+
        "acidic spit splats into your "+limb+
        "%^BOLD%^%^RED%^ BURNING%^BOLD%^%^GREEN%^"+
        "your flesh!%^RESET%^");
	
        tell_room(ETO, "%^BOLD%^%^GREEN%^The glob "+
        "of acidic spit splats into "+targ->QCN+"%^BOLD%^%^GREEN%^'s "+
        limb +" %^BOLD%^%^RED%^BURNING%^BOLD%^%^GREEN%^"+
        targ->QP+" flesh!%^RESET%^", targ); 
	
        targ->cause_typed_damage(targ,limb,roll_dice(8,6),"acid");
        continue;
    }
    return;
}
	
void hatchlings()
{
    object eggsac;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
	
    tell_room(ETO, TOQCN + "%^BOLD%^%^RED%^ tosses one of the "+
    "many eggsacs on her back into the middle of the floor!%^RESET%^");
	
    eggsac = new(FFOB+"eggsac");
    eggsac->adjust_count_down(2);
    eggsac->move(ETO);
    if(!random(2)) hatchlings();
    return;
}

void heart_beat()
{	
    object spiderling;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(random(4)) return;
    if(!objectp(spiderling = present("spiderling", ETO))) return;
	
    tell_room(ETO, TOQCN+" %^BOLD%^%^GREEN%^"+
    "grabs and devours "+
    spiderling->QCN+" quickly, healing herself!%^RESET%^");
    spiderling->remove();
    TO->add_hp(35 + random(10));
    return;
}
