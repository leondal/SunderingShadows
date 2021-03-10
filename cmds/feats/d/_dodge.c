#include <std.h>
inherit FEAT;

void timer(object tp);

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Evasion");
    feat_name("dodge");
    feat_prereq("Dexterity 13");
    feat_desc("This feat allows the character to retain their dexterity bonus to ac even being incapacitated.");
    set_required_for(({"mobility","evasion","scramble","spring attack"}));
    set_target_required(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if((int)ob->query_base_stats("dexterity") < 13) {
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
