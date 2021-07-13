/*
  _worldly_traveler.c
  
  Nomad feat.
  
  -- Tlaloc --
*/

#include <std.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("Psionics");
    feat_name("worldly traveler");
    feat_prereq("Psion (Nomad) L21");
    feat_desc("Nomads are the masters of travel, and in that regard, they are unrivalled. This feat grants the nomad +2 to caster level when using teleportation powers. They also can remember 5 additional locations.");
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
    
    if(ob->query_discipline() != "nomad")
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

