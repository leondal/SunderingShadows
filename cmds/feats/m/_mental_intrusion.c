/*
  _mental_intrusion.c
  
  Telepath feat.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("active");
    feat_category("Psionics");
    feat_name("mental intrusion");
    feat_prereq("Psion (Telepath) L2");
    feat_syntax("mental_intrusion");
    feat_desc("This feat showcases the telepath's elevated ability to reach into the minds of others. By spending their psionic focus, the telepath increases the spell save DC of their next mind-affecting spell by +5.");
    psionic(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob))
        return 0;
    
    if(ob->query_class_level("psion") < 2)
    {
        dest_effect();
        return 0;
    }
    
    if(ob->query_discipline() != "telepath")
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_mental_intrusion(string str)
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
        tell_object(caster, "You need to be focused to use mental intrusion.");
        return;
    }
    
   if ((int)caster->query_property("using instant feat"))
   {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    
    if(caster->query_property("mental intrusion"))
    {
        tell_object(caster, "You are already using mental intrusion.");
        dest_effect();
        return;
    }
    
    tell_object(caster, "%^CYAN%^BOLD%^You place your finger upon your temple and focus your mental powers to be more potent!%^RESET%^");
    tell_room(place, caster->QCN + " places a finger upon their temple and concentrates deeply!", ({ caster }));
    caster->set_property("mental intrusion", 1);
    dest_effect();
}

void dest_effect()
{   
    ::dest_effect();
    remove_feat(TO);
    return;
}

