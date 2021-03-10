//Iron Body by ~Circe~ 7/25/05
//Note:  I altered this from stoneskin and left it using the SS
//variables because I do not want psions to be able to stack this
//spell with mage stoneskin.
// upgraded to the book vers, self-only DR15. Better than stoneskin (and does not stack). N, 5/15.
#include <spell.h>
#include <magic.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("iron body");
    set_spell_level(([ "psion" : 8, "mage" : 8, "oracle" : 9 ]));
    set_spell_sphere("alteration");
    set_mystery("metal");
    set_syntax("cast CLASS iron body");
    set_description("By using this power, the caster lends some of his psychic energy or arcane spellcraft to "
"protect himself. It causes the caster to gain a strong resistance to physical attacks, as well as immunity "
"to most standard poisons. It does not work together with stoneskin.");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([
      "mage" : ([ "diamond dust" : 1 ]),
    ]));
	set_helpful_spell(1);
}

int preSpell(){
    if(caster->query_stoneSkinned() || caster->query_property("iron body")){
        tell_object(caster,"You already have protection of this nature!");
        return 0;
    }
    return 1;
}

string query_cast_string() {
    if((string)TO->query_spell_type() == "psion") {
      tell_object(caster,"%^BOLD%^%^GREEN%^You cause two s%^RESET%^%^GREEN%^"+
          "t%^BOLD%^r%^RESET%^%^GREEN%^i%^BOLD%^p%^RESET%^%^GREEN%^e"+
          "%^BOLD%^d spheres to revolve in the air, growing ever faster!%^RESET%^");
      tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" causes two s%^RESET%^%^GREEN%^"+
       "t%^BOLD%^r%^RESET%^%^GREEN%^i%^BOLD%^p%^RESET%^%^GREEN%^e"+
       "%^BOLD%^d spheres to revolve in the air, growing ever faster!%^RESET%^",caster);
      return "display";
    }
    tell_object(caster,"%^BOLD%^%^BLACK%^You palm some %^BOLD%^%^WHITE%^gl%^RESET%^e"
       "%^BOLD%^%^WHITE%^am%^RESET%^in%^BOLD%^%^WHITE%^g %^BOLD%^%^BLACK%^diamond "
       "dust, a few grains escaping through your fingers.%^RESET%^");
    tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" palms some %^BOLD%^%^WHITE%^gl%^RESET%^e"
       "%^BOLD%^%^WHITE%^am%^RESET%^in%^BOLD%^%^WHITE%^g %^BOLD%^%^BLACK%^powder, "
       "a few grains escaping through "+caster->QP+" fingers.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    ::spell_effect();
    if((string)TO->query_spell_type() == "psion") {
      tell_room(environment(caster),"%^YELLOW%^The spheres fragment, motes "+
        "settling upon "+caster->QCN+"'s skin, giving "+caster->QO+" extra "+
        "protection!%^RESET%^",caster);
      tell_object(caster,"%^YELLOW%^The spheres fragment, motes settling "
          "upon your skin and lending you extra protection!%^RESET%^");
    }
    else { // mage
      tell_room(environment(caster),"%^BOLD%^%^BLACK%^"+caster->QCN+" releases the "+
        "dust across "+caster->QP+" skin, which shimmers momentarily with a "+
        "%^RESET%^%^ORANGE%^metal%^YELLOW%^l%^RESET%^%^ORANGE%^ic %^BOLD%^%^BLACK%^sheen"+
        ".%^RESET%^",caster);
      tell_object(caster,"%^BOLD%^%^BLACK%^You release the dust across your "+
        "skin, which shimmers momentarily with a %^RESET%^%^ORANGE%^metal%^YELLOW%^l"+
        "%^RESET%^%^ORANGE%^ic %^BOLD%^%^BLACK%^sheen.%^RESET%^");
    }
    caster->set_property("spelled",({TO}));
    caster->set_property("iron body",1);
    caster->set_property("damage resistance",15);
    caster->set_property("poison immunity",1);
    addSpellToCaster();
    spell_successful();
    spell_duration = (clevel+roll_dice(1,20)) * ROUND_LENGTH * 8;
    set_end_time();
    call_out("dest_effect", spell_duration);
}

void dest_effect() {
    string *poisonarray;
    if (!objectp(caster)) {
        ::dest_effect();
    	  if(objectp(TO)) TO->remove();
        return;
    }
    if((string)TO->query_spell_type() == "psion") {
      tell_room(environment(caster),"%^BOLD%^%^GREEN%^The protection "+
        "granted to "+caster->QCN+" phosphoresces before winking out "+
        "of existence!%^RESET%^",caster);
      tell_object(caster,"%^BOLD%^%^GREEN%^Your body glows faintly "+
        "green before you feel your extra protection fade away!%^RESET%^");
    }
    else {
      tell_room(environment(caster),"%^BOLD%^%^BLACK%^"+caster->QCN+
        "'s skin %^RESET%^%^ORANGE%^sh%^YELLOW%^i%^RESET%^%^ORANGE%^mmers "+
        "%^BOLD%^%^BLACK%^before returning to normal.%^RESET%^",caster);
      tell_object(caster,"%^BOLD%^%^BLACK%^Your skin %^RESET%^%^ORANGE%^sh"+
        "%^YELLOW%^i%^RESET%^%^ORANGE%^mmers %^BOLD%^%^BLACK%^before returning "+
        "to normal.%^RESET%^");
    }
    clevel = clevel * -1;
    caster->set_property("damage resistance",-15);
    caster->set_property("poison immunity",-1);
    caster->set_property("iron body",-1);
    caster->remove_property_value("spelled", ({TO}) );
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
