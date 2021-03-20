#include <spell.h>
#include <daemons.h>

inherit SPELL;

void create(){
    ::create();
    set_spell_name("bolt of force");
    set_spell_level( ([ "cleric" : 6, "psion" : 6 ]) );
    set_spell_sphere("invocation_evocation");
    set_discipline("kineticist");
    set_syntax("cast CLASS bolt of force on TARGET");
    set_description("This spell produces a bolt of pure force in the form of a wave of mental energy that is projected in "
"a cone before the caster.  Any enemy caught within the blast risks taking damage from the powerful wave of mental "
"energy.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
    splash_spell(2);
}

int preSpell(){
    if(!objectp(target)){
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    return 1;
}

string query_cast_string(){
   	tell_object(caster,"%^ORANGE%^Fanning out your hands, you begin to chant.%^RESET%^");
	tell_room(place,"%^ORANGE%^Fanning out "+caster->QP+" hands, "+
		""+caster->QCN+" begins to chant.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof){
    object *attackers=({});
    int x,damage;

    if (!present(target,place)){
        tell_object(caster,"%^BOLD%^Your target is not in this area.%^RESET%^");
        dest_effect();
        return;
    }

    attackers = target_selector();
    attackers += ({ target });
    attackers = distinct_array(attackers);

    tell_object(target, "%^BOLD%^%^CYAN%^"+caster->QCN+" fans out "+
       ""+caster->QP+" hands and blasts a wave of %^WHITE%^pure "+
       "force %^CYAN%^right at you!");
    tell_object(caster, "%^BOLD%^%^CYAN%^You fan out "+
       "your hands and blast a wave of %^WHITE%^pure "+
       "force %^CYAN%^right at "+target->QCN+"!");
    tell_room(place, "%^BOLD%^%^CYAN%^"+caster->QCN+" fans out "+
       ""+caster->QP+" hands and blasts a wave of %^WHITE%^pure "+
       "force %^CYAN%^right at "+target->QCN+"!", ({caster, target}) );

    for (x=0;x < sizeof(attackers);x++){
        if(!objectp(attackers[x])) { continue; }
        if(!present(attackers[x],place)) { continue; }

        define_base_damage(0);//lazy re-roll
        damage = sdamage;
        if(!do_save(attackers[x],0)){
        //if(SAVING_D->saving_throw(attackers[x], "spell",0)){
            tell_room(place, "%^BOLD%^"+attackers[x]->QCN+" dodges the wave "+
                "of force!", attackers[x] );
            tell_object(attackers[x], "%^BOLD%^You dodge the majority of the wave "+
                "of force!");
            damage_targ(attackers[x],"torso",(damage/2),"force");
            spell_kill(attackers[x],caster);
        }
        else{
            tell_room(place, "%^BOLD%^"+attackers[x]->QCN+" is blasted by "+
                "the wave of force!", attackers[x] );
            tell_object(attackers[x], "%^BOLD%^The wave of force blasts into you!");
            damage_targ(attackers[x],"torso", damage,"force");
            spell_kill(attackers[x],caster);
        }
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
