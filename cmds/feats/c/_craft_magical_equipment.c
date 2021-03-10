#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("ArcaneSpellcraft");
    feat_name("craft magical equipment");
    feat_syntax("craft enchant");
    feat_desc("This feat allows a character to go beyond the normal range of crafting skill, with the ability to make magically imbued arms and armor with any craft skill they are adept in. Craft magical equipment's effectiveness is based on the user's various crafting skills. Swords require craft, weaponsmith clothing requires craft, tailor, etc.

%^BOLD%^See also:%^RESET%^ craft, disenchant");
    permanent(1);
}

int allow_shifted() { return 0; }

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
