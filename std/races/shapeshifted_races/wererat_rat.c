#include <std.h>
#include <daemons.h>
inherit SHAPESHIFT;

#include "mage_shapes.h"

// all of the functions set in create below need to be there so it doesn't bug when trying to shapeshift -Ares
// when making a new shape, be sure to include those functions or it'll fall back to the defaults
void create()
{
    ::create();

    set_attack_limbs(({ "mouth" }));
    set_new_damage_type("piercing");
    set_limbs(({ "mouth", "head", "torso", "right foreleg", "left foreleg", "right rear leg", "left rear leg", "tail" }));
    set_attack_functions(([ "mouth" : (: TO, "shape_attack" :) ]));
    set_ac_bonus(6);
    set_base_attack_num(0);
    set_castable(1);
    set_can_talk(0);
    set_shape_race("bird");
    set_shape_profile("wererat_rat_999");
    set_shape_bonus("sight bonus", 5);
    set_shape_bonus("dexterity", 2);
    set_shape_height(10 + random(5));
    set_shape_weight(10 + random(20));
}

string* query_subraces()
{
    return ({ "rat" });
}

int default_descriptions(object obj)
{
    if (!objectp(obj)) {
        return 0;
    }

    obj->set_description("is a small creature with red eyes and fluffy fur.");
    obj->setDescriptivePhrase("$R");
    obj->force_me("message in crawls in");
    obj->force_me("message out crawls $D");
    return 1;
}

// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if (!objectp(obj)) {
        return 0;
    }
    tell_object(obj, "%^BOLD%^%^RED%^You close your eyes and concentrate on the plague within.");
    tell_object(obj, "%^RED%^You can feel your body beginning to change!");
    tell_object(obj, "%^BOLD%^%^RED%^Your senses heighten, you can feel the pulse of the world, smell countless scents, you can taste the very air.  Your body grows light and the winds tug at you, you are now a rat.");

    tell_room(environment(obj), "%^RED%^%^BOLD%^" + obj->QCN + " grows very still and appears to concentrate deeply.", obj);
    tell_room(environment(obj), "%^RESET%^%^RED%^" + obj->QCN + " begins to change in front of your very eyes!", obj);
    tell_room(environment(obj), "%^BOLD%^%^RED%^Where " + obj->QCN + " once stood, is now a rat!", obj);

    return 1;
}

int change_outof_message(object obj)
{
    if (!objectp(obj)) {
        return 0;
    }

    tell_object(obj, "%^RESET%^%^BOLD%^%^RED%^You relax your focus on the plague within.");
    tell_object(obj, "%^RESET%^%^BLUE%^You can feel the sharpness of your senses beginning to fade and the strength returning.");
    tell_object(obj, "%^RESET%^%^BOLD%^%^RED%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your another body once again.");

    tell_room(environment(obj), "%^RESET%^%^BOLD%^%^RED%^" + obj->QCN + "'s body grows still " + obj->QS + " gets a far-away look in " + obj->QP + " eyes.", obj);
    tell_room(environment(obj), "%^RESET%^%^RED%^" + obj->QCN + "'s body begins to change shape, elongating and curving!", obj);
    tell_room(environment(obj), "%^RESET%^%^RED%^%^BOLD%^Where " + obj->QCN + " once stood, now stands a " + obj->query_race() + "!", obj);

    return 1;
}

// custom unarmed attack functions go here, functions can be added just like hit functions for weapons
int shape_attack(object tp, object targ)
{
    return 0;
}

int can_cast()
{
    if (!objectp(query_owner())) {
        return 0;
    }
    if (FEATS_D->usable_feat(query_owner(), "wild spellcraft")) {
        return 1;
    }
    return can_cast_spells;
}
