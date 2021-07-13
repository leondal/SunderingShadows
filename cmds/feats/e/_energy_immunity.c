/*
  _energy_immunity.c
  
  Kineticist feat.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;

string *valid_types = ({ "fire", "cold", "electricity", "force", "sonic" });
string energy_type;

void create() 
{
    ::create();
    feat_type("active");
    feat_category("Psionics");
    feat_name("energy immunity");
    feat_prereq("Psion (Kineticist) L21");
    feat_syntax("energy_immunity [ENERGY TYPE]");
    feat_desc("This feat showcases the kineticists control over energy. With this feat, the kineticist creates a barrier that prevents all damage from the chosen energy type for short time. During this time, any damage taken from the chosen energy type will recharge the kineticist's power points. This feat happens immediately, with no delay. The valid energy types are: Fire, Electricity, Cold, Force, and Sonic.");
    psionic(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob))
        return 0;
    
    if(ob->query_class_level("psion") < 21)
    {
        dest_effect();
        return 0;
    }
    
    if(ob->query_discipline() != "kineticist")
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_energy_immunity(string str)
{
    object feat;
    
    if(!this_player())
        return 0;
    
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    return 1;
}

void execute_feat()
{
    ::execute_feat();
    
    if(!caster)
        return;
    
    if(!USER_D->spend_pool(caster, 1, "focus"))
    {
        tell_object(caster, "You need to be focused to use energy immunity.");
        return;
    }
    
   if ((int)caster->query_property("using instant feat"))
   {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    
    energy_type = (string)arg;
    
    if(!strlen(energy_type) || member_array(energy_type, valid_types) < 0)
    {
        tell_object(caster, "Valid types are : [" + implode(valid_types, ", ") + "]");
        return;
    }
    
    tell_object(caster, "%^CYAN%^BOLD%^You place your finger upon your temple and form a kinetic barrier against " + arg +"!%^RESET%^");
    tell_room(place, caster->QCN + " places a finger upon their temple and forms a kinetic barrier!", ({ caster }));
    caster->set_property("energetic recharge", energy_type);
    caster->set_resistance_percent(energy_type, 100);
    caster->set_property("using instant feat", 1);
    call_out("dest_effect", 30);
}

void execute_attack()
{
    caster->remove_property("using instant feat");
}

void dest_effect()
{
    if(caster)
    {
        caster->set_resistance_percent(energy_type, -100);
        caster->remove_property("energetic recharge");
        tell_object(caster, "%^BOLD%^You feel your energy immunity slipping away.%^RESET%^");
    }
    
    ::dest_effect();
    remove_feat(TO);
    return;
}

