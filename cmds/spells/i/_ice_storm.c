//Ice Storm coded by Bane//
//removed from druids for balance after discussion with Ts and players ~Circe~ 8/5/13
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int i, j, time, profs, flag;
object env, *foes;
string target_limb, element;

void create() {
    ::create();
    set_spell_name("ice storm");
    set_spell_level(([ "mage" : 4, "druid" : 4, "oracle" : 4, "magus" : 4, "cleric" : 4 ]));
    set_mystery( ({ "apocalypse", "winter", "waves" }) );
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS ice storm");
    set_domains(({"cold"}));
    set_description("When the ice storm spell is cast, the mage summons storm clouds above that rain hail and ice down "
"upon anything in the area.  The spell will not damage the caster and lasts for a number of rounds equal to the caster's "
"level. A versatile arcanist can manipulate the base element of this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([
      "mage" : ([ "pinch of special dust" : 1, "water" : 3, ]),
    ]));
    set_immunities( ({"cold"}) );
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^CYAN%^(scoured by sheets of ice)%^RESET%^");
}

int preSpell() {
    element = (string)caster->query("elementalist");
    switch(element) {
      case "acid": set_immunities(({"acid"})); set_aoe_message("%^BOLD%^%^GREEN%^(scoured by a storm of acid)%^RESET%^"); break;
      case "electricity": set_immunities(({"electricity"})); set_aoe_message("%^YELLOW%^(scoured by streaks of lightning)%^RESET%^"); break;
      case "fire": set_immunities(({"fire"})); set_aoe_message("%^BOLD%^%^RED%^(scoured by a rain of fire)%^RESET%^"); break;
      case "sonic": set_immunities(({"sonic"})); set_aoe_message("%^BOLD%^%^MAGENTA%^(scoured by reverberating echoes)%^RESET%^"); break;
      default: element = "cold"; break;
    }
    return 1;
}

void spell_effect(int prof) {
    string colorings;

    profs = prof;

    switch(element) {
      case "acid": colorings = "%^GREEN%^"; break;
      case "electricity": colorings = "%^BOLD%^%^BLACK%^"; break;
      case "fire": colorings = "%^RED%^"; break;
      case "sonic": colorings = "%^CYAN%^"; break;
      default: colorings = "%^BOLD%^%^BLUE%^"; break;
    }

    tell_object(caster,""+colorings+"You wave your hands around summoning the fury of the skies above!");
    tell_room(place,""+colorings+""+caster->QCN+" waves "+caster->QP+" hands around summoning the fury of the skies above!",({caster}));
    time = 0;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack() {
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
    if (time > clevel * 3) {
        dest_effect();
    }
    else {
      switch(element) {
        case "acid":
          message("info", "%^GREEN%^Fist sized globs of a%^BOLD%^c%^RESET%^%^GREEN%^i%^BOLD%^d %^RESET%^%^GREEN%^pour out of the sky %^YELLOW%^b%^GREEN%^u%^ORANGE%^r%^GREEN%^n%^ORANGE%^i%^GREEN%^n%^ORANGE%^g %^RESET%^%^GREEN%^into everything in sight!", nearbyRoom(place,2));
        break;
        case "electricity":
          message("info", "%^ORANGE%^The furious s%^BOLD%^t%^RESET%^%^ORANGE%^o%^BOLD%^r%^RESET%^%^ORANGE%^m above sends streaks of %^BOLD%^l%^WHITE%^ig%^ORANGE%^h%^WHITE%^tn%^ORANGE%^in%^WHITE%^g %^RESET%^%^ORANGE%^all around!", nearbyRoom(place,2));
        break;
        case "fire":
          message("info", "%^RED%^The clouds above %^BOLD%^burn %^RESET%^%^RED%^as %^BOLD%^f%^RESET%^%^RED%^l%^BOLD%^a%^RESET%^%^RED%^m%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g %^RESET%^%^RED%^bolts rain down, %^BOLD%^i%^RESET%^%^ORANGE%^m%^BOLD%^%^RED%^m%^RESET%^%^ORANGE%^ol%^BOLD%^%^RED%^a%^RESET%^%^ORANGE%^t%^BOLD%^%^RED%^i%^RESET%^%^ORANGE%^n%^BOLD%^%^RED%^g %^RESET%^%^RED%^the area!", nearbyRoom(place,2));
        break;
        case "sonic":
          message("info", "%^CYAN%^The storm above unleashes a %^BOLD%^%^GREEN%^p%^RESET%^%^GREEN%^a%^BOLD%^%^MAGENTA%^n%^GREEN%^d%^RED%^e%^GREEN%^m%^RESET%^%^GREEN%^o%^BOLD%^%^WHITE%^n%^MAGENTA%^i%^RESET%^%^ORANGE%^u%^BOLD%^%^GREEN%^m %^RESET%^%^CYAN%^of deadly %^BOLD%^n%^RESET%^o%^BOLD%^i%^RESET%^s%^BOLD%^%^CYAN%^e %^RESET%^%^CYAN%^and %^BOLD%^%^BLACK%^v%^MAGENTA%^i%^RESET%^b%^BOLD%^%^MAGENTA%^r%^BLACK%^a%^MAGENTA%^t%^RESET%^i%^BOLD%^%^BLACK%^o%^MAGENTA%^n%^BLACK%^s %^RESET%^%^CYAN%^that %^BOLD%^ravages %^RESET%^%^CYAN%^everything in sight!", nearbyRoom(place,2));
        break;
        default:
          message("info", "%^BOLD%^%^BLUE%^Shards of ice pour out of the sky slamming into everything in sight!", nearbyRoom(place,2));
        break;
      }

      for (i=0;i<j;i++) {
            if (!objectp(foes[i])) continue;
            if (!objectp(caster)) {
                dest_effect();
                return;
            }
            if (foes[i] == caster && caster != target) continue;
            if (interactive(foes[i]) && newbiep(foes[i])) continue;
            if(foes[i]->query_property("no detect")) continue;
//added by Circe to stop scry detectors, etc, from being hit.
            if (!present(caster,place) && caster != target) {
                dest_effect();
                return;
            }
            if(!present(foes[i],place)) continue;

            target_limb = foes[i]->return_target_limb();
            damage_targ(foes[i], target_limb, sdamage,element);
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
    if(objectp(place)) tell_room(place,"%^BOLD%^%^BLACK%^The storm overhead breaks apart and the clouds dissipate.");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
