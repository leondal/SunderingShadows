/*
  _guarded_thoughts.c
  
  Telepath feat.
  
  -- Tlaloc --
*/

#include <std.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("Psionics");
    feat_name("guarded thoughts");
    feat_prereq("Psion (Telepath) L21");
    feat_desc("Telepaths at the height of their powers are so adept at mental manipulation that they gain a near-immunity to the effects of mental spells and powers against them. As long as they are focused, the telepath with this feat gains +10 on saving throws against mind-affecting spells.");
    permanent(1);
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
    
    if(ob->query_discipline() != "telepath")
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}


void execute_feat()
{
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob)
{
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob)
{
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}

