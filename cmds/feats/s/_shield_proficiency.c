#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
   ::create();
   feat_type("permanent");
   feat_category("WeaponAndShield");
   feat_name("shield proficiency");
   feat_desc("Shield Proficiency is a passive feat that allows the use of various types of shields.");
   permanent(1);
}

int prerequisites(object ob)
{
   if(!objectp(ob)) {return 0; }
    return ::prerequisites(ob);
}

int allow_shifted() { return 0; }

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
