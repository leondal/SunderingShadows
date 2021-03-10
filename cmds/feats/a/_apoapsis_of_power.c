#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("MagicDamage");
    feat_name("apoapsis of power");
    feat_prereq("Greater spell penetration, Greater spell power,
               Mage, Sorcerer or Psion");
    feat_desc("Casters learn ability to shift their damage table two levels up. Only mage, sorcerer, and psion spells will be affected.");
    permanent(1);
}

int allow_shifted()
{
    return 1;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }

    if (!(FEATS_D->has_feat(ob, "greater spell penetration") && FEATS_D->has_feat(ob, "greater spell power"))) {
        dest_effect();
        return 0;
    }

    if (!(ob->is_class("mage") ||
          ob->is_class("sorcerer") ||
          ob->is_class("psion"))) {
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
