//by ~Circe~ for psywarriors
//Because theirs is much higher level, they get more than one resistance.
//The formula matches that for Resist Energy

#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

string mytype;
int mylevel;

void create() {
    ::create();
    set_spell_name("mind over energy");
    set_spell_level(([ "psywarrior" : 6 ]));
    set_spell_sphere("psychokinesis");
    set_syntax("cast CLASS mind over energy on <type>");
    set_description("When manifesting this power, the psionic character "
       "strengthens her mental defenses against certain types of energy. "
       "The manifester must choose either fiendish (protecting her from "
       "fire, electricity, and negative energy attacks) or celestial (protecting her "
       "from cold, acid, and sonic attacks) when manifesting the power.");
    set_verbal_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell(){
    if(caster->query_property("castspellresist")){
        tell_object(caster,"%^YELLOW%^You are already under the influence of a similar spell.");
        return 0;
    }
    if(!arg){
       tell_object(caster,"You must specify fiendish or celestial when manifesting this power.");
       return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    if (!objectp(caster)){
        TO->remove();
        return;
    }
    mylevel = clevel;
    if(arg == "fiendish"){
       mytype = "fiendish";
    }else if(arg == "celestial"){
       mytype = "celestial";
    }else{
       tell_object(caster,"%^YELLOW%^The power fails because of your unfocused mind. "
          "Please specify fiendish or celestial when manifesting the power.%^RESET%^");
       dest_effect();
       return;
    }

    if (objectp(place)) place = environment(caster);
    tell_object(caster,"%^CYAN%^You draw upon your mental reserves and bolster yourself "
        "with %^BOLD%^"+mytype+" %^RESET%^%^CYAN%^energies.%^RESET%^");
    tell_room(place,"%^CYAN%^A shimmering, m%^BOLD%^u%^RESET%^%^GREEN%^l%^BOLD%^t%^RESET%^"
        "%^RED%^i%^ORANGE%^c%^YELLOW%^o%^WHITE%^l%^CYAN%^o%^BLUE%^r%^RESET%^%^GREEN%^e"
        "%^CYAN%^d shield swirls around "+caster->QCN+" before disappearing.%^RESET%^",caster);
    switch(mytype){
       case "fiendish": caster->set_resistance("fire",mylevel);
                        caster->set_resistance("electricity",mylevel);
                        caster->set_resistance("negative energy",mylevel);
                        break;
       default: caster->set_resistance("cold",mylevel);
                caster->set_resistance("acid",mylevel);
                caster->set_resistance("sonic",mylevel);
                break;
    }
    caster->set_property("castspellresist",1);
    spell_successful();
    addSpellToCaster();
}

void dest_effect(){
    if(objectp(caster)){
       switch(mytype){
          case "fiendish": caster->set_resistance("fire",-mylevel);
                           caster->set_resistance("electricity",-mylevel);
                           caster->set_resistance("negative energy",-mylevel);
                           break;
          default: caster->set_resistance("cold",-mylevel);
                   caster->set_resistance("acid",-mylevel);
                   caster->set_resistance("sonic",-mylevel);
                   break;
       }
       caster->set_property("castspellresist",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
