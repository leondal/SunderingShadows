#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("RageProphet");
    feat_name("raging healer");
    feat_prereq("Rage Prophet L1");
    feat_desc("With this feat a raging prophet has a chance to preserve any channeling spell in the memory while raging.

Spells that are covered by this feat are all cure/cause wounds spell, heal, harm, and mass variants of all of the above.");
    permanent(1);
}

//blep blep mew mew

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("rage_prophet") < 1)
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
