#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    set_author("wedex");
    feat_type("instant");
    feat_category("MagusArcana");
    feat_name("arcana reflection");
    feat_prereq("Magus L15");
    feat_classes("magus");
    feat_syntax("arcana_reflection");
    feat_desc("When arcana reflection is active, 1 or more points from the arcane pool can be sacrificed to reflect a spell back at its caster.
The chance is half the magus level plus your intelligence modifier. If active, this feat takes precedence over and doesn't stack with other reflection sources.
A number of points equal to the spell level are required to reflect the spell. If not enough points are available, you might use your regular reflection chance.");
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_class_level("magus") < 15) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_arcana_reflection()
{
    object feat;
    if (!objectp(TP)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP, "");
    return 1;
}

string cm(string str)
{
    return CRAYON_D->color_string(str, "dark black");
}

void execute_feat()
{
    object obj;
    int duration;

    if (!objectp(caster))
    {
        dest_effect();
        return;
    }

    if (FEATS_D->is_active(caster, "arcana reflection"))
    {
        obj = query_active_feat("arcana reflection");
        obj->dest_effect();
        return;
    }
    ::execute_feat();

    tell_object(caster, cm("Your inner arcana swirls around you."));
    caster->set_property("active_feats", ({ TO }));
    caster->set_property("arcana reflection", 1);

    return;
}

void dest_effect()
{
    if (objectp(caster))
    {
        caster->remove_property_value("active_feats", ({ TO }));
        caster->remove_property("arcana reflection");
        tell_object(caster, cm("The arcana flows back at you."));
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}