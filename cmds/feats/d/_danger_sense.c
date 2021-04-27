#include <std.h>
inherit FEAT;

void timer(object tp);

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Evasion");
    feat_name("danger sense");
    feat_prereq("Barbarian L5 or Thief L5");
    feat_desc("This feat gives the barbarian or thief an uncanny sense of danger around them. They gain a scaling bonus to reflex saves and perception skill (max 6). They also become harder for thieves to catch them unaware, reducing sneak attack dice by half against them (as long as the enemy is no more than 4 levels higher than them).");
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if((int)ob->query_class_level("barbarian") < 5 && ob->query_class_level("thief") < 5) {
      dest_effect();
      return 0;
    }
    return ::prerequisites(ob);
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
