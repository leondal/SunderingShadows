#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

void create()
{
    ::create();
    set_author("wedex");
    feat_type("instant");
    feat_category("MagusArcana");
    feat_name("enruned great weapon");
    feat_classes("magus");
    feat_syntax("enruned_great_weapon");
    feat_desc("You may expend a point from the arcane pool to scribe a rune of power on a two handed weapon wielded. You can use a hand holding the weapon to cast magus spells and you can use spell combat. The rune lasts 10 minutes per level.");
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!ob->is_class("magus")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_enruned_great_weapon()
{
    object feat, * wielded;
    if (!objectp(TP)) { return 0; }
    wielded = (object*)TP->query_wielded();
    if (!(sizeof(wielded) == 2 && wielded[0] == wielded[1]))
    {
        tell_object(TP, "%^RESET%^%^BOLD%^You must be wielding a two handed weapon.%^RESET%^");
        return 1;
    }
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

    if (FEATS_D->is_active(caster, "enruned great weapon"))
    {
        obj = query_active_feat("enruned great weapon");
        obj->dest_effect();
        return;
    }
    ::execute_feat();

    tell_object(caster, cm("You scribe a rune in your weapon."));
    caster->set_property("active_feats", ({ TO }));
    caster->set_property("enruned great weapon", 1);

    if (FEATS_D->has_feat(caster, "greater enruned great weapon")) {
        duration = (int)caster->query_class_level("magus") * 600;
    }
    else {
        duration = (int)caster->query_class_level("magus") * 60;
    }

    call_out("dest_effect", duration);

    return;
}

void dest_effect()
{
    if (objectp(caster))
    {
        caster->remove_property_value("active_feats", ({ TO }));
        caster->remove_property("enruned great weapon");
        tell_object(caster, cm("The rune in your weapon vanishes."));
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}