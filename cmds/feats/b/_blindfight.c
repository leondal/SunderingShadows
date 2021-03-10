#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("GeneralCombat");
    feat_name("blindfight");
    feat_desc("This feat reflects increased aptitude in handling oneself when robbed of sight, both in combat accuracy and in avoiding obstacles while walking. It will allow to retain dexterity bonus to armor class when blinded and will allow to use targeted feats. It does not, however, allow the character to use spells or directly targetted abilities on an unseen foe.

%^BOLD%^See also:%^RESET%^ status effects");
    permanent(1);
    allow_blind(1);
}

int allow_shifted() { return 1; }

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
