//New Torm Spell to replace Break Curse - Cythera 5/05

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define LION "/d/magic/mon/riding_lion"
inherit SPELL;

object caster, place, ob;

void clean_up() { return 1; }

void create(){
    ::create();
    set_spell_name("pride of torm");
    set_spell_level(7);
    set_spell_type("priest");
    set_diety("torm");
    set_spell_sphere("summoning");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string(){
    return "%^YELLOW%^"+caster->QCN+" calls upon the favors of Torm,"+
	" grasping "+caster->QP+" holy symbol firmly.";
}

int preSpell(){
    if(caster->query_in_vehicle()){
      tell_object(caster, "%^YELLOW%^A mount will not come if you are already mounted.");
      return 0;
    }
    return 1;
}

void spell_effect(int prof){
    string name;

    caster = CASTER;
    place = PLACE;
    if(!objectp(caster)) return 0;
    if(objectp(place)) place = environment(caster);
    name = caster->query_cap_name();


    tell_object(caster, "%^YELLOW%^You begin to chant pray to Torm, that he may send to you a lion!");
    tell_room(place, "%^YELLOW%^"+name+" calls upon Torm, calling for a lion for his mount!", caster);
    caster->set_paralyzed(7, "You are calling to Torm to send your mount!");
    call_out("mount", 5);
}

void mount(){
    string name;

    name = caster->query_cap_name();
    if(!objectp(caster)) return 0;
    if(objectp(place)) place = environment(caster);

    tell_object(caster, "%^YELLOW%^A great roar sounds out as a lion races towards you.");
    tell_room(place, "%^YELLOW%^"+name+" beams a bright grin as a lion "+
		"races towards "+caster->QO+".", caster);
    if(random(2)){
    ob = new(LION);
    ob->set_property("spell", TO);
    ob->set_property("spell_creature", TO);
    ob->set_owner(caster);
    ob->move(place);
    caster->force_me("mount lion");
    }
	return;
}
void dest_effect(){
    TO->remove();
}

int help(){
write(
@HELP
Spell  : Pride of Torm
Level  : 7th Level
Sphere : Conjuration
Deity  : Torm
Syntax : chant pride of torm

This spell will call to Torm, asking him to send
you a majestic lion to act as your mount and 
help defend you.  This spell will not work if
you are already mounted.      

HELP
);
return 1;
}
