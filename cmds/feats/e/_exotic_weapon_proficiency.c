#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("GeneralCombat");
    feat_name("exotic weapon proficiency");
    feat_desc("Exotic Weapon Proficiency is a passive feat that allows the use of various types of weapons such as double-bladed swords, whip, giant-sized weapons, and other unique weapons.");
    feat_prereq("Martial weapon proficiency");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
   if(!objectp(ob)) {return 0; }

   if(!FEATS_D->has_feat(ob,"martial weapon proficiency")&&!ob->is_class("inquisitor"))
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
