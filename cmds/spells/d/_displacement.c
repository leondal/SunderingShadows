//New illusion domain spell.  Based on the psion power Concealing
//Amorpha ~Circe~ 4/27/08 Rebalancing priest domains
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int reversed;

void create() {
    ::create();
    set_spell_name("displacement");
    set_spell_level(([ "bard" : 3, "mage" : 3, "magus" : 3, "cleric" : 3 ]));
    set_spell_sphere("illusion");
    set_domains("illusion");
    set_syntax("cast CLASS displacement");
    set_damage_desc("20% miss chance");
    set_description("Using the power of illusion, the caster calls forth a distortion of her form, making her harder to "
"target with melee attacks. It will cause one fifth of attacks to miss. Unlike blink and blurred movement, this spell will work in armor, but it has reduced potency.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

string query_cast_string(){
   return "%^MAGENTA%^As "+caster->QCN+" begins to chant, "+
      ""+caster->QP+" form grows d%^BOLD%^i%^RESET%^%^MAGENTA%^s"+
      "%^BOLD%^t%^RESET%^%^MAGENTA%^o%^BOLD%^r%^RESET%^%^MAGENTA%^t"+
      "%^BOLD%^e%^RESET%^%^MAGENTA%^d.%^RESET%^";
}

int preSpell() {
    if (caster->query_property("amorpha") || caster->query_property("timeless body")) {
//together these are broken, stacking regularly 100% miss chance. N, 4/14
        tell_object(caster, "You are already protected by a spell of concealment.");
        return 0;
    }
    if (caster->query_blinking()) {
        tell_object(caster, "You can't maintain such a spell while blinking.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {

    if (caster->query_property("amorpha")) {
        tell_object(caster, "You are already protected by a spell "+
           "similar to this one.");
        if(objectp(TO)) TO->remove();
        return;
    }
    if((string)TO->query_spell_type() == "potion") {
      if(prof == -100) { // hack for potions. Cuz lib doesn't seem to call reverse spell anymore, and I'm lazy. N, 6/15.
        reverse_spell();
        return;
      }
      tell_object(caster,"%^MAGENTA%^As the potion warms your stomach, a soft vibration runs through your body and it becomes blurred.%^RESET%^");
      tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+"'s form grows suddenly "+
       "%^RESET%^%^MAGENTA%^b%^BOLD%^l%^WHITE%^u%^RESET%^r%^BOLD%^r"+
       "%^MAGENTA%^e%^RESET%^%^MAGENTA%^d.%^RESET%^",caster);
    }
    else {
      if((string)TO->query_spell_type() == "bard") {
        tell_object(caster,"%^BOLD%^%^MAGENTA%^You hum softly, using the vibrations "+
        "in the air to blur your appearance, making you harder to target!%^RESET%^");
      }
      else {
        tell_object(caster,"%^BOLD%^%^MAGENTA%^You call upon your deity's "+
        "aid to blur your appearance, making you harder to target!%^RESET%^");
      }
      tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+"'s form grows "+
       "%^RESET%^%^MAGENTA%^b%^BOLD%^l%^WHITE%^u%^RESET%^r%^BOLD%^r"+
       "%^MAGENTA%^e%^RESET%^%^MAGENTA%^d %^BOLD%^as "+caster->QS+" "+
       "completes "+caster->QP+" spell.%^RESET%^",caster);
    }
    caster->set_property("spelled", ({TO}) );
    caster->set_property("amorpha",1);
    caster->set_missChance(caster->query_missChance()+ 30); // 30% evasion
    caster->set_property("added short",({"%^BOLD%^%^MAGENTA%^ (slightly distorted)%^RESET%^"}));
    spell_successful();
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 5;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    int chance;

    if (objectp(caster)) {
        if (reversed) {
            tell_object(caster, "%^MAGENTA%^You feel your body return to normal as the potion wears off.");
            tell_room(environment(caster), "%^MAGENTA%^" + caster->QCN + " suddenly seems normal again.%^RESET%^", caster);
            caster->add_ac_bonus(5);    // restore their lost AC!
        } else {
            if ((string) TO->query_spell_type() == "potion") {
                tell_object(caster, "%^MAGENTA%^You feel your body become more substantial as the potion wears off.");
            } else {
                if ((string) TO->query_spell_type() == "bard") {
                    tell_object(caster, "%^MAGENTA%^You feel your body become more " + "substantial as your song's protection fades.");
                } else {
                    tell_object(caster, "%^MAGENTA%^You feel your body become more " + "substantial as your deity's protection fades.");
                }
            }
            tell_room(environment(caster), "%^MAGENTA%^" + caster->QCN + " suddenly seems more " + "substantial as " + caster->QP + " skin loses its " + "distortion.%^RESET%^", caster);
            chance = (int) caster->query_missChance() - 30;
            caster->set_missChance(chance);
            caster->remove_property_value("added short", ( {
                        "%^BOLD%^%^MAGENTA%^ (slightly distorted)%^RESET%^"}));
        }
        caster->remove_property("amorpha");
    }
    ::dest_effect();
    if (objectp(TO))
        TO->remove();
}

void reverse_spell(){
    // adding in backfires for potions! Can't find where lib actually calls this anymore.
    tell_object(caster,"%^MAGENTA%^A queasy feeling runs through you, and your movements become slow and deliberate.%^RESET%^");
    reversed = 1;
    caster->add_ac_bonus(-5); // restore their lost AC!
    spell_successful();
    caster->set_property("spelled", ({TO}) );
    caster->set_property("amorpha",1);
    call_out("dest_effect",(clevel*20));
}
