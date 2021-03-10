#include <std.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("ArmorMastery");
    feat_name("light armor proficiency");
    feat_desc("Light Armor Proficiency is a passive feat that allows the use of padded, leather, and studded leather, and hide armor.");
    permanent(1);
    set_required_for(({"medium armor proficiency","shield proficiency","heavy armor proficiency"}));
}

int allow_shifted() { return 1; }

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
