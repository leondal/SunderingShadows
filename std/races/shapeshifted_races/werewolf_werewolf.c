#include <std.h>
#include <daemons.h>

inherit SHAPESHIFT;

void create()
{
    ::create();

    set_attack_limbs(({ "right hand", "left hand" }));
    set_limbs(({ "mouth", "head", "torso", "waist ", "left arm", "left hand", "right arm", "right hand", "left leg", "left foor", "right leg", "right food", "tail", "maw" }));
    set_base_attack_num(4);
    set_ac_bonus(2);
    set_castable(1);
    set_can_talk(1);
    set_shape_bonus("survival", 4);
    set_shape_bonus("perception", 2);
    set_shape_bonus("sight bonus", 3);
    set_shape_bonus("strength", 2);
    set_shape_bonus("dexterity", 2);
    set_shape_bonus("constitution", 2);
    set_shape_bonus("wisdom", 2);

    set_shape_bonus("damage bonus",3);
    set_shape_bonus("attack bonus",3);

    set_shape_bonus("cold resistance percent", 14);
    set_shape_bonus("silver resistance percent", -33);
    set_shape_race("werewolf");
    set_shape_profile("werewolf_hybrid_999");
}

int default_descriptions(object obj)
{
    if (!objectp(obj)) {
        return 0;
    }
    obj->set_description("is a strange humanoid resembling its original race. It has wolf-like ears and is covered in dark bluesh fur.");
    obj->setDescriptivePhrase("lean $R with dark blue fur and fluffy ears");

    return 1;
}

// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if (!objectp(obj)) {
        return 0;
    }
    tell_object(obj, "%^RESET%^%^RED%^%^BOLD%^You turn your mind out to the darkness as you focus on the core of your spirit.");
    tell_object(obj, "%^RESET%^%^RED%^You can feel your body beginning to change, you grow a tail and couple of wolf-like ears!");
    tell_object(obj, "%^RESET%^%^RED%^%^BOLD%^Your senses heighten, you can feel the pulse of the night, smell countless scents, you can taste the very air. You are werewolf!");

    tell_room(environment(obj), "%^RESET%^%^RED%^" + obj->QCN + " grows very still and appears to concentrate deeply.", obj);
    tell_room(environment(obj), "%^RESET%^%^RED%^" + obj->QCN + " begins to change in front of your very eyes and grows a tail and couple of wolf-like ears!", obj);
    tell_room(environment(obj), "%^RED%^Where " + obj->QCN + " once stood, is now a werewolf!", obj);

    return 1;
}

// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if (!objectp(obj)) {
        return 0;
    }

    tell_object(obj, "%^RESET%^%^RED%^You relax your focus on the wilds.");
    tell_object(obj, "%^RESET%^%^RED%^You can feel the sharpness of your senses beginning to fade and the strength returning.");
    tell_object(obj, "%^RESET%^%^GREEN%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your another body once again.");

    tell_room(environment(obj), "%^RESET%^%^BOLD%^" + obj->QCN + "'s muscles slacken and " + obj->QS + " gets a far-away look in " + obj->QP + " eyes.", obj);
    tell_room(environment(obj), "%^RESET%^%^BLUE%^" + obj->QCN + "'s body begins to change shape, elongating and curving!", obj);
    tell_room(environment(obj), "%^RESET%^%^GREEN%^Where " + obj->QCN + " once stood, now stands a " + obj->query_race() + "!", obj);

    return 1;
}

int can_cast()
{
    return 1;
}

int shape_attack(object tp, object targ)
{
    return 0;
}

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
    shape->set_shape_race("werewolf");
    shape->apply_bonuses(shape->query_owner());

    obj->add_id("werewolf");
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
    obj->remove_id("werewolf");
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
