#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("PaleLord");
    feat_name("undead graft");
    feat_prereq("Pale Lord L1");
    feat_desc("This is a first step of transformation into the pale lord. A mortal wishing to become one starts so with cutting out most of own internal organs, mummifying them, infusing with powerful spells and placing them back into own body. Such organs despite being virtually dead still serve their function through entwined spells. This step of transformation gives the pale lord unprecedented resilience to damage. Negative energy no longer harms them. They gain damage reduction to physical attacks, and they ignore half of the stabs of a thief of the same power, gain poison and disease immunity. They also become fully immune to assassin crits.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("pale_lord") < 1)
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
