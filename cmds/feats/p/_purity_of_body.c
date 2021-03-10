#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("KiDefense");
    feat_name("purity of body");
    feat_prereq("Monk L10");
    feat_desc("Your mastery of Ki has safeguarded you against both poisons and diseases, granting immunity to both.");
    permanent(1);
    set_required_for(({}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
   if(!objectp(ob)) { return 0; }

   if((int)ob->query_class_level("monk") < 10 || (int)ob->query_alignment() > 3)
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
