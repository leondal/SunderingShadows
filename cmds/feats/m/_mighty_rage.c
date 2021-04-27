#include <std.h>
#include <daemons.h>
inherit FEAT;

void create()
{
   ::create();
   feat_type("permanent");
   feat_category("Rampage");
   feat_name("mighty rage");
   feat_prereq("Barbarian L20");
   feat_desc("This feat allows the barbarian to enter a fit of furious rage, boosting their attack, damage, max health, will saves, and fortitude saves even more than rage and greater rage, as well as allowing them to regenerate health during the rage. The ability will last longer, and grow stronger, as the barbarian gains levels.");
   permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
   if(!objectp(ob)) { return 0; }
   if(ob->query_class_level("barbarian") < 20)
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
