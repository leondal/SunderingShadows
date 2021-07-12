#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Shadowdancer");
    feat_name("one with the shadows");
    feat_prereq("Shadowdancer L1");
    feat_desc("A shadowdancer gains the use of several new spells as innate abilities:

shadow stride, darkvision, shadow double, greater shadow conjuration, shadow evocation, shadow necromancy, shadow body");
    permanent(1);
    set_required_for(({"shadow master",}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("shadowdancer") < 1)
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
