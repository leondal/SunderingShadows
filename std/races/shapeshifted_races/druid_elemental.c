#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit SHAPESHIFT;

int trip_timer;

// all of the functions set in create below need to be there so it doesn't bug when trying to shapeshift -Ares
// when making a new shape, be sure to include those functions or it'll fall back to the defaults
void create()
{
    ::create();

    set_attack_limbs( ({ "right arm","left arm" }) );
    set_new_damage_type("bludgeoning");
    set_limbs( ({ "head","torso","right arm", "left arm" }) );
//    set_attack_functions(([ "right arm" : (:TO,"arm_attack":), "left arm" : (:TO,"arm_attack":) ])); // moving this to an on-demand command
    set_attack_functions(([ "right arm" : (:TO,"shape_attack":), "left arm" : (:TO,"shape_attack":) ]));
    set_ac_bonus(0); // ac bonus is different from the other bonuses because of the way ac is calculated with different body types -Ares
    set_base_attack_num(0);
    set_castable(1);
    set_can_talk(0);
    set_shape_race("elemental");
    set_shape_language("sylvan");
    set_shape_profile("druid_elemental_999"); // needs to be something the player is unlikely to name one of their profiles when disguise goes in
    set_shape_bonus("perception",4);
    set_shape_bonus("spellcraft",4);
    set_shape_bonus("sight bonus",3);
    set_shape_bonus("water breather",1);
    set_shape_bonus("empowered",2);
    set_shape_bonus("spell penetration",4);
    set_shape_bonus("damage resistance",10);
    set_shape_bonus("spell damage resistance",10);
    set_shape_bonus("magic resistance",2);
    set_shape_height(200+random(40));
    set_shape_weight(5000+random(2000));
}

string * query_subraces() {
    return ({ "elemental","fire elemental","water elemental","air elemental","earth elemental" });
}

// custom descriptions here, override this function
int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("rises before you, a creature of pure elemental force. Vaguely humanoid, it "
        "has a head with depthless orbs for eyes, descending to the outline of a body with arms at "
        "either side. The torso trails down to a formless mass that moves over the ground somehow. "
        "The being is unsettling at best, its intimidating bulk being something not of this plane.");

    obj->setDescriptivePhrase("shifting $R");

    obj->set("speech string","voice");
    obj->set("describe string","eerily");

    obj->force_me("message in moves in");
    obj->force_me("message out moves off to the $D");

    return 1;
}


// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^GREEN%^You turn your mind out to the wilds as you focus on the core of your spirit.");
    tell_object(obj,"%^RESET%^%^BOLD%^You can feel your body beginning to change!");
    tell_object(obj,"%^RESET%^%^BLUE%^You reach out to the planes beyond the material, harnessing the very essence of the "
        "elements. Your bond with the wild grows stronger, attuned as you are now with the magical energies of the "
        "world around you.  You are ELEMENTAL!");
    tell_object(obj,"%^RESET%^%^BOLD%^You realise that you can <surge> with energy!");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^RED%^Where "+obj->QCN+" once stood, now stands an ELEMENTAL!",obj);

    return 1;
}


// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^BOLD%^You relax your focus on the natural world.");
    tell_object(obj,"%^RESET%^%^BLUE%^You can feel a tinge of remose as you feel your elemental form slipping away.");
    tell_object(obj,"%^RESET%^%^GREEN%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your own body once again.");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+"'s motions slow and "+obj->QS+" gets a far-away look in "+obj->QP+" eyes.",obj);
    tell_room(environment(obj),"%^RESET%^%^BLUE%^"+obj->QCN+"'s body begins to change shape, shrinking and gaining definition!",obj);
    tell_room(environment(obj),"%^RESET%^%^GREEN%^Where "+obj->QCN+" once stood, now stands a "+obj->query_race()+"!",obj);

    return 1;
}

// custom unarmed attack functions go here, functions can be added just like hit functions for weapons
int shape_attack(object tp, object targ)
{
    return 0;
}

