//Crushing Hand - new spell for the Strength domain by ~Circe~
//created during the rebalancing of domains 5/4/08
//Loosely based on Shocklet
#include <magic.h>
#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;

object endplace, device, elem;

void create(){
    ::create();
    set_author("circe");
    set_spell_name("crushing hand");
    set_spell_level( ([ "mage" : 9, "psion" : 8, "cleric" : 8 ]) );
    set_spell_sphere("invocation_evocation");
    set_domains("strength");
    set_discipline("kineticist");
    set_syntax("cast CLASS crushing hand");
    set_description("This spell will call forth a crushing hand to help defend the caster as well as lend its strength to the battles the caster may face.  While the hand is under the caster's control, he may <command hand to [action]> or <dismiss> the crushing hand if it is no longer needed.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell() {
   if(present("crushdevice999",caster)){
      tell_object(caster,"You can only control such force at a time.");
      return 0;
   }
   return 1;
}

string query_cast_string(){
   tell_room(environment(caster),"%^CYAN%^"+caster->QCN+" spreads "+
      ""+caster->QP+" arms wide and clenches "+caster->QP+" "+
      "fists.%^RESET%^",caster);
   tell_object(caster,"%^CYAN%^You spread your arms wide and clench "+
      "your fists, praying for "+(string)caster->query_diety()+"'s "+
      "aid.%^RESET%^");
   return "display";
}

void spell_effect(int prof){
   if(!objectp(caster)){
      TO->remove();
      return;
   }
   tell_room(place,"%^BOLD%^%^BLUE%^Suddenly, "+caster->QCN+" "+
      "swings "+caster->QP+" arms forward, filling the air with "+
      "a %^RED%^booming%^BLUE%^ clap.%^RESET%^", caster);
   tell_object(caster,"%^BOLD%^%^BLUE%^Feeling "+(string)caster->query_diety()+"'s "+
      "strength, you swing your arms forward, filling the air with "+
      "a %^RED%^booming %^BLUE%^clap.%^RESET%^");
   call_out("next_step",ROUND_LENGTH);
}

void next_step() {
   if(!objectp(caster)){
      TO->remove();
      return;
   }
   tell_room(place,"%^BOLD%^%^RED%^At the moment of impact, a small "+
      "%^BLACK%^portal%^RED%^ opens before "+caster->QCN+", and a "+
      "monstrous hand begins clawing its way through!%^RESET%^",caster);
   tell_object(caster,"%^BOLD%^%^RED%^At the moment of impact, a small "+
      "%^BLACK%^portal%^RED%^ opens before you, and a "+
      "monstrous hand begins clawing its way through!%^RESET%^");
   call_out("step3",ROUND_LENGTH);
}

void step3(){
int hd,hp,strength;
   if(!objectp(caster)){
      TO->remove();
      return;
   }
   elem = new("/d/magic/mon/crushing_hand");
   elem->set_property("spell",TO);
   elem->set_property("spelled",({TO}));
   elem->set_property("spell_creature", TO);
   if(objectp(caster)) elem->set_property("minion", caster);
   device = new("/d/magic/obj/crush_control");
   tell_room(place,"%^BOLD%^%^BLUE%^The monstrous hand stands "+
      "before "+caster->QCN+", bowing to "+caster->QP+" whim!%^RESET%^",caster);
   tell_object(caster,"%^BOLD%^%^BLUE%^The monstrous hand "+
      "stands before you, bowing to your whim!%^RESET%^");
   caster->add_ac_bonus(2);
   hd = clevel;
   hp = caster->query_max_hp();
   strength = (int)caster->query_lowest_level()/4;
   strength = strength + 8;
   device->set_elemental(elem);
   device->set_caster(caster);
   caster->add_follower(elem);
   device->move(caster);
   device->set_property("spell",TO);
   device->set_property("spelled",({TO}));
   elem->set_stats("strength",strength);
   elem->set_hd(hd,8);
   elem->set_max_hp(hp);
   elem->set_hp(hp);
   elem->move(place);
}

void dest_effect() {

    if(objectp(elem)){
        tell_room(environment(elem), "%^ORANGE%^The giant hand vanishes into thin air!%^RESET%^");
        elem->move("/d/shadowgate/void");
        elem->remove();
    }
    if(objectp(device))
    {
        device->remove();
    }
    if(objectp(caster))
        caster->add_ac_bonus(-2);
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
