#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("PaleLord");
    feat_name("undead cohort");
    feat_prereq("Pale Lord L4");
    feat_desc("The second phase of transformation is infusion of negative energy. To achieve that Pale Lord drains all own blood and replaces it with delicately woven spells that substitute its function. The blood itself is sacrificed in the ritual to summon power needed to sustain such spells. This step of transformation gives the Pale Lord innate understanding of the undeath. They gain ability to cast vampiric touch, animate dead, exhume corpses, create undead, create greater undead spells as innate powers.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("pale_lord") < 4)
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
