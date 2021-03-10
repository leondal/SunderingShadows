#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("EldritchKnight");
    feat_name("eldritch conditioning");
    feat_prereq("Eldritch Knight L1");
    feat_desc("As eldrich knight embodies worlds of magic and martial combat, they learn to cast in armor with a weapon in their hand. The spells of their base class will be always at character level potency.");
    permanent(1);
    set_required_for(({"improved prescience","metabolic perfection"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("eldritch_knight") < 1)
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
