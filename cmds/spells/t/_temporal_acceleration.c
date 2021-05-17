//Psionic version of haste
#include <std.h>
#include <priest.h>
#include <party.h>
inherit SPELL;

object *affected = ({});
int reversed;

void create(){
    ::create();
    set_spell_name("temporal acceleration");
    set_spell_level(([ "psion" : 6 ]));
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS temporal acceleration");
    set_description("Like the magic spell haste, this power "
       "considerably speeds up the caster and her nearby allies. "
       "It grants all affected targets an extra attack if they are striking "
       "in melee, as well as a small bonus to AC, reflex saves "
       "and athletics. This power does not work in conjunction "
       "with similar magical effects, such as rage, berserker "
       "and fell flight.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

void spell_effect(int prof) {
    string party;
    int i,mylevel;
    object *party_base = ({}), *party_members = ({});

    if((string)TO->query_spell_type() == "potion") {
      if(caster->query_property("hasted") || caster->query_property("raged")) {
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

      tell_object(caster,"%^RESET%^%^CYAN%^You pluck at the very particles of time, "
         "granting speed to yourself and your allies!%^RESET%^");
      tell_room(place,"%^RESET%^%^GREEN%^The air around you crackles with static as time seems to shift.%^RESET%^");
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
            tell_object(party_members[i],"%^BOLD%^%^CYAN%^You feel a surge of "
               "force excite your cells, quickening your body and mind!%^RESET%^");
        }
      }
    }
    spell_successful();
    addSpellToCaster();
    mylevel = clevel;
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    int i;
    if(!sizeof(affected)) {
      ::dest_effect();
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
            else tell_object(affected[i],"%^BOLD%^%^CYAN%^As the surge of time fades from your cells, you feel almost lethargic.%^RESET%^");
          }
          affected[i]->set_property("hasted",-1);
        }
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
