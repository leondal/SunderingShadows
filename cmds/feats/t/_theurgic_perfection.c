#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Hierophant");
    feat_name("theurgic perfection");
    feat_prereq("Hierophant L7");
    feat_desc("As experienced theurgist, Hierophant gains ability to keep any cast spell in memory, with a chance based on her wisdom for clerics and druids, or charisma for oracle.");
    permanent(1);
}

int allow_shifted()
{
    return 1;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }

    if ((int)ob->query_class_level("hierophant") < 7) {
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
