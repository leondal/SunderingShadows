#include <std.h>
#include <daemons.h>
#include <party.h>
#include <spell.h>
#include <magic.h>
#include <teleport.h>
inherit SPELL;

object endplace;
string heritage;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("walk the planes");
    set_spell_level(([ "warlock" : 4 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS walk the planes on <location>");
    set_description("This powerful invocation allows the warlock to travel along the edge of the plane with "
"which they bear affinity, using it as 'shortcut' of sorts to a known destination upon the prime. Such travel "
"will heal some of the caster's injuries along the way, given their natural bond with that particular plane. "
"Any party-mates who are with the caster at the time are considered to be willing subjects of the spell, and "
"will travel alongside the caster to his or her destination, if they are not pre-occupied with combat.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
    set_peace_needed(1);
}

string query_cast_string() {
    tell_object(caster,"%^CYAN%^With a step forward, you send out traces of your power to seek a way between the planes.%^RESET%^");
    tell_room(place,"%^CYAN%^With a step forward, "+caster->QCN+" carefully considers the area.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    string destination,a,file;
    int mypower,startpower,endpower,bonus;
    mapping tmp;

    endplace = caster->query_rem_room(arg);

    if(!endplace || catch(call_other(endplace, "???")))
    {
        tell_object(caster, "Destination invalid.");
        return;
    }

    spell_successful();

    if(!TELEPORT->object_can_be_teleported(caster,endplace,clevel))
    {
        tell_object(caster,"You sense something is wrong with your spell and it backfires.");
        damage_targ(caster, caster->return_target_limb(), sdamage / 4, "mental");
        tell_room(place,caster->QCN+" "+
                  "looks startled.",caster);
        dest_effect();

    }
    heritage = (string)caster->query("warlock heritage");

    switch(heritage) {
      case "celestial":
        tell_object(caster,"%^CYAN%^Sensing a weakness, you reach out and part reality to reveal a %^RESET%^hazy realm %^CYAN%^of %^ORANGE%^radiant light %^CYAN%^beyond.%^RESET%^");
        tell_room(place,"%^CYAN%^"+caster->QCN+" reaches out and somehow parts reality, opening a fissure in the air to revealing a %^RESET%^hazy realm %^CYAN%^of %^ORANGE%^radiant light %^CYAN%^beyond.%^RESET%^", caster);
        tell_room(endplace,"%^CYAN%^The air trembles and takes on a gentle %^ORANGE%^radiance%^CYAN%^.%^RESET%^",caster);
      break;
      case "fey":
        tell_object(caster,"%^CYAN%^Sensing a weakness, you reach out and part reality to reveal a %^RESET%^hazy realm %^CYAN%^of %^GREEN%^verdant mists %^CYAN%^beyond.%^RESET%^");
        tell_room(place,"%^CYAN%^"+caster->QCN+" reaches out and somehow parts reality, opening a fissure in the air to revealing a %^RESET%^hazy realm %^CYAN%^of %^GREEN%^verdant mists %^CYAN%^beyond.%^RESET%^", caster);
        tell_room(endplace,"%^CYAN%^The air trembles and takes on a muted %^GREEN%^glow%^CYAN%^.%^RESET%^",caster);
      break;
      case "abyssal":
        tell_object(caster,"%^CYAN%^Sensing a weakness, you reach out and part reality to reveal a %^RESET%^hazy realm %^CYAN%^of %^MAGENTA%^shifting fog %^CYAN%^beyond.%^RESET%^");
        tell_room(place,"%^CYAN%^"+caster->QCN+" reaches out and somehow parts reality, opening a fissure in the air to revealing a %^RESET%^hazy realm %^CYAN%^of %^MAGENTA%^shifting fog %^CYAN%^beyond.%^RESET%^", caster);
        tell_room(endplace,"%^CYAN%^The air trembles and wavers %^MAGENTA%^eerily%^CYAN%^.%^RESET%^",caster);
      break;
      case "gloom":
        tell_object(caster,"%^CYAN%^Sensing a weakness, you reach out and part reality to reveal a %^RESET%^hazy realm %^CYAN%^of %^BOLD%^%^BLACK%^drifting shadows %^RESET%^%^CYAN%^beyond.%^RESET%^");
        tell_room(place,"%^CYAN%^"+caster->QCN+" reaches out and somehow parts reality, opening a fissure in the air to revealing a %^RESET%^hazy realm %^CYAN%^of %^BOLD%^%^BLACK%^drifting shadows %^RESET%^%^CYAN%^beyond.%^RESET%^", caster);
        tell_room(endplace,"%^CYAN%^The air trembles and %^BOLD%^%^BLACK%^darkens %^CYAN%^perceptibly.%^RESET%^",caster);
      break;
	  case "astral":
        tell_object(caster,"%^CYAN%^Sensing a weakness, you reach out and part reality to reveal a %^RESET%^hazy realm %^CYAN%^of an %^BLUE%^endless cosmos %^CYAN%^beyond.%^RESET%^");
        tell_room(place,"%^CYAN%^"+caster->QCN+" reaches out and somehow parts reality, opening a fissure in the air to revealing a %^RESET%^hazy realm %^CYAN%^of %^BLUE%^endless cosmos %^CYAN%^beyond.%^RESET%^", caster);
        tell_room(endplace,"%^CYAN%^The air trembles amid a susurrus of %^BLUE%^whispers%^CYAN%^.%^RESET%^",caster);
      break;
      case "infernal":
        tell_object(caster,"%^CYAN%^Sensing a weakness, you reach out and part reality to reveal a %^RESET%^hazy realm %^CYAN%^of %^RED%^torrid smoke %^CYAN%^beyond.%^RESET%^");
        tell_room(place,"%^CYAN%^"+caster->QCN+" reaches out and somehow parts reality, opening a fissure in the air to revealing a %^RESET%^hazy realm %^CYAN%^of %^RED%^torrid smoke %^CYAN%^beyond.%^RESET%^", caster);
        tell_room(endplace,"%^CYAN%^The air trembles and takes on a dull %^RED%^warmth%^CYAN%^.%^RESET%^",caster);
      break;
      default:
     	  tell_object(caster,"Your pact fails to reach out to a suitable plane, and the spell fails.");
        tell_room(place,caster->QCN+" pauses and looks a little disoriented.",caster);
        TO->remove();
        return;
      break;
    }

    spell_successful();
    caster->setAdminBlock();
    call_out("move_caster", ROUND_LENGTH, endplace, prof);
}

void move_caster(object endplace, int prof) {
    object *party, *presentparty, *followers;
    int i, healed;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->removeAdminBlock();
    if (caster->query_ghost()) { dest_effect(); return; }

    if (!endplace) {
        tell_object(caster,"You pause before stepping into the rift, sensing that something strange has happened to your target location.");
        tell_room(place,caster->QCN+" apparently looks quite startled.");
        dest_effect();
        return;
    }
    if (sizeof(caster->query_attackers())) {
        tell_object(caster,"Combat distracts you from your invocation, and the rift ripples and vanishes.");
        tell_room(place,caster->QCN+" is distracted by combat, and the rift ripples and vanishes.");
        dest_effect();
        return;
    }

    presentparty = ({});
    if(caster->query_party()) { // pick up any party members that are in the room with the caster on spell activation
      party = PARTY_D->query_party_members(caster->query_party());
      if(sizeof(party)) {
        for(i=0;i<sizeof(party);i++) {
          if(environment(party[i]) == environment(caster) && party[i] != caster) {
            if(sizeof(party[i]->query_attackers())) {
              tell_object(party[i],"%^CYAN%^"+caster->QCN+" reaches out to you, but you are too busy fighting!%^RESET%^");
              tell_object(caster,"%^CYAN%^You reach out to take "+party[i]->QCN+" with you, but "+party[i]->QS+" is too busy fighting!%^RESET%^");
            }
            else presentparty += ({ party[i] });
          }
        }
      }
    }

    if(!sizeof(presentparty))
    { // teleporting alone!
      followers = caster->query_followers();
      if(sizeof(followers)) {
        for(i=0;i<sizeof(followers);i++) {
            if(!objectp(followers[i])) continue;
            presentparty += ({followers[i]});
            //followers[i]->set_following(0);
        }
      }
      //caster->clear_followers();
      tell_object(caster,"%^CYAN%^You step into the rift, and in the blink of an eye you step out again at "+endplace->query_short()+".%^RESET%^");
      tell_room(place,"%^CYAN%^"+caster->QCN+" steps into the rift, and it snaps out of existence as if it had never been!%^RESET%^", caster);
      switch(heritage) {
        case "celestial":
          tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^ORANGE%^radiant light %^CYAN%^from which "+caster->QCN+" steps. It snaps shut behind "+caster->QO+"!%^RESET%^",caster);
        break;
        case "fey":
          tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^GREEN%^verdant mists %^CYAN%^from which "+caster->QCN+" steps. It snaps shut behind "+caster->QO+"!%^RESET%^",caster);
        break;
        case "abyssal":
          tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^MAGENTA%^shifting fog %^CYAN%^from which "+caster->QCN+" steps. It snaps shut behind "+caster->QO+"!%^RESET%^",caster);
        break;
		case "astral":
          tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^BLUE%^endless cosmos %^CYAN%^from which "+caster->QCN+" steps. It snaps shut behind "+caster->QO+"!%^RESET%^",caster);
        break;
        case "gloom":
          tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^BOLD%^%^BLACK%^drifting shadows %^RESET%^%^CYAN%^from which "+caster->QCN+" steps. It snaps shut behind "+caster->QO+"!%^RESET%^",caster);
        break;
        case "infernal":
          tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^RED%^torrid smoke %^CYAN%^from which "+caster->QCN+" steps. It snaps shut behind "+caster->QO+"!%^RESET%^",caster);
        break;
        default:
          tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^from which "+caster->QCN+" steps. It snaps shut behind "+caster->QO+"!%^RESET%^",caster);
        break;
      }
      TELEPORT->teleport_object(caster,caster,endplace,clevel);
      presentparty->move(endplace);
    }
    else { // group teleport!
      tell_object(caster,"%^CYAN%^Linking hands with your allies, you step into the %^RESET%^hazy rift%^CYAN%^, and in the blink of an eye you step out again at "+endplace->query_short()+".%^RESET%^");
      for(i=0;i<sizeof(presentparty);i++) {
        tell_object(presentparty[i],"%^CYAN%^Linking hands with your allies, you step into the %^RESET%^hazy rift%^CYAN%^, and in the blink of an eye you step out again at "+endplace->query_short()+".%^RESET%^");
      }
      if(sizeof(presentparty) > 1) {
        switch(heritage) {
          case "celestial":
            tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^ORANGE%^radiant light %^CYAN%^from which "+caster->QCN+" steps, followed by several others. It snaps shut behind them!%^RESET%^",caster);
          break;
          case "fey":
            tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^GREEN%^verdant mists %^CYAN%^from which "+caster->QCN+" steps, followed by several others. It snaps shut behind them!%^RESET%^",caster);
          break;
          case "abyssal":
            tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^MAGENTA%^shifting fog %^CYAN%^from which "+caster->QCN+" steps, followed by several others. It snaps shut behind them!%^RESET%^",caster);
          break;
		  case "astral":
            tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^BLUE%^endless cosmos %^CYAN%^from which "+caster->QCN+" steps, followed by several others. It snaps shut behind them!%^RESET%^",caster);
          break;
          case "gloom":
            tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^BOLD%^%^BLACK%^drifting shadows %^RESET%^%^CYAN%^from which "+caster->QCN+" steps, followed by several others. It snaps shut behind them!%^RESET%^");
          break;
          case "infernal":
            tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^RED%^torrid smoke %^CYAN%^from which "+caster->QCN+" steps, followed by several others. It snaps shut behind them!%^RESET%^",caster);
          break;
          default:
            tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^from which "+caster->QCN+" steps, followed by several others. It snaps shut behind them!%^RESET%^",caster);
          break;
        }
      }
      else {
        switch(heritage) {
          case "celestial":
            tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^ORANGE%^radiant light %^CYAN%^from which "+caster->QCN+" steps, followed by another. It snaps shut behind them!%^RESET%^",caster);
          break;
          case "fey":
            tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^GREEN%^verdant mists %^CYAN%^from which "+caster->QCN+" steps, followed by another. It snaps shut behind them!%^RESET%^",caster);
          break;
          case "abyssal":
            tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^MAGENTA%^shifting fog %^CYAN%^from which "+caster->QCN+" steps, followed by another. It snaps shut behind them!%^RESET%^",caster);
          break;
		  case "astral":
            tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^BLUE%^endless cosmos %^CYAN%^from which "+caster->QCN+" steps, followed by another. It snaps shut behind them!%^RESET%^",caster);
          break;
          case "gloom":
            tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^BOLD%^%^BLACK%^drifting shadows %^RESET%^%^CYAN%^from which "+caster->QCN+" steps, followed by another. It snaps shut behind them!%^RESET%^");
          break;
          case "infernal":
            tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^of %^RED%^torrid smoke %^CYAN%^from which "+caster->QCN+" steps, followed by another. It snaps shut behind them!%^RESET%^",caster);
          break;
          default:
            tell_room(endplace,"%^CYAN%^A rift suddenly parts reality in the air before you, revealing a %^RESET%^hazy realm %^CYAN%^from which "+caster->QCN+" steps, followed by another. It snaps shut behind them!%^RESET%^",caster);
          break;
        }
      }
      presentparty += ({ caster }); // just to make the message work!
      tell_room(place,"%^CYAN%^"+caster->QCN+" links hands with "+caster->QP+" companions and steps into the %^RESET%^hazy rift %^CYAN%^with them, and the fissure snaps out of existence as if it had never been!%^RESET%^", presentparty);
      presentparty -= ({ caster });

      followers = caster->query_followers();
      if(sizeof(followers)) {
        presentparty += followers;
        for(i=0;i<sizeof(followers);i++) {
            if(!objectp(followers[i]))
            {
                presentparty -= ({followers[i]});
                continue;
            }
            if(member_array(followers[i],presentparty) != -1) continue;
            //followers[i]->set_following(0);
            //caster->remove_follower(followers[i]);
        }
      }
      TELEPORT->teleport_object(caster,caster,endplace,clevel); // caster should go first, followed by the rest.
      for(i=0;i<sizeof(presentparty);i++) { TELEPORT->teleport_object(caster,presentparty[i],endplace,clevel); }
    }
    if(caster->query_hp() < caster->query_max_hp()){ // the travel heals the caster if injured!
      tell_object(caster,"%^BOLD%^%^CYAN%^You feel refreshed by your brief passage across the planes!%^RESET%^");
      healed = -sdamage*5/4;
      damage_targ(caster,"torso", healed,"untyped");
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}