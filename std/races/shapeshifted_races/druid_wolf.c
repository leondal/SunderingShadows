#include <std.h>
#include <daemons.h>

inherit SHAPESHIFT;

// all of the functions set in create below need to be there so it doesn't bug when trying to shapeshift -Ares
// when making a new shape, be sure to include those functions or it'll fall back to the defaults

// to change into a shape...    "/std/races/shapeshifted_races/race_name"->init_shape(player)
// to change out of a shape ..  "/std/races/shapeshifted_races/race_name"->reverse_shape(player)
void create()
{
    ::create();

    set_attack_limbs( ({ "maw" }) );
    set_new_damage_type("piercing");
    set_limbs( ({ "mouth","head","torso","right foreleg","right forepaw","left foreleg","left forepaw","right rear leg","right rear paw","left rear leg","left rear paw","tail" }) );
    set_attack_functions( ([ "maw" : (:TO,"shape_attack":) ]) );
    set_ac_bonus(2); // ac bonus is different from the other bonuses because of the way ac is calculated with different body types -Ares
    set_base_attack_num(4);
    set_castable(0);
    set_can_talk(0);
    set_shape_race("wolf");
    set_shape_language("sylvan");
    set_shape_profile("druid_wolf_999"); // needs to be something the player is unlikely to name one of their profiles when disguise goes in
    set_shape_bonus("perception",2);
    set_shape_bonus("survival",4);
    set_shape_bonus("cold resistance",5);
    set_shape_bonus("sight bonus",3);
    set_shape_bonus("damage bonus",3);
    set_shape_bonus("attack bonus",3);
    set_shape_height(30+random(12));
    set_shape_weight(90+random(50));
    set_shape_mastery_feat("knockdown");
}

string * query_subraces() {
    return ({ "wolf","coyote","hyena","jackal","fox","worg","wolverine" });
}

// custom descriptions here, override this function
int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("is covered from snout to tail in smooth gray fur.  A maw of razor sharp teeth and keen eyes shows that the wolf is a natural predator in its own environment.  Every step it takes reveals lean muscles under the heavy coat of fur.");

    obj->setDescriptivePhrase("lean gray $R with intense green eyes");

    obj->set("speech string","growl");
    obj->set("describe string","angrily");

    obj->force_me("message in trots in quickly");
    obj->force_me("message out darts quickly to the $D");

    return 1;
}


// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^GREEN%^You turn your mind out to the wilds as you focus on the core of your spirit.");
    tell_object(obj,"%^RESET%^%^BOLD%^You can feel your body beginning to change!");
    tell_object(obj,"%^RESET%^%^RED%^Your senses heighten, you can feel the pulse of the world, smell countless scents, "
        "you can taste the very air.  You are one with the pack.   You are WOLF!");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^RED%^Where "+obj->QCN+" once stood, is now a large wolf!",obj);

    return 1;
}


// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^BOLD%^You relax your focus on the natural world.");
    tell_object(obj,"%^RESET%^%^BLUE%^You can feel the sharpness of your senses beginning to fade and the keen edge of intellect returning.");
    tell_object(obj,"%^RESET%^%^GREEN%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your own body once again.");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+"'s muscles slacken and "+obj->QS+" gets a far-away look in "+obj->QP+" eyes.",obj);
    tell_room(environment(obj),"%^RESET%^%^BLUE%^"+obj->QCN+"'s body begins to change shape, elongating and curving!",obj);
    tell_room(environment(obj),"%^RESET%^%^GREEN%^Where "+obj->QCN+" once stood, now stands a "+obj->query_race()+"!",obj);

    return 1;
}

int can_cast()
{
    if(!objectp(query_owner())) { return 0; }
    if(FEATS_D->usable_feat(query_owner(),"wild spellcraft")) { return 1; }
    return can_cast_spells;
}


