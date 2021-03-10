#include <std.h>

inherit SHAPESHIFT;

// all of the functions set in create below need to be there so it doesn't bug when trying to shapeshift -Ares
// when making a new shape, be sure to include those functions or it'll fall back to the defaults
void create()
{
    ::create();

    set_attack_limbs( ({ "mouth" }) );
    set_new_damage_type("piercing");    
    set_limbs( ({ "mouth","head","torso","right foreleg","left foreleg","right rear leg","left rear leg","curly tail" }) );
    set_ac_bonus(0); // ac bonus is different from the other bonuses because of the way ac is calculated with different body types -Ares
    set_base_attack_num(0);
    set_castable(0);
    set_can_talk(0);
    set_shape_race("pig");
    set_shape_language("sylvan");
    set_shape_profile("circe_pig_999"); // needs to be something the player is unlikely to name one of their profiles when disguise goes in

}

string * query_subraces() {
    return ({ "pig" });
}

// custom descriptions here, override this function
int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("is a fat, pink little pig.");

    obj->setDescriptivePhrase("fat, pink little $R");

    obj->set("speech string","oink");
    obj->set("describe string","eagerly");

    obj->force_me("message rushes in and roots around on the ground");
    obj->force_me("message squeals and runs off to the $D");

    return 1;
}


// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^MAGENTA%^You feel something happening, your body starts to change!");
    tell_object(obj,"%^MAGENTA%^Your hands and feet turn into hooves and your nose into a snout!");
    tell_object(obj,"%^MAGENTA%^You are now a PIG!");

    tell_room(environment(obj),"%^MAGENTA%^"+obj->QCN+" looks worried for a moment.",obj);
    tell_room(environment(obj),"%^MAGENTA%^"+obj->QCN+"'s hands and feet start changing into hooves, and "+obj->QP+" nose into a snout!",obj);
    tell_room(environment(obj),"%^MAGENTA%^Where "+obj->QCN+" once stood, now stands a PIG!",obj);

    obj->force_me("emote oinks!");

    return 1;
}


// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^BOLD%^You feel yourself quickly changing back!");
    tell_object(obj,"%^BOLD%^Your belly shrinks and your snout retracts back into your nose!");
    tell_object(obj,"%^BOLD%^You're left kneeling on all fours, and you can't resist the urge to oink one last time!");

    tell_room(environment(obj),"%^BOLD%^You can see "+obj->QCN+" starting to change!",obj);
    tell_room(environment(obj),"%^BOLD%^"+obj->QCN+"'s belly shrinks and "+obj->QP+" snout retracts back into "+obj->QP+" nose!",obj);
    tell_room(environment(obj),"%^BOLD%^"+obj->QCN+" is left kneeling on all fours!",obj);

    obj->force_me("emote oinks!");
    
    return 1;
}


// custom unarmed attack functions go here, functions can be added just like hit functions for weapons
int shape_attack(object tp, object targ)
{
    return 0;
}