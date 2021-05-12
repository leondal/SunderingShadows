/*
  _kinetic_aura.c
  
  Kineticist feat.
  
  -- Tlaloc --
*/

#include <std.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("Psionics");
    feat_name("kinetic aura");
    feat_prereq("Psion (Kineticist) L11");
    feat_desc("The kineticist surrounds themselves with a sphere of swirling objects, passively offering protection against attacks. This feat gives a small AC bonus to the kineticist, which grows with their powers.");
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
    
    if(ob->query_discipline() != "kineticist")
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

