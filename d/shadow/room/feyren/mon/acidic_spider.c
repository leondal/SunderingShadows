#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;

void create() 
{
    object ob;
    ::create();
    set_name("monstrous spider");
    set_id(({"spider","monstrous spider", "large spider", 
    "emerald spider", "emerald green spider", "feyrenspidermob"}));
    set_short("%^BOLD%^%^GREEN%^Br%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^"+
    "ll%^RESET%^%^GREEN%^ia%^BOLD%^%^GREEN%^nt green %^RESET%^"+
    "%^GREEN%^m%^BOLD%^o%^RESET%^%^GREEN%^"+
    "nstr%^BOLD%^ou%^RESET%^%^GREEN%^s %^BOLD%^%^GREEN%^spider"+
    "%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^This spider is massive, perhaps "+
    "five feet in diameter, and it looks old. Its eight legs are covered "+
    "in a thick, course bright green fuzz that extends to the rest of its "+
    "body and becomes thicker and coarser. Most of its body is "+
    "a very brilliant green. Its body has many "+
    "scrapes and tears and several of its legs look "+
    "oddly bent as if they never fully healed right. "+
    "Its eyes are a deep %^BOLD%^%^RED%^fiery"+
    "%^BOLD%^%^GREEN%^ red. Its speckled black "+
    "mandibles open very wide to reveal two vicious "+
    "fangs. A steady stream of acidic "+
    "%^BOLD%^%^YELLOW%^goo%^BOLD%^%^GREEN%^ drips from them.%^RESET%^");

    set_gender("female");
    set_race("arachnid");
    set_body_type("arachnid");
    set_alignment(5);
    set_size(2);
    set_hd(15,5);
    set("aggressive", 25);
    set_stats("strength",17);
    set_stats("dexterity",17);
    set_hp(135 + random(70));
    set_max_hp(query_hp());
    set_new_exp(13, "normal");
    set_attacks_num(3);
    set_base_damage_type("piercing");
    set_base_damage_type("piercing");
    set_damage(2,6);
    set_moving(1);
    set_speed(45);
    //need to fix poisons so that they work 
    //like we were playing D&D - Saide
    set_property("natural poisoner", 1);
    set_property("natural poison", "medium spider venom");
    set_property("poison chance", 4);
    set_nogo(({OA, FFTR"40", FFOR"b6"}));
    set_funcs(({"poison_bite", "acidic_spit"}));
    set_func_chance(25); 
    set_property("death effects", "splash");
    set_overall_ac(-2);
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

void acidic_spit(object targ)
{
    string limb;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    tell_object(targ, TOQCN+"%^BOLD%^%^GREEN%^"+
    " launches a glob of acidic spit at you!%^RESET%^");

    tell_room(ETO, TOQCN+"%^RESET%^%^GREEN%^"+
    " launches a glob of acidic spit at "+targ->QCN+
    "%^RESET%^%^GREEN%^!%^RESET%^", targ);

    if(targ->reflex_save(22))
    {
        tell_object(targ, "%^BOLD%^%^WHITE%^You "+
        "easily avoid the glob of spit and "+
        "it collides with a wall behind you!%^RESET%^");    
        tell_room(ETO, targ->QCN+"%^BOLD%^%^WHITE%^ "+
        "easily avoids the glob of spit and it collides "+
        "with a wall behind "+targ->QO+"!%^RESET%^", targ); 
        return;
    }
    limb = targ->return_target_limb();
    tell_object(targ, "%^BOLD%^%^GREEN%^The glob of "+
    "acidic spit splats into your "+limb+
    "%^BOLD%^%^RED%^ BURNING %^BOLD%^%^GREEN%^"+
    "your flesh!%^RESET%^");
	
    tell_room(ETO, "%^BOLD%^%^GREEN%^The glob "+
    "of acidic spit splats into "+targ->QCN+"%^BOLD%^%^GREEN%^'s "+
    limb +" %^BOLD%^%^RED%^BURNING %^BOLD%^%^GREEN%^"+
    targ->QP+" flesh!%^RESET%^", targ); 
	
    targ->cause_typed_damage(targ,limb,roll_dice(4,6),"acid");

    poison_bite(targ);
	
    return;
}
	

