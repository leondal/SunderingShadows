#include <std.h>
#include <daemons.h>
inherit FEAT;

void timer(object tp);

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Evasion");
    feat_name("scramble");
    feat_prereq("Mobility, Evasion");
    feat_desc("This feat allows the user to fight defensively during combat, dodging from blows that may be directed at the character. Its effectiveness is based upon the character's skill in athletics, and can only be used in light armor.");
    set_required_for(({"spring attack"}));
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob,"mobility") || !FEATS_D->has_feat(ob,"evasion")) {
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

