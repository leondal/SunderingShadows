#include <std.h>
#include <daemons.h>

inherit SHAPESHIFT;

// all of the functions set in create below need to be there so it doesn't bug when trying to shapeshift -Ares
// when making a new shape, be sure to include those functions or it'll fall back to the defaults
void create()
{
    ::create();

    set_attack_limbs( ({ "mouth" }) );
    set_new_damage_type("piercing");    
    set_limbs( ({ "mouth","head","torso","right foreleg","left foreleg","right rear leg","left rear leg","tail" }) );
    set_attack_functions( ([ "mouth" : (:TO,"shape_attack":) ]) );
    set_ac_bonus(0); // ac bonus is different from the other bonuses because of the way ac is calculated with different body types -Ares
    set_base_attack_num(0);
    set_castable(0);
    set_can_talk(0);
    set_shape_race("animal");
    set_shape_language("sylvan");
    set_shape_profile("druid_large_animal_999"); // needs to be something the player is unlikely to name one of their profiles when disguise goes in
    set_shape_height(30+random(20));
    set_shape_weight(500+random(500));
}

string * query_subraces() {
    return ({ "animal","ape","horse","buffalo","deer","moose","goat","boar","camel","bison" });
}

// custom descriptions here, override this function
int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("is a large, furry animal.");

    obj->setDescriptivePhrase("furry $R");

    obj->set("speech string","rumble");
    obj->set("describe string","lazily");

    obj->force_me("message in lumbers in");
    obj->force_me("message out lumber to the $D");

    return 1;
}


// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^GREEN%^You turn your mind out to the wilds as you focus on the core of your spirit.");
    tell_object(obj,"%^RESET%^%^BOLD%^You can feel your body beginning to change!");
    tell_object(obj,"%^RESET%^%^RED%^Your senses heighten, you can feel the pulse of the world, smell countless scents, "
        "you can taste the very air.  You feel yourself quickly turning into a large animal.");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^YELLOW%^Where "+obj->QCN+" once stood, is now a large animal!",obj);

    return 1;
}


// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^BOLD%^You relax your focus on the natural world.");
    tell_object(obj,"%^RESET%^%^BLUE%^You can feel the sharpness of your senses beginning to fade and the keen edge of intellect returning.");
    tell_object(obj,"%^RESET%^%^GREEN%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your own body once again.");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+"'s body grows still "+obj->QS+" gets a far-away look in "+obj->QP+" eyes.",obj);
    tell_room(environment(obj),"%^RESET%^%^BLUE%^"+obj->QCN+"'s body begins to change shape, elongating and curving!",obj);
    tell_room(environment(obj),"%^RESET%^%^GREEN%^Where "+obj->QCN+" once stood, now stands a "+obj->query_race()+"!",obj);
    
    return 1;
}


// custom unarmed attack functions go here, functions can be added just like hit functions for weapons
int shape_attack(object tp, object targ)
{
    return 0;
}

int can_cast() 
{ 
    if(!objectp(query_owner())) { return 0; }
    if(FEATS_D->usable_feat(query_owner(),"wild spellcraft")) { return 1; }
    return can_cast_spells; 
}
