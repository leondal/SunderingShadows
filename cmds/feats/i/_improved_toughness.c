#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("DamageResistance");
    feat_name("improved toughness");
    feat_prereq("Toughness");
    feat_desc("Improved Toughness is a passive feat that when taken will further increase the character's health by a certain amount per level beyond that of toughness. Like toughness, this feat will also apply to levels gained before the feat was taken.");
    permanent(1);
    set_required_for(({"damage resistance","regeneration"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if(!FEATS_D->has_feat(ob,"toughness"))
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

