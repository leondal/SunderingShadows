#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("VersatileArcanist");
    feat_name("greater spell knowledge");
    feat_prereq("Versatile Arcanist L1");
    feat_desc("A versatile arcanist can learn up to five spells in any of their normal spell slots, above the limit.");
    permanent(1);
    set_required_for(({"master of elements"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("versatile_arcanist") < 1)
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
