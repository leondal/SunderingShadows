//last change 6/24/01.  Updated by Circe 11/8/03.  Changed to provide either a leopard or a wolf.
// mon file moved to /d/magic/mon/ Ares/Styx 1/29/05

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

/*
#define DRAGON "/d/magic/obj/dragon"
#define GRIFFON "/d/magic/obj/griffon"
Changed to provide beasts as mounts by Circe 11/8/03 - taking out dragon or griffon
*/
#define LEOPARD "/d/magic/mon/riding_leopard"
#define WOLF "/d/magic/mon/riding_wolf"
inherit SPELL;

object caster, place, ob;

void clean_up() { return 1; }

void create(){
    ::create();
    set_spell_name("faithful mount");
    set_spell_level(5);
    set_spell_type("priest");
    set_diety("malar");
    set_spell_sphere("conjuration");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string(){
    return "%^BOLD%^%^CYAN%^"+caster->query_cap_name()+" starts chanting to Malar, "+caster->query_possessive()+" hands folded in prayer, "+caster->query_possessive()+" eyes on the horizon.";
}

int preSpell(){
    if(caster->query_in_vehicle()){
      tell_object(caster, "%^BOLD%^%^CYAN%^A mount will not come if you are already mounted.");
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


    tell_object(caster, "%^BOLD%^%^CYAN%^You begin to chant slowly to Malar, that he may send you a great beast for your mount!");
    tell_room(place, "%^BOLD%^%^CYAN%^"+name+" calls upon Malar, calling for a great beast for his mount!", caster);
    caster->set_paralyzed(7, "You are calling to Malar to send your mount!");
    call_out("mount", 5);
}

void mount(){
    string name;

    name = caster->query_cap_name();
    if(!objectp(caster)) return 0;
    if(objectp(place)) place = environment(caster);

    tell_object(caster, "%^BOLD%^%^CYAN%^As you see a shape take form in the sky, you know that Malar has smiled upon you, and sent you a beast to ride.");
    tell_room(place, "%^BOLD%^%^CYAN%^A smile creeps across "+name+"'s face as a beast flies from the sky and lands next to "+caster->query_objective()+".", caster);
    if(random(2)){
    ob = new(LEOPARD);
    ob->set_property("spell", TO);
    ob->set_property("spell_creature", TO);
    ob->set_owner(caster);
    ob->move(place);
    caster->force_me("mount leopard");
    } else {
    ob = new(WOLF);
    ob->set_property("spell", TO);
    ob->set_property("spell_creature", TO);
    ob->set_owner(caster);
    ob->move(place);
    caster->force_me("mount wolf");
    }

    return;
}
void dest_effect(){
    TO->remove();
}

int help(){
write(
@HELP
Spell  : Faithful Mount
Level  : 5th Level
Sphere : Conjuration
Deity  : Malar
Syntax : chant faithful mount

    This spell will call to Malar, asking him to send you
a faithful beast to act as your mount and help defend you.
This spell will not work if you are already mounted.
HELP
);
return 1;
}
