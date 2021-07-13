#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

#define SCRY_D "/daemon/ic_scry_locate_d"
object invisob, blocker;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("cloak of shadows");
    set_spell_level(([ "monk" : 11, "warlock" : 4 ]));
    set_spell_sphere("illusion");
    set_monk_way("way of the shadow");
    set_syntax("cast CLASS cloak of shadows on <vision|divination>");
    set_description("This invocation allows the warlock to draw a curtain of shadow energy around "
"him, concealing him from normal and magical detection attempts. It can be used in two ways, though "
"only one at a time. If cast on vision, it will generate a more powerful magical concealment than "
"standard invisibility - it does not require the same direct concentration to maintain, and so it "
"does not fail if combat is initiated. If cast on divination, it will potentially deflect magical "
"divination attempts to locate or watch the caster from a distance. If invisible, the caster can "
"simply forgo his concentration to <step> from the shadows, or with either type of casting, it can "
"simply be dispelled. Both effects can only be centred upon the caster.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

string query_cast_string() {
    tell_object(caster,"%^CYAN%^You extend your arms to either side, seeking darkness to hide within.%^RESET%^");
    tell_room(place,"%^CYAN%^"+caster->QCN+" extends "+caster->QP+" arms to either side, grasping at empty air.%^RESET%^",caster);
    return "display";
}

int preSpell() {
    if(arg != "vision" && arg != "divination") {
      tell_object(caster,"You may only cloak yourself from vision or divination.");
      return 0;
    }
    if(caster->query_property("cloak_of_shadows")) { // only one active copy of this spell at a time in any version!
      tell_object(caster,"You can only maintain that kind of spellcraft on one type of perception!");
      return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    tell_object(caster,"%^CYAN%^Your fingertips ensnare te%^RESET%^n%^CYAN%^dri%^RESET%^l%^CYAN%^s of sh%^BLUE%^a%^CYAN%^dow, and you pull them close, drawing them about you like a shroud.%^RESET%^");
    tell_room(place,"%^CYAN%^"+caster->QCN+" ensnares te%^RESET%^n%^CYAN%^dri%^RESET%^l%^CYAN%^s of sh%^BLUE%^a%^CYAN%^dow from seemingly nowhere, whisps trailing through "+caster->QP+" fingers as "+caster->QS+" draws them about "+caster->QO+"self.%^RESET%^",caster);
    call_out("targ_vanish",2);
}

void targ_vanish()
{
    int num,stat_bonus,power;
    if(arg == "vision") {
      if (caster->query_invis()) {
        tell_object(caster,"You're already invisible!");
        TO->remove();
        return;
      }
      if(caster->query_property("visible")){
        tell_object(caster,"The invocation fails utterly.");
        TO->remove();
        return;
      }
      num = clevel;
      tell_object(caster,"%^CYAN%^The shadows collapse around your form and hide you from view!%^RESET%^");
      tell_room(place,"%^CYAN%^The shadows collapse around "+caster->QCN+", and "+caster->QS+" disappears from view!%^RESET%^",caster);
      spell_successful();
      addSpellToCaster();
      invisob=new("/d/magic/obj/invisobgreater.c");
      invisob->set_property("spell",TO);
      invisob->set_property("spelled", ({TO}) );
      invisob->set_player_name(caster->query_name());
      invisob->set_mychance(num);
      invisob->move(caster);
      caster->set_property("cloak_of_shadows",1);
      return;
    }

// now scry blocking second!
    if(arg == "divination")
    {
      tell_object(caster,"%^CYAN%^The shadows collapse around your form and seep into your skin!%^RESET%^");
      tell_room(place,"%^CYAN%^The shadows collapse around "+caster->QCN+", and seep into "+caster->QP+" skin!%^RESET%^",caster);
      spell_successful();
      addSpellToCaster();
      blocker = SCRY_D->add_block_scrying(caster);
      if(!objectp(blocker)) {
        tell_object(caster,"%^BOLD%^RED%^Something is wrong that a wiz might want to look at!");
        dest_effect();
        return;
      }
      stat_bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
      power = CLEVEL + stat_bonus + random(6); // set to match scry power & other block effects
      blocker->set_block_power(power);
      caster->set_property("spelled",({TO}));
      caster->set_property("cloak_of_shadows",1);
      duration = 9 * (int)CLEVEL;
      spell_duration = duration;
      set_end_time();
      call_out("dest_effect",spell_duration);
      return;
    }
    tell_object(caster,"Something has gone wrong! Please contact a wiz!");
    TO->remove();
}

void dest_effect() {
    if(objectp(caster)) {
      caster->remove_property("cloak_of_shadows");
      if(arg == "vision") {
        tell_object(caster,"%^CYAN%^You step from a shadow into sight, trailed by remnants of d%^BLUE%^a%^CYAN%^rkn%^BLUE%^es%^CYAN%^s in your wake.%^RESET%^");
        tell_room(environment(caster),"%^CYAN%^"+caster->QCN+" steps out of a nearby shadow, trailing remnants of d%^BLUE%^a%^CYAN%^rkn%^BLUE%^es%^CYAN%^s in "+caster->QP+" wake.%^RESET%^",caster);
      }
      if(arg == "divination") {
        tell_object(caster,"%^CYAN%^Remnants of d%^BLUE%^a%^CYAN%^rkn%^BLUE%^es%^CYAN%^s finally disperse from your skin.%^RESET%^");
        tell_room(environment(caster),"%^CYAN%^Remnants of d%^BLUE%^a%^CYAN%^rkn%^BLUE%^es%^CYAN%^s finally disperse from "+caster->QCN+"'s skin.%^RESET%^",caster);
      }
    }
    if(objectp(invisob)) invisob->cancel_inv();
    if(objectp(blocker)) blocker->self_destruct();
    if(objectp(TO)) TO->remove();
    ::dest_effect();
}
