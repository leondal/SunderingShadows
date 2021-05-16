#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("hostile empathic transfer");
    set_spell_level(([ "psywarrior" : 3, "psion" : 3 ]));
    set_spell_sphere("telepathy");
    mental_spell();
    set_discipline("telepath");
    set_syntax("cast CLASS hostile empathic transfer");
    set_description("By manifesting this power, the psionic character is able "
       "to transfer some of his own injuries to his foes. The amount of hit "
       "points healed cannot exceed the manifester's maximum hit points. The "
       "manifester must be careful to control his mental energies in order to avoid "
       "hitting allies in the process.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
    splash_spell(3);
}

void spell_effect(int prof) {
    int damage, i, mytally, cap, mylevel;
    string target_limb;
    object *foes;

    mylevel = clevel;

    foes = target_selector();


    if (member_array(caster,foes) != -1) foes -= ({ caster });

    if(!sizeof(foes)){
       tell_object(caster,"You do not see any enemies here.");
       return;
    }

    spell_successful();

    if (interactive(caster)) {
        tell_object(caster,"%^RESET%^%^ORANGE%^You gaze at your foes intently, "
           "preparing to show them the meaning of pain!%^RESET%^");
    }

    for(i=0;i<sizeof(foes);i++){
       if(!objectp(foes[i])) continue;
       tell_object(foes[i],"%^RESET%^%^ORANGE%^"+caster->QCN+" focuses "+caster->QP+" "
          "steely gaze on you!%^RESET%^");
       define_base_damage(0);
       damage = sdamage;
       target_limb = foes[i]->return_target_limb();
       if(!do_save(foes[i],0)){
          tell_object(foes[i],"%^BOLD%^%^RED%^You shriek in pain as your "+target_limb+" "
             "suddenly feels as though it's on fire!%^RESET%^");
          tell_room(environment(caster),"%^BOLD%^%^RED%^"+foes[i]->QCN+" suddenly shrieks "
             "in pain, clutching "+foes[i]->QP+" "+target_limb+"!%^RESET%^", ({foes[i]}) );
          damage_targ(foes[i], target_limb, damage, "mental");
          mytally += damage;
       }else{
          damage = damage/2;
          tell_object(foes[i],"%^RESET%^%^RED%^You feel "+caster->QCN+"'s power assault your "
             ""+target_limb+" but manage to fight off some of its effects!%^RESET%^");
          tell_room(environment(caster),"%^RESET%^%^RED%^A look of concentration passes "
             "over "+foes[i]->QCN+"'s face as "+foes[i]->QS+" winces but fights off much of the mental assault.%^RESET%^",
             ({ foes[i]}) );
//          tell_object(caster, "Halved damage = "+damage+"."); //for testing/debugging
          damage_targ(foes[i], target_limb, damage, "mental");
          mytally += damage;
       }
    }
    cap = mylevel*2; //capping healing at 3 HP per caster level; adjusted to 2 HP per level ~Circe~ 1/11/16
//    tell_object(caster,"Running tally = "+mytally+". Cap = "+cap+"."); //for testing/debugging
    if(mytally > cap){
       mytally = cap;
//       tell_object(caster, "Healing "+mytally+" hit points.");
    }
    tell_object(caster,"%^YELLOW%^You feel a rush of healing as you "
       "siphon off energy from your foes.%^RESET%^");
    damage_targ(caster, caster->return_target_limb(), -mytally, "untyped");
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
