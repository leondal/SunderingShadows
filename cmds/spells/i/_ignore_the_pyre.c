#include <spell.h>
#include <magic.h>
inherit SPELL;

#define OKTYPES ({ "acid","cold","electricity","fire","sonic" })
string myelement;
int active;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("ignore the pyre");
    set_spell_level(([ "warlock" : 2, ]));
    set_spell_sphere("abjuration");
    set_bonus_type("resistance");
    set_syntax("cast CLASS ignore the pyre on ELEMENT");
    set_description("This invocation bestows the warlock with an innate affinity for the element of choice, which results "
"in less damage taken from any attacks of that type. Elements that can be chosen are acid, cold, electricity, fire, or sonic.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell(){
    /*
    if(caster->query_property("castspellresist")){
        tell_object(caster,"%^YELLOW%^You are already under the influence of similar spellcraft.");
        return 0;
    }
    */
    return 1;
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^%^WHITE%^You invoke a protective ward about yourself.%^RESET%^");
    tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" invokes a protective ward about "+caster->QO+"self.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    if (!objectp(caster)){
        TO->remove();
        return;
    }
    if (!ARG) {
      tell_object(caster,"%^YELLOW%^The invocation fails without your concentration on an element. Acid, cold, electricity, fire, or sonic can be resisted.%^RESET%^");
      dest_effect();
      return;
    }
  
    if (member_array(ARG,OKTYPES) == -1) {
      tell_object(caster,"%^YELLOW%^The invocation fails without your concentration on a valid element. Only acid, cold, electricity, fire, or sonic can be resisted.%^RESET%^");
      dest_effect();
      return;
    }
    switch(ARG) {
      case "acid":
        tell_object(caster,"%^BOLD%^%^WHITE%^Your skin prickles briefly with a %^RESET%^%^GREEN%^b%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^rn%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^ng %^BOLD%^%^WHITE%^sensation.%^RESET%^");
        tell_room(place,"%^BOLD%^%^WHITE%^A hiss of %^RESET%^%^GREEN%^acr%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^d sm%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^ke %^BOLD%^%^WHITE%^rises briefly from "+caster->QCN+"'s skin.%^RESET%^",caster);
      break;
      case "cold":
        tell_object(caster,"%^BOLD%^%^WHITE%^A %^BOLD%^%^CYAN%^co%^BOLD%^%^WHITE%^l%^BOLD%^%^CYAN%^d sh%^BOLD%^%^BLUE%^i%^BOLD%^%^CYAN%^ver %^BOLD%^%^WHITE%^runs across your skin.%^RESET%^");
        tell_room(place,"%^BOLD%^%^WHITE%^A %^BOLD%^%^CYAN%^co%^BOLD%^%^WHITE%^l%^BOLD%^%^CYAN%^d sh%^BOLD%^%^BLUE%^i%^BOLD%^%^CYAN%^ver %^BOLD%^%^WHITE%^runs across "+caster->QCN+"'s skin.%^RESET%^",caster);
      break;
      case "electricity":
        tell_object(caster,"%^BOLD%^%^WHITE%^A crackle of %^YELLOW%^s%^BOLD%^%^WHITE%^t%^YELLOW%^a%^RESET%^%^ORANGE%^t%^YELLOW%^ic %^BOLD%^%^WHITE%^traces across your skin.%^RESET%^");
        tell_room(place,"%^BOLD%^%^WHITE%^A crackle of %^YELLOW%^s%^BOLD%^%^WHITE%^t%^YELLOW%^a%^RESET%^%^ORANGE%^t%^YELLOW%^ic %^BOLD%^%^WHITE%^traces across "+caster->QCN+"'s skin.%^RESET%^",caster);
      break;
      case "fire":
        tell_object(caster,"%^BOLD%^%^WHITE%^A momentary %^BOLD%^%^RED%^w%^YELLOW%^a%^BOLD%^%^RED%^r%^RESET%^%^RED%^m%^ORANGE%^t%^BOLD%^%^RED%^h %^BOLD%^%^WHITE%^heats your skin.%^RESET%^");
        tell_room(place,"%^BOLD%^%^WHITE%^A momentary %^BOLD%^%^RED%^w%^YELLOW%^a%^BOLD%^%^RED%^r%^RESET%^%^RED%^m%^ORANGE%^t%^BOLD%^%^RED%^h %^BOLD%^%^WHITE%^emanates from "+caster->QCN+"'s skin.%^RESET%^",caster);
      break;
      case "sonic":
        tell_object(caster,"%^BOLD%^%^WHITE%^Your skin thrums briefly with faint %^RESET%^%^MAGENTA%^vi%^BOLD%^%^MAGENTA%^b%^RESET%^%^MAGENTA%^rat%^RED%^io%^MAGENTA%^ns%^BOLD%^%^WHITE%^.%^RESET%^");
        tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+"'s skin thrums briefly with faint %^RESET%^%^MAGENTA%^vi%^BOLD%^%^MAGENTA%^b%^RESET%^%^MAGENTA%^rat%^RED%^io%^MAGENTA%^ns%^BOLD%^%^WHITE%^.%^RESET%^",caster);
      break;
    }
    active = 1;
    caster->set_resistance(ARG,clevel);
    //caster->set_property("castspellresist",1);
    spell_successful();
    addSpellToCaster();
}

void dest_effect(){
    if(objectp(caster) && active) {
      tell_object(caster,"%^BOLD%^%^WHITE%^You feel the protective ward fade from you.%^RESET%^");
      caster->set_resistance(ARG,-1*clevel);
      //caster->set_property("castspellresist",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
