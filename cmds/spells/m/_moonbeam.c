//Made 5th level to bring in line with the other bolt spells
//during the domain rebalancing ~Circe~ 4/24/08
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

void create(){
    ::create();
    set_spell_name("moonbeam");
    set_spell_level(([ "cleric" : 5, "oracle" : 4 ]));
    set_mystery("lunar");
    set_domains("moon");
    set_spell_sphere("combat");
    set_syntax("cast CLASS moonbeam on TARGET");
    set_description("This spell begins by the caster fanning out her hands while chanting the spell.  Bolts of moonlight "
"will fly out and do damage to the target and possibly those near him.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
    splash_spell(1);
}

int preSpell(){
    if(!objectp(target)){
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    return 1;
}

string query_cast_string(){
    tell_object(caster,"%^BOLD%^Picturing a full moon in your mind, you "+
        "call upon the cyclical energies of the celestial body.");
    tell_room(place,"%^BOLD%^"+caster->QCN+" closes "+
        ""+caster->QP+" eyes for a moment, as "+caster->QS+" begins"+
        " to focus.",caster);
	return "display";
}

spell_effect(int prof){
    object *attackers;
    int i,damage;

    if (!present(target,place)){
        tell_object(caster,"%^BOLD%^Your target is not in this area.");
        dest_effect();
        return 1;
    }
    attackers = target_selector();
    attackers += ({ target });
    attackers = distinct_array(attackers);

    if(sizeof(attackers)){
        for(i=0;i<sizeof(attackers);i++){
            define_base_damage(0);
            damage = sdamage;
            if(!objectp(attackers[i])) { continue; }
            if(attackers[i] == target){
                tell_object(target, "%^BOLD%^A bolt of shimmering moonlight streaks "+
		            "from "+caster->QCN+"'s outstretched hand and into you!");
                tell_object(caster, "%^BOLD%^Holding your hand out, you create a bolt"+
		            " of shimmering moonlight that streaks through the air and "+
		            "into "+target->QCN+"!");
                tell_room(place, "%^BOLD%^A bolt of shimmering moonlight streaks from"+
		            " "+caster->QCN+"'s hand, striking "+target->QCN+".", ({caster, target}) );
                spell_kill(attackers[i],caster);
                if(!do_save(attackers[i],0))
                    damage_targ(attackers[i],attackers[i]->return_target_limb(),damage,"divine");
                else
                    damage_targ(attackers[i],attackers[i]->return_target_limb(),damage/2,"divine");
            }
            else{
                if(!do_save(attackers[i],0)) {
                //if(!SAVING_D->saving_throw(attackers[i],"spell",0)){
                    tell_room(place,"%^BOLD%^"+attackers[i]->QCN+" is struck by "+
		                "a shimmering bolt of moonlight!",attackers[i]);
                    tell_object(attackers[i],"%^BOLD%^A bolt of moonlight rips into your flesh!");
                    damage_targ(attackers[i],attackers[i]->return_target_limb(),damage,"divine");
                    spell_kill(attackers[i],caster);
                }
                else{
                    tell_room(place, "%^BOLD%^"+attackers[i]->QCN+" turns out of"+
		                " the way of the flying moon bolt!",attackers[i]);
                    tell_object(attackers[i], "%^BOLD%^The shimmering bolt of moonlight only grazes you.");
                    damage_targ(attackers[i],attackers[i]->return_target_limb(),damage/2,"divine");
                    spell_kill(attackers[i],caster);
                }
            }
        }
    }
    spell_successful();
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
