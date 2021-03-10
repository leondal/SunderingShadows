#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("VampireLord");
    feat_name("sanguine bloodline");
    feat_prereq("Vampire Lord L7");
    feat_desc("Through forming greater bloodline, you gain ability to control ancient blood magic in a limited fashion and gain unique spells. This feat adds some hemomancy abilities to innate spell list: blood cauldron, blood pyre, blood raze, night auspex, mytherceria, harvest of tyrannos.");
    permanent(1);
}

int allow_shifted()
{
    return 1;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }

    if ((int)ob->query_class_level("vampire_lord") < 4) {
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
