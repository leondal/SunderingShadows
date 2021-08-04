//fixed typo of "brow" throughout ~Circe~ 10/29/13

#include <std.h>
#include <daemons.h>

inherit SHAPESHIFT;

// all of the functions set in create below need to be there so it doesn't bug when trying to shapeshift -Ares
// when making a new shape, be sure to include those functions or it'll fall back to the defaults
void create()
{
    ::create();

    set_attack_limbs( ({ "maw","right claw","left claw" }) );
    set_new_damage_type("piercing");
    set_limbs( ({ "mouth","head","torso","right claw", "left claw", "right foreleg","right forepaw","left foreleg","left forepaw","right rear leg","right rear paw","left rear leg","left rear paw" }) );
    set_attack_functions(([ "maw" : (:TO,"bite_attack":), "right claw" : (:TO,"claw_attack":), "left claw" : (:TO,"claw_attack":) ]));
    set_ac_bonus(-20); // ac bonus is different from the other bonuses because of the way ac is calculated with different body types -Ares
    set_base_attack_num(3);
    set_castable(0);
    set_can_talk(0);
    set_shape_race("bear");
    set_shape_language("sylvan");
    set_shape_profile("druid_bear_999"); // needs to be something the player is unlikely to name one of their profiles when disguise goes in
    set_shape_bonus("perception",2);
    set_shape_bonus("survival",4);
    set_shape_bonus("constitution",4);
    set_shape_bonus("cold resistance",10);
    set_shape_bonus("sight bonus",2);
    set_shape_bonus("damage resistance",20);
    set_shape_height(150+random(40));
    set_shape_weight(4000+random(1000));
    set_shape_mastery_feat("sunder");
}

string * query_subraces() {
    return ({ "bear","grizzly bear","kodiak bear","polar bear","black bear","brown bear","panda" });
}

// custom descriptions here, override this function
int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("is covered in course, brown fur from the tip of "+obj->QP+" snout to the end of "+obj->QP+" large. "
        "muscular frame.  Long claws can be seen at the ends of "+obj->QP+" paws any time "+obj->QO+" takes a step.  Such a large "
        "creature could prove a dangerous foe.");

    obj->setDescriptivePhrase("hulking brown $R with dark brown eyes");

    obj->set("speech string","growl");
    obj->set("describe string","angrily");

    obj->force_me("message in plods in");
    obj->force_me("message out rumbles off to the $D");

    return 1;
}


// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^GREEN%^You turn your mind out to the wilds as you focus on the core of your spirit.");
    tell_object(obj,"%^RESET%^%^BOLD%^You can feel your body beginning to change!");
    tell_object(obj,"%^RESET%^%^YELLOW%^Your senses heighten, you can feel the pulse of the world, smell countless scents, "
        "you can taste the very air.  Your body grows larger and you feel the weight and strength of newfound muscle.  You "
        "are BEAR!");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^RED%^Where "+obj->QCN+" once stood, now stands a huge BEAR!",obj);

    return 1;
}


// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^BOLD%^You relax your focus on the natural world.");
    tell_object(obj,"%^RESET%^%^BLUE%^You can feel the bulk of your muscles shrinking and feel the keen edge of intellect returning.");
    tell_object(obj,"%^RESET%^%^GREEN%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your own body once again.");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+"'s muscles slacken and "+obj->QS+" gets a far-away look in "+obj->QP+" eyes.",obj);
    tell_room(environment(obj),"%^RESET%^%^BLUE%^"+obj->QCN+"'s body begins to change shape, shrinking and quickly loosing fur!",obj);
    tell_room(environment(obj),"%^RESET%^%^GREEN%^Where "+obj->QCN+" once stood, now stands a "+obj->query_race()+"!",obj);

    return 1;
}

int can_cast()
{
    if(!objectp(query_owner())) { return 0; }
    if(FEATS_D->usable_feat(query_owner(),"wild spellcraft")) { return 1; }
    return can_cast_spells;
}

