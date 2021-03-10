#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("NonCombat");
    feat_name("timeless body");
    feat_prereq("Monk L15, Druid L15");
    feat_desc("This feat allows ignoring the ill effects of old age and makes it so that you no longer need food or water to survive. Monks are able to achieve this feat through their mastery of Ki, should they choose to do so. Druids are able to achieve this feat through their very close connection to nature.");
    permanent(1);
    set_required_for(({}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob) 
{
   if(!objectp(ob)) { return 0; }
   if((int)ob->query_class_level("monk") < 15 && (int)ob->query_class_level("druid") < 15)
   {
       dest_effect();
       return 0;
   }
   if((int)ob->is_class("monk") && (int)ob->query_alignment() > 3)
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

