#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Archmage");
    feat_name("arcane perfection");
    feat_prereq("Archmage L7");
    feat_desc("With the arcane perfection feat, an archmage has achieved near perfection over his ability to use his arcane skills to manipulate the weave. As such, when an archmage with this feat casts a spell, she will have a chance based on her intelligence to retain the spell in memory.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("archmage") < 7)
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
