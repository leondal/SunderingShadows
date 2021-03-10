#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Archdruid");
    feat_name("natures gift");
    feat_prereq("Archdruid L4");
    feat_desc("The archdruid has learned to cast certain spells so well that she is able to cast them an unlimited amount of times per day without needing to prepare the spells. The following spells can be cast without preparation: faerie fire, entangle, animal messenger, meld into nature, flame strike, wall of thorns, wall of stone, vortex, euphoric tranquility and regenerate.");
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("archdruid") < 4 )
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
