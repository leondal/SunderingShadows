//Slightly lowered version of fear for psywarriors, level 1 power
//~Circe~ 9/27/15

#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

void create() {
	::create();
    set_spell_name("primal fear");
    set_spell_level(([ "psywarrior" : 1 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS primal fear on TARGET");
    set_description("This power allows the psionic character to project "
                    "an aura of fear toward a target, potentially sending him fleeing "
                    "or causing him to cower in terror.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string(){
    return "%^RESET%^%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^'s eyes darken as dread emanates from "+caster->QO+".%^RESET%^";
}

void spell_effect(int prof){
     int i,j, percent, x, hits, bonus,mylevel;
     string *ids, MyType;
     object *weapons;
     if(!objectp(target)) dest_effect();
     mylevel = clevel;
     tell_object(caster,"%^RESET%^%^BLUE%^You project horrifying images directly into "+target->QCN+"'s mind.%^RESET%^");
     spell_successful();
     bonus = (int)caster->query_stats("intelligence");
     bonus = (bonus - 10) / 2;
     if(bonus < 0) bonus = 0;
     bonus = bonus*(-1);
     if(do_save(target,bonus)){
          tell_object(target, "%^RESET%^%^BLUE%^You fight back some "+
                      "horrid images psionically projected into your mind.%^RESET%^");
          tell_room(place,"%^RESET%^%^BLUE%^"+target->QCN+" grimmaces and shakes "
                    ""+target->QP+" head, fighting off the psionic attack.%^RESET%^",target);
          target->add_attacker(caster);
          dest_effect();
          return;
     }
     if (((string)target->query_race() == "half-elf" && random(100) < 15) ||
         ((string)target->query_race() == "half-drow" && random(100) < 15) ||
         ((string)target->query_race() == "beastman" && random(100) < 30) ||
         ((string)target->query_race() == "firbolg" && random(100) < 8) ||
         ((string)target->query_race() == "drow" && random(100) < 30) ||
         ((string)target->query_race() == "elf" && random(100) < 35) ||
         ((string)target->query_race() == "human" && (string)target->query("subrace") == "attayan")) {
          tell_object(target, "%^RESET%^%^BLUE%^You fight back some "+
                      "horrid images psionically projected into your mind.%^RESET%^");
          tell_room(place,"%^RESET%^%^BLUE%^"+target->QCN+" grimmaces and shakes "
                    ""+target->QP+" head, fighting off the psionic attack.%^RESET%^",target);
          target->add_attacker(caster);
          dest_effect();
          return;
     }
     if(FEATS_D->usable_feat(target, "unyielding soul")){
          tell_object(target,"%^BOLD%^%^WHITE%^You feel a spell trying to "+
                      "take hold of your mind, but such is the strength "
                      "of your soul that you manage to shake it off!%^RESET%^");
          tell_object(caster,"%^BOLD%^%^WHITE%^%^"+target->QCN+
                      " struggles momentarily, before shaking off the spell's "
                      "effects!%^RESET%^");
          target->add_attacker(caster);
          damage_targ(target, target->return_target_limb(), roll_dice(2,8),"untyped");
          dest_effect();
          return;
     }
     if(FEATS_D->usable_feat(target, "presence of mind")){
          tell_object(target,"%^BOLD%^%^WHITE%^You feel a spell trying to "+
                      "take hold of your mind, but such is your mental strength "
                      "that you manage to shake it off!%^RESET%^");
          tell_object(caster,"%^BOLD%^%^WHITE%^%^"+target->QCN+
                      " struggles momentarily, before shaking off the spell's "
                      "effects!%^RESET%^");
          target->add_attacker(caster);
          damage_targ(target, target->return_target_limb(), roll_dice(2,8),"untyped");
          dest_effect();
          return;
     }
     tell_object(target,"%^BOLD%^%^BLACK%^Images from your worst nightmares "
                 "spring to life, flooding your mind and shaking the foundation of your soul.%^RESET%^");
     tell_room(place, "%^BOLD%^%^BLACK%^Sheer horror contorts "+
               ""+target->QCN+"'s face as "+target->QS+" breaks in "+
               "fear and trembles.%^RESET%^",target);
     if(mylevel+random(10) > (int)target->query_highest_level()+random(10)){
          tell_object(target,"%^BOLD%^%^BLUE%^Unable to contain "+
                      "your terror, you cower before "+caster->QCN+"!%^RESET%^");
          tell_room(environment(target),"%^BOLD%^%^BLUE%^"+
                    ""+target->QCN+" cowers in terror!%^RESET%^",target);
          weapons = target->query_wielded();
          if (sizeof(weapons) && !target->query_property("no disarm")){
               tell_object(target,"%^CYAN%^You lose your grip on your weapons!%^RESET%^");
               tell_room(environment(target),"%^CYAN%^"+target->QCN+" drops "+target->QP+" "+
                         "weapons!%^RESET%^",target);
               for (x=0;x<sizeof(weapons);x++){
                    ids = weapons[x]->query_id();
                    if((int)weapons[x]->query_property("enchantment") < 0) continue;
                    target->force_me("unwield "+ids[0]+"");
                    target->remove_property("disarm time");
                    target->set_property("disarm time", time() + (ROUND_LENGTH * roll_dice(1, 4)));
               }
          }
          target->set_paralyzed((15+random(20)),"You cannot contain your fear to do that!");
     }else{
          tell_object(target,"%^BOLD%^You flee from "+caster->QCN+" "+
                      "before controlling yourself!%^RESET%^");
          tell_room(place,"%^BOLD%^"+target->QCN+" flees in fright!%^RESET%^",target);
          target->run_away();
     }
     dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
