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
    set_limbs(({ "head","torso","right leg","left leg","right arm","left arm","right hand","left hand",}));
    set_attack_functions(([ "right hand" : (:TO,"claw_attack":), "left hand" : (:TO,"claw_attack":)]));
    set_ac_bonus(-6);
    set_base_attack_num(3);
    set_castable(1);
    set_can_talk(1);
    set_shape_race("pixie");
    set_shape_profile("mage_pixie_999");
    set_shape_bonus("perception",4);
    set_shape_bonus("sight bonus",3);
    set_shape_bonus("damage bonus",3);
    set_shape_bonus("attack bonus",3);
    set_shape_bonus("spell damage resistance",15);
    set_shape_height(6);
    set_shape_weight(1);
}

string * query_subraces() {
    return ({ "pixie" });
}

// custom descriptions here, override this function
int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("%^BOLD%^%^GREEN%^ is about two and half feet tall with beautiful silver wings. It is dressed in brightly colored clothing. Its little wings flutter back and forth making a faint buzzing noise. Its hair is pink.%^RESET%^");

    obj->setDescriptivePhrase("%^BOLD%^%^MAGENTA%^tiny $R%^RESET%^");

    obj->set("speech string","chirp");
    obj->set("describe string","cheerfully");

    obj->force_me("message in flies in");
    obj->force_me("message out flies $D");

    return 1;
}


// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^RED%^You turn your mind elsewhere.");
    tell_object(obj,"%^RESET%^%^BOLD%^You can feel your body beginning to change!");
    tell_object(obj,"%^BOLD%^%^GREEN%^You flap your wings and make a cute tiny roar. You are a pixie.");
    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^BOLD%^%^GREEN%^Where "+obj->QCN+" once stood, now flies a pixie.",obj);
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
    string RND_COLORS = ({"%^BOLD%^%^GREEN%^","%^BOLD%^%^MAGENTA%^","%^MAGENTA%^","%^CYAN%^","%^BOLD%^%^CYAN%^"});
    string clr = RND_COLORS[random(sizeof(RND_COLORS))];
    if(!random(6))
    {
        tell_object(tp, clr+"You furiously claw "+targ->QCN+"!");
        tell_object(targ, clr+tp->QCN+" furiously claws you!");
        tell_room(ENV(tp), clr+tp->QCN+" furiously claws "+targ->QCN+"!",({tp,targ}));
        targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(clevel,8),"slashing");
    }

    return roll_dice(2,6);
    //2d6+13
}
