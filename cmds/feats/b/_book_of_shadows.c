#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("TomeBoundMaster");
    feat_name("book of shadows");
    feat_prereq("Tome Bound Master L1");
    feat_desc(""
"Warlocks who show greater dedication to their pact can deepen that pact "
"in pursuit of arcane and forbidden knowledge. The warlock is gifted a Book "
"of Shadows, which not only gives the warlock an understanding of the arcane "  
"but also promises further secrets, should they continue their devotion. "
"This feat grants the warlock the 'mending', 'unseen servant', 'rope trick', "
"'command', 'minor creation', and 'clairvoyance' spells as known invocations.");
    permanent(1);
    set_required_for(({ "mystic arcana" }));
}

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("tome_bound_master") < 1)
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