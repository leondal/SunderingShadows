#include <std.h>

inherit WEAPONLESS;

void create(){
    ::create();
    set_property("swims", 1);
    set_name("Water Naga");
    set_id( ({"naga", "water naga"}) );
    set_short("%^BOLD%^%^CYAN%^Water Naga");
    set_long(
      "The water naga is a long snake like creature with a human head on the end of its length.  Emerald green scales cover its long, supple, and armored length.  It looks at you with strangely hypnotic eyes."
    );
    if(random(2)) set_gender("male"); else set_gender("female");
    set_race("Naga");
    set_body_type("snake");
    set_hd(12+random(20), 9);
    set_hp(query_hd()*(7+random(7)));
    set_exp(650*query_hd());
    set_base_damage_type("piercing");
    set_damage(2,4);
    set_attack_limbs( ({"mouth", "tail"}) );
    set_attacks_num(2);
    set_hit_funcs( (["mouth":(:TO,"poison":), "tail":(:TO,"poison":)]) );
    set_class("fighter");
    set_funcs(({"squeeze"}));
    set_func_chance(25);
    set_overall_ac(-5);
}

int poison(object targ)
{
    string limb;
    if(!objectp(targ)) return 10;
    limb = "tail";
    switch(limb)
    {
        case "tail":
        if(!random(5)) 
        {
            tell_object(targ, "%^GREEN%^The naga whips you hard with its tail!");
            tell_room(ETO, "%^GREEN%^The Naga whips "+targ->query_cap_name()+" with its tail!", targ);
            return random(15);
        }
        break;
        case "mouth":
            if(!random(5)) 
            {
                tell_object(targ, "%^BOLD%^%^GREEN%^The Naga's fangs sink deep into your flesh, injecting you with a strong poison!");
                tell_room(ETO, "%^BOLD%^%^GREEN%^The Naga's fangs sink deep into "+targ->query_cap_name()+"'s flesh!", targ);
                return random(10);
                targ->add_poison(50+random(50));
            }
            break;
    }
    return random(20);
}

int squeeze(object targ){
    tell_object(targ, "%^BOLD%^%^GREEN%^The Naga whips its strong coils around you and starts to squeeze you!");
    tell_room(ETO, "%^BOLD%^%^GREEN%^The Naga whips its coils around "+targ->query_cap_name()+" and starts to squeeze "+targ->query_objective()+"!", targ);
    if(targ->query_stats("strength") < random(35)){
      tell_object(targ, "%^BOLD%^%^GREEN%^The Naga squeezes the breath out of you!");
      tell_room(ETO, "%^BOLD%^%^GREEN%^The Naga squeezes the breath out of "+targ->query_cap_name(), targ);
      targ->do_damage("torso", roll_dice(5,10));
      targ->set_paralyzed(10+random(25), "The Naga has you in its coils!");
    } else {
      tell_object(targ, "%^BOLD%^You are able to push your way out of the naga's coils!");
      tell_room(ETO, targ->query_cap_name()+" is able to push "+targ->query_possessive()+" way from the naga's coils!", targ);
    }
    return 1;
}
