//Frozen breath - Aurilian flamestrike alternative, coded by Nienne, 05/05//
//changed to general priest spell for a flamestrike ascetic alternative. Nienne, 05/07
// Dalamar@Shadowgate

#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

int effect,damage,x,y,i;
string tmp,YOU,HIM;

object tempob,*foes,*oldfoes,*tempfoes,*allies;

void dest_effect();
void damage();

void create() {
    ::create();
    set_spell_name("frozen breath");
    set_spell_level(([ "cleric" : 5 ]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS frozen breath on TARGET");
    set_description("This spell will call forth a breath of ice to chill your foes.  It can be used in two ways - when "
"used before combat begins, it will engulf a single foe; when cast during combat, it is particularly devastating, as it "
"will cause harm to up to five enemies. Beware, the caster should advise his allies to not stand too close to the target "
"of the spell!");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_immunities( ({ "ice", "spell_immunity"}) );
    set_save("reflex");
    splash_spell(1);
}

void spell_effect(int prof) {
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
    foes -= ({ target});


    tell_object(target,"%^BOLD%^%^CYAN%^A gust of chilling wind races toward you and engulfs you in frost!");
    tell_object(caster,"%^BOLD%^%^CYAN%^You summon your god's wrath to engulf "+HIM+" in a chilling wind of frost!");
    tell_room(place,"%^BOLD%^%^CYAN%^A gust of chilling wind engulfs "+HIM+" in frost, as "+YOU+" calls upon the power of "+caster->QP+" god!",({ caster, target}) );
    tell_object(target,"%^BOLD%^%^WHITE%^You are chilled to the bone by the icy wind!",target);

    oldfoes=foes;
    foes = ({});
    allies = ({});
    y=4;
    if (sizeof(oldfoes) < y)
        y = sizeof(oldfoes);

    for (x=0;x < y;x++) {
        tempob=oldfoes[random(sizeof(oldfoes))];
        if(do_save(tempob,0))
        //if ("/daemon/saving_d"->saving_throw(tempob, "spell", -1 * clevel/10))
            allies += ({ tempob});
        else
            foes += ({ tempob});
        oldfoes -= ({ tempob});
    }
    damage=sdamage;
    if(do_save(target,0))
    //if ("/daemon/saving_d"->saving_throw(target, "spell",-1 * clevel/10))
        damage_targ(target, "torso", to_int(damage / 2),"cold" );
    else
        damage_targ(target, "torso", damage,"cold" );
    for (x=0;x < sizeof(foes);x++) {
		if(!objectp(foes[x])) { continue; }
		if(foes[x]->query_true_invis()) { continue; }
        damage=sdamage;
        tell_room(environment(foes[x]),"%^BOLD%^%^WHITE%^The frozen wind also catches "+foes[x]->QCN+" in its chilling embrace!",foes[x]);
        tell_object(foes[x], "%^BOLD%^%^WHITE%^You are chilled to the bone by the icy wind!");
        damage_targ(foes[x], "torso", damage/2,"cold");
    }
    for (x=0;x < sizeof(allies);x++) {
        if (!objectp(allies[x])) continue;
		if (allies[x]->query_true_invis()) { continue; }
        damage=sdamage;
        tell_room(environment(allies[x]), "%^BOLD%^%^WHITE%^The outer edges of the frozen wind catch "+allies[x]->QCN+"!", allies[x]);
        tell_object(allies[x], "%^BOLD%^%^WHITE%^You are chilled by the edge of the icy wind.");
        damage_targ(allies[x], "torso", to_int(damage / 4),"cold" );
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

string query_cast_string() {
    return "%^BOLD%^%^CYAN%^"+caster->QCN+" purses "+caster->QP+" lips and blows lightly across "+caster->QP+" fingertips.";
}
