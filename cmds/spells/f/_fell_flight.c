#include <std.h>
#include <priest.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

string message_out,message_in,heritage,active;
int bonus;

void create(){
    ::create();
    set_spell_name("fell flight");
    set_spell_level(([ "warlock" : 2 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS fell flight");
    set_description("This spell causes the warlock to sprout a set of wings, their nature "
"dependent upon the origins of their pact. As the wings are only shaped from energy, they "
"are not powerful enough to bear the caster aloft in true flights of any length. However, "
"they allow the warlock to drift in short bursts to conserve energy when travelling, and may "
"also be used to propel the warlock with unexpected speed in combat, to land an extra attack "
"against a foe. This invocation does not work together with other flight-based spells, nor "
"similar spell buffs such as haste, rage or berserker.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell() {
    if(caster->query_property("hasted") || caster->query_property("raged")) {
      tell_object(caster,"You're already under a similar effect!");
      return 0;
    }
    if((int)caster->query_property("flying")) {
      tell_object(caster,"You're already under a similar effect!");
      return 0;
    }
    if(caster->query_in_vehicle()) {
      tell_object(caster,"You can't cast this while mounted!");
      return 0;
    }
    return 1;
}

string query_cast_string() {
    tell_object(caster,"%^RESET%^%^ORANGE%^You hunch your shoulders, feeling traces of energy run up from the ground through your feet.%^RESET%^");
    tell_room(place,"%^RESET%^%^ORANGE%^"+caster->QCN+" hunches "+caster->QP+" shoulders, "+caster->QP+" focus turning briefly inwards.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    if(caster->query_property("hasted") || caster->query_property("raged")) {
      tell_object(caster,"You're already under a similar effect!");
      TO->remove();
      return;
    }
    if((int)caster->query_property("flying")) {
      tell_object(caster,"You're already under a similar effect!");
      TO->remove();
      return;
    }
    heritage = (string)caster->query("warlock heritage");
    switch(heritage) {
      case "celestial":
        tell_room(caster,"%^RESET%^%^ORANGE%^You straighten your shoulders as radiant wings of %^YELLOW%^l%^BOLD%^%^WHITE%^i%^YELLOW%^g%^BOLD%^%^WHITE%^h%^YELLOW%^t %^RESET%^%^ORANGE%^unfurl from them!%^RESET%^");
        tell_room(place,"%^RESET%^%^ORANGE%^"+caster->QCN+" straightens "+caster->QP+" shoulders as radiant wings of %^YELLOW%^l%^BOLD%^%^WHITE%^i%^YELLOW%^g%^BOLD%^%^WHITE%^h%^YELLOW%^t %^RESET%^%^ORANGE%^unfurl from them!%^RESET%^",caster);
        caster->set_property("added short",({"%^BOLD%^%^YELLOW%^ (trailed by r%^BOLD%^%^WHITE%^a%^YELLOW%^di%^BOLD%^%^WHITE%^a%^YELLOW%^nt wings)%^RESET%^"}));
      break;
      case "fey":
        tell_room(caster,"%^RESET%^%^ORANGE%^You straighten your shoulders as gossamer wings of %^CYAN%^i%^BOLD%^%^CYAN%^r%^BOLD%^%^GREEN%^i%^RESET%^%^CYAN%^de%^BOLD%^%^MAGENTA%^s%^RESET%^%^CYAN%^ce%^YELLOW%^n%^RESET%^%^CYAN%^t %^ORANGE%^energy unfurl from them!%^RESET%^");
        tell_room(place,"%^RESET%^%^ORANGE%^"+caster->QCN+" straightens "+caster->QP+" shoulders as gossamer wings of %^CYAN%^i%^BOLD%^%^CYAN%^r%^BOLD%^%^GREEN%^i%^RESET%^%^CYAN%^de%^BOLD%^%^MAGENTA%^s%^RESET%^%^CYAN%^ce%^YELLOW%^n%^RESET%^%^CYAN%^t %^ORANGE%^energy unfurl from them!%^RESET%^",caster);
        caster->set_property("added short",({"%^BOLD%^%^CYAN%^ (trailed by i%^BOLD%^%^GREEN%^r%^BOLD%^%^CYAN%^ide%^BOLD%^%^MAGENTA%^s%^BOLD%^%^CYAN%^ce%^YELLOW%^n%^BOLD%^%^CYAN%^t wings)%^RESET%^"}));
      break;
      case "abyssal":
        tell_room(caster,"%^RESET%^%^ORANGE%^You straighten your shoulders as translucent wings of %^GREEN%^vei%^ORANGE%^n%^GREEN%^ed me%^MAGENTA%^m%^GREEN%^bra%^ORANGE%^n%^GREEN%^e %^ORANGE%^unfurl from them!%^RESET%^");
        tell_room(place,"%^RESET%^%^ORANGE%^"+caster->QCN+" straightens "+caster->QP+" shoulders as translucent wings of %^GREEN%^vei%^ORANGE%^n%^GREEN%^ed me%^MAGENTA%^m%^GREEN%^bra%^ORANGE%^n%^GREEN%^e %^ORANGE%^unfurl from them!%^RESET%^",caster);
        caster->set_property("added short",({"%^RESET%^%^GREEN%^ (trailed by me%^ORANGE%^mb%^GREEN%^ran%^MAGENTA%^o%^GREEN%^us wings)%^RESET%^"}));
      break;
	  case "astral":
        tell_room(caster,"%^RESET%^%^ORANGE%^You straighten your shoulders as %^BLUE%^t%^BOLD%^hi%^RESET%^%^BLUE%^c%^BOLD%^k writhing %^RESET%^%^BLUE%^t%^BOLD%^e%^RESET%^%^BLUE%^n%^BOLD%^ta%^RESET%^%^BLUE%^c%^BOLD%^l%^RESET%^%^BLUE%^e%^BOLD%^s %^RESET%^%^ORANGE%^erupt from them.%^RESET%^");
        tell_room(place,"%^RESET%^%^ORANGE%^"+caster->QCN+" %^RESET%^%^ORANGE%^straightes %^WHITE%^"+caster->QP+" %^RESET%^%^ORANGE%^shoulders as %^BLUE%^t%^BOLD%^hi%^RESET%^%^BLUE%^c%^BOLD%^k writhing %^RESET%^%^BLUE%^t%^BOLD%^e%^RESET%^%^BLUE%^n%^BOLD%^ta%^RESET%^%^BLUE%^c%^BOLD%^l%^RESET%^%^BLUE%^e%^BOLD%^s %^RESET%^%^ORANGE%^erupt from them.%^RESET%^",caster);
        caster->set_property("added short",({"%^RESET%^%^BLUE%^ (held aloft by %^BOLD%^writhing %^RESET%^%^BLUE%^t%^BOLD%^e%^RESET%^%^BLUE%^n%^BOLD%^ta%^RESET%^%^BLUE%^c%^BOLD%^l%^RESET%^%^BLUE%^e%^BOLD%^s%^RESET%^%^BLUE%^)%^RESET%^"}));
      break;
      case "gloom":
        tell_room(caster,"%^RESET%^%^ORANGE%^You straighten your shoulders as hazy wings of %^BOLD%^%^BLACK%^s%^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^do%^BOLD%^%^BLACK%^w %^RESET%^%^ORANGE%^unfurl from them!%^RESET%^");
        tell_room(place,"%^RESET%^%^ORANGE%^"+caster->QCN+" straightens "+caster->QP+" shoulders as hazy wings of %^BOLD%^%^BLACK%^s%^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^do%^BOLD%^%^BLACK%^w %^RESET%^%^ORANGE%^unfurl from them!%^RESET%^",caster);
        caster->set_property("added short",({"%^BOLD%^%^BLACK%^ (trailed by h%^RESET%^az%^BOLD%^%^BLACK%^y wings)%^RESET%^"}));
      break;
      case "infernal":
        tell_room(caster,"%^RESET%^%^ORANGE%^You straighten your shoulders as rippling wings of %^RED%^f%^BOLD%^%^RED%^l%^YELLOW%^a%^BOLD%^%^RED%^m%^RESET%^%^RED%^e %^ORANGE%^unfurl from them!%^RESET%^");
        tell_room(place,"%^RESET%^%^ORANGE%^"+caster->QCN+" straightens "+caster->QP+" shoulders as rippling wings of %^RED%^f%^BOLD%^%^RED%^l%^YELLOW%^a%^BOLD%^%^RED%^m%^RESET%^%^RED%^e %^ORANGE%^unfurl from them!%^RESET%^",caster);
        caster->set_property("added short",({"%^BOLD%^%^RED%^ (trailed by f%^YELLOW%^i%^BOLD%^%^WHITE%^e%^YELLOW%^r%^BOLD%^%^RED%^y wings)%^RESET%^"}));
      break;
      default:
        tell_object(caster,"Your heritage is borked! Please contact a wiz!");
        TO->remove();
        return;
      break;
    }

// flight/levitate properties
    caster->set_property("flying",1);
    caster->set_property("endurance",(clevel/10));
    message_in  = caster->query_message_in();
    message_out = caster->query_message_out();
    caster->set_property("MIN","$N drifts in.");
    caster->set_property("MOUT","$N wings lightly to the $D.");

    bonus = clevel/12+1;
    bonus = bonus>4?4:bonus;
    caster->add_ac_bonus(bonus);
    caster->add_attack_bonus(bonus);
    caster->add_damage_bonus(bonus);
    caster->set_property("hasted",1); // tracking!
    caster->set_property("spelled", ({TO}) );
    active = 1;
    spell_successful();
    addSpellToCaster();
    call_out("wings",ROUND_LENGTH);
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void wings(){
    if(!objectp(caster)) { dest_effect(); return; }
    if(sizeof(caster->query_attackers()) && !caster->query_casting()){
        if(!random(3)){
           tell_object(caster,"%^RESET%^%^ORANGE%^Your wings allow you to move with ease, striking again at your foes!");
           tell_room(environment(caster),"%^RESET%^%^ORANGE%^"+caster->QCN+"'s wings propel "+caster->QO+" forward for another attack!",caster);
        }
        caster->execute_attack();
    }
    else { // crayoning goes here for non-combat! if(random(1000) < 10) echotiem!
    }
    call_out("wings",ROUND_LENGTH);
}

void dest_effect() {

    if(find_call_out("wings") != -1) remove_call_out("wings");
    if(objectp(caster) && active) {
      caster->set_property("flying",-1);
      caster->set_property("endurance",(-1*(clevel/10)));
      caster->remove_property("MIN");
      caster->remove_property("MOUT");
      caster->add_attack_bonus(-bonus);
      caster->add_damage_bonus(-bonus);
      caster->add_ac_bonus(-bonus);
      caster->set_property("hasted",-1);

      switch(heritage) {
        case "celestial":
          caster->remove_property_value("added short",({"%^BOLD%^%^YELLOW%^ (trailed by r%^BOLD%^%^WHITE%^a%^YELLOW%^di%^BOLD%^%^WHITE%^a%^YELLOW%^nt wings)%^RESET%^"}));
        break;
        case "fey":
          caster->remove_property_value("added short",({"%^BOLD%^%^CYAN%^ (trailed by i%^BOLD%^%^GREEN%^r%^BOLD%^%^CYAN%^ide%^BOLD%^%^MAGENTA%^s%^BOLD%^%^CYAN%^ce%^YELLOW%^n%^BOLD%^%^CYAN%^t wings)%^RESET%^"}));
        break;
        case "abyssal":
          caster->remove_property_value("added short",({"%^RESET%^%^GREEN%^ (trailed by me%^ORANGE%^mb%^GREEN%^ran%^MAGENTA%^o%^GREEN%^us wings)%^RESET%^"}));
        break;
        case "astral":
          caster->remove_property_value("added short",({"%^RESET%^%^BLUE%^ (held aloft by %^BOLD%^writhing %^RESET%^%^BLUE%^t%^BOLD%^e%^RESET%^%^BLUE%^n%^BOLD%^ta%^RESET%^%^BLUE%^c%^BOLD%^l%^RESET%^%^BLUE%^e%^BOLD%^s%^RESET%^%^BLUE%^)%^RESET%^"}));
        break;
        case "gloom":
          caster->remove_property_value("added short",({"%^BOLD%^%^BLACK%^ (trailed by h%^RESET%^az%^BOLD%^%^BLACK%^y wings)%^RESET%^"}));
        break;
        case "infernal":
          caster->remove_property_value("added short",({"%^BOLD%^%^RED%^ (trailed by f%^YELLOW%^i%^BOLD%^%^WHITE%^e%^YELLOW%^r%^BOLD%^%^RED%^y wings)%^RESET%^"}));
        break;
        default:
          tell_object(caster,"Your heritage is borked! Please contact a wiz!");
        break;
      }
      tell_object(caster,"%^BOLD%^%^CYAN%^The wings ripple and quite suddenly burst, leaving only a trail of residual energy.%^RESET%^");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}

