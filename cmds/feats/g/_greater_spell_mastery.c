#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;
int choosing;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Archmage");
    feat_name("greater spell mastery");
    feat_prereq("Archmage L4");
    feat_desc("With the greater spell mastery feat, casters are able to cast up to a level four spell of their school spontaneously.");
    permanent(1);
    set_required_for(({"arcane perfection"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }

    if ((int)ob->query_class_level("archmage") < 4) {
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
    if (choosing) {
        return;
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}

void remove()
{
    if (choosing) {
        return;
    }
    return ::remove();
}
