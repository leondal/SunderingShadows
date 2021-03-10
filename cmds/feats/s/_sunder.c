#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

int mod, fired, in_shapeshift;
void refix();

#define FEATTIMER 35

void create() {
    ::create();
    feat_type("instant");
    feat_category("MeleeDamage");
    feat_name("sunder");
    feat_prereq("Powerattack");
    feat_desc("The character can attempt to disrupt or damage the armor of their opponent, making them more vulnerable to melee attacks. This will only work while shapeshifted, or using a weapon, unless the character has an aptitude in unarmed combat.

A druid with the 'mastery of fang and claw' feat may also use this feat while in bear form, even if it has not been purchased directly.");
    set_target_required(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob,"powerattack")) {
      dest_effect();
      return 0;
    }
    return ::prerequisites(ob);
}

int cmd_sunder(string str) {
    object feat;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat() {
    int i, count;
    mapping tempmap;
    object ammo, *weapons;
    ::execute_feat();
    if(!objectp(target)) {
        dest_effect();
        return;
    }
    if((int)caster->query_property("using instant feat")) {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    tempmap = caster->query_property("using sunder");
    if(mapp(tempmap)) {
        if(tempmap[target] > time()) {
          tell_object(caster,"That target is still wary of such an attack!");
          dest_effect();
          return;
        }
    }
    if(caster->query_property("shapeshifted") && !caster->query_property("altered")) in_shapeshift = 1;
    else in_shapeshift = 0;
    if(!sizeof(caster->query_wielded()) && !in_shapeshift) {
        tell_object(caster,"How can you sunder anyone's armor without a weapon?");
        dest_effect();
        return;
    }
    if(sizeof(weapons) && weapons[0]->is_lrweapon() && !in_shapeshift) {
        ammo = present(weapons[0]->query_ammo(),caster);
        if(FEATS_D->usable_feat(caster,"point blank shot") && objectp(ammo) && ammo->use_shots()) fired = 1;
    }
    tell_object(caster,"%^BOLD%^%^GREEN%^You aim a strike directly at "+target->QCN+
        "'s armor!%^RESET%^");
    tell_object(target,"%^BOLD%^%^GREEN%^"+caster->QCN+" aims a strike directly at "
        "your armor!");
    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" aims a strike directly at "
        +target->QCN+"'s armor!%^RESET%^",({target,caster}));
    caster->use_stamina(roll_dice(1,6));
    caster->set_property("using instant feat",1);
    spell_kill(target,caster);
    return;
}

void execute_attack() {
    int skinned, i, timerz, sunder_bonus;
    object *keyz, *weapons;
    mapping tempmap, newmap;

    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
    if(!objectp(target) || !present(target,place)) {
        tell_object(caster,"Your target is no longer here!");
        dest_effect();
        return;
    }
    if(caster->query_property("shapeshifted") && !caster->query_property("altered")) in_shapeshift = 1;
    else in_shapeshift = 0;
    if(!sizeof(caster->query_wielded()) && !in_shapeshift) {
        tell_object(caster,"How can you sunder anyone's armor without a weapon?");
        dest_effect();
        return;
    }
    tempmap = caster->query_property("using sunder"); // adding per-target tracking. -N, 9/10.
    if(!mapp(tempmap)) tempmap = ([]);
    if(tempmap[target]) map_delete(tempmap,target);
    newmap = ([]);
    keyz = keys(tempmap);
    if(sizeof(keyz)) {
      for(i=0;i<sizeof(keyz);i++) { if(objectp(keyz[i])) newmap += ([ keyz[i] : tempmap[keyz[i]] ]); }
    }
    timerz = time() + FEATTIMER;
    newmap += ([ target : timerz ]);
    delay_subject_msg(target, FEATTIMER,"%^BOLD%^%^WHITE%^"+target->QCN+" can be %^CYAN%^sundered%^WHITE%^ again.%^RESET%^");
    caster->remove_property("using sunder");
    caster->set_property("using sunder",newmap);

    tell_object(caster,"%^BOLD%^%^GREEN%^You damage "+target->QCN+"'s armor and "
        "knock it askew, leaving a hole in "+target->QP+" defenses!");
    tell_object(target,"%^BOLD%^%^GREEN%^"+caster->QCN+" damages your armor and "
        "knocks it askew, leaving a hole in your defenses!");
    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" damages "+target->QCN+"'s "
        "armor and knocks it askew, leaving a hole in "+target->QP+
        " defenses!",({target,caster}));
    weapons = caster->query_wielded();
    if (sizeof(weapons)>0){
        sunder_bonus = 0;
        for (i = 0;i<sizeof(weapons);i++){
            if (weapons[i]->query("sunder bonus") > sunder_bonus){
                sunder_bonus = weapons[i]->query("sunder bonus");
            }
        }
    }
    mod = clevel/5 + sunder_bonus;
    target->add_ac_bonus((-1)*mod);
    call_out("refix",(ROUND_LENGTH*roll_dice(3,2)));
}

void refix() {
    if(objectp(target)) {
        tell_object(target,"%^BOLD%^%^GREEN%^You manage to get your armor back into place.");
        tell_room(place,"%^BOLD%^%^GREEN%^"+target->QCN+" settles "+target->QP+" armor back into place.",target);
        target->add_ac_bonus(mod);
    }
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
