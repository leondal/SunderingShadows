#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("GrandmasterOfTheWay");
    feat_name("way of the learned pupil");
    feat_prereq("Grandmaster Of The Way L1");
    feat_desc("With this feat, the grandmaster of the way is able to restore a small amount of ki each time he is damaged.");
    permanent(1);
    set_required_for(({"way of the merciful soul", "grandmaster of the way"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("grandmaster_of_the_way") < 1)
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
