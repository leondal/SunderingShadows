#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Cypher");
    feat_name("clone scroll");
    feat_prereq("Cypher L7");
    feat_desc("With this feat a cypher can copy any scoll in her inventory with scribe feat, even scrolls of other classes.");
    permanent(1);
    allow_blind(1);
}

int allow_shifted()
{
    return 1;
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_class_level("cypher") < 7) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
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
