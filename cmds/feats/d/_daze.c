#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

int FLAG, fired;

#define FEATTIMER 35

void create() {
    ::create();
    feat_type("instant");
    feat_category("MeleeAccuracy");
    feat_name("daze");
    feat_desc("The character can attempt to daze a foe, with a blow to the side of the head, in an attempt to addle them sufficiently that they cannot cast spells for a time. It will also interrupt any spells being cast.

%^BOLD%^See also:%^RESET%^ daze *spells");
    feat_syntax("daze TARGET");
    feat_prereq("Knockdown, Disarm");
    set_target_required(1);
    set_save("fort");
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob,"disarm") || !FEATS_D->has_feat(ob,"knockdown")) {
      dest_effect();
      return 0;
    }
    return ::prerequisites(ob);
}

int cmd_daze(string str) {
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
    tempmap = caster->query_property("using daze");
    if(mapp(tempmap)) {
        if(tempmap[target] > time()) {
          tell_object(caster,"That target is still wary of such an attack!");
          dest_effect();
          return;
        }
    }
    weapons = caster->query_wielded();
    if(sizeof(weapons) && weapons[0]->is_lrweapon() && !caster->query_property("shapeshifted")) {
        ammo = present(weapons[0]->query_ammo(),caster);
        if(FEATS_D->usable_feat(caster,"point blank shot") && objectp(ammo) && ammo->use_shots()) fired = 1;
    }
    if(fired) {
        tell_object(caster,"%^BOLD%^%^CYAN%^You aim a sudden, precise shot at "
            +target->QCN+"'s head!%^RESET%^");
        tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" aims a sudden, "
            "precise shot at your head!");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" aims a sudden, precise "
            "shot at "+target->QCN+"'s head!%^RESET%^",({target,caster}));
    }
    else {
        tell_object(caster,"%^BOLD%^%^CYAN%^You aim a sudden, precise strike at "
            +target->QCN+"'s head!%^RESET%^");
        tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" aims a sudden, "
            "precise strike at your head!");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" aims a sudden, precise "
            "strike at "+target->QCN+"'s head!%^RESET%^",({target,caster}));
    }
    caster->use_stamina(roll_dice(1,6));
    caster->set_property("using instant feat",1);
    spell_kill(target,caster);
    return;
}

void execute_attack() {
    int i, mod, timerz, res;
    mapping tempmap, newmap;
    object *keyz;

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

    tempmap = caster->query_property("using daze"); // adding per-target tracking. -N, 9/10.
    if(!mapp(tempmap)) tempmap = ([]);
    if(tempmap[target]) map_delete(tempmap,target);
    newmap = ([]);
    keyz = keys(tempmap);
    if(sizeof(keyz)) {
      for(i=0;i<sizeof(keyz);i++) { if(objectp(keyz[i])) newmap += ([ keyz[i] : tempmap[keyz[i]] ]); }
    }
    timerz = time() + FEATTIMER;
    newmap += ([ target : timerz ]);
    delay_subject_msg(target,FEATTIMER,"%^BOLD%^%^WHITE%^"+target->QCN+" can be %^CYAN%^dazed%^WHITE%^ again.%^RESET%^");
    caster->remove_property("using daze");
    caster->set_property("using daze",newmap);

    if(!(res = thaco(target)))
    {
        tell_object(caster,"%^RED%^"+target->QCN+" dodges to the side and "
            "you're thrown off balance!%^RESET%^");
        tell_object(target,"%^BOLD%^%^CYAN%^You dodge to the side, throwing "
            +caster->QCN+" off balance!%^RESET%^");
        tell_room(place,"%^BOLD%^"+target->QCN+" dodges to the side, throwing "
            ""+caster->QCN+" off balance!%^RESET%^",({target,caster}));
        caster->set_paralyzed(roll_dice(2,6),"%^MAGENTA%^You're getting back into position.%^RESET%^");
        dest_effect();
        return;
    }
    else if(res == -1 || target->query_property("no daze"))
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

    mod = clevel;
    mod += clevel - (int)target->query_level();
    mod = mod * -1;

    if(!do_save(target,mod)) {
        if(fired) {
            tell_object(caster,"%^BOLD%^%^GREEN%^Your shot strikes "+target->QCN+
                " directly in the throat, leaving "+target->QO+" gasping for air!");
            tell_object(target,"%^BOLD%^%^GREEN%^"+caster->QCN+"'s shot strikes you "
                "directly in the throat, and suddenly it's a struggle just to breathe!");
            tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+"'s shot strikes "+target->QCN+
                " directly in the throat, leaving "+target->QO+" gasping for air!",({target,caster}));
        }
        else {
            tell_object(caster,"%^BOLD%^%^GREEN%^You smack "+target->QCN+" forcefully "
                "upside the head, sending "+target->QO+" stumbling!");
            tell_object(target,"%^BOLD%^%^GREEN%^"+caster->QCN+" smacks you forcefully "
                "upside the head, so hard your can't even think straight!");
            tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" smacks "+target->QCN+
                " forcefully upside the head, sending "+target->QO+" stumbling!",({target,caster}));
        }
        FLAG = 1;
        if(interactive(target)) target->set_static("spell interrupt","%^RED%^Your head is ringing!%^RESET%^");
        else target->spell_interrupt("spell interrupt","%^RED%^Your head is ringing!%^RESET%^");
        call_out("dest_effect",roll_dice(3,6));
        return;
    }
    if(fired) {
        tell_object(caster,"%^BOLD%^%^GREEN%^Your shot only grazes "+target->QCN+
            "'s throat, and "+target->QS+" grits "+target->QP+" teeth and "
            "seems to maintain concentration!");
        tell_object(target,"%^BOLD%^%^GREEN%^"+caster->QCN+"'s shot only grazes "
            "your throat, and you grit your teeth and keep your focus!");
        tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+"'s shot only grazes "
            +target->QCN+"'s throat, and "+target->QS+" grits "+target->QP+
            " teeth and seems to maintain concentration!",({target,caster}));
        dest_effect();
        return;
    }
    tell_object(caster,"%^BOLD%^%^GREEN%^You smack "+target->QCN+" forcefully "
        "upside the head, but "+target->QS+" grits "+target->QP+" teeth and "
        "seems to maintain concentration!");
    tell_object(target,"%^BOLD%^%^GREEN%^"+caster->QCN+" smacks you forcefully "
        "upside the head, but you grit your teeth and keep your focus!");
    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" smacks "+target->QCN+
        " forcefully upside the head, but "+target->QS+" grits "+target->QP+
        " teeth and seems to maintain concentration!",({target,caster}));
    dest_effect();
    return;
}

void dest_effect(){
    if(FLAG && objectp(target)) {
        if(interactive(target)) target->set_static("spell interrupt",0);
        else target->remove_property("spell interrupt");
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
