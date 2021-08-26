// this file is only for use in the "alter self" spell. It creates a single same-race profile for the caster.
#include <std.h>
#include <objects.h>
#include <daemons.h>
inherit SHAPESHIFT;

int height, weight;
object file;

void create(){
    ::create();
    set_ac_bonus(0);
    set_base_attack_num(0);
    set_castable(1);
    set_can_talk(1);
    set_shape_profile("spell_alter_self_999"); // single alter self profile per caster.
}

// custom descriptions here, override this function
int default_descriptions(object obj) {
    if(!objectp(obj)) { return 0; }

    obj->set_description("is a typical specimen of the race.");
    obj->setDescriptivePhrase("typical $R");
    return 1;
}

int change_into_message(object obj) {
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^GREEN%^You turn your mind inwards as the spell begins to take effect.");
    tell_object(obj,"%^RESET%^%^BOLD%^You can feel your body beginning to change! Your skin ripples, and your facial features run like wax.");
    tell_object(obj,"%^RESET%^%^RED%^Finally, just when you feel like you can take no more, you take a breath and you are someone else entirely!");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes. Textures ripple across skin as facial features run like wax.",obj);
    tell_room(environment(obj),"%^YELLOW%^Where "+obj->QCN+" once stood, is now a different person!",obj);
    return 1;
}

int change_outof_message(object obj) {
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^BOLD%^You attune your mind to the person you used to be.");
    tell_object(obj,"%^RESET%^%^BLUE%^You can feel the sense of the world around you fading, as everything becomes momentarily blurred.");
    tell_object(obj,"%^RESET%^%^GREEN%^You inhale a breath and stretch as you grow accustomed to the familiar sensation of your own body once again.");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+"'s body grows still "+obj->QS+" gets a far-away look in "+obj->QP+" eyes.",obj);
    tell_room(environment(obj),"%^RESET%^%^BLUE%^"+obj->QCN+"'s features run together and shift as you watch!",obj);
    tell_room(environment(obj),"%^RESET%^%^GREEN%^Where "+obj->QCN+" once stood, now stands a "+obj->query_race()+"!",obj);
    return 1;
}

int shape_attack(object tp, object targ) { return 0; }

int init_shape(object obj,string str){
    string alter_profile;

    if(!objectp(obj)) { return 0; } //
    if(member_array(str,RACE_D->query_races())==-1)
       return 0;
    if(obj->query_property("altered") || obj->query_property("shapeshifted")) { return 0; } // can't shapeshift twice
    obj->set_property("altered",shape = new(base_name(TO)+".c")); // makes a new shape and sets the shapeshifted property to it, this is where all the work is done, very important
    if((alter_profile=obj->query("alter_self_profile")))
    {
        shape->set_shape_profile(alter_profile);
    }
    shape->set_owner(obj);
    shape->change_into_message(obj);
    shape->set_base_profile((string)obj->query("relationship_profile"));

    shape->set_shape_race(str);
    obj->set("relationship_profile",shape->query_shape_profile());
    obj->add_id(shape->query_shape_race());

    height = obj->query_player_height();
    weight = obj->query_player_weight();
    
    /*
    if(userp(obj)){
        shape->set_shape_height(obj->query_player_height());
        shape->set_shape_weight(obj->query_player_weight());
    }
    */

    if(userp(obj))
    {
        if(file = find_object("/std/races/" + str + ".c"))
        {
            weight = file->weight_base(obj->query_gender());
            height = file->height_base(obj->query_gender());
            shape->set_shape_weight(weight);
            shape->set_shape_height(height);
        }
    }    

    if(objectp(to_object(DESC_D)))     {
        desc = new(DESC_D); //
        if(!desc->restore_profile_settings(obj,shape->query_shape_profile())) {
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
    if (obj->query_race() != shape->query_shape_race()) {
        obj->remove_id(shape->query_shape_race());
    }
    if (objectp(to_object(DESC_D))) {
        desc = new(DESC_D);
        desc->restore_profile_settings(obj, shape->query_base_profile());
    }
    shape->change_outof_message(obj);
    shape->set_owner(0);
    obj->remove_property("altered");
    clean_me = 1;
    destruct(TO);
    return 1;
}

int can_cast()
{
    return 1;
}
