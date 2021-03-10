//Vampiric Touch
//Origionally Coded by Pearl on 1-2-96
 
#include <std.h>
#include <spell.h>
#include <magic.h>

int dam;
inherit SPELL;

void create() {
  ::create();
  set_spell_name("vampiric touch");
  set_spell_level(3);
  set_spell_type("wizard");
  set_spell_sphere("necromancy");
  set_verbal_comp();
  set_somatic_comp();
}
 
string query_cast_string() {
  return CASTER->query_cap_name()+"utters some archaic runes as "+
  CASTER->query_possessive()+" eyes glow faintly red. ";
}

void spell_effect() {
//Defines and variables...Boring stuff..ect.
  int damage;
  clevel=CLEVEL;
#define TPC    CASTER->query_cap_name()
#define TPS    CASTER->query_subjective()
#define TPR    CASTER->query_real_name()
#define TPO    CASTER->query_objective()
#define TPP    CASTER->query_possessive()
    if(clevel > 2) {
        clevel=2;
    }
    if(clevel > 4) {
        clevel=4;
    }
    if(clevel > 6) {
        clevel=6;
    }
    if(clevel > 8) {
        clevel=8;
    }
    if(clevel > 10) {
        clevel=10;
    }
    if(clevel > 12) {
        clevel=12;
    }
    dam=random(7)*clevel;  
//Welp..Here goes the actual spell! WOO! WOO!

  if((int) TARGET->query_property("undead")==1) {
    tell_object(CASTER,"%^BOLD%^%^BLACK%^"+TARGET->query_cap_name()+
"laughs uncontrollably in your face as you try to absorb life from "+
"the undead. %^RED%^"+TARGET->query_cap_name()+"attacks you due to "+
"your ignorance!%^RESET%^");
    tell_object(PLACE,TARGET->query_cap_name()+" laughs and attacks "+
CASTER->query_cap_name()+" for their ignorance!");
    tell_object(TARGET,CASTER->query_cap_name()+" foolishly attempts "+
"to attack you, an UNDEAD with Vampiric Touch. After laughing "+
"for quite awhile, you decide to attack "+CASTER->query_cap_name()+
"for their ignorance!");
   TARGET->force_me("kill "+CASTER->query_real_name());
  spell_succuess();
}
  tell_object(CASTER,"The cold touch of death enters your body and "+
"swirls around you and focuses on your hands. You reach out and "+
"touch "+TARGET->query_cap_name()+". "+TARGET->query_objective()+
"screams in pain as you feel "+TARGET->query_possessive()+" very "+
"life being drained and sucked into you.");
  tell_object(TARGET,CASTER->query_cap_name()+" reaches out and "+
"touches you. A horrid cold fill your body as you feel death grip "+
"your soul. Your very life slowly drains out and enters "+
CASTER->query_cap_name()+".");
  tell_object(PLACE,CASTER->query_cap_name()+" reaches out and "+
"touches "+TARGET->query_cap_name()+", and slowly drains the "+
"very life from "+TARGET->query_cap_name()+".");
  damage_targ(TARGET,dam);
  CASTER->add_hp(dam);
}

void dest_affect() {
  destruct(TO);
}

  

