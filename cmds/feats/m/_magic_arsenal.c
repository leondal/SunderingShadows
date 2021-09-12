#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("MagicDamage");
    feat_name("magic arsenal");
    feat_prereq("greater spell power");
    feat_desc("The Magic Arsenal feat will allow the character to cast 2 more spells per level of every level spell that they are currently able to cast. The spells do not get any stronger and it will not allow the character to cast spells of a higher level than they might otherwise be able to cast.\n\n Please note, this feat provides extra slots for memorization/casting; it will not grant classes such as sorcerer or warlock extra known spells.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }
    if(!FEATS_D->has_feat(ob,"greater spell power"))
    {
        dest_effect();
        return 0;
    }
    //Single-class warlocks or warlocks + prestige have no use for this feat.
    //Also true of psion/psywarrior
    if(ob->query_level() == ob->query_prestige_level("warlock") ||
       ob->query_level() == ob->query_prestige_level("psion") ||
       ob->query_level() == ob->query_prestige_level("psywarrior"))
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
