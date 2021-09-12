#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int i, j, time, profs, flag, elemflag;
object env, *foes;
string target_limb, element, colorings;

#define MYTYPES ({ "fire", "electricity", "cold", "acid", "sonic", "random" })
#define MYCOLOR ([ "fire" : "%^RESET%^%^RED%^", "electricity" : "%^RESET%^%^ORANGE%^", "cold" : "%^RESET%^%^CYAN%^", "acid" : "%^RESET%^%^GREEN%^", "sonic" : "%^RESET%^%^MAGENTA%^" ])

void create() {
    ::create();
    set_spell_name("energy current");
    set_spell_level(([ "psion" : 5 ]));
    set_spell_sphere("psychokinesis");
    set_syntax("cast CLASS energy current as <type>");
    set_description("Upon manifesting this power, the kineticist generates a "
       "current of energy that lashes out at those around him. Feats such as "
       "perfect caster and body cognition can help ensure the psion strikes "
       "only foes. The psion must choose one of the following energy types "
       "when manifesting the power: fire, electricity, cold, acid, sonic, or "
       "random. If random is chosen, the energy type may change each round. This "
       "power functions like an AOE storm, so it does not stack with similar "
       "spells or powers.");
    set_discipline("kineticist");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_save("reflex");
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^BLACK%^(filled with crackling energy)%^RESET%^");
}

int preSpell() {
    if (!arg) {
      tell_object(caster,"You need to specify a type for this power!");
      return 0;
    }
    return 1;
}

void spell_effect(int prof) {

    profs = prof;

    if (!arg) {
      tell_object(caster,"You need to specify a type for this power!");
      dest_effect();
      return;
    }
    if(member_array(arg,MYTYPES) == -1){
       tell_object(caster,"That is not a valid type!");
       dest_effect();
       return;
    }
    element = arg;
    if(arg == "random"){
       element = MYTYPES[random(5)];
       elemflag = 1;
    }
    colorings = MYCOLOR[element];

    tell_object(caster,""+colorings+"You open your mind, detecting the miniscule "
       "currents of %^BOLD%^"+element+""+colorings+" in the air around you!%^RESET%^");
    tell_room(place,""+colorings+""+caster->QCN+"'s eyes %^BOLD%^flash"+colorings+" "
       "as you feel the air around you crackle with energy!%^RESET%^",({caster}));
    time = 0;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack() {
    int damage;
    if (!flag) {
        flag = 1;
        ::execute_attack();
        return;
    }
    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    foes = target_selector();


    j = sizeof(foes);
    if(elemflag > 0){
       if(elemflag == 1){
          elemflag++;
       }else{
          element = MYTYPES[random(5)];
          elemflag++;
       }
    }
    colorings = MYCOLOR[element];
    if (time > clevel * 3) {
        dest_effect();
    } else {
       tell_room(place,""+colorings+"Crackling bolts of %^BOLD%^"+element+" energy"+colorings+" lash out wildly, striking all those in range!%^RESET%^");

       damage = sdamage;
       //damage = roll_dice(clevel,3); //discipline-only power and 5th level, so the base damage is slightly higher than ice storm
       for (i=0;i<j;i++) {
          if (!objectp(foes[i])) continue;
          if (!objectp(caster)) {
             dest_effect();
             return;
          }
          if (foes[i] == caster) continue;
          if (interactive(foes[i]) && newbiep(foes[i])) continue;
          if(foes[i]->query_property("no detect")) continue;
//added by Circe to stop scry detectors, etc, from being hit.
          if (!present(caster,place)) {
             dest_effect();
             return;
          }
          if(!present(foes[i],place)) continue;
          if(i==0){
             damage = roll_dice(clevel,5);
//             tell_object(caster,"%^YELLOW%^First target: D5, damage = "+damage+"%^RESET%^");
          }else if(i==1){
             damage = roll_dice(clevel,4);
//             tell_object(caster,"%^YELLOW%^Second target: D4, damage = "+damage+"%^RESET%^");
          }else{
             damage = roll_dice(clevel,3);
//             tell_object(caster,"%^YELLOW%^Extra target: D3, damage = "+damage+"%^RESET%^");
          }
          target_limb = foes[i]->return_target_limb();
          if(do_save(foes[i],0)) {
             damage_targ(foes[i], target_limb, sdamage/2,element);
          }else{
             damage_targ(foes[i], target_limb, sdamage,element);
          }
      }
      time+=1;
      if (present(caster,place) && !caster->query_unconscious()) {
            environment(CASTER)->addObjectToCombatCycle(TO,1);
      }
      else {
          dest_effect();
      }
    }
}

void dest_effect() {
    if(objectp(place)) tell_room(place,"%^BOLD%^%^BLACK%^The crackling current of "
       "energy subsides, leaving raised goose bumps on your skin.%^RESET%^");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
