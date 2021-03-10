#include <std.h>
#include <daemons.h>
inherit FEAT;

void timer(object tp);

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Performance");
    feat_name("inspire greatness");
    feat_prereq("Bard L9");
    feat_desc("With this feat you gain access to songs of greatness. They grant maximum hit points bonus of 3 / 2 of your bard levels, and bonus every eight levels to attack, spell penetration and fortitude.");
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
    if (ob->query_class_level("bard") < 9) {
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
