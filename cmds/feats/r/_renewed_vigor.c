/*
  _renewed_vigor.c
  
  Rage Power used to heal onesself.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;

#define FEATTIMER 80

void create()
{
    ::create();
    feat_type("instant");
    feat_category("RagePower");
    feat_name("renewed vigor");
    feat_syntax("renewed_vigor");
    feat_desc("While raging, the barbarian can tap into a well of vigor deep within themselves, healing for 1d8 (+1d8 per 4 barbarian levels) plus their constitution modifier.");
    feat_prereq("Barbarian");
}

int prerequisites(object ob)
{
    if(!objectp(ob))
        return 0;
    
    if(ob->query_class_level("barbarian") < 1 )
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_layonhands(string str)
{
    object feat;
    
    if(!objectp(this_player())) 
        return 0;
    
    if(!stringp(str))
        return 0;
    
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

int allow_shifted() { return 1; }

void execute_feat()
{
    int delay;
    
    if(caster->cooldown("renewed vigor"))
    {
        tell_object(caster,"You're not ready to use Renewed Vigor yet.");
        return;
    }
    
    if(!caster->query_property("raged"))
    {
        tell_object(caster, "You can only use Renewed Vigor while raged.");
        return;
    }
    
    ::execute_feat();
    
    if(!objectp(target))
        target = this_player();
    
    tell_object(caster, "%^GREEN%^You begin to channel divine energy.%^RESET%^");
    
    caster->add_cooldown("renewed vigor", FEATTIMER);
    caster->set_property("using instant feat", 1);
    return;
}

void execute_attack()
{
    int amount;
    string dedication;
    object *effects;
    
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
    
    if(caster->query_unconscious())
    {
        dest_effect();
        return;
    }

    tell_object(caster,"%^BOLD%^%^GREEN%^You tap into some deep well of vigor within you and you feel yoru wounds fade.%^RESET%^");
    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" reaches deep down and " + caster->QP + " wounds seem to fade.%^RESET%^",({caster}));
    
    amount = (1 + caster->query_prestige_level("barbarian") / 4) * roll_dice(1, 8);
    amount += BONUS_D->query_stat_bonus(caster, "constitution");
    caster->add_hp(amount);
    
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(this_object());
    return;
}  