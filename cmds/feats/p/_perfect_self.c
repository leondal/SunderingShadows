#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("KiOffense");
    feat_name("perfect self");
    feat_prereq("Monk L20");
    feat_desc("Any time that you enter combat, if you do not have  Ki available to you, you will regenerate 4 Ki instantly.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob) 
{
   if(!objectp(ob)) { return 0; }
   if((int)ob->query_class_level("monk") < 20 || (int)ob->query_alignment() > 3) 
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

