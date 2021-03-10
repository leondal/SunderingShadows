#include <std.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("GeneralCombat");
    feat_name("simple weapon proficiency");
    feat_desc("Simple Weapon Proficiency is a passive feat that allows the use of various types of weapons such as the dagger, mace, morning star, staff, spear, and club.");
    permanent(1);
    set_required_for(({"martial weapon proficiency","exotic weapon proficiency"}));
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

