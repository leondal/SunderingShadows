//For psionic characters - increases hit points based on the number of psionic feats they've taken
//any feats added to the array below will increase hit points

#include <std.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("Psionics");
    feat_name("psionic body");
    feat_prereq("Psywarrior L17 or Psion");
    feat_desc("Psionic Body is a passive feat that will increase the psionic character's hit points based on the number of psionic feats that character has taken, including Psionic Body.");
    permanent(1);
    psionic(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }
    if(ob->query_class_level("psywarrior") < 17 && !ob->is_class("psion")){ // Psywarriors get it for free at 17; psions can take whenever
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

