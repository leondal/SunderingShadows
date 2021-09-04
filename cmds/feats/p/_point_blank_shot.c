#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("RangedCombat");
    feat_name("point blank shot");
    feat_desc("Point blank shot allows for projectile weaponsto be fired even in close-quarters combat. Taking this feat will allow archer to use bows in combat, using %^BOLD%^dexterity%^RESET%^ as their base stat for both damage and attack bonuses. This feat also gives a +1 hit bonus to ranged touch attacks.

%^BOLD%^See also:%^RESET%^ ranged weapons");
    permanent(1);
    set_required_for(({"manyshot","deadeye","precise shot","shot on the run"}));
}

int allow_shifted() { return 0; }

int prerequisites(object ob) {
    string myname;
    if(!objectp(ob)) return 0;
    myname = (string)ob->query_name();
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
