#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("timestop");
    set_spell_level(([ "mage" : 9, "bard" : 6, "oracle":9, "psion" : 9 ]));
    set_domains("trickery");
    set_discipline("nomad");
    set_mystery("lore");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS timestop");
    set_description("This spell allows the transmuter to alter their immediate surroundings into a state of such forced "
"suspension that it would seem that time had stopped for all but the caster.  This allows them to act normally while "
"their opponents can only watch, and will drop them out of direct combat. Foes will force their way out of the spell "
"after a brief interval, while the very strongest of opponents may manage to resist the effect entirely.");
    set_verbal_comp();
    set_somatic_comp();
    set_feats_required(([ "bard" : "timeweaver" ]));
    splash_spell();
}

string query_cast_string() {
   tell_object(caster,"%^GREEN%^You spread your arms and throw back your head, as your awareness filters into the world around you.%^RESET%^");
   tell_room(place,"%^GREEN%^"+caster->QCN+" spreads "+caster->QP+" arms and throws back "+caster->QP+" head.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    object *mytargs, myparty;
    int duration, i;
    duration = (ROUND_LENGTH * roll_dice(1,4) * 8); // d4 rounds, no +1
    mytargs = target_selector();
    mytargs -= ({ caster });
    myparty = ob_party(caster);

    tell_object(caster,"%^BOLD%^%^GREEN%^As you pick up and twist the weave energies around you, wrenching your arms "
"forward, your surroundings slow almost to a complete stop!%^RESET%^");
    tell_room(place,"%^BOLD%^%^GREEN%^With a sudden forward wrench of "+caster->QCN+"'s hands, everything in the "
"surrounding area seems to freeze in place!%^RESET%^",caster);
    if(!sizeof(mytargs)) {
      tell_room(place,"%^GREEN%^The spell's energies still the very air around you, but the spell fails to affect "
"anyone.%^RESET%^");
      dest_effect();
      return;
    }
    for(i=0; i<sizeof(mytargs); i++) {
      if(mytargs[i]->query_property("no paralyze")) {
        tell_room(place,"%^BOLD%^%^CYAN%^With an incredible show of strength, "+mytargs[i]->QCN+" shakes off the "
"stasis!%^RESET%^",mytargs[i]);
        tell_object(mytargs[i],"%^BOLD%^%^CYAN%^You put all your effort into resisting the stasis, and manage to shrug "
"it off!%^RESET%^");
      }
      else {
        mytargs[i]->set_paralyzed(duration,"%^BOLD%^%^WHITE%^The world around you has slowed nearly to a stop!%^RESET%^");
        if(member_array(mytargs[i],caster->query_attackers()) != -1) {
          mytargs[i]->remove_attacker(caster);
          caster->remove_attacker(mytargs[i]);
        }
      }
    }
    spell_successful();
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
