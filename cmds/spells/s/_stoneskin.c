// Stoneskin

#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <std.h>
inherit SPELL;
int reversed;

void create() {
    ::create();
    set_spell_name("stoneskin");
    set_spell_level(([ "mage" : 4, "druid" : 4, "monk" : 11, "inquisitor" : 4, "bard":4, "oracle":6, "magus" : 4 ]));
    set_spell_sphere("abjuration");
    set_monk_way("way of the elements");
    set_syntax("cast CLASS stoneskin on TARGET");
    set_damage_desc("10 damage resistance");
    set_description("This spell causes the target to take less damage from to a certain number of attacks, based on the level of "
"the caster. It does not work together with iron body.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_components(([
      "mage" : ([ "granite dust":1, ]),
    ]));
	set_helpful_spell(1);
}

int preSpell()
{
    if(spell_type == "monk") target = caster;
    if(!objectp(caster))
    {
        return 0;
    }
    if(!objectp(target))
    {
        tell_object(caster, "You must specify a target!");
        return 0;
    }
    if(target->query_stoneSkinned() || target->query_property("iron body"))
    {
        tell_object(caster,"That target already has protection of this nature!");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    if(spell_type == "monk")
        return "%^BOLD%^"+caster->QCN+"%^BOLD%^ begins focusing intently as "+caster->QS+" mumbles incromprehensibly.";
    return "%^BOLD%^"+caster->QCN+" sprinkles some granite dust over "+target->QCN+" and begins muttering incomprehensibly.";
}

void spell_effect(int prof)
{
    ::spell_effect();
    if(spell_type == "monk") target = caster;
    if((string)TO->query_spell_type() == "potion") {
      if(target->query_stoneSkinned() || target->query_property("iron body")){
        tell_object(caster,"The potion doesn't seem to have any effect. You realise you already have protection of this nature!");
        TO->remove();
        return;
      }
      if(prof == -100) { // hack for potions. Cuz lib doesn't seem to call reverse spell anymore, and I'm lazy. N, 6/15.
        reverse_spell();
        return;
      }
      tell_object(caster,"%^BOLD%^As the potion warms your stomach, a layer of granite ripples out over your skin.%^RESET%^");
      tell_room(place,"%^BOLD%^A layer of granite ripples out over "+caster->QCN+"'s skin.",caster);
    }
    else
    {
        tell_room(place, target->QCN+"%^BOLD%^%^WHITE%^ is suddenly surrounded by an impenetrable granite armor!", target);
        tell_object(target, "%^BOLD%^%^WHITE%^You are suddenly surrounded by an impenetrable granite armor!%^RESET%^");

    }
    target->set_property("spelled",({TO}));
    target->set_property("damage resistance",10);
    target->set_property("iron body",1);
    addSpellToCaster();
    return;
}

void dest_effect() {
    if (!objectp(target)) {
      TO->remove();
      return;
    }
    if(reversed && objectp(caster)){
      tell_object(caster,"%^MAGENTA%^You feel your body return to normal as the potion wears off.");
      caster->set_property("damage resistance",5); // restore their lost AC!
      caster->set_property("iron body",-1);
    }
    else {
      tell_room(environment(target),"%^BOLD%^The armor surrounding "+target->QCN+" loses its form and falls apart.",target);
      tell_object(target,"%^BOLD%^The force protecting you breaks apart, leaving you vulnerable once again.");
      target->set_property("damage resistance",-10);
      target->set_property("iron body",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

void reverse_spell(){
    // adding in backfires for potions! Can't find where lib actually calls this anymore.
    tell_object(caster,"%^BOLD%^A queasy feeling runs through you, and your skin grows suddenly hypersensitive.%^RESET%^");
    reversed = 1;
    caster->set_property("damage resistance",-5); // restore their lost AC!
    spell_successful();
    caster->set_property("spelled", ({TO}) );
    caster->set_property("iron body",1);
    call_out("dest_effect",(clevel*10));
}
