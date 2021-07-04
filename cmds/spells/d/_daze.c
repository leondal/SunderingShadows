#include <spell.h>
#include <magic.h>
#include <priest.h>
inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("daze");
    set_spell_level(([ "inquisitor":1, "cantrip" : 1 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS daze on TARGET");
    set_description("%^RESET%^This spell attempts to dazzle a creature into immobility. %^RESET%^%^BOLD%^N.B.%^RESET%^:

%^BOLD%^%^RED%^See also%^RESET%^: daze *feats%^RESET%^");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string() {
    tell_object(caster,"%^MAGENTA%^You close your hand into a fist.");
    tell_room(place,"%^MAGENTA%^"+caster->QCN+" closes "+caster->QP+" hand into a fist.",caster);
    return "display";
}

void spell_effect(int prof) {
    int duration, targlevel;
    if (!objectp(caster) || !objectp(target)) {
      dest_effect();
      return;
    }
    if (!present(target,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target has left the area.\n");
        dest_effect();
        return;
    }
    tell_object(caster, "%^BOLD%^Flicking your fingers suddenly open, coruscating motes of light are cast forth directly "
"into "+target->QCN+"'s face!%^RESET%^");
    tell_object(target, "%^BOLD%^"+caster->QCN+" flicks "+caster->QP+" fingers suddenly open, and coruscating motes of "
"light are cast forth directly into your face!%^RESET%^");
    tell_room(place,"%^BOLD%^"+caster->QCN+" flicks "+caster->QP+" fingers suddenly open, and coruscating motes of light "
"are cast forth directly into "+target->QCN+"'s face!%^RESET%^",({caster,target}));
    targlevel = (int)target->query_level();
    if(do_save(target) || target->query_property("no paralyze")) {
        tell_object(target, "%^BOLD%^You manage to shake off the hypnotic effects of the light.%^RESET%^");
        tell_room(place,"%^BOLD%^"+target->QCN+" manages to shake off the light's hypnotic effects!%^RESET%^",target);
        dest_effect();
        return;
    }
    duration = ((10 - targlevel)/3)+1; // one round length per 3 levels below 10
    if (duration > 3) duration = 3; // max 3 round stun to a L1 beastie
    duration = duration * ROUND_LENGTH;
    tell_object(target, "%^YELLOW%^You can't help but be enthralled by the sparkling motes of light!.%^RESET%^");
    tell_room(place,"%^YELLOW%^"+target->QCN+" stares in fascination at the sparkling motes of light!%^RESET%^",target);
    target->set_paralyzed(duration,"%^YELLOW%^You are held fascinated by the sparkling motes of light!%^RESET%^");
    spell_successful();
    spell_kill(target, caster);
    dest_effect();
}

void dest_effect() {
     ::dest_effect();
     if(objectp(TO)) TO->remove();

}
