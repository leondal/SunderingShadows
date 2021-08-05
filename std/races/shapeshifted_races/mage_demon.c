#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SHAPESHIFT;

#include "mage_shapes.h"

int clevel;

void set_clevel(int x)
{
    clevel = x;
}

// all of the functions set in create below need to be there so it doesn't bug when trying to shapeshift -Ares
// when making a new shape, be sure to include those functions or it'll fall back to the defaults
void create()
{
    ::create();

    set_attack_limbs( ({ "right claw","left claw"}) );
    set_new_damage_type("piercing");
    set_limbs( ({ "maw","head","torso","right claw", "left claw", "right arm","right arm","left leg","right leg","tail","right wing","left wing" }) );
    set_attack_functions(([ "right claw" : (:TO,"claw_attack":), "left claw" : (:TO,"claw_attack":) ]));
    set_ac_bonus(-3);
    set_base_attack_num(4);
    set_castable(1);
    set_can_talk(1);
    set_shape_race("demon");
    set_shape_profile("mage_demon_999");
    set_shape_bonus("spellcraft",2);
    set_shape_bonus("stealth", 2);
    set_shape_bonus("sight bonus",3);
    set_shape_bonus("damage bonus",4);
    set_shape_bonus("attack bonus",4);
    set_shape_bonus("spell damage resistance",20);
    set_shape_height(180+random(10));
    set_shape_weight(4000+random(500));
}

string * query_subraces() {
    return ({ "demon" });
}

// custom descriptions here, override this function
int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description(" towers at an impressive thirty feet tall. Its whole humanoid body is covered in a fine red fur. Giant black leathery wings extend from it's back and two horns rise above it's head. Its face is vaugely bull like, with horns extending at the side of each of its jaws. Massive teeth fill a large maw.");

    obj->setDescriptivePhrase("towering $G $R");

    obj->set("speech string","growl");
    obj->set("describe string","angrily");

    obj->force_me("message in stomps in");
    obj->force_me("message out stomps $D");

    return 1;
}


// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^RED%^You turn your mind elsewhere.");
    tell_object(obj,"%^RESET%^%^BOLD%^You can feel your body beginning to change!");
    tell_object(obj,"%^RESET%^%^BLUE%^You flap your wings and roar. You are a DEMON!");
    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^BOLD%^%^RED%^Where "+obj->QCN+" once stood, now stands a DEMON!",obj);
    return 1;
}


// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^BOLD%^You relax your focus.");
    tell_object(obj,"%^RESET%^%^GREEN%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your own body once again.");

    tell_room(environment(obj),"%^RESET%^%^BLUE%^"+obj->QCN+"'s body begins to change shape, shrinking and quickly loosing red fur!",obj);
    tell_room(environment(obj),"%^RESET%^%^GREEN%^Where "+obj->QCN+" once stood, now stands a "+obj->query_race()+"!",obj);
    return 1;
}

int can_cast()
{
    return 1;
}

int claw_attack(object tp, object targ)
{
    int rand;
    rand = random(10);
    if(rand > 5)
    {
        tell_object(tp,"%^RED%^You %^BOLD%^%^BLACK%^rake%^RESET%^%^RED%^ your massive claws into "+targ->QCN+"'s flesh!");
        tell_object(targ,"%^RED%^"+tp->QCN+" %^BOLD%^%^BLACK%^rakes%^RESET%^%^RED%^ its massive claws into your flesh!");
        tell_room(ENV(tp),"%^RED%^"+tp->QCN+" %^BOLD^%^BLACK%^rakes%^RESET%^%^RED%^ its massive claws into "+targ->QCN+"'s flesh!",({tp,targ}));
        targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(clevel/5,6),"slashing");
    }
    else
    {
        tell_object(tp,"%^BOLD%^%^RED%^%^You grab "+targ->QCN+" with both claws, then bite massive chunk of "+targ->QP+" flesh!");
        tell_object(targ,"%^BOLD%^%^RED%^"+tp->QCN+" grabs you with both claws, then bites massive chunk of your flesh!");
        tell_room(ENV(tp),"%^BOLD%^%^RED%^"+tp->QCN+" grabs "+targ->QCN+" with both claws, then bites massive chunk of "+targ->QP+" flesh!",({tp,targ}));
        targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(clevel/3,6),"piercing");
    }

    return roll_dice(1,6);

    //2d6+13
}
