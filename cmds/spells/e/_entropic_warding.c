#include <spell.h>
#include <magic.h>
inherit SPELL;

int active;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("entropic warding");
    set_spell_level(([ "warlock" : 1 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS entropic warding");
    set_description("The caster invokes chaotic energies into a field around their person, "
"which makes it harder to discern their exact location. This may cause physical blows to miss "
"them entirely. The shield has the added effect of preventing any trail being left in "
"their wake, either by footfall or by scent.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell() {
    if (caster->query_property("amorpha") || caster->query_property("timeless body")) {
//together these are broken, stacking regularly 100% miss chance. N, 4/14
        tell_object(caster, "You are already protected by a spell of concealment.");
        return 0;
    }
    if (caster->query_blinking()) {
        tell_object(caster, "You can't maintain such a spell while blinking.");
        return 0;
    }
    return 1;
}

string query_cast_string() {
    tell_object(caster,"%^CYAN%^You raise both hands above your head.%^RESET%^");
    tell_room(place,"%^CYAN%^"+caster->QCN+" raises both hands above "+caster->QP+" head.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    if (caster->query_property("amorpha")) {
        tell_object(caster, "You are already protected by a spell similar to this one.");
        TO->remove();
        return;
    }

    tell_object(caster,"%^CYAN%^Twi%^GREEN%^s%^CYAN%^t%^GREEN%^in%^CYAN%^g your hands as you bring them down, you draw a field of %^BOLD%^%^GREEN%^c%^RESET%^%^CYAN%^h%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^o%^RESET%^%^GREEN%^t%^BOLD%^%^CYAN%^i%^BOLD%^%^GREEN%^c %^RESET%^%^CYAN%^e%^BOLD%^%^GREEN%^n%^YELLOW%^e%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^g%^BOLD%^%^GREEN%^y %^RESET%^%^CYAN%^around yourself.%^RESET%^");
    tell_room(place,"%^CYAN%^Twi%^GREEN%^s%^CYAN%^t%^GREEN%^in%^CYAN%^g "+caster->QP+" hands as "+caster->QS+" brings them down, "+caster->QCN+" draws a field of %^BOLD%^%^GREEN%^c%^RESET%^%^CYAN%^h%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^o%^RESET%^%^GREEN%^t%^BOLD%^%^CYAN%^i%^BOLD%^%^GREEN%^c %^RESET%^%^CYAN%^e%^BOLD%^%^GREEN%^n%^YELLOW%^e%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^g%^BOLD%^%^GREEN%^y %^RESET%^%^CYAN%^around "+caster->QO+"self.%^RESET%^",caster);

    caster->set_property("spelled", ({TO}) );
    caster->set_property("added short",({"%^RESET%^%^CYAN%^ (shielded by %^BOLD%^%^GREEN%^s%^RESET%^%^CYAN%^w%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^r%^RESET%^%^GREEN%^l%^BOLD%^%^CYAN%^i%^BOLD%^%^GREEN%^n%^RESET%^%^CYAN%^g %^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^n%^YELLOW%^e%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^g%^BOLD%^%^GREEN%^y%^RESET%^%^CYAN%^) %^RESET%^"}));
    caster->set_missChance(caster->query_missChance()+ 30); // 30% evasion
    caster->set_property("amorpha",1);
    caster->set_property("untrackable",1);
    active = 1;
    spell_successful();
    addSpellToCaster();

    spell_duration = (10 + clevel * 2 + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    int chance;
    if(objectp(caster) && active){
      tell_object(caster,"%^CYAN%^The %^BOLD%^%^CYAN%^r%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^p%^YELLOW%^p%^RESET%^%^GREEN%^l%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^n%^RESET%^%^GREEN%^g %^RESET%^%^CYAN%^field of energy around you splutters and then winks out.%^RESET%^");
      tell_room(environment(caster),"%^CYAN%^The %^BOLD%^%^CYAN%^r%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^p%^YELLOW%^p%^RESET%^%^GREEN%^l%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^n%^RESET%^%^GREEN%^g %^RESET%^%^CYAN%^field of energy around "+caster->QCN+" splutters and then winks out.%^RESET%^",caster);
      caster->remove_property_value("added short",({"%^RESET%^%^CYAN%^ (shielded by %^BOLD%^%^GREEN%^s%^RESET%^%^CYAN%^w%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^r%^RESET%^%^GREEN%^l%^BOLD%^%^CYAN%^i%^BOLD%^%^GREEN%^n%^RESET%^%^CYAN%^g %^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^n%^YELLOW%^e%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^g%^BOLD%^%^GREEN%^y%^RESET%^%^CYAN%^) %^RESET%^"}));
      chance = (int)caster->query_missChance()-30;
      caster->set_missChance(chance);
      caster->set_property("amorpha",-1);
      caster->set_property("untrackable",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
