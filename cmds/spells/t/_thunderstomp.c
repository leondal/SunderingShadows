/*
  _thunderstomp.c

  reskin of stomp from psywarrior

  -- Tlaloc --
*/

#include <spell.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("thunderstomp");
    set_spell_level(([ "ranger" : 1, "druid" : 1, "mage" : 1, "magus" : 1, "cleric" : 1 ]));
    set_domains("storms");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS thunderstomp");
    set_description("Upon casting this spell, the caster "
       "releases a stream of magical energy to empower a stomp, creating a "
       "ripple in the earth. The resulting quake may stun or damage "
       "all those in the area, save the caster.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    splash_spell(3);
    //debug_saves(1);
}

void spell_effect(int prof)
{
    object *mytargs;
    int i,mylevel,damage, x;
    if (!objectp(caster)) {
      dest_effect();
      return;
    }

    mylevel = clevel;

    mytargs = target_selector();
    mytargs -= ({caster});

    if (!sizeof(mytargs)) {
        tell_object(caster,"%^BOLD%^The spell fizzles and fades for lack of a target.\n");
        dest_effect();
        return;
    }
    tell_object(caster, "%^BOLD%^%^CYAN%^You stomp the ground, releasing a stream of energy!%^RESET%^");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" stomps the ground, "
       "and you feel a pulse of energy!%^RESET%^",caster);
    for(i=0;i<sizeof(mytargs);i++){
       if(!do_save(mytargs[i])){
          if(!objectp(mytargs[i])) continue;
          if(!present(mytargs[i],environment(caster))) continue;
          tell_object(mytargs[i],"%^RESET%^%^CYAN%^Debris rises from the earth, striking you!%^RESET%^");
          tell_room(environment(mytargs[i]),"%^RESET%^%^CYAN%^"+mytargs[i]->QCN+" is hit by flying debris!%^RESET%^",mytargs[i]);
          damage_targ(mytargs[i],"torso",sdamage,"untyped");
       }
       if(!do_save(mytargs[i])){
          if(!objectp(mytargs[i])) continue;
          if(!present(mytargs[i],environment(caster))) continue;
          tell_object(mytargs[i],"%^BOLD%^%^CYAN%^You lose your footing and fall to the ground!%^RESET%^");
          tell_room(environment(mytargs[i]),"%^BOLD%^%^CYAN%^"+mytargs[i]->QCN+" falls to the ground!%^RESET%^",mytargs[i]);
          mytargs[i]->set_tripped(roll_dice(1,2),"%^BOLD%^You are struggling to regain your footing!%^RESET%^",4);
        }
   }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) { TO->remove(); }
}
