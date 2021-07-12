#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("GrandmasterOfTheWay");
    feat_name("way of the merciful soul");
    feat_prereq("Grandmaster of The Way L4");
    feat_desc("With this feat, a grandmaster of the way is able to mercifully end the suffering of enemies below 25% health on a successful critical strike. If the enemy passes a saving throw or if they are immune to death effects, they will instead receive an amount of damage based on monk levels.");
    permanent(1);
    set_required_for(({"grandmaster of the way"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("grandmaster_of_the_way") < 4)
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
