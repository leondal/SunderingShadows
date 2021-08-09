#include <priest.h>
inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("shield of shadows");
    set_spell_level(([ "innate" : 1 ]));
    set_spell_sphere("illusion");
    set_bonus_type("shield");
    set_syntax("cast CLASS shield of shadows");
    set_description("This spell calls a protective shield into existance before the caster, crafted of the stuff of "
"shadows. While it may seem intangible, it will negate magic missiles, and provides a small bonus to armor class for "
"its duration. Use of a physical shield will interfere with the spell and cause it to fade.");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([
      "mage" : ([ "clear crystal" : 1, ]),
    ]));
    set_helpful_spell(1);
}

int preSpell(){
   if((int)CASTER->query_property("spell shield")){
      tell_object(CASTER,"You are already under the influence of such a spell.");
      return 0;
   }
   return 1;
}

string query_cast_string() {
    return "%^BLUE%^"+caster->QCN+" makes a circular motion with an open palm, whisps of shadow trailing "+caster->QP+" fingertips.%^RESET%^";
}

void spell_effect(int prof) {
    int i;
    if (!objectp(caster)) {
      dest_effect();
      return;
    }
    if (interactive(caster)) {
      tell_object(caster, "%^CYAN%^The trailing whisps resolve into a circle of shadowy force before you!%^RESET%^");
      tell_room(place,"%^CYAN%^The trailing whisps resolve into a circle of shadowy force, hovering before "+caster->QCN+".%^RESET%^",caster);
    }
    caster->add_ac_bonus(4);
    caster->set_property("spell shield",1);
    spell_successful();
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 8;
    set_end_time();
    call_out("dest_effect",spell_duration);
    call_out("test", ROUND_LENGTH);
}

void test() {
    object *armour;
    int i;
//This was if (!objectp(target)) and the spell was dissipating immediately.
//Changing it to caster to see if that fixes the problem. ~Circe~ 2/10/13
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    armour = caster->query_armour("left hand");
    for (i=0;i<sizeof(armour);i++) {
        if ((string)armour[i]->query_type() == "shield" || (string)armour[i]->query_type() == "thiefshield") {
            tell_object(caster,"Taking up a shield causes the conjured protection to waver and fade.");
            dest_effect();
            return;
        }
    }
    armour = caster->query_armour("right hand");
    for (i=0;i<sizeof(armour);i++) {
        if ((string)armour[i]->query_type() == "shield" || (string)armour[i]->query_type() == "thiefshield") {
            tell_object(caster,"Taking up a shield causes the conjured protection to waver and fade.");
            dest_effect();
            return;
        }
    }
    call_out("test", ROUND_LENGTH);
}

void dest_effect(){
    int i;
    if(find_call_out("test") != -1) remove_call_out("test");
    if(objectp(CASTER)) {
      tell_object(caster,"%^BLUE%^The shadowy shield shimmers and fades.%^RESET%^");
      tell_room(environment(caster),"%^BLUE%^"+caster->QCN+"'s shadowy shield shimmers and fades.%^RESET%^",caster);
      caster->add_ac_bonus(-4);
      caster->set_property("spell shield",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
