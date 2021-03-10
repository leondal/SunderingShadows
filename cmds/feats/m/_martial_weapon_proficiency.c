#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("GeneralCombat");
    feat_name("martial weapon proficiency");
    feat_prereq("Simple weapon proficiency");
    feat_desc("Martial Weapon Proficiency is a passive feat that allows the use of various types of weapons such as swords, hammers, polearms, and axes.");
    permanent(1);
    set_required_for(({"exotic weapon proficiency"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
   if(!objectp(ob)) {return 0; }

   if(!FEATS_D->has_feat(ob,"simple weapon proficiency"))
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
