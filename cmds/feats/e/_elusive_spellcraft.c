#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("ShadowAdept");
    feat_name("elusive spellcraft");
    feat_prereq("Shadow Adept L4, Gift of The Shadows");
    feat_desc("Shadow adept gains insights into schools touched by shadoweave, and gains ability to cast enchantment, illusion and necromancy spells at greater potency, albeit far from powers that of an archmage for specific school.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("shadow_adept") < 4 || !FEATS_D->usable_feat(ob,"gift of the shadows"))
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
