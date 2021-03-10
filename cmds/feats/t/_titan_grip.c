//Updated wording to clarify no large sized one handed wielding - Yves 6/29/19

#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("TwoHandedWeapons");
    feat_name("titan grip");
    feat_prereq("Strength 19");
    feat_desc("This reflects your outstanding strength, and permits you to wield very large two-handed weapons that otherwise would be too large for you. With this feat, small character can wield two-handed large weapons and medium-sized character can wield giant two handed weapons.

%^BOLD%^N.B.:%^RESET%^ This feat won't allow you to wield weapons in one hand that you would normally wield two-handed.");
    permanent(1);
    allow_blind(1);
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_base_stats("strength") < 19) {
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
