/*
  _psychic_vampire.c
  
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
    feat_name("psychic vampire");
    feat_prereq("Psion (Telepath) L11");
    feat_desc("Once a telepath has gained a certain amount of power, they begin to almost automatically make connections with minds around them. With this feat, the telepath will slowly harvest power points from other intelligent minds around them. While focused the telepath slowly gains power point regen, increasing the more minds there are in the area.");
    permanent(1);
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

