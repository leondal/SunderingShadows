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

    set_attack_limbs( ({ "maw","right claw","left claw"}) );
    set_new_damage_type("piercing");
    set_limbs( ({ "maw","head","maw","right arm", "left arm", "left leg", "right leg", "right claw","left claw" }) );
    set_attack_functions(([ "maw" : (:TO,"bite_attack":), "right claw" : (:TO,"claw_attack":), "left claw" : (:TO,"claw_attack":) ]));
    set_ac_bonus(-4);
    set_base_attack_num(3);
    set_castable(1);
    set_can_talk(1);
    set_shape_race("troll");
    set_shape_profile("mage_troll_999");
    set_shape_bonus("survival",4);
    set_shape_bonus("sight bonus",3);
    set_shape_bonus("damage bonus",3);
    set_shape_bonus("attack bonus",3);
    set_shape_bonus("damage resistance",7);
    set_shape_bonus("spell damageresistance",7);
    set_shape_height(120+random(10));
    set_shape_weight(180+random(40));
}

string * query_subraces() {
    return ({ "troll" });
}

// custom descriptions here, override this function
int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("%^RESET%^%^ORANGE%^ is disgusting green skinned creature stands in front of you at almost 10 feet tall. A rubbery skin covers its skinny limbs. It has black hair growing out of its oblong head and its eyes are hidden inside deep black sockets.%^RESET%^");

    obj->setDescriptivePhrase("%^RESET%^%^ORANGE%^stinking $R%^RESET%^");

    obj->set("speech string","growl");
    obj->set("describe string","angrily");

    obj->force_me("message in lumbers in");
    obj->force_me("message out lumbers off to the $D");

    return 1;
}


// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^RED%^You turn your mind elsewhere.");
    tell_object(obj,"%^RESET%^%^BOLD%^You can feel your body beginning to change!");
    tell_object(obj,"%^GREEN%^You roar. You are a troll.");
    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^GREEN%^Where "+obj->QCN+" once stood, now stands a troll!",obj);
    return 1;
}


// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^BOLD%^You relax your focus.");
    tell_object(obj,"%^RESET%^%^GREEN%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your own body once again.");

    tell_room(environment(obj),"%^RESET%^%^BLUE%^"+obj->QCN+"'s body begins to change shape, shrinking and quickly loosing scales!",obj);
    tell_room(environment(obj),"%^RESET%^%^GREEN%^Where "+obj->QCN+" once stood, now stands a "+obj->query_race()+"!",obj);
    return 1;
}

int can_cast()
{
    return 1;
}

int bite_attack(object tp, object targ)
{
    string my_limb;
    if(!random(6))
    {
        tell_object(tp,"%^GREEN%^You lightning quick bite %^BOLD%^%^BLACK%^deeply%^RESET%^%^GREEN%^ into "+targ->QCN+"'s "+(my_limb=targ->return_target_limb())+"!");
        tell_object(targ,"%^GREEN%^"+tp->QCN+" lightning quick bites %^BOLD%^%^BLACK%^deeply%^RESET%^ into your "+my_limb+"!");
        tell_room(ENV(tp),"%^GREEN%^"+tp->QCN+" snakes "+tp->QP+" lightning quick bites %^BOLD^%^BLACK%^deeply%^RESET%^ into "+targ->QCN+"'s "+my_limb+"!",({tp,targ}));
        targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(clevel,8),"piercing");
    }
}

int claw_attack(object tp, object targ)
{
    if(!random(6))
    {
        tell_object(tp,"%^GREEN%^You reach out and %^BOLD%^violently %^RESET%^%^GREEN%^claw "+targ->QCN+"!");
        tell_object(targ,"%^GREEN%^"+tp->QCN+" reaches out and %^BOLD%^violently%^RESET%^%^GREEN%^ claws you!");
        tell_room(ENV(tp),"%^GREEN%^"+tp->QCN+" reaches out and %^BOLD%^violently%^RESET%^%^GREEN%^ claws "+targ->QCN+"!",({tp,targ}));
        targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(clevel,6),"slashing");
    }
    return roll_dice(2,6);
}
