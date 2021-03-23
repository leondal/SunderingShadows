// Flame Strike
// Dalamar@Shadowgate

#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

int effect,damage,x,y,i;
string tmp,YOU,HIM;

object tempob,place,*foes,*oldfoes,*tempfoes,*allies;

void dest_effect();
void damage();

void create() {
    ::create();
    set_spell_name("flame strike");
    set_spell_level(([ "druid" : 4, "inquisitor":5, "cleric" : 4 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS flame strike on TARGET");
    set_description("This spell will call down a pillar of flame to engulf your foes.  It can be used in two ways - when "
"used before combat begins, it will engulf a single foe; when cast during combat, it is particularly devastating, as it "
"will severely burn up to five enemies.  Beware, the caster should advise his allies to not stand too close to the target "
"of the spell!");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(2);
    set_immunities( ({ "fire", "spell_immunity"}) );
    set_save("reflex");
}

void spell_effect(int prof)
{
    place = environment(caster);
    YOU=caster->QCN;
    spell_successful();

    if (!interactive(caster) && !caster->query_invis())
        YOU=caster->QCN;

    if (!present(target,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target has left the area.\n");
        dest_effect();
        return;
    }
    HIM=target->QCN;
    foes=target_selector();


    if (member_array(target,foes) != -1)
        foes -= ({ target});
    tell_object(target,"%^RED%^%^BOLD%^A blazing pillar of flame descends from directly above you!");
    tell_object(caster,"%^RED%^%^BOLD%^You summon your god's wrath to engulf "+HIM+" in a pillar of flame!");
    tell_room(place,"%^BOLD%^%^RED%^A scorching pillar of flame descends on "+HIM+", as "+YOU+" calls upon the power of "+caster->QP+" god!",({ caster, target}) );

    if(sizeof(foes))
    {
        oldfoes=foes;
        foes = ({});
        allies = ({});
        y=4;
        if (sizeof(oldfoes) < y)
            y = sizeof(oldfoes);

        for (x=0;x < y;x++) {
            tempob=oldfoes[random(sizeof(oldfoes))];
            if(do_save(tempob,0))
                allies += ({ tempob});
            else
                foes += ({ tempob});
            oldfoes -= ({ tempob});
        }
    }

    if(do_save(target,0)) {
          damage_targ(target, "torso", to_int(sdamage / 4),"fire" );
          damage_targ(target, "torso", to_int(sdamage / 4),"divine" );
          tell_object(target,"%^RED%^You are partly burned by the holy flame!",target);
    }
    else {
        tell_object(target,"%^RED%^You are burned badly by the holy flame!",target);
        damage_targ(target, "torso", to_int(sdamage / 2),"fire" );
        damage_targ(target, "torso", to_int(sdamage / 2),"divine" );
    }
    for (x=0;sizeof(foes) > 0,x < sizeof(foes);x++) {
        if(!objectp(foes[x])) { continue; }
        if(do_save(foes[x],0)) {
            tell_room(environment(foes[x]), "The outer edges of the blast singes "+foes[x]->QCN+"!", foes[x]);
            tell_object(foes[x], "%^RED%^You are slightly singed by the outer edge of the flaming pillar.");
            damage_targ(foes[x], "torso", to_int(sdamage / 4),"fire" );
            damage_targ(foes[x], "torso", to_int(sdamage / 4),"divine" );
        }
        else {
          tell_room(environment(foes[x]),"%^RED%^The pillar of flame also catches "+foes[x]->QCN+" in its fiery embrace!",foes[x]);
          tell_object(foes[x], "%^RED%^The pillar of fire scorches you!");
          damage_targ(foes[x], "torso", to_int(sdamage / 2),"fire");
          damage_targ(foes[x], "torso", to_int(damage / 2),"divine");
        }
    }
    for (x=0;sizeof(allies) > 0,x < sizeof(allies);x++) {
        if (!objectp(allies[x])) continue;
        tell_room(environment(allies[x]), "The outer edges of the blast singes "+allies[x]->QCN+"!", allies[x]);
        tell_object(allies[x], "%^RED%^You are slightly singed by the outer edge of the flaming pillar.");
        damage_targ(allies[x], "torso", to_int(sdamage / 4),"fire" );
        damage_targ(allies[x], "torso", to_int(sdamage / 4),"divine" );
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}

string query_cast_string() {
    return caster->QCN+" mutters a prayer and gestures at the air above "+target->QCN+".";
}