int bite_attack(object tp, object targ) // bear bite attack significantly more likely to heal
{
    object etp,*attackers;
    string *specials=({}),*active_specials=({}),my_limb;
    int i,chance,dice;

    etp = environment(tp);

    if(!objectp(tp)) { return 0; }
    attackers = (object*)tp->query_attackers();
    if(!objectp(targ) && !sizeof(attackers)) { return 0; }

    chance = (int)tp->query_guild_level("druid");

    if(chance > 60) { chance = 60; }
    if(chance > 39 && !FEATS_D->usable_feat(TP,"savage instincts iii")) { chance = 39; }
    if(chance > 29 && !FEATS_D->usable_feat(TP,"savage instincts ii")) { chance = 29; }
    if(chance > 19 && !FEATS_D->usable_feat(TP,"savage instincts i")) { chance = 19; }

    dice = ( chance / 4) + 2;

    if(FEATS_D->usable_feat(tp,"perfect predator"))
    {
        dice += 3;
        tp->add_hp(dice*2); // twice as much healing on the bear form, since it's the tank form
    }

    if(roll_dice(1,100) > chance) { return roll_dice(3,dice); }

    // switch falls through intentionally
    switch(chance)
    {
        case 35..60: specials += ({ "heal" });
        case 30..34: specials += ({ "heal" });
        case 25..29: specials += ({ "trip" });
        case 20..24: specials += ({ "high damage" });
        case 15..19: specials += ({ "stun" });
        case 10..14: specials += ({ "high damage" });
        default:     specials += ({ "heal"  });
    }

    //////////////
    i=0;

    do
    {
        active_specials += ({ specials[random(sizeof(specials))] });
        i += 5;
    }
    while(roll_dice(1,100) < (chance - i));
    //////////////

    set_new_damage_type("piercing");

    for(i=0;i<sizeof(active_specials);i++)
    {
        if(!objectp(tp) || !objectp(targ)) { return 0; }

        switch(active_specials[i])
        {

        case "heal":

            tell_object(tp,"%^CYAN%^You tear deeply into "+targ->QCN+" flesh and are revitalized by "+targ->QP+" life blood!");
            tell_object(targ,"%^RED%^"+tp->QCN+" tears deeply into you with "+tp->QP+" large teeth, bleeding you!");
            tell_room(etp,"%^RED%^"+tp->QCN+" tears deeply into "+targ->QCN+" causing "+targ->QO+" to bleed profusely!",({tp,targ}));

            tp->do_damage(tp->return_target_limb(),(roll_dice(dice,4) * -1));
            targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,4),get_new_damage_type());
            break;

        case "trip":

            tell_object(tp,"%^YELLOW%^You bite into "+targ->QCN+"'s "+(my_limb=targ->return_target_limb())+" and yank "+targ->QO+" off of "+targ->QP+" feet!");
            tell_object(targ,"%^YELLOW%^"+tp->QCN+" bites into your "+my_limb+" and yanks you off of your feet!");
            tell_room(etp,"%^YELLOW%^"+tp->QCN+" bites into "+targ->QCN+"'s "+my_limb+" and yanks "+targ->QO+" off of "+targ->QP+" feet!",({tp,targ}));

            if(!targ->reflex_save(chance+5)) { targ->set_tripped(roll_dice(1,dice/2),"%^RESET%^%^YELLOW%^You are struggling to get your feet back under you!"); }
            break;

        case "high damage":

            tell_object(tp,"%^MAGENTA%^You clamp your powerful jaws down on "+targ->QCN+" and feel your teeth dig in deep!");
            tell_object(targ,"%^MAGENTA%^"+tp->QCN+" clamps "+tp->QP+" powerful jaws down on you and bites painfully!");
            tell_room(etp,"%^MAGENTA%^"+tp->QCN+" clamps "+tp->QP+" powerful jaws down on "+targ->QCN+" and bites painfully!",({tp,targ}));

            targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,5),get_new_damage_type());
            break;

        case "stun":

            tell_object(tp,"%^GREEN%^You grab "+targ->QCN+" in your mouth and shake "+targ->QO+" raggedly, leaving "+targ->QO+" disoriented!");
            tell_object(targ,"%^GREEN%^"+tp->QCN+" grabs you and shakes you in "+tp->QP+" mouth, disorienting you!");
            tell_room(etp,"%^GREEN%^"+tp->QCN+" grabs "+targ->QCN+" in "+tp->QP+" mouth and shakes "+targ->QO+" furiously, leaving "+targ->QCN+" disoriented!",({tp,targ}));

            targ->set_paralyzed(roll_dice(1,dice/2),"%^RESET%^%^YELLOW%^You're trying to regain your senses!");
            break;
        }
    }

    return roll_dice(1,dice);

}

