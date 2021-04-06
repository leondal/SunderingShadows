// Top end melee bard buff. Note that it can and does stack with heroism and haste, so no longer replicates the same bonuses.
// The idea of this spell is to boost them to parity with a fighter or similar pure-melee class.
// /daemon/bonus_d picks up the spell property to give them fighter-parity BAB/attacks innately, so the spell itself only sets the
// property and attaches the AC.
#include <priest.h>
inherit SPELL;

int mybonus;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("dance of a thousand cuts");
    set_spell_level(([ "bard" : 6 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS dance of a thousand cuts");
    set_description("By way of this spell, the bard harnesses the pinnacle of their personal magnetism, and channels "
"it through a series of graceful and lethal movements during combat. Doing so serves to empower their own strikes, "
"granting them greater prowess with melee attacks. It similarly enthralls attackers, making it harder "
"for anyone to land a successful hit upon their person. This spell does not work alongside similarly powerful melee "
"spells, such as rage, dance of a thousand cuts, or cunning insight.");
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
   if((int)CASTER->query_property("raged") || (int)CASTER->query_property("transformed") || (int)caster->query_property("dance-of-cuts")){
      tell_object(caster,"You are already moving with as much grace as you can manage!");
      return 0;
   }
   return 1;
}

void spell_effect(int prof) {
    int i;
    if (!objectp(caster)) {
      dest_effect();
      return;
    }
    if (interactive(caster)) {
      tell_object(caster, "%^BOLD%^%^MAGENTA%^You draw upon an inner well of power, and channel it through your entire frame. Your movements grow swift and deadly!%^RESET%^");
      tell_room(environment(caster),"%^BOLD%^%^MAGENTA%^"+caster->QCN+"'s movements become suddenly fluid, graceful and deadly!%^RESET%^",caster);
    }
    spell_successful();
    mybonus = (clevel+9)/10; // +1 per 10 level bracket
    if(mybonus > 4) mybonus = 4;
    caster->add_ac_bonus(mybonus);
    caster->set_property("dance-of-cuts",1);
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH + 1200;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
    addSpellToCaster();
}

void dest_effect(){
    int i;

    if(objectp(caster)) {
      tell_object(caster,"%^MAGENTA%^Your graceful movements lose their precision and return to normal.%^RESET%^");
      tell_room(environment(caster),"%^CYAN%^"+caster->QCN+"'s smooth, flawless motions seem to return to normal again.%^RESET%^",caster);
      caster->add_ac_bonus((-1)*mybonus);
      caster->set_property("dance-of-cuts",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
