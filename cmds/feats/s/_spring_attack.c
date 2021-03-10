#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Evasion");
    feat_name("spring attack");
    feat_prereq("Scramble");
    feat_desc("This passive feat gives a chance upon successfully scrambling from a blow, to spring forward past the opponent's defenses and launch an additional attack.

%^BOLD%^N.B.%^RESET%^ If a character has both the spring attack feat and the masters parry feat they will have a chance at performing an even greater defensive maneuver.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob,"scramble")) {
      dest_effect();
      return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat(){
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob){
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob){
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}

