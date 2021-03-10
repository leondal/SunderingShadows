#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Evasion");
    feat_name("defensive roll");
    feat_prereq("Dextrity 15, Thief L21 or Monk L21");
    feat_desc("This passive feat grants the character the ability to roll with a blow that would otherwise cause them heavy amounts of damage. A successful attempt will halve the damage taken from the blow.");
    permanent(1);
    set_required_for(({}));
}

int allow_shifted() {return 1;}

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if((int)ob->query_base_stats("dexterity") < 15) {
      dest_effect();
      return 0;
    }
    if(ob->query_class_level("thief") < 21 && ob->query_class_level("monk") < 21) {
      dest_effect();
      return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat(){
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob){
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob){
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}

