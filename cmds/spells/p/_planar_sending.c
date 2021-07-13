#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>
#include <teleport.h>
inherit SPELL;

#define DELAY 300 //between uses

object endplace;
object teleportee;
string destination;

void create() {
    ::create();
    set_spell_name("planar sending");
    set_spell_level(([ "psion" : 9 ]));
    set_spell_sphere("psychoportation");
    set_syntax("cast CLASS planar sending on TARGET to DESTINATION");
    set_description("This spell sends annoying people away. Although strong-willed will stay to annoy you even more.");
    set_verbal_comp();
    set_somatic_comp();
    set_discipline("nomad");
    set_arg_needed();
    set_components(([
      "mage" : ([ "sand" : 1, "pinch of special dust" : 1, ]),
    ]));
    set_save("will");
}

string query_cast_string() {
    return "%^BOLD%^%^BLUE%^"+caster->QCN+" snarls some syllables.";
}

int preSpell(){
   if((int)caster->query_property("spell summon time")+DELAY > time())
   {
      tell_object(caster,"You cannot send anyone away so quickly.");
      return 0;
   }
   return 1;
}

void spell_effect(int prof) {
    string targ;
    string destfile;
    mapping remrooms;

    if (sscanf(arg,"%s to %s",targ, destination)!=2)
    {
        tell_object(caster,"You must provide both target and destination!");
        dest_effect();
        return;
    }

    teleportee = present(targ,environment(caster));
    if(!teleportee)
        present(TP->realNameVsProfile(targ),environment(caster));
    if(!objectp(teleportee) || !teleportee)
    {
     	tell_object(caster,"Your target not in this area, thus the spell fails.");
     	tell_room(place,caster->QCN+" pauses and looks a little disoriented.",caster);
     	dest_effect();
     	return;
    }

    if(do_save(teleportee))
    {
     	tell_object(caster,"%^BOLD%^%^WHITE%^Your target manages to resist your sending attempt!");
     	tell_room(place,caster->QCN+" pauses and looks a little disoriented.",caster);
     	dest_effect();
     	return;
    }

    tell_room(place,"%^BOLD%^%^BLUE%^Bright blue light envelops "+teleportee->QCN+"!%^RESET%^");
    spell_successful();
    call_out("do_sending",ROUND_LENGTH);
}

void do_sending()
{
    object endplace;
    if(!objectp(teleportee)||
       !objectp(caster))
    {
        dest_effect();
        return;
    }
    if(!(endplace=TELEPORT->teleport_object(caster,teleportee,destination,clevel)))
    {
        tell_object(caster,"You sense something blocking your casting and lose concentration on your power.");
        tell_room(place,caster->QCN+" looks startled.",caster);
    }
    else
    {
        tell_room(place,"%^BOLD%^%^BLUE%^"+teleportee->QCN+"%^BOLD%^%^BLUE%^ vanishes!");
        tell_room(endplace,"%^BOLD%^%^BLUE%^"+teleportee->QCN+"%^BOLD%^%^BLUE%^ appears in the flash of bright blue light!");
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
