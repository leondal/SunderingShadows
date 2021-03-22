// Bless
#include <std.h>
#include <magic.h>

inherit SPELL;

#define ALIGN_D "/daemon/alignment_d.c"

int bonus;

void create() {
    ::create();
    set_author("ares");
    set_spell_name("bless");
    set_spell_level(([ "cleric" : 1,"inquisitor" : 1, "paladin" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS bless on TARGET");
    set_damage_desc("clevel / 24 + 1 to damage and attack bonus, but no more than 2");
    set_description("This spell will bless the target, giving them a slightly better chance to hit in combat as well as "
"allowing them to do a small amount more damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
	set_helpful_spell(1);
}

int preSpell()
{
//    if(!ALIGN_D->is_good(caster)) {
    if(!target) { target = caster; }
    if(target->query_property("blessed")) {
        tell_object(caster,"%^BOLD%^%^RED%^Your target is already enjoying the blessings of a deity!%^RESET%^");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    tell_object(caster,"%^YELLOW%^You begin to chant a delicate prayer.");
	tell_room(place,"%^YELLOW%^"+caster->QCN+" begins a delicate prayer"+
		" to "+caster->QP+" diety.",caster);
    return "display";
}

void spell_effect(int prof) {
    int duration;
    duration = (ROUND_LENGTH * 20) * clevel;

    bonus = clevel/24+1;
    bonus = bonus>2?2:bonus;

    if((string)TO->query_spell_type() == "potion") {
      if(target->query_property("blessed")) {
        tell_object(caster,"%^BOLD%^%^RED%^Your target is already enjoying the blessings of a deity!%^RESET%^");
        TO->remove();
        return;
      }
      if(prof == -100) {
        tell_object(caster,"%^GREEN%^A queasy feeling runs through you, leaving you feeling weakened.%^RESET%^");
        bonus = -1;
      }
      else tell_object(caster,"%^MAGENTA%^A faint warmth tingles through your body, infusing you with energy.%^RESET%^");
    }
    else {
	if(target == caster) {
        tell_room(place,"%^YELLOW%^A holy radiance surrounds"+
		    " "+caster->QCN+"'s for a moment.",target);
        tell_object(target, "%^YELLOW%^You feel a holy radiance surround "+
		    "you for a moment, before it sinks into your skin.");
      }
      else {
	    tell_object(caster,"%^BOLD%^You call on "+capitalize((string)caster->query_diety())+"'s aid and bless "
            ""+target->QCN+".");
    	tell_object(target,"%^BOLD%^"+caster->QCN+" calls to "+caster->QP+" diety for aid, blessing you.");
    	tell_room(place,"%^BOLD%^"+caster->QCN+" calls to "+caster->QP+" diety for aid, blessing "
            ""+target->QCN+".",({caster,target}));
      }
    }
    target->add_damage_bonus(bonus);
    target->add_attack_bonus(bonus);
    target->set_property("spelled",({TO}));
    target->set_property("blessed",1);
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    if(prof != -100) addSpellToCaster();
    spell_successful();
}

void dest_effect() {
    if(objectp(target)) {
      if((string)TO->query_spell_type() == "potion") {
        if(bonus < 0) tell_object(caster,"%^GREEN%^The queasy feeling finally fades away.%^RESET%^");
        else tell_object(caster,"%^MAGENTA%^The warmth fades from your skin.%^RESET%^");
      }
      else tell_object(target,"%^ORANGE%^You can feel the blessing you have been granted fade away.");
      target->add_damage_bonus(-1*bonus);
      target->add_attack_bonus(-1*bonus);
      target->remove_property("blessed");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
