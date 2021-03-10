// Cometfall
// Based on Moonfire - converted by ~Circe~ 4/4/08
#include <std.h>
#include <daemons.h>

inherit SPELL;

void create(){
    ::create();
    set_author("circe");
    set_spell_name("cometfall");
    set_spell_level(([ "cleric" : 7 ]));
    set_spell_sphere("combat");
    set_domains("creation");
    set_syntax("cast CLASS cometfall");
    set_description("By chanting this spell, the priest calls into being a horde of comets, blanketing a small area.  "
"Those within the area risk being knocked to the ground and seared by the molten rock.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    splash_spell(3);
}

string query_cast_string(){
	tell_object(caster,"%^ORANGE%^Calling upon your deity, you "+
         "raise your palms toward the sky.%^RESET%^");
	tell_room(place,"%^ORANGE%^"+caster->QCN+" %^RESET%^%^ORANGE%^raises "+
		""+caster->QP+" hands to the sky and chants.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof){
    object *attackers;
    int i,damage;
    attackers = target_selector();

    if(!sizeof(attackers)){
        tell_object(caster,"%^ORANGE%^A brilliant light fills the "+
           "air, but there seems to be no other effect.%^RESET%^");
        dest_effect();
        return;
    }
    tell_object(caster,"%^YELLOW%^At your command, dozens of %^RED%^"+
       "fiery %^YELLOW%^comets appear in the air over your head!%^RESET%^");
    tell_room(place,"%^YELLOW%^At "+caster->QCN+"'s command, dozens "+
       "of %^RED%^fiery%^YELLOW%^ comets appear in the air!%^RESET%^",caster);
    for(i=0;i<sizeof(attackers);i++){
        if(!objectp(attackers[i])) { continue; }
        tell_object(attackers[i],"%^BOLD%^%^RED%^The burning "+
           "%^RESET%^%^ORANGE%^rock %^BOLD%^%^RED%^of the comets "+
           "tears into your skin!%^RESET%^");
        damage = sdamage;
        if(do_save(attackers[i],0)) { damage = damage / 2; }
        //if(SAVING_D->saving_throw(attackers[i],"spell",0)) { damage = damage/2; }
        if(!do_save(attackers[i],0)) {
        //if(!SAVING_D->saving_throw(attackers[i],"petrification_polymorph",0)){
            tell_object(attackers[i],"%^BOLD%^The molten rock tears "+
               "into your flesh and knocks you to the ground!%^RESET%^");
            attackers[i]->set_tripped(roll_dice(1,3),"%^BOLD%^You are unable to stand!");
        }
        spell_kill(attackers[i],caster);
        damage_targ(attackers[i],attackers[i]->return_target_limb(),damage/2,"bludgeoning"); // half bludgeoning
        damage_targ(attackers[i],attackers[i]->return_target_limb(),damage/2,"fire"); // half fire
    }
    spell_successful();
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
