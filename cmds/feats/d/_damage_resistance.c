#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("DamageResistance");
    feat_name("damage resistance");
    feat_prereq("Improved toughness, or Barbarian L7, or Warlock L7");
    feat_desc("Damage Resistance is a passive feat that when taken will increase the character's resistance to damage by a small amount.");
    permanent(1);
    set_required_for(({"improved damage resistance","regeneration"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if(!FEATS_D->has_feat(ob,"improved toughness") && ob->query_class_level("barbarian") < 7 && ob->query_class_level("warlock") < 7)
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

