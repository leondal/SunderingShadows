#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

int num,effect,level,tarlevel,i,flag, mod;
string hardness,HIM,YOU,*immunities,element;
object *attackers, *inven, *hits, *ownparty;

void dest_effect();

void create() {
    ::create();
    set_spell_name("scorcher");
    set_spell_level(([ "mage" : 2, "magus" : 2, "cleric" : 2, "druid": 2 ]));
    set_domains("fire");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS scorcher on TARGET");
    set_damage_desc("fire or versatile arcanist");
    set_description("When a mage casts this ferocious spell, fire blazes out of the caster's hand towards a target, "
"burning through all in the way.  The mage will make an effort to aim at only attackers, but this is not always "
"possible. While the spell will reliably hit the primary target, a quick opponent may avoid being caught by the "
"worst of the flame's edges. A versatile arcanist can manipulate the base element of this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_immunities( ({"fire"}) );
    set_save("reflex");
}

string query_cast_string() {
    return "%^BLUE%^"+caster->QCN+"'s eyes fill with fire as "+caster->QS+" screams magical words with fury.";
}

void spell_effect(int prof) {
	object *SpellMasterySpells = ({});
	hits = ({});
    	ownparty = ({});
    	YOU = caster->QCN;
    	HIM = target->QCN;

    if(!objectp(caster)) {
        dest_effect();
        return;
    }

    if(!objectp(target) || !present(target,place))
    {
        tell_object(caster,"Your target is no longer here.");
        dest_effect();
        return;
    }

    if (caster->query_party()) ownparty=PARTY_D->query_party_members(caster->query_party());
    else ownparty = ({ caster });

    element = (string)caster->query("elementalist");
    // force-type to fire if anything outside the normal five-element subset. Since the non-interactive doesn't have a switch to fix this, it's necessary.
    if(element != "acid" && element != "cold" && element != "electricity" && element != "sonic") element = "fire";

    spell_successful();
    if (interactive(caster)) {
      switch(element) {
        case "acid":
          tell_room(place, "%^BOLD%^%^GREEN%^A stream of acid from "+YOU+"'s hand surges towards "+HIM+"!",({caster, target}) );
          tell_object(caster, "%^BOLD%^%^GREEN%^A stream of acid from your hand surges towards "+HIM+"!");
          tell_object(target, "%^BOLD%^%^GREEN%^A stream of acid from "+YOU+"'s hand surges towards you!");
        break;
        case "cold":
          tell_room(place, "%^BOLD%^%^CYAN%^A stream of frost from "+YOU+"'s hand blasts towards "+HIM+"!",({caster, target}) );
          tell_object(caster, "%^BOLD%^%^CYAN%^A stream of frost from your hand blasts towards "+HIM+"!");
          tell_object(target, "%^BOLD%^%^CYAN%^A stream of frost from "+YOU+"'s hand blasts towards you!");
        break;
        case "electricity":
          tell_room(place, "%^YELLOW%^A stream of lightning from "+YOU+"'s hand arcs towards "+HIM+"!",({caster, target}) );
          tell_object(caster, "%^YELLOW%^A stream of lightning from your hand arcs towards "+HIM+"!");
          tell_object(target, "%^YELLOW%^A stream of lightning from "+YOU+"'s hand arcs towards you!");
        break;
        case "sonic":
          tell_room(place, "%^CYAN%^A loud %^BOLD%^%^GREEN%^blast %^RESET%^%^CYAN%^of %^BOLD%^s%^ORANGE%^o%^RED%^n%^GREEN%^i%^CYAN%^c %^RESET%^%^CYAN%^energy erupts from "+YOU+" towards "+HIM+"!",({caster, target}) );
          tell_object(caster, "%^CYAN%^A loud %^BOLD%^%^GREEN%^blast %^RESET%^%^CYAN%^of %^BOLD%^s%^ORANGE%^o%^RED%^n%^GREEN%^i%^CYAN%^c %^RESET%^%^CYAN%^energy erupts from you towards "+HIM+"!");
          tell_object(target, "%^CYAN%^A loud %^BOLD%^%^GREEN%^blast %^RESET%^%^CYAN%^of %^BOLD%^s%^ORANGE%^o%^RED%^n%^GREEN%^i%^CYAN%^c %^RESET%^%^CYAN%^energy erupts from "+YOU+" towards you!");
        break;
        default:
          tell_room(place, "%^BOLD%^%^RED%^A stream of fire from "+YOU+"'s hand rams towards "+HIM+"!",({caster, target}) );
          tell_object(caster, "%^BOLD%^%^RED%^A stream of fire from your hand rams towards "+HIM+"!");
          tell_object(target, "%^BOLD%^%^RED%^A stream of fire from "+YOU+"'s hand rams towards you!");
        break;
      }
    }
    else { // no switch here, only mobs cast from non-interactive.
        tell_room(place, "%^BOLD%^%^RED%^A stream of fire from "+caster->QCN+" rams towards "+HIM+"!",({caster, target}) );
        tell_object(caster, "%^BOLD%^%^RED%^A stream of fire rams from you towards "+HIM+"!");
        tell_object(target, "%^BOLD%^%^RED%^A stream of fire from "+caster->QCN+" rams towards you!");
    }

    attackers = target_selector();
    hits = attackers;
    hits -= ({caster});
    hits -= ({ target });

    mod = clevel;
    if(mod > 10) mod = 10;
    if(mod < 1) mod = 1;
    for (i = 0;i < sizeof(hits);i++) {
        if(!objectp(hits[i])) continue;
        if(random(2)) { continue; }
        switch(element) {
          case "acid":
            tell_object(hits[i], "%^GREEN%^The acid splashes you!");
            tell_room(place, "%^GREEN%^The acid splashes "+hits[i]->QCN+"!",hits[i]);
          break;
          case "cold":
            tell_object(hits[i], "%^CYAN%^The frost chills you!");
            tell_room(place, "%^CYAN%^The frost chills "+hits[i]->QCN+"!",hits[i]);
          break;
          case "electricity":
            tell_object(hits[i], "%^ORANGE%^The static jolts through you!");
            tell_room(place, "%^ORANGE%^The static jolts through "+hits[i]->QCN+"!",hits[i]);
          break;
          case "sonic":
            tell_object(hits[i],"%^CYAN%^You are struck by the s%^BOLD%^o%^RESET%^%^CYAN%^n%^BOLD%^i%^RESET%^%^CYAN%^c w%^BOLD%^a%^RESET%^%^CYAN%^v%^BOLD%^e%^RESET%^%^CYAN%^s!");
            tell_room(place,"%^CYAN%^"+HIM+" is struck by the s%^BOLD%^o%^RESET%^%^CYAN%^n%^BOLD%^i%^RESET%^%^CYAN%^c w%^BOLD%^a%^RESET%^%^CYAN%^v%^BOLD%^e%^RESET%^%^CYAN%^s!", hits[i]);
          break;
          default:
            tell_object(hits[i], "%^RED%^The fire blazes through you!");
            tell_room(place, "%^RED%^The fire blazes through "+hits[i]->QCN+"!",hits[i]);
          break;
        }
        damage_targ(hits[i], hits[i]->return_target_limb(), sdamage,element);
    }

    if(evade_splash(target)) { dest_effect(); return; }
    switch(element) {
      case "acid":
        tell_object(target,"%^BOLD%^%^GREEN%^The searing blast strikes you, coating you in acid!");
        tell_room(place,"%^BOLD%^%^GREEN%^The searing blast strikes "+HIM+", coating "+target->QO+" in acid!", target);
      break;
      case "cold":
        tell_object(target,"%^BOLD%^%^CYAN%^The icy blast strikes you, coating you in a layer of frost!");
        tell_room(place,"%^BOLD%^%^CYAN%^The icy blast strikes "+HIM+", coating "+target->QO+" in a layer of frost!", target);
      break;
      case "electricity":
        tell_object(target,"%^YELLOW%^The crackling burst strikes you, covering you in static!");
        tell_room(place,"%^YELLOW%^The crackling burst strikes "+HIM+", covering "+target->QO+" in static!", target);
      break;
      case "sonic":
        tell_object(target,"%^CYAN%^The blast %^YELLOW%^slams %^RESET%^%^CYAN%^into you, covering you in a layer of resonating energy!");
        tell_room(place,"%^CYAN%^The blast %^YELLOW%^slams %^RESET%^%^CYAN%^ into "+HIM+", covering "+target->QO+" in a layer of resonating energy!", target);
      break;
      default:
        tell_object(target,"%^BOLD%^%^RED%^The infernal blaze burns into you, blanketing you in flames!");
        tell_room(place,"%^BOLD%^%^RED%^The infernal blaze burns into "+HIM+", blanketing "+target->QO+" in flames!", target);
      break;
    }
    damage_targ(target, target->return_target_limb(), sdamage,element);
        dest_effect();
}

void next_zap(int prof) {
    if (!caster || !objectp(caster) || !target || !objectp(target)) {
        dest_effect();
        return;
    }
    if ( !present(target,environment(caster)) ){
        dest_effect();
        return;
    }
    tell_room(place, "%^RED%^Fire sears into "+HIM+"'s skin!",target );
    tell_object(target, "%^RED%^Fire sears into your skin!");
    damage_targ(target,"torso",sdamage,element);
    dest_effect();
}

void dest_effect() {
	object *SpellMasterySpells;
    if (find_call_out("next_zap") != -1)
        remove_call_out("next_zap");
    if (target && objectp(target)) {
      switch(element) {
        case "acid":
          tell_room(place, "%^GREEN%^The acid on "+HIM+" dissipates.",target );
          tell_object(target, "%^GREEN%^The acid on you dissipates!");
        break;
        case "cold":
          tell_room(place, "%^CYAN%^The frost on "+HIM+"'s skin melts away.",target );
          tell_object(target, "%^CYAN%^The frost on your skin melts away!");
        break;
        case "electricity":
          tell_room(place, "%^ORANGE%^The static on "+HIM+" subsides.",target );
          tell_object(target, "%^ORANGE%^The static on you subsides!");
        break;
        case "sonic":
          tell_room(place, "%^CYAN%^The sonic energy surrounding "+HIM+" fades away.",target );
          tell_object(target, "%^CYAN%^The sonic energy surrounding you fades away.");
        break;
        default:
          tell_room(place, "%^RED%^The fire on "+HIM+" dies away.",target );
          tell_object(target, "%^RED%^The fire on you dies away!");
        break;
      }
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
