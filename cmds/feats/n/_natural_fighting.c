#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("PrimevalChampion");
    feat_name("natural fighting");
    feat_prereq("Primeval champion L4");
    feat_desc("The natural fighting feat allows the druid to take additional melee attacks per round based on the shape he is shifted into.

Wolf - 2 attacks, 
Bear - 1 attacks, 
Cat - 3 attacks, 
Dragon - 2 attacks.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("primeval_champion") < 4 )
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

