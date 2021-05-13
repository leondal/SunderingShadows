/*
  _nomads_step.c
  
  Nomad feat.
  
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
    feat_name("nomads step");
    feat_prereq("Psion (Nomad) L11");
    feat_syntax("nomads_step [DIRECTION]");
    feat_desc("This feat showcases the kineticists control over energy. With this feat, the kineticist creates a barrier that prevents all damage from the chosen energy type for short time. During this time, any damage taken from the chosen energy type will recharge the kineticist's power points. This feat happens immediately, with no delay. The valid energy types are: Fire, Electricity, Cold, Force, and Sonic.");
    psionic(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob))
        return 0;
    
    if(ob->query_class_level("psion") < 11)
    {
        dest_effect();
        return 0;
    }
    
    if(ob->query_discipline() != "nomad")
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_nomads_step(string str)
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
    string *exits, dest_name;
    object dest;
    
    ::execute_feat();
    
    if(!caster)
        return;
    
   if ((int)caster->query_property("using instant feat"))
   {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    
    exits = place->query_exits();
    
    if(member_array(arg, exits) < 0)
    {
        tell_object(caster, "That exit doesn't exist here.");
        dest_effect();
        return;
    }
    
    if(place->query_property("no phase"))
    {
       tell_object(caster,"This place seems to be enchanted against such things!\n");
       dest_effect();
       return;
    }
    
    dest_name = place->query_exit(arg);
    dest = find_object_or_load(dest_name);
    
    if(dest->query_property("no phase"))
    {
       tell_object(caster,"This place seems to be protected from magical travel!\n");
       dest_effect();
       return;
    }
    
    if(!USER_D->spend_pool(caster, 1, "focus"))
    {
        tell_object(caster, "You need to be focused to use nomad's step.");
        return;
    }
    
    tell_object(caster, "%^BOLD%^You set your mind towards the " + arg + " exit and slip away!");
    if(!caster->query_invis())
    {
        tell_room(place, caster->QCN + " concentrates and suddenly disappears!");
        tell_room(dest, caster->QCN + " suddenly appears near you!");
    }
    
    caster->clear_followers();
    caster->move(dest);

    caster->set_property("using instant feat", 1);
}

void execute_attack()
{
    caster->remove_property("using instant feat");
    dest_effect();
}

void dest_effect()
{   
    ::dest_effect();
    remove_feat(TO);
    return;
}

