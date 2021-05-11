// 10 MR vs relevant element
#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("DamageResistance");
    feat_name("energy resistance");
    feat_prereq("Warlock L9");
    feat_desc("This feat represents the warlock's attunement to their pact or lineage,
manifesting as a minor resistance to certain types of energy. As follows by %^BOLD%^heritage:%^RESET%^
  -%^BOLD%^celestial:%^RESET%^ acid
  -%^BOLD%^fey:%^RESET%^ sonic
  -%^BOLD%^demonic:%^RESET%^ electricity
  -%^BOLD%^astral:%^RESET%^ psychic
  -%^BOLD%^gloom:%^RESET%^ cold
  -%^BOLD%^infernal:%^RESET%^ fire");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
    if(!objectp(ob)) return 0;

    if(ob->query_class_level("warlock") < 9) {
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