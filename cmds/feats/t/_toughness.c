#include <std.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("DamageResistance");
    feat_name("toughness");
    feat_desc("Toughness is a passive feat that when taken will increase the character's health by a small amount per level. This feat will apply even for the levels before it was taken.");
    permanent(1);
    set_required_for(({"improved toughness","damage resistance","improved damage resistance","regeneration"}));
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

