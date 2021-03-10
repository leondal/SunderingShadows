#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("ArmorMastery");
    feat_name("armor mastery");
    feat_prereq("Fighter L19");
    feat_desc("You learn to absorb some damage with your armor even if you got hit. Any damage taken will have a point subtracted for every six fighter levels. You must be wearing some form of armor for this feat to work.");
    permanent(1);
}

int allow_shifted()
{
    return 0;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_class_level("fighter") < 19) {
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
