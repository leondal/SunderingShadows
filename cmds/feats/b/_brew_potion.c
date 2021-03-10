#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("ArcaneSpellcraft");
    feat_name("brew potion");
    feat_desc("This feat allows a character of competent healing ability to use their knowledge
in the crafting of various oils, potions, poisons and other alchemical brews.

%^BOLD%^See also:%^RESET%^ help brew.");
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
