#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("premanent");
    feat_category("SavageCombat");
    feat_name("savage instincts i");
    feat_prereq("Druid L5");
    feat_desc("A druid can master some of the instincts ofeach of its combat-based shapeshifts, allowing an extra ability whilefighting.");
    permanent(1);
    set_required_for(({"savage instincts ii","savage instincts iii","mastery of fang and claw"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
    if(!objectp(ob)) return 0;

    if((int)ob->query_class_level("druid") < 5) {
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

