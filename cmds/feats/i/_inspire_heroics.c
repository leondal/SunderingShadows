#include <std.h>
#include <daemons.h>
inherit FEAT;

void timer(object tp);

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Performance");
    feat_name("inspire heroics");
    feat_prereq("Bard L15");
    feat_desc("With this feat you gain access to songs of heroics. They grant a bonus every four levels, but no more than eight, to all saves and armor class.");
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
    if (ob->query_class_level("bard") < 15) {
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
