#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("RisenMartyr");
    feat_name("spiritual body");
    feat_prereq("Risen Martyr L1");
    feat_desc("The hero rises from the ashes, rebuilt with new purpose, a holy vessel made flesh. " +
"The Risen Martyr possesses an aura of influence wherever she goes and the very nature " +
"of her newfound glory protects her in battle. This feat grants the Risen Martyr a +2 " +
"bonus to Charisma and adds her Charisma Bonus to Armor Class.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("risen_martyr") < 1)
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