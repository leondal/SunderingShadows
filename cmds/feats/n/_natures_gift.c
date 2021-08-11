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
    feat_desc("The archdruid is in-tune with the forces of nature, above and beyond the capabilities of other druids. The elemental forces of the world lend their aid to the archdruid. The archdruid uses wisdom instead of constitution to determine his bonus hit points. He also gain protection from the natural forces of the world, and has 25% resistance to fire, cold, acid, and electricity damage.");
    permanent(1);
}

int allow_shifted() { return 1; }

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
