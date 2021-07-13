#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("ArcaneSpellcraft");
    feat_name("use magic device");
    feat_prereq("Thief or Bard L13");
    feat_desc("With this feat, the thief or bard has learned to use magical scrolls and wands, regardless of class requirements. The level and power of scrolls and wands is still limited by total levels in the thief/bard class. The thief/bard can cast scrolls and use wands of a spell level up to half their thief/bard level. The total caster level of the scroll is limited to their thief/bard level plus intelligence/charisma modifier.");
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) {return 0; }
    if(ob->query_class_level("thief") < 13 &&
    ob->query_class_level("bard") < 13)
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
