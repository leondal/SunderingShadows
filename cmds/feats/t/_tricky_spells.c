#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("ArcaneTrickster");
    feat_name("tricky spells");
    feat_prereq("Arcane Trickster L1");
    feat_desc("An arcane trickster learns how to cast from shadows, using their guile to fool their targets. They now cast Alteration, Enchantment, and Illusion spells at full caster level. In addition, the Arcane Trickster gains 'spectral hand' as an innate spell.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("arcane_trickster") < 1)
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
