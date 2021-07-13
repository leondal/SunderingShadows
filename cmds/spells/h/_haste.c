// haste - new bard spell (& transmute mage domain). N, 5/15.
#include <std.h>
#include <priest.h>
#include <party.h>
inherit SPELL;

object *affected = ({});
int reversed;

void create(){
    ::create();
    set_spell_name("haste");
    set_spell_level(([ "mage" : 3, "bard" : 3, "assassin":3, "magus" : 3 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS haste");
    set_bonus_type("dodge");
    set_damage_desc("1 attack bonus, 1 AC, 1 reflex, 2 athletics");
    set_description("This spell considerably speeds up the caster, and those allies in his or "
"her immediate vicinity. It grants all affected targets an extra attack if they are striking "
"in melee, as well as a small bonus to AC, reflex saves and athletics. This spell does not work "
"in conjunction with similar magical effects, such as rage, berserker and fell flight.");
    set_verbal_comp();
    set_somatic_comp();
     // school specific mage spell
    set_helpful_spell(1);
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^%^CYAN%^You make an abrupt motion with a flick of your fingers.%^RESET%^");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" makes a quick motion with a flick of "+caster->QP+" fingers.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    string party;
    int i;
    object *party_base = ({}), *party_members = ({});

    if((string)TO->query_spell_type() == "potion") {
      if(caster->query_property("hasted") || caster->query_property("raged") || caster->query_property("prescienced")) {
        tell_object(caster,"You're already under such an effect!");
        TO->remove();
        return;
      }
      if(prof == -100) {
        reversed = 1;
        tell_object(caster,"%^CYAN%^As the potion warms your stomach, you feel a shudder of lethargy run through your body.%^RESET%^");
        caster->set_property("fighter_attacks_mod",-1); // extra attack!
        caster->add_attack_bonus(-1); // +1 BAB!
        caster->add_ac_bonus(-1); // +1 dodge to AC!
        caster->add_saving_bonus("reflex",-1); // +1 reflex save!
        caster->add_skill_bonus("athletics",-2); // +2 athletics skill!
      }
      else {
        tell_object(caster,"%^CYAN%^As the potion warms your stomach, you feel a quiver of energy ripple through your body.%^RESET%^");
        caster->set_property("fighter_attacks_mod",1); // extra attack!
        caster->add_attack_bonus(1); // +1 BAB!
        caster->add_ac_bonus(1); // +1 dodge to AC!
        caster->add_saving_bonus("reflex",1); // +1 reflex save!
        caster->add_skill_bonus("athletics",2); // +2 athletics skill!
      }
      caster->set_property("hasted",1); // tracking!
      affected = ({ caster });
    }
    else {
      party = (string)caster->query_party();
      if(party) party_base = (object *)PARTY_OB->query_party_members(party);
      else party_base = ({ caster });
      party_members = distinct_array(party_base);

      tell_room(place,"%^BOLD%^%^YELLOW%^A quiver of energy ripples through the air around you.");
      if(sizeof(party_members)) {
        for(i=0;i<sizeof(party_members);i++) {
            if(!objectp(party_members[i])) continue;
            if(!present(party_members[i],place)) continue;
            if(party_members[i]->query_property("hasted")) continue;
            if(party_members[i]->query_property("raged")) continue;
            affected += ({ party_members[i] });
            party_members[i]->set_property("fighter_attacks_mod",1); // extra attack!
            party_members[i]->add_attack_bonus(1); // +1 BAB!
            party_members[i]->add_ac_bonus(1); // +1 dodge to AC!
            party_members[i]->add_saving_bonus("reflex",1); // +1 reflex save!
            party_members[i]->add_skill_bonus("athletics",2); // +2 athletics skill!
            party_members[i]->set_property("hasted",1); // tracking!
            tell_object(party_members[i],"%^BOLD%^%^CYAN%^As the energy passes through you, you "
"feel your body resonate in response, and your movements quicken!%^RESET%^");
        }
      }
    }
    spell_successful();
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    int i;
    if(!sizeof(affected)) {
	if(objectp(TO)) TO->remove();
      return;
    }

    for(i=0;i<sizeof(affected);i++) {
        if(objectp(affected[i])) {
          if(reversed) {
            affected[i]->set_property("fighter_attacks_mod",1);
            affected[i]->add_attack_bonus(1);
            affected[i]->add_ac_bonus(1);
            affected[i]->add_saving_bonus("reflex",1);
            affected[i]->add_skill_bonus("athletics",2);
            tell_object(affected[i],"%^BOLD%^%^CYAN%^The lethargy finally lifts from you.%^RESET%^");
          }
          else {
            affected[i]->set_property("fighter_attacks_mod",-1);
            affected[i]->add_attack_bonus(-1);
            affected[i]->add_ac_bonus(-1);
            affected[i]->add_saving_bonus("reflex",-1);
            affected[i]->add_skill_bonus("athletics",-2);
            if((string)TO->query_spell_type() == "potion") tell_object(affected[i],"%^BOLD%^%^CYAN%^The potion wears off and you slow back down.%^RESET%^");
            else tell_object(affected[i],"%^BOLD%^%^CYAN%^The spell fades and you slow back down.%^RESET%^");
          }
          affected[i]->set_property("hasted",-1);
        }
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
