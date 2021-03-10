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

    set_attack_limbs( ({ "right hand","left hand"}) );
    set_new_damage_type("piercing");
    set_limbs( ({ "head","torso","right hand", "left hand", "right arm","right arm","left leg","right leg",}) );
    set_attack_functions(([ "right hand" : (:TO,"hand_attack":), "left hand" : (:TO,"hand_attack":) ]));
    set_ac_bonus(-6);
    set_base_attack_num(4);
    set_castable(1);
    set_can_talk(1);
    set_shape_race("golem");
    set_shape_profile("mage_golem_999");
    set_shape_bonus("perception",6);
    set_shape_bonus("sight bonus",3);
    set_shape_bonus("damage bonus",3);
    set_shape_bonus("attack bonus",3);
    set_shape_bonus("spell damage resistance",30);
    set_shape_height(900+random(100));
    set_shape_weight(5000+random(500));
}

string * query_subraces() {
    return ({ "golem" });
}

// custom descriptions here, override this function
int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("%^BOLD%^%^BLUE%^ standing at an impressive thirty feet tall, this statue is made of iron. Rust-free and gray, it is molded to look like a fighter wearing a full face helmet and plate armor. The statue has both hands resting on the pommel of a huge sword, the tip of which rests upon the ground in front of it.%^RESET%^");

    obj->setDescriptivePhrase("%^BOLD%^%^BLUE%^gigantic  $R%^RESET%^");

    obj->set("speech string","reverb");
    obj->set("describe string","calmly");

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
    tell_object(obj,"%^RESET%^%^BLUE%^Your stomp, sending a waves of rolling thunder. You are a GOLEM!");
    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^RED%^Where "+obj->QCN+" once stood, now stands a DEMON!",obj);
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

int hand_attack(object tp, object targ)
{
    int rand;
    rand = random(10);
    if (!objectp(targ)) {
        return;
    }

    switch(rand)
    {
    case 0..2:
        tell_object(tp,"%^BLUE%^You swing at "+targ->QCN+" with your mighty fists, the blows connecting solidly!");
        tell_object(targ,"%^BLUE%^"+tp->QCN+" swings at you with its mighty fists, the blows connecting solidly!");
        tell_room(ENV(tp),"%^BLUE%^"+tp->QCN+" swings at "+targ->QCN+" with its mighty fists, the blows connecting solidly!",({tp,targ}));
        targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(clevel,6),"bludgeoning");
        break;
    case 3:
        tell_object(tp,"%^BOLD%^%^BLUE%^You grasp your hands together above the head before bringing them down in unison at "+targ->QCN+"!");
        tell_object(targ,"%^BOLD%^%^BLUE%^"+tp->QCN+"grasps its hands together above the head before bringing them down in unison at you!");
        tell_room(ENV(tp),"%^BOLD%^%^BLUE%^"+tp->QCN+" grasps its hands together above the head before bringing them in unison at "+targ->QCN+"!",({tp,targ}));
        targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(clevel,12),"bludgeoning");
    }
    return roll_dice(1,12);
}
