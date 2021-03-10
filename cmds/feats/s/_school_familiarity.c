#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Archmage");
    feat_name("school familiarity");
    feat_prereq("Archmage L1");
    feat_desc("Archmage becomes unrivaled in their knowledge of the school. With the school familiarity feat, an archmage can extend the power of their school spells even further, significantly increasing their potency at the expense of their opposing school.

Sorcerers advancing to archmage must choose a school with <advance class special> for this feat to work.");
    permanent(1);
    set_required_for(({"greater spell mastery","arcane perfection"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("archmage") < 1)
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
