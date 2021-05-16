#include <priest.h>
#include <magic.h>
inherit SPELL;

int mybonus;

void create() {
    ::create();
    set_author("circe");
    set_spell_name("chameleon skin");
    set_spell_sphere("psychometabolism");
    set_spell_level(([ "psywarrior" : 1 ]));
    set_syntax("cast CLASS chameleon skin");
    set_description("When the psychic character manifests this power, "
       "he harnesses the power of the chameleon, granting him the "
       "ability to blend into his surroundings. This power functions "
       "as a bonus to your ability to hide and sneak, rather than true invisibility.");
    set_verbal_comp();
    set_somatic_comp();
}

int preSpell(){
   if((int)CASTER->query_property("chameleoned")){
      tell_object(CASTER,"You are already under the influence of such a spell.");
      return 0;
   }
   return 1;
}

string query_cast_string() {
    return "%^BOLD%^%^WHITE%^"+caster->QCN+"'s pupils widen and then narrow to points.%^RESET%^";
}

void spell_effect(int prof) {
    int i, mylevel, duration;
    if (!objectp(caster)) {
      dest_effect();
      return;
    }
    duration = (ROUND_LENGTH * 10) * clevel;
    if (interactive(caster)) {
      tell_object(caster, "%^RESET%^%^GREEN%^You draw upon the power of "
         "the %^BOLD%^c%^RESET%^%^CYAN%^h%^RESET%^a%^GREEN%^me%^ORANGE%^l"
         "%^RESET%^%^GREEN%^e%^RESET%^o%^ORANGE%^n%^RESET%^%^GREEN%^, helping you hide!%^RESET%^");
      tell_room(place,"%^RESET%^%^GREEN%^A %^BOLD%^k%^RESET%^%^RED%^a%^GREEN%^l"
         "%^ORANGE%^e%^GREEN%^i%^MAGENTA%^d%^GREEN%^o%^CYAN%^s%^GREEN%^c%^RESET%^o"
         "%^BLUE%^p%^GREEN%^e of c%^CYAN%^o%^MAGENTA%^l%^RED%^o%^ORANGE%^r %^GREEN%^"
         "flashes across "+caster->QCN+"%^RESET%^%^GREEN%^'s skin as "+caster->QS+" "
         "manifests a power.%^RESET%^",caster);
    }
    mylevel = clevel;
    mybonus = (mylevel/2) + 1;
//    caster->add_skill_bonus("stealth",mybonus);
    caster->set_property("chameleoned",mybonus);
//Because this was affecting other thief things (stab, etc.), I have adjusted only sneak and hide in shadows to take chameleoned into account ~C~ 11/28/15
    caster->set_property("spelled", ({TO}));
    spell_successful();
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect(){
    int i;

    if(objectp(CASTER)) {
      tell_object(caster,"%^RESET%^%^GREEN%^Your insight into the chameleon fades.%^RESET%^");
//      caster->add_skill_bonus("stealth",(-1)*mybonus);
      caster->remove_property("chameleoned");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
