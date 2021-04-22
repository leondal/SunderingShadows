/*
  _second_wind.c
  
  Fighter class level 31 capstone.
  Causes a heal-over-time and cleanses some conditions.
  
  --Tlaloc--
*/


#include <std.h>
#include <daemons.h>

inherit FEAT;

int power;

void create()
{
    ::create();
    set_author("tlaloc");
    feat_type("instant");
    feat_category("GeneralCombat");
    feat_name("second wind");
    feat_prereq("31 levels in Fighter Class");
    feat_syntax("second_wind");
    feat_desc("This feat represents the grit of a fighter who is truly dedicated to battle. With this feat, the fighter cleanses negative effects from themselves, and will gain fast healing over 8 rounds.");
    set_required_for(({ }));
}


int allow_shifted() { return 1; }


int prerequisites(object ob)
{
    int success = 0;
    string *classes;
    
    if(!objectp(ob)) { return 0; }
    
    if(ob->query_class_level("fighter") < 31)
        return 0;
        
    return ::prerequisites(ob);
}

int cmd_second_wind(string str)
{
    object feat;
    if(!objectp(this_player())) { return 0; }
    
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    return 1;
}


void execute_feat()
{
    object cleanser;
    
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    
    if(FEATS_D->is_active(caster, "second wind"))
    {
        tell_object(caster, "Second Wind is already active.");
        dest_effect();
        return;
    }
    
    if(caster->cooldown("second wind"))
    {
        tell_object(caster, "You can't use second wind yet.");
        return;
    }

    ::execute_feat();
    
    cleanser = find_object("/std/magic/cleanse")->cleanse(caster);
    cleanser && cleanser->cleanse(caster);
    power = caster->query_class_level("fighter") / 5;

    tell_object(caster, "You reach deep down, into your deepest reserves to overcome your enemies.");
    tell_room(place, caster->QCN + " reaches deep down into their reserves to overcome their enemies.", ({ caster }));
    caster->add_cooldown("second wind", 600);
    caster->set_property("active_feats", ({ TO }));
    caster->set_property("fast healing", power);
    call_out("dest_effect", 48);
    
    return;
}

void execute_attack()
{
    int power;
    
    ::execute_attack();
    
    if(!caster)
        return;
    
    tell_object(caster, "%^GREEN%^BOLD%^You feel your second wind emboldening you.%^RESET%^");
}
    
void dest_effect()
{
    if (objectp(caster))
    {
        tell_object(caster, "%^BOLD%^You feel your second wind ebbing and the your body begins to slow again.");
        caster->set_property("fast healing", -power);
        caster->remove_property_value("active_feats", ({ TO }));
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
