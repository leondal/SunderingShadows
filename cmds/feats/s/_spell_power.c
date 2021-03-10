#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("MagicDamage");
    feat_name("spell power");
    feat_desc("The Spell Power feat will allow the caster to cast spells as if they were more advanced in their spell casting class than they actually are. Warlocks do not need to take any of the pre-requisite feats to gain this feat.");
    permanent(1);
    set_required_for(({"improved spell power","greater spell power","hardenedminions","magic arsenal"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

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
