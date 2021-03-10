#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <dieties.h>
inherit FEAT;

#define FEATTIMER 35

void create() {
    ::create();
    feat_type("instant");
    feat_category("Presence");
    feat_syntax("smite");
    feat_prereq("Paladin L2");
    feat_classes("paladin");
    feat_desc("Drawing on the divine energy that infuses every holy knight, the paladin can smite the evil or good that lies in the hearts of men, beasts, and monsters alike. A successful attempt will strike any creature audacious enough to attack the paladin, causing vicious damage.");
    feat_name("smite");
}

int allow_shifted() { return 0; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(ob->query_class_level("paladin") < 2) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_smite(string str) {
    object feat;
    if(!objectp(TP)) return 0;
    feat = new(base_name(TO));
    feat->setup_feat(TP,"");
    return 1;
}

void execute_feat() {
    mapping tempmap;
    int delay;
    string mygawd, *mygawds;
    ::execute_feat();
    if((int)caster->query_property("using smite") > time()) {
        tell_object(caster,"You are not prepared to channel such powerful energies again so soon!");
        dest_effect();
        return;
    }
    if((int)caster->query_property("using instant feat")) {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    mygawd = (string)caster->query_diety();
    mygawds = keys(DIETIES);
    if(member_array(mygawd,mygawds) == -1) {
        tell_object(caster,"You have no deity to call upon!");
        dest_effect();
        return;
    }
    if(!sizeof(caster->query_attackers())) {
        tell_object(caster,"You're not under attack!");
        dest_effect();
        return;
    }
    delay = time() + FEATTIMER;
    delay_messid_msg(FEATTIMER,"%^BOLD%^%^WHITE%^You can %^CYAN%^smite%^WHITE%^ again.%^RESET%^");
    caster->set_property("using instant feat",1);
    caster->remove_property("using smite");
    caster->set_property("using smite",delay);
    return;
}

void execute_attack() {
    int chamod, i, dmg;
    object *targets;

    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();

    if(caster->query_unconscious()) {
        dest_effect();
        return;
    }
    chamod = ((int)caster->query_stats("charisma") - 10)/2;

    targets = caster->query_attackers();
    if(!sizeof(targets)) {
        tell_object(caster,"You are not under attack, and the divine energies dissipate harmlessly!");
        dest_effect();
        return;
    }
    caster->set_property("magic",1);
    targets += ({ caster });
    tell_object(caster,"%^BOLD%^%^CYAN%^With a shout to the heavens you unleash the divine might of your patron!");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" lets out a shout to the heavens and unleashes a wave of divine "
"energy!",targets);
    targets -= ({ caster });

    targets = shuffle(targets);

    for(i=0;i<sizeof(targets) && i < 8;i++) {
        if(targets[i] == caster) continue;
        if(!objectp(targets[i])) continue;
   	  tell_object(targets[i],"%^BOLD%^%^WHITE%^The energy washes over you, burning like fire!%^RESET%^");
        dmg = roll_dice(flevel + chamod,8);
        caster->cause_typed_damage(targets[i],"head",dmg,"divine");
        caster->add_attacker(targets[i]);
        targets[i]->add_attacker(caster);
    }
    caster->set_property("magic",-1);
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
