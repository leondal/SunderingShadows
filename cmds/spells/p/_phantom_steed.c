// repose sphere, summons a spectral mount. Nienne, 04/07
//Moved to level 3 after conversations with Nienne
//in rebalancing the domains ~Circe~ 4/24/08

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define HORSE "/d/magic/mon/mounts/spectral"
inherit SPELL;

object ob;

void create(){
    ::create();
    set_spell_name("phantom steed");
    set_spell_level(([ "bard" : 3, "mage" : 3, "oracle" : 3, "psion" : 2, "magus" : 3 ]));
    set_mystery("whimsy");
    set_discipline("nomad");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS phantom steed");
    set_description("By means of this spell, the caster calls upon his god to send forth a ghostly horse to serve as his "
"faithful mount and to help defend them.\n\nThis spell will not work if you are already mounted.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

string query_cast_string(){
    return "%^ORANGE%^"+caster->QCN+" brings both hands forward, "
"and then beckons them together towards "+caster->QO+
"self%^RESET%^.";
}

int preSpell(){
    if(caster->query_in_vehicle()){
      tell_object(caster, "A mount will not come if you are already mounted.");
      return 0;
    }
    return 1;
}

void spell_effect(int prof){
    string name;

    if(!objectp(caster)) return 0;
    if(objectp(place)) place = environment(caster);
    name = caster->QCN;

    tell_room(place, "%^ORANGE%^A faint, translucent %^RESET%^"
"m%^CYAN%^i%^RESET%^s%^CYAN%^t %^ORANGE%^becomes apparent in the air before "
"you, forming the outline of a ghostly creature!%^RESET%^");
    caster->set_paralyzed(7, "You are still calling upon your god to send you a mount!");
    call_out("mount", 5);
}

void mount(){
    string name;

    name = caster->QCN;
    if(!objectp(caster)) return 0;
    if(objectp(place)) place = environment(caster);

    tell_object(caster,"%^ORANGE%^The ghostly creature slowly becomes clear "
"enough to discern as the outline of a %^BOLD%^%^BLACK%^sp%^RESET%^e"
"%^BOLD%^%^BLACK%^ct%^RESET%^r%^BOLD%^%^BLACK%^al ho%^RESET%^r%^BOLD%^"
"%^BLACK%^se%^RESET%^%^ORANGE%^, standing before you. It paws the ground with "
"perfectly %^BLUE%^silent %^ORANGE%^hooves.%^RESET%^");
    ob = new(HORSE);
    ob->set_property("spell", TO);
    ob->set_property("spell_creature", TO);
    ob->set_owner(caster);
    ob->move(place);
    caster->force_me("mount spectral steed");
    return;
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
