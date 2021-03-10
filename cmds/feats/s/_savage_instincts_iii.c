#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("premanent");
    feat_category("SavageCombat");
    feat_name("savage instincts iii");
    feat_prereq("Savage instincts II, Druid L25");
    feat_desc("A druid can master the greatest of the instincts ofeach of its combat-based shapeshifts, allowing an extra ability whilefighting.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
    if(!objectp(ob)) return 0;

    if(!FEATS_D->has_feat(ob,"savage instincts ii")) {
      dest_effect();
      return 0;
    }
    if((int)ob->query_class_level("druid") < 25) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat() {
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

