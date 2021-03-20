//Unholy Orb based on Holy Orb
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

string query_cast_string(){
   tell_object(caster,"%^BOLD%^%^BLACK%^You begin to chant fervently as "+
      "you gather negative energy in your hands.");
   tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" chants fervently as "+
      ""+caster->QS+" begins to gather a pitch black energy "+
      "in "+caster->QP+" hands.",caster);
   return "display";
}

void create(){
    ::create();
    set_spell_name("unholy orb");
    set_spell_level(([ "cleric" : 6 ]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS unholy orb");
    set_description("The orb is a spell normally prepared by a priest who expects to encounter enemies whose alignment "
"opposes her own.  When cast, the spell streaks from the caster's hand to the desired point of effect, where a sphere "
"forms.  The sphere drains the essence of life from the targets in the area of effect.  The sphere does damage based on "
"the alignment of the caster with respect to the target.\n\nNOTE: This spell will damage all attackers regardless of "
"alignment, but the damage will very if the attackers are players based on each individual's alignment.  The damage done "
"to mobs is consistent no matter the mob's alignment.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(2);
    set_save("reflex");
}

void spell_effect(int prof){
    int damage;
    int i,j;
    object limb;
    object *foes;
    object *party;

    foes = target_selector();

   if(caster->query_party()){
      party =  PARTY_D->query_party_members(caster->query_party());
   }else{
      party = ({caster});
   }
   j = sizeof(foes);

   tell_room(place,"%^BOLD%^%^GREEN%^A sphere of %^BLACK%^dark "+
      "%^GREEN%^power radiates out from "+CASTER->QCN+"'s "+
      "hands!%^RESET%^",CASTER);
   tell_object(CASTER,"%^BOLD%^%^GREEN%^A sphere of %^BLACK%^"+
      "dark%^GREEN%^ power radiates out from your hands.%^RESET%^");

   for(i=0;i<j;i++){
      if(!objectp(foes[i])) continue;
      if(foes[i] == caster) continue;
      if (member_array(foes[i],party) != -1) continue;
      if (interactive(foes[i]) && foes[i]->query_level() < 6) continue;
      limb = foes[i]->return_target_limb();
      damage = sdamage;
      if(!interactive(foes[i])){
//Added to always do damage to mobs per conversations with Ares
//~Circe~ 5/12/08
         tell_object(CASTER,"%^BOLD%^%^BLACK%^The power from "+
            "your sphere %^GREEN%^glows%^BLACK%^ with a green "+
            "aura as it engulfs "+foes[i]->QCN+".%^RESET%^");
         tell_room(place,"%^BOLD%^%^BLACK%^The power from "+CASTER->QCN+"'s "+
            "sphere %^GREEN%^glows%^BLACK%^ with a green aura as it "+
            "engulfs "+foes[i]->QCN+".%^RESET%^",({foes[i],CASTER}));
         if(!do_save(foes[i],-2)) {
            damage_targ(foes[i],limb,damage,"divine");
         }else{
            damage_targ(foes[i],limb,damage/2,"divine");
         }
      }else{
         if(ALIGN->is_good(foes[i])){
            tell_object(foes[i],"%^BOLD%^%^BLACK%^The power from "+
               ""+CASTER->QCN+"'s sphere %^GREEN%^glows%^BLACK%^ "+
               "with a green aura as it engulfs you.%^RESET%^");
            tell_object(CASTER,"%^BOLD%^%^BLACK%^The power from "+
               "your sphere %^GREEN%^glows%^BLACK%^ with a green "+
               "aura as it engulfs "+foes[i]->QCN+".%^RESET%^");
            tell_room(place,"%^BOLD%^%^BLACK%^The power from "+CASTER->QCN+"'s "+
               "sphere %^GREEN%^glows%^BLACK%^ with a green aura as it "+
               "engulfs "+foes[i]->QCN+".%^RESET%^",({foes[i],CASTER}));
            if(!do_save(foes[i],-2)){
               damage_targ(foes[i],limb,damage,"divine");
            }else{
               damage_targ(foes[i],limb,damage/2,"divine");
            }
         }else if(ALIGN->is_neutral(foes[i])){
            tell_object(foes[i],"%^BOLD%^%^BLACK%^The power from "+
               ""+CASTER->QCN+"'s sphere %^GREEN%^glows %^BLACK%^"+
               "as it engulfs you.%^RESET%^");
            tell_object(CASTER,"%^BOLD%^%^BLACK%^The power from "+
               "your sphere %^GREEN%^glows%^BLACK%^ as it engulfs "+
               ""+foes[i]->QCN+".%^RESET%^");
            tell_room(place,"%^BOLD%^%^BLACK%^The power from "+
               ""+CASTER->QCN+"'s sphere %^GREEN%^glows%^BLACK%^ "+
               "as it engulfs "+foes[i]->QCN+".%^RESET%^",({foes[i],CASTER}));
            if(!do_save(foes[i])){
               damage_targ(foes[i],limb,damage,"divine");
            }else{
               damage_targ(foes[i],limb,damage/2,"divine");
            }
         }else if(ALIGN->is_evil(foes[i])){
           	tell_object(foes[i],"%^BOLD%^%^BLACK%^The power from "+
               ""+CASTER->QCN+"'s sphere %^GREEN%^flickers%^BLACK%^ "+
               "as it strikes you.%^RESET%^");
            tell_object(CASTER,"%^BOLD%^%^BLACK%^The power from "+
               "your sphere %^GREEN%^flickers%^BLACK%^ as it "+
               "strikes "+foes[i]->QCN+".%^RESET%^");
            tell_room(place,"%^BOLD%^%^BLACK%^The power from "+
               ""+CASTER->QCN+"'s sphere %^GREEN%^flickers%^BLACK%^ "+
               "as it strikes "+foes[i]->QCN+".%^RESET%^",({foes[i],CASTER}));
            define_base_damage(0);
            damage = sdamage;
            if(damage>0){
               if(!do_save(foes[i],2)){
                  damage_targ(foes[i],limb,damage,"divine");
               }else{
                  damage_targ(foes[i],limb,damage/2,"divine");
               }
            }
         }
      }
   }
   dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
