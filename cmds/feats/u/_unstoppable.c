#include <std.h>
inherit FEAT;

void timer(object tp);

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Rampage");
    feat_name("unstoppable");
    feat_prereq("Barbarian L31");
    feat_desc("This feat makes the Barbarian an unstoppable force. He gets an additional +2 max health per level while raged. He also gains an additional +3 damage resistance, and his Damage Reduction feat now applies to all resistance types.");
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if((int)ob->query_class_level("barbarian") < 31) {
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
