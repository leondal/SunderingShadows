//minor creation
//for the new Creation domain
//by ~Circe~ 12/29/07

#include <std.h>
#include "/cmds/spells/m/minor_creation.h"

inherit SPELL;
int bonus;

void create() {
    string stufflist, *tmp = ({});
    ::create();
    set_spell_name("minor creation");
    set_spell_level(([ "mage" : 1, "magus" : 1, "inquisitor" : 1, "psion" : 1, "warlock" : 1 ]));
    set_spell_sphere("conjuration_summoning");
    set_discipline("shaper");
    set_syntax("cast CLASS minor creation on <object>");
    tmp = keys(STUFF);
    tmp = sort_array(tmp, "sort_alpha", TO);
    stufflist = "This spell will allow the caster to gather minute particles from the air and form them into particular "+
"objects.  It will create a minor object from the list below for the cleric to use.  Items created in this manner are "+
"fleeting, however, and will disappear when the person carrying them logs out.\n\n"+format_page(tmp,3);
    set_description(stufflist);
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
    set_feats_required(([ "warlock" : "book of shadows"]));
}

string query_cast_string(){
   tell_object(caster,"%^BOLD%^%^WHITE%^You call upon creative "+
      "energies as you begin to utter a spell.%^RESET%^");
   tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" begins to "+
      "utter a spell.%^RESET%^",caster);
   return "display";
}

int preSpell(){
string thing;
   if(!arg){
      tell_object(caster,"Usage: chant minor creation on <object>");
      tell_object(caster,"See <help minor creation> for a list of possible objects.");
      return 0;
   }
   thing = arg;

   if(member_array(thing,keys(STUFF)) == -1){
      tell_object(caster,"No "+thing+" is on the list!");
      return 0;
   }
   return 1;
}

void spell_effect(int prof){
object obj;
   tell_room(place,"%^RESET%^%^MAGENTA%^Focusing on a point in space, "+
      ""+caster->QCN+" gathers particles of matter and forms them "+
      "into a new object!%^RESET%^",({target,caster}));
   tell_object(caster, "%^RESET%^%^MAGENTA%^You draw forth small "+
      "particles of matter and form them into a new object!%^RESET%^");
   obj = new(STUFF[arg]);
//   obj->set_property("no animate",1);
//Going to let it be animatable - for now - but we'll see if it needs to be limited ~Circe~ 5/31/08
   obj->set_value(0);
   if(obj->is_armor()) obj->set_size((int)caster->query_size());
   obj->set_property("temporary_item",1);
   obj->move(environment(caster));
   tell_object(caster,""+obj->query_short()+" appears before you!");
   tell_room(place,""+obj->query_short()+" appears before "+caster->QCN+"!",caster);
   dest_effect();
}

void dest_effect(){
   ::dest_effect();
   if(objectp(TO)) TO->remove();
}

string sort_alpha(string one, string two){
   return strcmp(one,two);
}

/***Make sure it's working - also make it not save set_property("no save",1)?***/
