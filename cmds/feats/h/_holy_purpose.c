#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("RisenMartyr");
    feat_name("holy purpose");
    feat_prereq("Risen Martyr L4");
    feat_desc("The Risen Martyr was returned to fulfill a holy purpose. To that end, their deity bestows " +
              "upon them additional power. With this feature, the Risen Martyr gains Bless, Protection from " +
              "Alignment, Daylight, Detect Evil, Shield Other, Holy Aura, and Celestial Brilliance as innate " +
              "spells.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("risen_martyr") < 4)
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