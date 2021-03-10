// help updated to reflect damage isn't maxed at level 10, last change 5/2001 *Styx* 8/2003
// Lightning Bolt
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit SPELL;

string element;
void dest_effect();

void create() {
    ::create();
    set_spell_name("lightning bolt");
    set_spell_level(([ "mage" : 3, "magus" : 3 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS lightning bolt on TARGET");
    set_description("This spell, when cast, will allow you to hurl a lightning bolt at your target.  The blazing "
"electricity will inflict 1d6 points of damage per level of the caster, subject to a maximum, reduced if they make their "
"save. A versatile arcanist can manipulate the base element of this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_components(([
      "mage" : ([ "firefly" : 1, ]),
    ]));
    set_immunities(({"electricity"}));
    set_save("reflex");
}

string query_cast_string() {
    return caster->QCN+" crushes a firefly while muttering some words.";
}

spell_effect(int prof) {
    int num;
    string target_limb;
    spell_successful();

    if (environment(caster) != environment(target)) {
        tell_object(caster,"Your target has left your range.\n");
        dest_effect();
        return;
    }
    target_limb = target->return_target_limb();

    element = (string)caster->query("elementalist");
    switch(element) {
      case "acid":
        if (interactive(caster)) {
          tell_object(caster,"%^BOLD%^%^GREEN%^You hurl your fist towards "+target->QCN+" and a bolt of acid streaks forth towards "+target->QO+".");
          tell_object(target,"%^BOLD%^%^GREEN%^A bolt of acid streaks forth from "+caster->QCN+"'s hand towards you!");
          tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" hurls "+caster->QP+" fist forth and a bolt of acid streaks out towards "+target->QCN+"!",({ caster, target}) );
        } else {
          tell_object(target,"%^BOLD%^%^GREEN%^A bolt of acid streaks towards you from "+caster->QCN+"!");
          tell_room(place,"%^BOLD%^%^GREEN%^A bolt of acid from "+caster->QCN+" streaks towards "+target->QCN+"!", target);
        }
      break;
      case "cold":
        if (interactive(caster)) {
          tell_object(caster,"%^BOLD%^%^CYAN%^You hurl your fist towards "+target->QCN+" and a bolt of ice is cast forth towards "+target->QO+".");
          tell_object(target,"%^BOLD%^%^CYAN%^A bolt of ice is cast forth from "+caster->QCN+"'s hand towards you!");
          tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" hurls "+caster->QP+" fist forth and a bolt of ice is cast out towards "+target->QCN+"!",({ caster, target}) );
        } else {
          tell_object(target,"%^BOLD%^%^CYAN%^A bolt of ice is cast towards you from "+caster->QCN+"!");
          tell_room(place,"%^BOLD%^%^CYAN%^A bolt of ice from "+caster->QCN+" is cast towards "+target->QCN+"!", target);
        }
      break;
      case "fire":
        if (interactive(caster)) {
          tell_object(caster,"%^BOLD%^%^RED%^You hurl your fist towards "+target->QCN+" and a bolt of flame races forth towards "+target->QO+".");
          tell_object(target,"%^BOLD%^%^RED%^A bolt of flame races forth from "+caster->QCN+"'s hand towards you!");
          tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+" hurls "+caster->QP+" fist forth and a bolt of flame races out towards "+target->QCN+"!",({ caster, target}) );
        } else {
          tell_object(target,"%^BOLD%^%^RED%^A bolt of flame races towards you from "+caster->QCN+"!");
          tell_room(place,"%^BOLD%^%^RED%^A bolt of flame from "+caster->QCN+" races towards "+target->QCN+"!", target);
        }
      break;
      case "sonic":
        tell_object(caster,"%^YELLOW%^%^BOLD%^%^CYAN%^A deafening %^YELLOW%^-%^RESET%^C%^BOLD%^R%^ORANGE%^A%^WHITE%^C%^RESET%^K%^YELLOW%^- %^CYAN%^p%^WHITE%^i%^CYAN%^er%^WHITE%^c%^CYAN%^es %^RESET%^%^CYAN%^the air as a d%^BOLD%^%^WHITE%^i%^BLACK%^s%^RESET%^%^CYAN%^t%^WHITE%^o%^BOLD%^r%^CYAN%^t%^RESET%^%^CYAN%^e%^BOLD%^%^WHITE%^d %^RESET%^%^CYAN%^streak of %^BOLD%^e%^RESET%^n%^CYAN%^e%^BOLD%^r%^WHITE%^g%^CYAN%^y %^RESET%^%^CYAN%^lashes out from you towards "+target->QCN+"!");
        tell_object(target,"%^CYAN%^A deafening %^YELLOW%^-%^RESET%^C%^BOLD%^R%^ORANGE%^A%^WHITE%^C%^RESET%^K%^YELLOW%^- %^CYAN%^p%^WHITE%^i%^CYAN%^er%^WHITE%^c%^CYAN%^es %^RESET%^%^CYAN%^the air as a d%^BOLD%^%^WHITE%^i%^BLACK%^s%^RESET%^%^CYAN%^t%^WHITE%^o%^BOLD%^r%^CYAN%^t%^RESET%^%^CYAN%^e%^BOLD%^%^WHITE%^d %^RESET%^%^CYAN%^streak of %^BOLD%^e%^RESET%^n%^CYAN%^e%^BOLD%^r%^WHITE%^g%^CYAN%^y %^RESET%^%^CYAN%^lashes out from "+caster->QCN+" towards you!");
        tell_room(place,"%^YELLOW%^%^BOLD%^%^CYAN%^A deafening %^YELLOW%^-%^RESET%^C%^BOLD%^R%^ORANGE%^A%^WHITE%^C%^RESET%^K%^YELLOW%^- %^CYAN%^p%^WHITE%^i%^CYAN%^er%^WHITE%^c%^CYAN%^es %^RESET%^%^CYAN%^the air as a d%^BOLD%^%^WHITE%^i%^BLACK%^s%^RESET%^%^CYAN%^t%^WHITE%^o%^BOLD%^r%^CYAN%^t%^RESET%^%^CYAN%^e%^BOLD%^%^WHITE%^d %^RESET%^%^CYAN%^streak of %^BOLD%^e%^RESET%^n%^CYAN%^e%^BOLD%^r%^WHITE%^g%^CYAN%^y %^RESET%^%^CYAN%^lashes out from "+caster->QCN+" towards "+target->QCN+"!",({ caster, target}) );
      break;
      default:
      element = "electricity";
        if (interactive(caster)) {
          tell_object(caster,"%^YELLOW%^%^BOLD%^You hurl your fist towards "+target->QCN+" and a bolt of lightning charges forth towards "+target->QO+".");
          tell_object(target,"%^YELLOW%^%^BOLD%^A bolt of lightning charges forth from "+caster->QCN+"'s hand towards you!");
          tell_room(place,"%^YELLOW%^%^BOLD%^"+caster->QCN+" hurls "+caster->QP+" fist forth and a bolt of lighting charges out towards "+target->QCN+"!",({ caster, target}) );
        } else {
          tell_object(target,"%^YELLOW%^%^BOLD%^A bolt of lightning streaks towards you from "+caster->QCN+"!");
          tell_room(place,"%^YELLOW%^%^BOLD%^A bolt of lightning from "+caster->QCN+" streaks towards "+target->QCN+"!", target);
        }
      break;
    }
    if(do_save(target,0)) {
        if(evade_splash(target)) {
          dest_effect();
          return;
        }
        switch(element) {
          case "acid":
            tell_object(target,"%^GREEN%^The acidic bolt grazes your "+target_limb+".");
            tell_room(environment(caster),"%^GREEN%^The acidic bolt grazes "+target->QCN+"'s "+target_limb+".",({ target}) );
          break;
          case "cold":
            tell_object(target,"%^CYAN%^The frozen bolt grazes your "+target_limb+".");
            tell_room(environment(caster),"%^CYAN%^The frozen bolt grazes "+target->QCN+"'s "+target_limb+".",({ target}) );
          break;
          case "fire":
            tell_object(target,"%^RED%^The blazing bolt scorches your "+target_limb+".");
            tell_room(environment(caster),"%^RED%^The blazing bolt scorches "+target->QCN+"'s "+target_limb+".",({ target}) );
          break;
          case "sonic":
            tell_object(target,"%^CYAN%^The sonic bolt %^BOLD%^%^BLACK%^g%^CYAN%^r%^BLACK%^a%^CYAN%^z%^BLACK%^e%^WHITE%^s %^RESET%^%^CYAN%^your "+target_limb+"!");
            tell_room(environment(caster),"%^CYAN%^The sonic bolt %^BOLD%^%^BLACK%^g%^CYAN%^r%^BLACK%^a%^CYAN%^z%^BLACK%^e%^WHITE%^s %^RESET%^%^CYAN%^"+target->QCN+"'s "+target_limb+"!", ({ target}) );
          break;
          default:
            tell_object(target,"%^ORANGE%^The lightning bolt scorches your "+target_limb+".");
            tell_room(environment(caster),"%^ORANGE%^The lightning bolt scorches "+target->QCN+"'s "+target_limb+".",({ target}) );
          break;
        }
        damage_targ(target, target_limb, to_int(sdamage / 2), element);
    }
    else {
        switch(element) {
          case "acid":
            tell_object(target,"%^WHITE%^%^BOLD%^The acidic bolt strikes you, burning into your "+target_limb+".");
            tell_room(environment(caster),"%^WHITE%^%^BOLD%^The acidic bolt strikes "+target->QCN+", burning into "+target->QP+" "+target_limb+".", ({ target}) );
          break;
          case "cold":
            tell_object(target,"%^WHITE%^%^BOLD%^The frozen bolt strikes you, chilling your "+target_limb+".");
            tell_room(environment(caster),"%^WHITE%^%^BOLD%^The frozen bolt strikes "+target->QCN+", chilling "+target->QP+" "+target_limb+".", ({ target}) );
          break;
          case "fire":
            tell_object(target,"%^WHITE%^%^BOLD%^The blazing bolt strikes you, searing into your "+target_limb+".");
            tell_room(environment(caster),"%^WHITE%^%^BOLD%^The blazing bolt strikes "+target->QCN+", searing into "+target->QP+" "+target_limb+".", ({ target}) );
          break;
          case "sonic":
            tell_object(target,"%^CYAN%^The sonic bolt %^BOLD%^%^BLACK%^t%^CYAN%^h%^BLACK%^u%^CYAN%^n%^BLACK%^d%^WHITE%^e%^CYAN%^r%^BLACK%^s %^RESET%^%^CYAN%^into you, %^BOLD%^b%^ORANGE%^l%^WHITE%^a%^CYAN%^st%^WHITE%^i%^ORANGE%^n%^CYAN%^g %^RESET%^%^CYAN%^your "+target_limb+"!");
            tell_room(environment(caster),"%^CYAN%^The sonic bolt %^BOLD%^%^BLACK%^t%^CYAN%^h%^BLACK%^u%^CYAN%^n%^BLACK%^d%^WHITE%^e%^CYAN%^r%^BLACK%^s %^RESET%^%^CYAN%^into "+target->QCN+", %^BOLD%^b%^ORANGE%^l%^WHITE%^a%^CYAN%^st%^WHITE%^i%^ORANGE%^n%^CYAN%^g %^RESET%^%^CYAN%^"+target->QP+" "+target_limb+"!", ({ target}) );
          break;
          default:
            tell_object(target,"%^WHITE%^%^BOLD%^The lightning bolt strikes you, electrifying your "+target_limb+".");
            tell_room(environment(caster),"%^WHITE%^%^BOLD%^The lightning bolt strikes "+target->QCN+", electrifying "+target->QP+" "+target_limb+".", ({ target}) );
          break;
        }
        damage_targ(target, target_limb, sdamage, element);
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
