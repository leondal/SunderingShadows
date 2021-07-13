#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("GrandmasterOfTheWay");
    feat_name("grandmaster of the way");
    feat_prereq("Grandmaster of The Way L7, Way of The Merciful Soul");
    feat_desc("With this feat, the monk is able to master and gain powers of all monk ways.

%^BOLD%^See also: grandmaster of the way *classes%^RESET%^");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("grandmaster_of_the_way") < 7 || !FEATS_D->usable_feat(ob,"way of the merciful soul"))
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
