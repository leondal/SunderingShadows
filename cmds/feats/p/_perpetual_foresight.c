/*
  _perpetual_foresight.c
  
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
    feat_name("perpetual foresight");
    feat_prereq("Psion (Seer) L21");
    feat_desc("A seer with enough power can see the multitudes of possibilities in reality. With this ability, the seer is able to prepare themselves for all dangers that the myriad of futures might impose. This feat grants the seer advantage (roll twice and take the highest roll) on all saving throws as long as he is focused.");
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

