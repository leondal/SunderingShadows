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

    set_attack_limbs( ({ "head"}) );
    set_new_damage_type("piercing");
    set_limbs( ({ "head","torso","abdomen","left first leg", "left second leg", "left trid leg","left forth leg","right first leg","right second leg", "right third leg", "right forth leg",}) );
    set_attack_functions(([ "head" : (:TO,"bite_attack":)]));
    set_ac_bonus(-6);
    set_base_attack_num(3);
    set_castable(1);
    set_can_talk(1);
    set_shape_race("spider");
    set_shape_profile("mage_spider_999");
    set_shape_bonus("perception",4);
    set_shape_bonus("sight bonus",3);
    set_shape_bonus("damage bonus",3);
    set_shape_bonus("attack bonus",3);
    set_shape_bonus("damage resistance",15);
    set_shape_height(500+random(20));
    set_shape_weight(200+random(30));
}

string * query_subraces() {
    return ({ "spider" });
}

// custom descriptions here, override this function
int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("%^BOLD%^%^BLACK%^ has a large plump abdomen, multiple eyes, and four pairs of segmented legs. Its body is covered with short, black bristles. Two gray stripes run the length of its back. Its eyes are bright red. The creature moves incredibly fast for a 15 foot long spider.%^RESET%^");

    obj->setDescriptivePhrase("%^BOLD%^%^BLACK%^gigantic $R%^RESET%^");

    obj->set("speech string","hiss");
    obj->set("describe string","calmly");

    obj->force_me("message in walks in");
    obj->force_me("message out walks $D");

    return 1;
}


// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^RED%^You turn your mind elsewhere.");
    tell_object(obj,"%^RESET%^%^BOLD%^You can feel your body beginning to change!");
    tell_object(obj,"%^BOLD%^%^BLACK%^You adjust your stance. You are a spider.");
    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^BOLD%^%^BLACK%^Where "+obj->QCN+" once stood, now stands a spider.",obj);
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

int bite_attack(object tp, object targ)
{
    if(!random(6))
    {
        tell_object(tp,"%^BOLD%^%^BLACK%^You sink your fangs %^RED%^deep%^BLACK%^ into "+targ->QCN+"'s flesh!");
        tell_object(targ,"%^BOLD%^%^BLACK%^"+tp->QCN+" sinks its fangs %^RED%^deep%^BLACK%^ into your flesh!");
        tell_room(ENV(tp),"%^BOLD%^%^BLACK%^"+tp->QCN+" sinks its fangs %^RED%^deep%^BLACK%^ into "+targ->QCN+"'s flesh!",({tp,targ}));
        targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(clevel,6),"piercing");
    }
    return roll_dice(2,6);
}
