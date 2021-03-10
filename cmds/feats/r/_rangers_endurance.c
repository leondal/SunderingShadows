#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("WildernessLore");
    feat_name("rangers endurance");
    feat_prereq("Ranger L3");
    feat_desc("A ranger is the master of survival, through a myriad of terrains,
and often finds themselves on a hunt for days and weeks at a time. This gives
them an enhanced level of endurance. This feat grants +10 to endurance skill
as a permanent effect.");
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

    if ((int)ob->query_class_level("ranger") < 3)
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
