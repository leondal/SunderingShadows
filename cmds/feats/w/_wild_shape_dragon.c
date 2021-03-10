// transitioned to the first of the HM 'epic' feats at L31. N, 4/15.
#include <std.h>
#include <daemons.h>
inherit FEAT;

int help();

void create() {
    ::create();
    feat_type("premanent");
    feat_category("PrimevalChampion");
    feat_name("wild shape dragon");
    feat_prereq("Primeval Champion L1");
    feat_syntax("shapeshift dragon");
    feat_desc("Having this feat will allow the character access to the shapeshift feat. The shapeshift feat is used to change into animal form. <shapeshift dragon> will transform the user into a young dragon. Despite the young age of the dragon that the character can change into, it is still a powerful predator. The iron-hard scales that cover the character's skin will increase his or her resistance to damage and the dragon's powerful muscles will make the character much stronger. In addition, dragon form can use <wing> command.");
    permanent(1);
    allow_blind(1);
}

int allow_shifted() { return 1; }

void execute_feat() {
    ::execute_feat();
    dest_effect();
}

int prerequisites(object ob) {
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("primeval_champion") < 1) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
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
