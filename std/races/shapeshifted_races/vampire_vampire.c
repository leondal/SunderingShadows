#include <std.h>
#include <daemons.h>

inherit SHAPESHIFT;

void create()
{
    ::create();

    set_base_attack_num(4);
    set_ac_bonus(6);
    set_castable(1);
    set_can_talk(1);
    set_shape_race("vampire");
    set_shape_profile("vampire_vampire_999");
    set_shape_bonus("perception",4);
    set_shape_bonus("damage bonus",2);
    set_shape_bonus("attack bonus",2);
    set_base_attack_num(2);
    set_shape_bonus("damage resistance",6);
    set_shape_bonus("spell damage resistance",20);
    set_shape_bonus("empowered",2);
    set_shape_bonus("spell penetration",4);
    set_shape_bonus("sight bonus",4);
}

int default_descriptions(object obj)
{
    if (!objectp(obj)) {
        return 0;
    }
    obj->set_description("is a humanoid whose features reflect its demonic and unliving origin. ");
    obj->setDescriptivePhrase("$R");

    return 1;
}

// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^RED%^%^BOLD%^You turn your sight inwards, embracing the call of your bloodline.");
    tell_object(obj,"%^RESET%^%^RED%^You feel your body changing, your nails turn to claws, your fangs lenghten.");
    tell_object(obj,"%^RESET%^%^RED%^You embrace yourself with pain as a pair of bat-like wings sprout from your back!");
    tell_object(obj,"%^RESET%^%^BOLD%^%^RED%^The hunt has began. You're a vampire lord.");

    tell_room(environment(obj),"%^RESET%^%^RED%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^RED%^"+obj->QCN+" begins to change in front of your very eyes, "+obj->QP+" nails turn to claws, fangs lenghten, a pair of bat-like wings sprout from the back.",obj);
    tell_room(environment(obj),"%^RED%^Where "+obj->QCN+" once stood, now stands a vampire lord!",obj);

    return 1;
}

// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^RED%^You relax your focus on the bloodline.");
    tell_object(obj,"%^RESET%^%^RED%^You can feel the sharpness of your senses beginning to fade and the strength returning.");
    tell_object(obj,"%^RESET%^%^RED%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your another form once again.");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+"'s muscles slacken and "+obj->QS+" gets a far-away look in "+obj->QP+" eyes.",obj);
    tell_room(environment(obj),"%^RESET%^%^BLUE%^"+obj->QCN+"'s body begins to change shape, elongating and curving!",obj);
    tell_room(environment(obj),"%^RESET%^%^RED%^Where "+obj->QCN+" once stood, now stands a "+obj->query_race()+"!",obj);

    return 1;
}

int can_cast()
{
    return 1;
}

int shape_attack(object tp, object targ) { return 0; }

int init_shape(object obj, string str)
{
    if (!objectp(obj)) {
        return 0;
    }
    if (obj->query_property("altered") || obj->query_property("shapeshifted")) {
        return 0;
    }                                                                                       // can't shapeshift twice
    obj->set_property("altered", shape = new(base_name(TO) + ".c"));
    shape->set_owner(obj);
    shape->change_into_message(obj);
    shape->set_base_profile((string)obj->query("relationship_profile"));
    shape->set_shape_race("vampire");
    shape->apply_bonuses(shape->query_owner());

    obj->add_id("vampire");
    obj->set("relationship_profile", shape->query_shape_profile());
    obj->add_id(obj->query_race());

    if (objectp(to_object(DESC_D))) {
        desc = new(DESC_D); //
        if (!desc->restore_profile_settings(obj, shape->query_shape_profile())) {
            shape->default_descriptions(obj);
            desc->initialize_profile(obj);
        }
    }
    return 1;
}

int reverse_shape(object obj)
{
    if (!objectp(obj)) {
        return 3;
    }
    if (!objectp(shape = obj->query_property("altered"))) {
        return 5;
    }
    obj->set("relationship_profile", shape->query_base_profile());
    obj->remove_id("vampire");
    if (objectp(to_object(DESC_D))) {
        desc = new(DESC_D);
        desc->restore_profile_settings(obj, shape->query_base_profile());
    }
    shape->reverse_bonuses(shape->query_owner());
    shape->change_outof_message(obj);
    shape->set_owner(0);
    obj->remove_property("altered");
    clean_me = 1;
    destruct(TO);
    return 1;
}
