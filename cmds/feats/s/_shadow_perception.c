#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("KiEnhancement");
    feat_name("shadow perception");
    feat_prereq("Monk L10, Way of The Shadow or Grandmaster of The Way");
    feat_desc("A monk who is dedicated to the way of the shadows  has a way of perceiving and hiding in shadows that most can never hope to  achieve. This feat represents this ability, granting a +5 to both stealth  and perception.\n NOTE: This feat only functions while unarmored.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }

    if ((int)ob->query_class_level("monk") < 10) {
        dest_effect();
        return 0;
    }
    if (((string)ob->query("monk way") != "way of the shadow") && !FEATS_D->usable_feat(ob, "grandmaster of the way")) {
        dest_effect();
        return 0;
    }
    if (!ob->is_ok_armour("barb")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat()
{
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

int help() {
    write("%^RESET%^%^BOLD%^Name:           Shadow Perception\n"
          "%^RESET%^%^BOLD%^Type:           %^GREEN%^Permanent\n"
          "%^RESET%^%^BOLD%^Syntax:         %^RESET%^None\n"
          "%^RESET%^%^BOLD%^Prerequisites:  %^RESET%^L10 Monk\n"
          "%^RESET%^%^BOLD%^                %^RESET%^Way of The Shadow\n\n"
        "%^RESET%^%^BOLD%^\tA monk who is dedicated to the way of the shadows "
        "has a way of perceiving and hiding in shadows that most can never hope to "
        "achieve. This feat represents this ability, granting a +2 to both stealth "
        "and perception.\n"
        "NOTE: This feat only functions while unarmored.");
    return 1;
}
