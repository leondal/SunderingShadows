//based on Smite, for psywarriors ~Circe~ 9/22/15
//This is the greater version, doing more damage with a reverb the next round for half damage.

#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

object *targets;
void smack_em(object ob);

#define FEATTIMER 35

void create() {
    ::create();
    feat_type("instant");
    feat_category("Psionics");
    feat_name("greaterpsionicweapon");
    feat_syntax("greaterpsionicweapon");
    feat_prereq("Psionicweapon, Psywarrior L15, or Psion L15");
    feat_desc("This feat improves on psionic weapon, making it more deadly.");
    psionic(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(ob->query_class_level("psywarrior") < 15 && ob->query_class_level("psion") < 15){
        dest_effect();
        return 0;
    }
    if(!FEATS_D->has_feat(ob,"psionicweapon")){
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_greaterpsionicweapon(string str) {
    object feat;
    if(!objectp(TP)) return 0;
    feat = new(base_name(TO));
    feat->setup_feat(TP,"");
    return 1;
}

void execute_feat() {
    mapping tempmap;
    int delay;
    ::execute_feat();
    if((int)caster->query_property("using smite") > time()) { //keeping the same variable to avoid stacking
        tell_object(caster,"You are not prepared to exert such mental force again so soon!");
        dest_effect();
        return;
    }
    if((int)caster->query_property("using instant feat")) {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if(!sizeof(caster->query_attackers())) {
        tell_object(caster,"You're not under attack!");
        dest_effect();
        return;
    }

    tell_object(caster,"%^RESET%^%^BOLD%^You focus your mind, preparing to unleash a psionic attack.");

    delay = time() + FEATTIMER;
    delay_messid_msg(FEATTIMER,"%^BOLD%^%^WHITE%^You can %^CYAN%^greaterpsionicweapon%^WHITE%^ again.%^RESET%^");
    caster->set_property("using instant feat",1);
    caster->remove_property("using smite");
    caster->set_property("using smite",delay);
    return;
}

void execute_attack()
{
    int die, i, dmg, myint, yourint, extra;
    object* targets;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    caster->remove_property("using instant feat");
    ::execute_attack();

    if (caster->query_unconscious()) {
        dest_effect();
        return;
    }

    die = 6;

    if (FEATS_D->usable_feat(caster, "mind wave")) {
        die = 8;
    }

    targets = caster->query_attackers();

    if (!sizeof(targets)) {
        tell_object(caster, "You are not under attack, and your mental force dissipates harmlessly!");
        dest_effect();
        return;
    }

    caster->set_property("magic", 1);
    targets += ({ caster });
    tell_object(caster, "%^RESET%^%^CYAN%^The power within you grows to a fever pitch, and you release a psionic tempest that slices through your enemies!");
    tell_room(place, "%^RESET%^%^CYAN%^A low hum resonates throughout the area before " + caster->QCN + " unleashes a psionic tempest that slices through " + caster->QP + " enemies!", targets);
    targets -= ({ caster });

    targets = shuffle(targets);

    for (i = 0; i < sizeof(targets) && i < 8; i++) {

        if (targets[i] == caster) {
            continue;
        }

        if (!objectp(targets[i])) {
            continue;
        }
        tell_object(targets[i], "%^BOLD%^%^CYAN%^" + caster->QCN + " releashes a psionic tempest that slices through your mind like countless blades!%^RESET%^");
        dmg = roll_dice(clevel, die);

        caster->cause_damage_to(targets[i], "head", dmg);
        caster->add_attacker(targets[i]);
        targets[i]->add_attacker(caster);
    }

    caster->add_mp(-roll_dice(1, 6));
    caster->set_property("magic", -1);
    dest_effect();
    return;
}


void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
