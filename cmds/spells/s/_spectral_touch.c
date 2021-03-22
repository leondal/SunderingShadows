//Rarely hit, so making a bolt spell like the others and
//raising to 5th level with the rebalancing of domains
//~Circe~ 4/26/08 - will do d4 and keep the stamina drain

#include <priest.h>
#include <std.h>
#include <daemons.h>

inherit SPELL;

void create(){
    ::create();
    set_spell_name("spectral touch");
    set_spell_level(([ "cleric" : 2 ]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS spectral touch on TARGET");
    set_description("This spell causes the caster's hand to glow with a blue light, infusing it with the energy of the "
"grave.  The energy in the casters hand blasts forth to strike the target, draining him of life and energy.  The beam may "
"also hit nearby targets.");
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
    splash_spell(1);
}

spell_effect(int prof){
    int damage,i;
    object *attackers;

    if(!objectp(caster) || !objectp(target)){
        dest_effect();
        return;
    }
    if(!present(target,place)){
        tell_object(caster,"Your target has left the area.");
        dest_effect();
        return;
    }
    tell_room(place,"%^BOLD%^%^CYAN%^An eerie blue glow surrounds "+
       ""+caster->QCN+"'s hand as "+caster->QS+" begins to chant.%^RESET%^",caster);
    tell_object(caster,"%^BOLD%^%^CYAN%^An eerie blue glow surrounds "+
       "your hand as you begin to chant.%^RESET%^");

    attackers = target_selector();
    attackers += ({ target });
    attackers = distinct_array(attackers);

    if(sizeof(attackers)){
        for(i=0;i<sizeof(attackers);i++){
            if(!objectp(attackers[i])) { continue; }
            define_base_damage(0);
            damage = sdamage;
            if(attackers[i] == target){
                tell_object(target,"%^BOLD%^%^BLUE%^A beam of energy "+
                   "is unleashed from "+caster->QCN+"'s glowing hand "+
                   "and shreads into you!%^RESET%^");
                tell_object(caster,"%^BOLD%^%^BLUE%^The gathered energy "+
                   "in your hand is unleashed, sending a beam shredding "+
                   "into "+target->QCN+"!%^RESET%^");
                tell_room(place,"%^BOLD%^%^BLUE%^A beam of energy is "+
                   "suddenly released from "+caster->QCN+"'s hand, "+
                   "striking "+target->QCN+"!%^RESET%^",({caster,target}));
                spell_kill(target,caster);
                if(!do_save(attackers[i],0)) {
                //if(!SAVING_D->saving_throw(attackers[i],"spell",0)){
                    damage_targ(attackers[i],attackers[i]->return_target_limb(),damage,"negative energy");
                    target->use_stamina(clevel/5);
                }else{
                    damage_targ(attackers[i],attackers[i]->return_target_limb(),damage/2,"negative energy");
                }
            }else{
                if(!do_save(attackers[i],0)) {
                //if(!SAVING_D->saving_throw(attackers[i],"spell",0)){
                    tell_room(place,"%^BOLD%^%^BLUE%^"+attackers[i]->QCN+" "+
                       "is struck by the beam of energy!%^RESET%^",attackers[i]);
                    tell_object(attackers[i],"%^BOLD%^%^BLUE%^The beam "+
                       "of energy tears into you as well!%^RESET%^");
                    damage_targ(attackers[i],attackers[i]->return_target_limb(),damage,"negative energy");
                    spell_kill(attackers[i],caster);
                }else{
                    tell_room(place,"%^BOLD%^%^BLUE%^"+attackers[i]->QCN+" "+
                       "is grazed by the beam of energy!%^RESET%^",attackers[i]);
                    tell_object(attackers[i],"%^BOLD%^%^BLUE%^The "+
                       "beam of energy grazes you!%^RESET%^");
                    damage_targ(attackers[i],attackers[i]->return_target_limb(),damage/2,"negative energy");
                    spell_kill(attackers[i],caster);
                }
            }
        }
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
