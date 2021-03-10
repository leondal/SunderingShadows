#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int mybonus, feattracker;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("cunning insight");
    set_spell_level(([ "warlock" : 4 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS cunning insight");
    set_description("By means of this potent invocation, the warlock imbues his body with "
"power, thereby expanding his awareness and ability to resist and react to outside forces. "
"This results in an improved command of physical combat and weapon handling, as well as a "
"better aptitude at avoiding attacks. This invocation does not work alongside similarly "
"powerful melee spells, such as rage, dance of a thousand cuts, or transformation.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell() {
   if((int)caster->query_property("raged") || (int)caster->query_property("transformed") || (int)caster->query_property("dance-of-cuts")){
      tell_object(caster,"You are already subject to similar magic!");
      return 0;
   }
   return 1;
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^%^WHITE%^You press your palms together and focus your power.%^RESET%^");
    tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" presses "+caster->QP+" palms together and focusses.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    tell_object(caster,"%^YELLOW%^Your magic filters through your body and into your immediate surroundings, enhancing your s%^BOLD%^%^GREEN%^e%^BOLD%^%^CYAN%^n%^YELLOW%^s%^BOLD%^%^GREEN%^e%^YELLOW%^s and re%^BOLD%^%^WHITE%^a%^YELLOW%^ct%^RESET%^%^ORANGE%^i%^YELLOW%^ons.%^RESET%^");
    tell_room(place,"%^YELLOW%^"+caster->QCN+"'s motions grow more assured, mirroring the co%^BOLD%^%^GREEN%^n%^BOLD%^%^CYAN%^f%^YELLOW%^i%^BOLD%^%^WHITE%^d%^YELLOW%^en%^BOLD%^%^GREEN%^c%^YELLOW%^e that now shows upon "+caster->QP+" visage.%^RESET%^",caster);
    mybonus = (clevel+9)/10; // +1 per 10 level bracket
    if(mybonus > 4) mybonus = 4;
    caster->add_ac_bonus(mybonus);
    caster->set_property("dance-of-cuts",1); // picking up this same prop from bards in /daemon/bonus_d; it grants fighter BAB/attacks without blocking spellcasting.
    if(member_array("martial weapon proficiency",(string*)caster->query_temporary_feats()) == -1) {
      caster->add_temporary_feat("martial weapon proficiency");
      feattracker = 1;
    }
    spell_successful();
    addSpellToCaster();
}

void dest_effect() {
    if(objectp(caster)){
      tell_object(caster,"%^ORANGE%^The invocation ends, and feeling normal again feels surprisingly %^RED%^d%^ORANGE%^u%^RED%^ll %^ORANGE%^by comparison.%^RESET%^",caster);
      caster->add_ac_bonus((-1)*mybonus);
      caster->set_property("dance-of-cuts",-1);
      if(feattracker == 1) caster->remove_temporary_feat("martial weapon proficiency");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
