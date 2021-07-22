#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("TwoWeapons");
    feat_name("ambidexterity");
    feat_prereq("Dexterity 13");
    feat_desc("Ambidexterity allows a character to wield two weapons which are normal size to that character. A human could wield two medium sized weapons, a giant could wield two large sized weapons.");
    permanent(1);
    set_replaces_feat("weapon finesse");
    set_required_for(({"two weapon fighting","improved two weapon fighting","unassailable parry","whirl"}));
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_base_stats("dexterity") < 13)
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
