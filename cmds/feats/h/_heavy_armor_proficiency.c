#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("ArmorMastery");
    feat_name("heavy armor proficiency");
    feat_prereq("Medium armor proficiency");
    feat_desc("Heavy Armor Proficiency is a passive feat that allows the use of various types of plate armor, including bronze, field, and full plate.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
   if(!objectp(ob)) {return 0; }

   if(!FEATS_D->has_feat(ob,"medium armor proficiency"))
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
