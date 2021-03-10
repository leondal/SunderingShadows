#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("KiDefense");
    feat_name("diamond soul");
    feat_prereq("Monk L14");
    feat_desc("Your mastery of Ki allows you to automatically reroll all failed saving throws, for the cost of 1 Ki, if you have enough available and are unarmored and unarmed or wielding only small weapons.");
    permanent(1);
    set_required_for(({}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
   if(!objectp(ob)) { return 0; }

   if((int)ob->query_class_level("monk") < 14)
   {
      dest_effect();
      return 0;
   }
   if((int)ob->is_ok_armour("barbarian"))
   return ::prerequisites(ob);
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob) {
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob) {
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}
