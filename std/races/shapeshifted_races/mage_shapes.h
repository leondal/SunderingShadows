int init_shape(object obj,string mysubrace)
{
    string *subraces;
    if(!objectp(obj))
        return 0;
    if(obj->query_property("shapeshifted") || obj->query_property("altered"))
        return 0;
    obj->set_property("shapeshifted",shape = new(base_name(TO)+".c"));
    shape->set_owner(obj);
    hp_percent = to_float( (to_float((int)obj->query_hp() - (int)obj->query_extra_hp())) / (to_float((int)obj->query_max_hp())));
    shape->apply_bonuses(shape->query_owner());
    obj->set_hp( to_int(  hp_percent * to_float((int)obj->query_max_hp())) );
    shape->set_old_attack_limbs((string*)obj->query_attack_limbs());
    obj->set_attack_limbs(shape->query_attack_limbs());
    obj->set_hit_funcs(shape->query_attack_functions());
    obj->set_fake_limbs(shape->query_limbs());
    shape->set_old_damage_type(obj->query_base_damage_type());
    shape->change_into_message(obj);
    shape->set_base_profile((string)obj->query("relationship_profile"));
    shape->set_shape_race(mysubrace);
    obj->set("relationship_profile",shape->query_shape_profile());
    obj->add_id(shape->query_shape_race());
    subraces = (string *)shape->query_subraces();
    if(sizeof(subraces))
    {
      if(member_array(subraces[0],(string *)obj->query_id()) == -1) obj->add_id(subraces[0]);
    }

    if(objectp(to_object(DESC_D)))
    {
        desc = new(DESC_D);
        if(!desc->restore_profile_settings(obj,shape->query_shape_profile()))
        {
            shape->default_descriptions(obj);
            desc->initialize_profile(obj);
        }
    }

    return 1;
}


varargs int reverse_shape(object obj,int silent)
{
    string *subraces;
    if(!objectp(obj))
        return 3;
    if(!objectp(shape = obj->query_property("shapeshifted")))
        return 5;
    hp_percent = to_float( (to_float((int)obj->query_hp() - (int)obj->query_extra_hp())) / (to_float((int)obj->query_max_hp())));
    shape->reverse_bonuses(shape->query_owner());
    obj->set_hp( to_int(  hp_percent * to_float((int)obj->query_max_hp())) );
    obj->set_attack_limbs(shape->query_old_attack_limbs());
    obj->set_hit_funcs( ([]) );
    obj->remove_fake_limbs();
    obj->set("relationship_profile",shape->query_base_profile());
    obj->remove_id(shape->query_shape_race());
    obj->set_base_damage_type(shape->query_old_damage_type());
    if(objectp(to_object(DESC_D)))
    {
        desc = new(DESC_D);
        desc->restore_profile_settings(obj,shape->query_base_profile());
    }
    if(!silent) shape->change_outof_message(obj);
    shape->set_owner(0);
    obj->remove_property("shapeshifted");
    clean_me = 1;
    destruct(TO);
    return 1;
}
