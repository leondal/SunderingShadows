// lowlevel illusion school specialty spell. Nienne, 08/09.
#include <priest.h>
inherit SPELL;

#define ALIGNS ({"lawful good","neutral good","chaotic good","lawful neutral","true neutral","chaotic neutral","lawful evil","neutral evil","chaotic evil"})

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("misdirection");
    set_spell_level(([ "mage" : 2, "bard" : 2, "assassin" : 3 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS misdirection on ALIGNMENT");
    set_description("This spell allows a skilled illusionist to weave an aura of misdirection around them, preventing the "
"use of alignment discerning spells and abilities upon them. They can appear to be any alignment of their choosing. There "
"are, naturally, ways to bypass this spell's protection, but it offers a degree of deception unavailable to most wizards."
"\n\nThe choices for alignment are lawful good, neutral good, chaotic good, lawful neutral, true neutral, chaotic neutral"
", lawful evil, neutral evil, or chaotic evil.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_silent_casting(1);
    set_helpful_spell(1);
}

int preSpell(){
   if((int)CASTER->query_property("hidden alignment")){
      tell_object(CASTER,"You are already have an alignment altering affect.");
      return 0;
   }
   return 1;
}

void spell_effect(int prof) {
    int newal;
    string arg;
    if (!ARG) {
       tell_object(CASTER,"That is not a valid alignment choice!");
       tell_object(CASTER,"Your choices are: lawful good, neutral "+
          "good, chaotic good, lawful neutral, true neutral, "+
          "chaotic neutral, lawful evil, neutral evil, or "+
          "chaotic evil.  Please make sure you do not capitalize "+
          "any part of your choice.");
       dest_effect();
       return;
    }
    arg = lower_case(ARG);
    if(member_array(arg,ALIGNS) == -1){
       tell_object(CASTER,"That is not a valid alignment choice!");
       tell_object(CASTER,"Your choices are: lawful good, neutral "+
          "good, chaotic good, lawful neutral, true neutral, "+
          "chaotic neutral, lawful evil, neutral evil, or "+
          "chaotic evil.  Please make sure you do not capitalize "+
          "any part of your choice.");
       dest_effect();
       return;
    }
    switch(arg){
       case "lawful good": newal = 1;
                           break;
       case "neutral good": newal = 4;
                           break;
       case "chaotic good": newal = 7;
                           break;
       case "lawful neutral": newal = 2;
                           break;
       case "true neutral": newal = 5;
                           break;
       case "chaotic neutral": newal = 8;
                           break;
       case "lawful evil": newal = 3;
                           break;
       case "neutral evil": newal = 6;
                           break;
       case "chaotic evil": newal = 9;
                           break;
    }
    if((string)TO->query_spell_type() == "potion") {
      if((int)CASTER->query_property("hidden alignment")){
        tell_object(CASTER,"You are already have an alignment altering affect.");
        TO->remove();
        return;
      }
      tell_object(CASTER,"%^GREEN%^The potion settles into your stomach, and you feel a second's chill run through you.%^RESET%^");
    }
    else tell_object(CASTER,"%^MAGENTA%^You carefully weave misdirection around you, hiding your true intentions.");
    tell_object(CASTER,"%^CYAN%^Your alignment will been seen as %^BOLD%^"+arg+" %^RESET%^%^CYAN%^for a while.");
    CASTER->set_property("hidden alignment",newal);
    spell_successful();
    addSpellToCaster();
}

void dest_effect(){
    if(objectp(CASTER)) CASTER->remove_property("hidden alignment");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
