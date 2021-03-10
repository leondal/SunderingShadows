#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("WildernessLore");
    feat_name("hunters bond");
    feat_prereq("Ranger L7");
    feat_desc("\
The ranger and their animal companion have begun to work together\
seemlessly as a team, and now have a keen understanding on how to\
stalk their prey together. When the ranger and companion reach this\
level of bonding, they also share their knowlefge of the ranger's\
favored enemy. This feat now grants the companion all of the same\
favored enemy bonuses that the ranger has.");
    permanent(1);
    set_required_for(({}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("ranger") < 7)
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
