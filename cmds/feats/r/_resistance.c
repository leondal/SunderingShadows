#include <std.h>

inherit FEAT;

int help();

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("MagicResistance");
    feat_name("resistance");
    feat_desc("Resistance is a passive feat that when taken will boost the character's saving throws by a small amount and add a small amount of spell damage resistance.

%^BOLD%^See also:%^RESET%^ resistance *spells");
    permanent(1);
    set_required_for(({"increased resistance","improved resistance","death ward","spell reflection"}));
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