int arm_attack(object tp, object targ)
{
    object etp,*attackers,att;
    string *specials=({}),*active_specials=({}),myrace;
    int i,j,chance,dice;

    etp = environment(tp);

    if(!objectp(tp)) { return 0; }
    attackers = (object*)tp->query_attackers();
    attackers = distinct_array(attackers);
    if(!objectp(targ) && !sizeof(attackers)) { return 0; }

    chance = (int)tp->query_guild_level("druid");

    if(chance < 15) { chance = 15; }
    if(chance > 60) { chance = 60; }

    dice = ( chance / 3) + 2;

    if(roll_dice(1,100) > chance) { return roll_dice(dice,3); }
    myrace = (string)TO->query_shape_race();

    // picks up one spell of L2, L3 and L4 for each type of elemental (and default). Varies by element.
    // switch falls through intentionally
    switch(chance)
    {
        case 35..60: specials += ({ "level 4" });
        case 30..34: specials += ({ "level 3" });
        case 25..29: specials += ({ "level 2" });
        case 20..24: specials += ({ "level 4" });
        case 15..19: specials += ({ "stun slam" });
        case 10..14: specials += ({ "level 3" });
        default:     specials += ({ "level 2"  });

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

        if(tp->query_casting()) return 0; // it was allowing multicasting! Oops.

        switch(active_specials[i]) {

        case "stun slam":

            if(time() > trip_timer)
            {
                trip_timer = time() + (ROUND_LENGTH * 25);

                tell_object(tp,"%^BOLD%^%^WHITE%^You heave yourself up, before slamming back down into the ground!");
                tell_room(etp,"%^BOLD%^%^WHITE%^"+tp->QCN+" heaves "+tp->QO+"self up, before slamming back down into the ground!",tp);

                for(j=0;j<sizeof(attackers);j++)
                {
                    if(!objectp(att = attackers[j])) { continue; }

                    if(!att->reflex_save(chance))
                    {
                        tell_object(att,"%^GREEN%^The earth shakes and knocks you off of your feet!");
                        tell_room(etp,"%^GREEN%^The earth shakes and knocks "+att->QCN+" off of "+att->QP+" feet!",({att}));

                        att->set_tripped(roll_dice(1,dice),"%^RESET%^%^YELLOW%^You are struggling to get your feet back under you!");
                    }
                    else
                    {
                        tell_object(att,"%^BOLD%^%^GREEN%^You manage to withstand the trembling of the earth and keep your footing!");
                        tell_room(etp,"%^BOLD%^%^GREEN%^"+att->QCN+" manages to withstand the trembling of the earth and keep "+att->QP+" footing!",({att}));
                    }
                }
                break;
            } // falls through if timer isn't up


        case "level 2":

            tell_object(tp,"%^RED%^You call upon the elements and invoke a spell at "+targ->QCN+"!%^RESET%^");
            tell_object(targ,"%^RED%^"+tp->QCN+" calls upon the elements and invokes a spell at you!%^RESET%^");
            tell_room(etp,"%^RED%^"+tp->QCN+" calls upon the elements and invokes a spell at "+targ->QCN+"!%^RESET%^",({tp,targ}));

            switch(myrace) {
              case "fire elemental": case "earth elemental": new("/cmds/spells/h/_heat_metal")->use_spell(tp,targ,chance,100,"druid"); break;
              case "air elemental": case "water elemental": default: new("/cmds/spells/c/_chill_metal")->use_spell(tp,targ,chance,100,"druid"); break;
            }
            break;

        case "level 3":

            tell_object(tp,"%^CYAN%^You raise an arm and call upon the elements for aid!%^RESET%^");
            tell_room(etp,"%^CYAN%^"+tp->QCN+" raises an arm and calls upon the elements for aid!%^RESET%^",tp);

            switch(myrace) {
              case "water elemental": case "earth elemental": new("/cmds/spells/q/_quench")->use_spell(tp,targ,chance,100,"druid"); break;
              case "fire elemental": case "air elemental": default: new("/cmds/spells/c/_call_lightning")->use_spell(tp,targ,chance,100,"druid"); break;
            }
            break;

        case "level 4":

            tell_object(tp,"%^RED%^You clench your fist and then fling your hand towards "+targ->QCN+", striking him with nature's wrath!%^RESET%^");
            tell_object(targ,"%^RED%^"+tp->QCN+" clenches a fist and then flings "+tp->QP+" hand towards you, striking you with nature's wrath!%^RESET%^");
            tell_room(etp,"%^RED%^"+tp->QCN+" clenches a fist and then flings "+tp->QP+" hand towards "+targ->QCN+", striking "+targ->QO+" with nature's wrath!%^RESET%^",({tp,targ}));

            switch(myrace) {
              case "fire elemental": case "air elemental": new("/cmds/spells/f/_flame_strike")->use_spell(tp,targ,chance,100,"druid"); break;
              case "water elemental": case "earth elemental": default: new("/cmds/spells/r/_rusting_grasp")->use_spell(tp,targ,chance,100,"druid"); break;
            }
            break;
        }
    }

    return roll_dice(dice,3);
}
