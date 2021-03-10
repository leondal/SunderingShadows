#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("WildernessLore");
    feat_name("seen it before");
    feat_prereq("Ranger L21");
    feat_desc("\
A ranger taking this feat has reached the pinnacle in understanding in\
how to fight their favored enemy. At this point, nothing that this\
enemy does can even surprises the ranger. This feat adds the ranger's\
favored enemy bonus to all saving throws when fighting their favored enemy.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("ranger") < 21)
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