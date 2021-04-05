#include <spell.h>
#include <magic.h>
#include <priest.h>
inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("flare");
    set_spell_level(([ "cantrip" : 1,"druid" : 1, "mage":1, "magus" : 1, "cleric" : 1 ]));
    set_domains("sun");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS flare on TARGET");
    set_description("This minor spell creates an abrupt flash of light, which if cast immediately in front of a creature, can dazzle them and cause difficulties with their vision.

%^BOLD%^%^RED%^See also:%^RESET%^ status effects");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

int preSpell(){
    if(!objectp(target)) {
        tell_object(caster,"You need a target for this spell.");
        return 0;
    }
    if((int)target->query_property("effect_dazzled")) {
        tell_object(caster,"%^YELLOW%^The target already looks dazzled!");
        return 0;
    }
    return 1;
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
    spell_successful();
    if(do_save(target,-1*(clevel/7))){
       tell_object(caster,"%^BOLD%^You snap your fingers and a brilliant flash lights up before "+target->QCN+"'s eyes, "
"but "+target->QS+" blinks away the afterimage!");
       tell_object(target,"%^BOLD%^"+caster->QCN+" snaps "+caster->QCN+" fingers and a brilliant flash lights up before "
"your eyes, but you manage to blink away the vivid afterimage.");
       tell_room(place,"%^BOLD%^"+caster->QCN+" snaps "+caster->QCN+" fingers and a brilliant flash lights up before "
+target->QCN+"'s eyes, but "+target->QS+" blinks away the afterimage!",({caster, target}));
       dest_effect();
       return;
    }
   if(FEATS_D->usable_feat(target,"blindfight")) {
       tell_object(caster,"%^BOLD%^You snap your fingers and a brilliant flash lights up before "+target->QCN+"'s eyes, "
"but "+target->QP+" abilities seem unaffected!");
       tell_object(target,"%^BOLD%^"+caster->QCN+" snaps "+caster->QCN+" fingers and a brilliant flash lights up before "
"your eyes, but you are so accustomed to fighting with impaired vision that it causes you no difficulties.");
       tell_room(place,"%^BOLD%^"+caster->QCN+" snaps "+caster->QCN+" fingers and a brilliant flash lights up before "
+target->QCN+"'s eyes, but "+target->QP+" abilities seem unaffected!",({caster, target}));
       dest_effect();
       return;
    }

    tell_object(caster,"%^BOLD%^You snap your fingers and a brilliant flash lights up before "+target->QCN+"'s eyes, "
"leaving "+target->QO+" dazzled!");
    tell_object(target,"%^BOLD%^"+caster->QCN+" snaps "+caster->QCN+" fingers and a brilliant flash lights up before "
"your eyes, leaving you dazzled!");
    tell_room(place,"%^BOLD%^"+caster->QCN+" snaps "+caster->QCN+" fingers and a brilliant flash lights up before "
+target->QCN+"'s eyes, leaving "+target->QO+" dazzled!",({caster, target}));
    "/std/effect/status/dazzled"->apply_effect(target,clevel/6+1);
}
