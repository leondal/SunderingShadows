#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("premanent");
    feat_category("SavageCombat");
    feat_name("mastery of fang and claw");
    feat_prereq("Savage Instincts II");
    feat_desc("A diverse command of combat in druidic shapeshifted forms,which allows the use of a specific feat in each. 

A wolf can trip foes with the %^ORANGE%^<knockdown>%^RESET%^ feat. 
A bear can attempt to %^ORANGE%^<sunder>%^RESET%^ a foe to make them easier to hit.
A cat can %^ORANGE%^<whirl>%^RESET%^ to unleash a flurry of attacks on several foes at once. 
A dragon can attempt to %^ORANGE%^<impale>%^RESET%^ a foe with its claws.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
    if(!objectp(ob)) return 0;

    if(!FEATS_D->has_feat(ob,"savage instincts ii")) {
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
