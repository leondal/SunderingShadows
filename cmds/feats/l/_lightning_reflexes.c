#include <std.h>

inherit FEAT;

int help();

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("MagicResistance");
    feat_name("lightning reflexes");
    feat_desc("Lightning Reflexes is a passive feat that when taken will boost the character's reflex saving throw by a small amount.");
    permanent(1);
    set_required_for(({"increased resistance","improved resistance"}));
    set_obsolete(1);
}

int allow_shifted() { return 1; }

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

