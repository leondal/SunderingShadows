#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Evasion");
    feat_name("mobility");
    feat_prereq("Dodge");
    feat_desc("This passive feat grants an AC dodge bonus against all melee foes, except while incapacitated.");
    permanent(1);
    set_required_for(({"scramble","spring attack"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob,"dodge")) {
      dest_effect();
      return 0;
    }
    return 1;
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

