#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Metamind");
    feat_name("mind wave");
    feat_prereq("Metamind L7");
    feat_desc("The metamind has focused his mental abilities into a keen weapon, allowing him to more effectively strike opponents with psionicweapon and greaterpsionicweapon. His powers are also slightly stronger.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("metamind") < 7)
    {
        dest_effect();
        return 0;
    }
    return 1;
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