int claw_attack(object tp, object targ)
{
    object etp,*attackers;
    string *specials=({}),*active_specials=({}),my_limb;
    int i,chance,dice;

    etp = environment(tp);

    if(!objectp(tp)) { return 0; }
    attackers = (object*)tp->query_attackers();
    if(!objectp(targ) && !sizeof(attackers)) { return 0; }

    chance = (int)tp->query_guild_level("druid");

    if(chance > 60) { chance = 60; }
    if(chance > 39 && !FEATS_D->usable_feat(TP,"savage instincts iii")) { chance = 39; }
    if(chance > 29 && !FEATS_D->usable_feat(TP,"savage instincts ii")) { chance = 29; }
    if(chance > 19 && !FEATS_D->usable_feat(TP,"savage instincts i")) { chance = 19; }

    dice = ( chance / 3) + 2;

    if(roll_dice(1,100) > chance) { return roll_dice(3,dice); }

    // switch falls through intentionally
    switch(chance)
    {
        case 35..60: specials += ({ "high damage" });
        case 30..34: specials += ({ "trip" });
        case 25..29: specials += ({ "trip" });
        case 20..24: specials += ({ "high damage" });
        case 15..19: specials += ({ "stun" });
        case 10..14: specials += ({ "extra attack" });
        default:     specials += ({ "high damage"  });
    }

    //////////////
    i=0;

    do
    {
        active_specials += ({ specials[random(sizeof(specials))] });
        i += 5;
    }
    while(roll_dice(1,100) < (chance - i));
    //////////////

    set_new_damage_type("bludgeoning");

    for(i=0;i<sizeof(active_specials);i++)
    {
        if(!objectp(tp) || !objectp(targ)) { return 0; }

        switch(active_specials[i])
        {

        case "trip":

            tell_object(tp,"%^BLUE%^You knock "+targ->QCN+"'s feet out from under "+targ->QO+" with a swipe of your mighty paw!");
            tell_object(targ,"%^BLUE%^"+tp->QCN+" knocks your feet out from under you with a swipe of "+tp->QP+" mighty paw!");
            tell_room(etp,"%^BLUE%^"+tp->QCN+" knocks "+targ->QCN+"'s feet out from under "+targ->QO+" with a swipe of "+tp->QP+" mighty paw!",({tp,targ}));

            if(!targ->reflex_save(chance+5)) { targ->set_tripped(roll_dice(1,dice/2),"%^RESET%^%^YELLOW%^You are struggling to get your feet back under you!"); }
            break;

        case "high damage":

            tell_object(tp,"%^RED%^You connect with a devastating blow to the side of "+targ->QCN+"'s "+(my_limb=targ->return_target_limb())+"!");
            tell_object(targ,"%^RED%^"+tp->QCN+" delivers a devastating blow to your "+my_limb+"!");
            tell_room(etp,"%^RED%^"+tp->QCN+" delivers a devastating blow to "+targ->QCN+"'s "+my_limb+"!",({tp,targ}));

            targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,5),get_new_damage_type());
            break;

        case "stun":

            tell_object(tp,"%^ORANGE%^You quickly strike "+targ->QCN+" first with one mightly claw and then the other, knocking "+targ->QO+" senseless!");
            tell_object(targ,"%^ORANGE%^"+tp->QCN+" quickly strikes you with one mightly claw and then the other, knocking your senseless!");
            tell_room(etp,"%^ORANGE%^"+tp->QCN+" quickly strikes "+targ->QCN+" first with one mighty claw and then the next, knocking "+targ->QO+" senseless!",({tp,targ}));

            targ->set_paralyzed(roll_dice(1,dice/2),"%^RESET%^%^YELLOW%^You're struggling to regain your balance!");
            break;

        case "extra attack":

            tell_object(tp,"%^RESET%^%^BOLD%^Your attack lands squarely on "+targ->QCN+"'s "+(my_limb=targ->return_target_limb())+", bouncing off for another attack!");
            tell_object(targ,"%^RESET%^%^BOLD%^"+tp->QCN+"'s attack bounces off of your "+my_limb+" and "+tp->QS+" quickly hits you again!");
            tell_room(etp,"%^RESET%^%^BOLD%^"+tp->QCN+"s attack bounces off of "+targ->QCN+"'s "+my_limb+" and "+tp->QS+" quickly hits "+targ->QO+" again!",({tp,targ}));

            tp->execute_attack();
            break;
        }
    }

    return roll_dice(3,dice);
}
