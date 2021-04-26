#include <std.h>
inherit FEAT;

void timer(object tp);

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Rampage");
    feat_name("indomitable will");
    feat_prereq("Barbarian L16");
    feat_desc("This feat represents the supreme battle focus the barbarian gains while raging. The barbarian recieves an additional +2 to will saves will raging. This bonus stacks with the inherent will save bonus from rage.");
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if((int)ob->query_class_level("barbarian") < 16) {
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
