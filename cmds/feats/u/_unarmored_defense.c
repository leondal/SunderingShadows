#include <std.h>
#include <daemons.h>
inherit FEAT;

void create()
{
   ::create();
   feat_type("permanent");
   feat_category("Rampage");
   feat_name("unarmored defense");
   feat_prereq("Barbarian or Monk");
   feat_desc("This feat offers the barbarian the equivalent armor class of hide armor whilst unarmored, however, use of a shield is allowed. The protection offered increases as the barbarian gains levels.");
   permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
   if(!objectp(ob)) { return 0; }
   if(!ob->is_class("barbarian") && !ob->is_class("monk")) {
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

