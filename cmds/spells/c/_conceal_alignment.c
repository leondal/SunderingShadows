// swiped from aura alteration for the priest spell, conceal alignment -Ares
//Moved to 2nd level by ~Circe~ in the rebalancing of domains
//since so many of the alignment detecting abilities have been
//removed from game 4/26/08
#include <priest.h>

inherit SPELL;

#define ALIGNS ({"lawful good","neutral good","chaotic good","lawful neutral","true neutral","chaotic neutral","lawful evil","neutral evil","chaotic evil"})

void create(){
    ::create();
    set_spell_name("conceal alignment");
    set_spell_level(([ "cleric" : 1, ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS conceal alignment on <align>");
    set_description("When this spell is cast, the caster must pick the alignment that he wishes for others to see him as"
".  This spell has a chance to fool any magical or other means of detecting the caster's true alignment.\n\nThe choices "
"for alignment are lawful good, neutral good, chaotic good, lawful neutral, true neutral, chaotic neutral, lawful evil, "
"neutral evil, or chaotic evil.  Please make sure you do not capitalize any part of your choice.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_silent_casting(1);
    set_helpful_spell(1);
}

int preSpell(){
   if((int)caster->query_property("hidden alignment")){
      tell_object(caster,"You are already have an alignment altering affect.");
      return 0;
   }
   return 1;
}

void spell_effect(int prof){
    int newal;
    string arg;
    if (!ARG){
       tell_object(caster,"That is not a valid alignment choice!");
       tell_object(caster,"Your choices are: lawful good, neutral "+
          "good, chaotic good, lawful neutral, true neutral, "+
          "chaotic neutral, lawful evil, neutral evil, or "+
          "chaotic evil.  Please make sure you do not capitalize "+
          "any part of your choice.");
       dest_effect();
       return;
    }
    arg = lower_case(ARG);
    if(member_array(arg,ALIGNS) == -1){
       tell_object(caster,"That is not a valid alignment choice!");
       tell_object(caster,"Your choices are: lawful good, neutral "+
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
    tell_object(caster,"%^CYAN%^You turn your thoughts inward, "+
       "hiding those you wish not to reveal.");
    tell_object(caster,"%^BOLD%^%^CYAN%^Your alignment will "+
       "been seen as "+arg+" for a time.");
    caster->set_property("hidden alignment",newal);
    spell_successful();
    addSpellToCaster();
}

void dest_effect(){
    if(objectp(caster)) { caster->remove_property("hidden alignment"); }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
