#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

int fired;

#define FEATTIMER 30

void create() {
    ::create();
    feat_type("instant");
    feat_category("MeleeAccuracy");
    feat_name("disarm");
    feat_prereq("Expertise");
    feat_syntax("disarm TARGET");
    feat_desc("The character can attempt to disarm a foe of their weapons momentarily. This will only work while shapeshifted, or using a weapon, unless the character has an aptitude in unarmed combat.");
    set_target_required(1);
    set_required_for(({"daze"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob,"expertise")) {
      dest_effect();
      return 0;
    }
    return ::prerequisites(ob);
}

int cmd_disarm(string str) {
    object feat;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat() {
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
    tempmap = caster->query_property("using disarm");
    if(mapp(tempmap)) {
        if(tempmap[target] > time()) {
          tell_object(caster,"That target is still wary of such an attack!");
          dest_effect();
          return;
        }
    }
    if(!sizeof(caster->query_wielded()) && !caster->query_property("shapeshifted") && !FEATS_D->usable_feat(caster,"unarmed combat")) {
        tell_object(caster,"How can you disarm anyone without a weapon?");
        dest_effect();
        return;
    }
    if(!sizeof(target->query_wielded())) {
        tell_object(caster,"They don't have a weapon!");
        dest_effect();
        return;
    }
    weapons = caster->query_wielded();
    if(sizeof(weapons) && weapons[0]->is_lrweapon() && !caster->query_property("shapeshifted")) {
        ammo = present(weapons[0]->query_ammo(),caster);
        if(FEATS_D->usable_feat(caster,"point blank shot") && objectp(ammo) && ammo->use_shots()) fired = 1;
    }
    if(fired) {
        tell_object(caster,"%^BOLD%^%^CYAN%^You aim a shot at "+target->QCN+"'s weapon hand!%^RESET%^");
        tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" aims a shot at your weapon hand!");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" aims a shot at "+target->QCN+"'s weapon "
            "hand!%^RESET%^",({target,caster}));
    }
    else {
        tell_object(caster,"%^BOLD%^%^CYAN%^You lash out at "+target->QCN+" and attempt to "
            "knock "+target->QP+" weapon from "+target->QP+" hands!%^RESET%^");
        tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" lashes out at you in an attempt "
            "to knock your weapon from your hands!");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" lashes out at "+target->QCN+" in an "
            "attempt to knock "+target->QP+" weapon from "+target->QP+" hands!%^RESET%^",({target,caster}));
    }
    caster->use_stamina(roll_dice(1,6));
    caster->set_property("using instant feat",1);
    spell_kill(target,caster);
    return;
}

void execute_attack() {
    int i, timerz, res;
    object *targweapon, *keyz;
    string wpn_name, *ids;
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
    if(!sizeof(caster->query_wielded()) && !caster->query_property("shapeshifted") && !FEATS_D->usable_feat(caster,"unarmed combat")) {
        tell_object(caster,"How can you disarm anyone without a weapon?");
        dest_effect();
        return;
    }
    if(!sizeof(target->query_wielded())) {
        tell_object(caster,"They don't have a weapon!");
        dest_effect();
        return;
    }

    tempmap = caster->query_property("using disarm"); // adding per-target tracking. -N, 9/10.
    if(!mapp(tempmap)) tempmap = ([]);
    if(tempmap[target]) map_delete(tempmap,target);
    newmap = ([]);
    keyz = keys(tempmap);
    if(sizeof(keyz)) {
      for(i=0;i<sizeof(keyz);i++) { if(objectp(keyz[i])) newmap += ([ keyz[i] : tempmap[keyz[i]] ]); }
    }
    timerz = time() + FEATTIMER;
    newmap += ([ target : timerz ]);
    delay_subject_msg(target, FEATTIMER,"%^BOLD%^%^WHITE%^"+target->QCN+" can be %^CYAN%^disarmed%^WHITE%^ again.%^RESET%^");
    caster->remove_property("using disarm");
    caster->set_property("using disarm",newmap);

    if(!(res = thaco(target)))
    {
        tell_object(caster,"%^RED%^"+target->QCN+" twists away quickly, leaving "
            "you off balance!%^RESET%^");
        tell_object(target,"%^BOLD%^%^GREEN%^You twist away quickly, leaving "
            +caster->QCN+" off balance!%^RESET%^");
        tell_room(place,"%^BOLD%^"+target->QCN+" twists away quickly, leaving "
            ""+caster->QCN+" off balance!%^RESET%^",({target,caster}));
        caster->set_paralyzed(roll_dice(2,6),"%^MAGENTA%^You're getting back into position.%^RESET%^");
        dest_effect();
        return;
    }
    else if(res == -1 || target->query_property("no disarm"))
    {
        if(stringp(caster->query("featMiss")))
        {
            tell_object(caster, caster->query("featMiss")+" " +query_feat_name()+"!");
            caster->delete("featMiss");
        }
        else
        {
            tell_object(caster, "%^RED%^"+target->QCN+" is totally unaffected!%^RESET%^");
            tell_room(place, "%^RED%^"+target->QCN+" is totally unaffected!%^RESET%^", ({target, caster}));
        }
        dest_effect();
        return;
    }

    if(fired) {
        tell_object(caster,"%^BOLD%^%^CYAN%^Your shot flies true, knocking "
            +target->QCN+"'s weapon from "+target->QP+" grasp.");
        tell_object(target,"%^BOLD%^%^CYAN%^The shot flies true, and your "
            "weapon flies from your grasp!");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+"'s shot flies true, "
            "knocking "+target->QCN+"'s weapon from "+target->QP+" grasp!",({target,caster}));
    }
    else {
        tell_object(caster,"%^BOLD%^%^CYAN%^With a deft twist, you knock "+target->QCN+"'s weapon "
            "from "+target->QP+" grasp.");
        tell_object(target,"%^BOLD%^%^CYAN%^Your weapon flies from your grasp!");
        tell_room(place,"%^BOLD%^%^CYAN%^With a deft twist, "+caster->QCN+" knocks "
            +target->QCN+"'s weapon free of "+target->QP+" grasp!",({target,caster}));
    }

    targweapon = target->query_wielded();
    i = random(sizeof(targweapon));
    //ids = targweapon[i]->query_id();
    wpn_name = targweapon[i]->query_name();
    targweapon[i]->set_name("disarm_this");
    target->force_me("unwield disarm_this");
    targweapon[i]->set_name(wpn_name);
    //target->force_me("unwield "+ids[0]);
    target->remove_property("disarm time");
    target->set_property("disarm time",(time() + (ROUND_LENGTH * roll_dice(1,4))));

    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
