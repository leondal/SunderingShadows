#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("MagicResistance");
    feat_name("spellcasting harrier");
    feat_prereq("Fighter L31 + Spellbreaker Feat");
    feat_desc("You have advantage on saving throws (roll twice and take the highest result). This feat does not stack with the 'live to tell the tale' feat from the chronicler class.");
    permanent(1);
    allow_blind(1);
}

int allow_shifted()
{
    return 1;
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!FEATS_D->has_feat(ob,"spellbreaker"))
    {
        dest_effect();
        return 0;
    }
    if(ob->query_class_level("fighter") < 31)
    {
        dest_effect();
        return 0;
    }
    if(FEATS_D->has_feat(ob, "live to tell the tale"))
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
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
