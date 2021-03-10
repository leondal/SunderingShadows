#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("TomeBoundMaster");
    feat_name("mystic arcana");
    feat_prereq("Tome Bound Master L4");
    feat_desc(""
"The warlock taking this feat continues to show greater dedication to their "
"pact and are reaping greater benefits from that pact. The patron shows the warlock "
"how to bend their force of ambition and influence into strengthening their spells. "
"A warlock with this feat applies the 'agonizing blast' trait to their eldritch "
"blast, eldritch chain, and eldritch burst invocations, which adds damage based on "
"the warlock's charisma. The patron also shows the warlock how to strengthen the "
"resilience of their invocations, and the warlock gains a additional resistance to "
"dispell effects.");
    permanent(1);
    set_required_for(({ "tome of ancient secrets" }));
}

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("tome_bound_master") < 4)
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