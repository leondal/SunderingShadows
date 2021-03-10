//Tsunami - Istishian flamestrike alternative, coded by Nienne, 05/05//
#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

int effect,damage,x,y,i;
string tmp,YOU,HIM;

object victim,caster,target,tempob,place,*foes,*oldfoes,*tempfoes,*allies;

void dest_effect();
void damage();

void create() {
    ::create();
    set_spell_name("tsunami");
    set_spell_level(5);
    set_spell_type("priest");
    set_spell_sphere("combat");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_immunities( ({ "water", "spell_immunity"}) );
    set_xp_bonus(50);
}

spell_effect(int prof) {
    place = environment(caster);
    YOU=caster->query_cap_name();
    spell_successful();

    if (!interactive(caster) && !caster->query_invis())
        YOU=caster->query_cap_name();

    if (!present(target,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target has left the area.\n");
        dest_effect();
        return;
    }
    HIM=target->query_cap_name();
    foes=caster->query_attackers();
    if (member_array(target,foes) != -1)
        foes -= ({ target});
    tell_object(target,"%^BOLD%^%^BLUE%^A massive wave of water rushes through the area engulfing you in its mighty torrent!");
    tell_object(caster,"%^BOLD%^%^BLUE%^You summon your god's wrath to engulf "+HIM+" in a mighty wave of water!");
    tell_room(place,"%^BOLD%^%^BLUE%^A massive wave of water rushes through the area and engulfs "+HIM+", as "+YOU+" calls upon the power of "+caster->query_possessive()+" god!",({ caster, target}) );
    tell_object(target,"%^BLUE%^You are thrown around by the rushing water!",target);

    oldfoes=foes;
    foes = ({});
    allies = ({});
    y=4;
    if (sizeof(oldfoes) < y)
        y = sizeof(oldfoes);

    for (x=0;x < y;x++) {
        tempob=oldfoes[random(sizeof(oldfoes))];
        if ("/daemon/saving_d"->saving_throw(tempob, "spell", -1 * clevel/10))
            allies += ({ tempob});
        else
            foes += ({ tempob});
        oldfoes -= ({ tempob});
    }
    damage=roll_dice((6+(clevel-9)/4),10);
//tell_object(caster,"damage = "+damage);
//taking this back out in response to a bug report.
//I'm assuming someone was using it for debugging?  Circe 9/19/04
    if ("/daemon/saving_d"->saving_throw(target, "spell",-1 * clevel/10))
        damage_targ(target, "torso", to_int(damage / 2) );
    else
        damage_targ(target, "torso", damage );
    for (x=0;x < sizeof(foes);x++) {
        damage=roll_dice((6+(clevel-9)/4),10);
        tell_room(environment(foes[x]),"%^BLUE%^The rushing water also catches "+foes[x]->query_cap_name()+" in its mighty torrent!",foes[x]);
        tell_object(foes[x], "%^BLUE%^You are thrown around by the rushing water!");
        damage_targ(foes[x], "torso", damage);
    }
    for (x=0;x < sizeof(allies);x++) {
        if (!objectp(allies[x])) continue;
        damage=roll_dice((6+(clevel-9)/4),10);
        tell_room(environment(allies[x]), "%^BLUE%^The outer edges of the wave toss "+allies[x]->query_cap_name()+" around!", allies[x]);
        tell_object(allies[x], "%^BLUE%^You are thrown around by the edges of the massive wave.");
        damage_targ(allies[x], "torso", to_int(damage / 2) );
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    TO->remove();
}

string query_cast_string() {
    return "%^BOLD%^%^BLUE%^"+caster->query_cap_name()+" speaks a prayer and gestures in a sweeping motion to "+target->query_cap_name()+".";
}

int help(string str) {
    write(
@HELP
Spell  : Tsunami
Level  : 5th Level
Sphere : Combat
Deity  : Istishia
Syntax : chant tsunami on <target>

This spell will call forth a massive wave to engulf your foes.
It can be used in two ways - when used before combat begins, it
will engulf a single foe; when cast during combat, it is
particularly devastating, as it will cause harm to up to
five enemies. Beware, the caster should advise his allies
to not stand too close to the target of the spell!

HELP
);
    return 1;
}
