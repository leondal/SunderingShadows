#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("BeastMastery");
    feat_name("pack leader");
    feat_prereq("Beast Master L4");
    feat_desc("The Beast Master has become a pack leader, able to call on their pack to aid them. " +
              "With this feat, the Beast Master's animal companion feat summons two additional copies " +
              "of their animal companion, provided the animal companion is their chosen animal type.");
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

    if ((int)ob->query_class_level("beast_master") < 4)
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
