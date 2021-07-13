/*
  _seeing_the_connections.c
  
  Seer feat.
  
  -- Tlaloc --
*/

#include <std.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("Psionics");
    feat_name("seeing the connections");
    feat_prereq("Psion (Seer) L2");
    feat_desc("The seer is particularly adept with Clairsentience powers and their singular focus allows them an unprecedented ability to gain information near and far. This feat grants the Seer a +1 spell DC when using Clairsentience powers while focused.");
    permanent(1);
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
    
    if(ob->query_discipline() != "seer")
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