// custom unarmed attack functions go here, functions can be added just like hit functions for weapons
int shape_attack(object tp, object targ)
{
    object etp,*attackers;
    string *specials=({}),*active_specials=({});
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
        tp->add_hp(dice);
    }

    if(roll_dice(1,100) > chance) { return roll_dice(2,dice); }

    // switch falls through intentionally
    switch(chance)
    {
        case 35..60: specials += ({ "blind" });
        case 30..34: specials += ({ "heal" });
        case 25..29: specials += ({ "trip" });
        case 20..24: specials += ({ "high damage" });
        case 15..19: specials += ({ "stun" });
        case 10..14: specials += ({ "extra attack" });
        default:     specials += ({ "low damage"  });
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



    for(i=0;i<sizeof(active_specials);i++)
    {
        if(!objectp(tp) || !objectp(targ)) { return 0; }

        switch(active_specials[i])
        {

        case "blind":

            tell_object(tp,"%^RESET%^%^RED%^You leap up and savagely tear at "+targ->QCN+"'s eyes, narrowly missing!");
            tell_object(targ,"%^RESET%^%^BOLD%^%^GREEN%^"+tp->QCN+" leaps up and tears at your face, nearly ripping your eyes out!");
            tell_room(etp,"%^RESET%^%^BOLD%^%^GREEN%^"+tp->QCN+" leaps up and tears at "+targ->QCN+"'s face, nearly ripping out "+targ->QP+" eyes!",({tp,targ}));

            if(!targ->reflex_save(chance)) { targ->set_temporary_blinded(dice/2); }
            break;


        case "heal":

            tell_object(tp,"%^RESET%^%^BOLD%^%^CYAN%^You pull on "+targ->QCN+"'s essence with your attack, draining "+targ->QO+" and restoring some of your vital health!");
            tell_object(targ,"%^RESET%^%^RED%^"+tp->QCN+"'s pulls at your essence, leaving you drained!");
            tell_room(etp,"%^RESET%^%^BLUE%^"+tp->QCN+"'s wounds look less severe after "+tp->QS+" attacks "+targ->QCN+"!",({tp,targ}));

            tp->do_damage(tp->return_target_limb(),(dice * -1 * 2));
            targ->cause_typed_damage(targ,targ->return_target_limb(),dice*2,get_new_damage_type());
            break;


        case "trip":

            tell_object(tp,"%^RESET%^%^GREEN%^You dig your teeth into "+targ->QCN+"'s shoulder and drag "+targ->QO+" to the ground!");
            tell_object(targ,"%^RESET%^%^GREEN%^"+tp->QCN+" digs "+tp->QP+" teeth into your shoulder and drags you to the ground!");
            tell_room(etp,"%^RESET%^%^GREEN%^"+tp->QCN+" digs "+tp->QP+" teeth into "+targ->QCN+"'s shoulder and drags "+targ->QO+" to the ground!",({tp,targ}));

            if(!targ->fort_save(chance)) { targ->set_tripped(roll_dice(1,dice),"%^RESET%^%^YELLOW%^You are struggling to get your feet back under you!"); }
            break;

        case "high damage":

            tell_object(tp,"%^RESET%^%^YELLOW%^You snarl angrily and lunge, tearing deeply into "+targ->QCN+"'s flank!");
            tell_object(targ,"%^RESET%^%^ORANGE%^"+tp->QCN+" snarls angrily and lunges, tearing painfully into your side!");
            tell_room(etp,"%^RESET%^%^ORANGE%^"+tp->QCN+" snarls angrily and lunches, tearing deeply into "+targ->QCN+"'s flank!",({tp,targ}));

            targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,4),get_new_damage_type());
            break;


        case "stun":
            if(!random(3)){
//               tell_object(tp,"%^B_BLUE%^%^BOLD%^%^GREEN%^You failed to stun "+targ->QCN+". ~Debugging Message~%^RESET%^");
               break;
            }else{

            tell_object(tp,"%^RESET%^%^MAGENTA%^You lower your head and circle around "+targ->QCN+" before lunging, "
                "knocking "+targ->QO+" off balance!");
            tell_object(targ,"%^RESET%^%^MAGENTA%^"+tp->QCN+" lowers "+tp->QP+" head and circles around you before "
                "lunging and knocking you off balance and unable to move!");
            tell_room(etp,"%^RESET%^%^MAGENTA%^"+tp->QCN+" lowers "+tp->QP+" head and circles around "+targ->QCN+" "
                "before lunging and knocking "+targ->QO+" off balance!",({tp,targ}));

            targ->set_paralyzed(roll_dice(1,dice),"%^RESET%^%^YELLOW%^You're struggling to regain your balance!");
            break;
            }


        case "extra attack":

            tell_object(tp,"%^RESET%^%^BOLD%^You hit the ground and twist, immediately launching another quick attack at "+targ->QCN+"!");
            tell_object(targ,"%^RESET%^%^BOLD%^"+tp->QCN+" hits the ground and twists, immediately launching another attack at you!");
            tell_room(etp,"%^RESET%^%^BOLD%^"+tp->QCN+" hits the ground and twists, immediately launching another attack at "+targ->QCN+"!",({tp,targ}));

            tp->execute_attack();
            break;

        case "low damage":

            tell_object(tp,"%^RESET%^%^BOLD%^%^GREEN%^You quickly snap inside "+targ->QCN+"'s defenses and bite a vulnerable spot!");
            tell_object(targ,"%^RESET%^%^BOLD%^%^GREEN%^"+tp->QCN+" quickly snaps inside of your defenses and bites you!");
            tell_room(etp,"%^RESET%^%^BOLD%^%^GREEN%^"+tp->QCN+" quickly snaps inside of "+targ->QCN+"'s defenses and bites "+targ->QO+"!",({tp,targ}));

            targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,2),get_new_damage_type());
            break;

        }
    }

    return roll_dice(2,dice);
}
