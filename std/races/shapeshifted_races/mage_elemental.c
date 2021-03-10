#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SHAPESHIFT;

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
    set_new_damage_type("bludgeoning");
    set_limbs( ({ "head","torso","right arm", "left arm" }) );
    set_attack_functions(([ "right hand" : (:TO,"shape_attack":), "left hand" : (:TO,"shape_attack":) ]));
    set_base_attack_num(2);
    set_castable(1);
    set_can_talk(1);

    set_shape_race("elemental");
    set_shape_bonus("sight bonus",3);
    set_shape_profile("mage_elemental_999");
}

string * query_subraces() {
    return ({ "elemental" });
}

// custom descriptions here, override this function
int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("rises before you, a creature of pure elemental force. Vaguely humanoid, it "
        "has a head with depthless orbs for eyes, descending to the outline of a body with arms at "
        "either side. The torso trails down to a formless mass that moves over the ground somehow. "
        "The being is unsettling at best, its intimidating bulk being something not of this plane.");

    obj->setDescriptivePhrase("small $R");

    obj->set("speech string","reverb");
    obj->set("describe string","eerly");

    obj->force_me("message in floats in");
    obj->force_me("message out floats $D");

    return 1;
}


// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^BOLD%^You can feel your body beginning to change!");
    tell_object(obj,"%^RESET%^%^WHITE%^Your shift, embracing your new elemental body.");
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^WHITE%^Where "+obj->QCN+" once stood, now stands an elemental!",obj);
    return 1;
}


// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^BOLD%^You relax your focus, releasing the elements.");
    tell_object(obj,"%^RESET%^%^WHITE%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your own body once again.");

    tell_room(environment(obj),"%^RESET%^%^WHITE%^"+obj->QCN+"'s body begins to change shape, shrinking and quickly loosing elemental infusion!",obj);
    tell_room(environment(obj),"%^RESET%^%^WHITE%^Where "+obj->QCN+" once stood, now stands a "+obj->query_race()+"!",obj);
    return 1;
}

int can_cast()
{
    return 1;
}

int shape_attack(object tp, object target)
{
    if(!random(10))
    {
        if(!objectp(target)) return;
        tell_object(target,"%^YELLOW%^The %^RESET%^%^RED%^e%^BOLD%^l%^RESET%^%^GREEN%^e%^BOLD%^m%^RESET%^%^ORANGE%^e%^BOLD%^n%^RESET%^%^CYAN%^t%^BOLD%^a%^RESET%^%^MAGENTA%^l%^WHITE%^%^BOLD%^ %^RESET%^%^YELLOW%^moves pummel you%^RESET%^%^YELLOW%^!");
        tell_room(ENV(tp),"%^YELLOW%^The %^RESET%^%^RED%^e%^BOLD%^l%^RESET%^%^GREEN%^e%^BOLD%^m%^RESET%^%^ORANGE%^e%^BOLD%^n%^RESET%^%^CYAN%^t%^BOLD%^a%^RESET%^%^MAGENTA%^l%^WHITE%^%^BOLD%^ %^RESET%^%^YELLOW%^moves pummel "+target->QCN+"%^RESET%^%^YELLOW%^!",target);
        target->do_damage("torso",random(70)+clevel);
    }
    return roll_dice(2,6);
}
