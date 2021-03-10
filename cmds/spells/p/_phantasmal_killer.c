//borrowed from Circe's phantasmal killer from priest domains. Nienne, 12/09
#include <magic.h>
#include <std.h>
#include <spell.h>
#include <daemons.h>
inherit SPELL;

object ob;

void create(){
    ::create();
    set_author("nienne");
    set_spell_name("phantasmal killer");
    set_spell_level(([ "mage" : 4, "cleric" : 8, "magus" : 4 ]));
    set_spell_sphere("illusion");
    set_spell_domain("illusion");
    set_syntax("cast CLASS phantasmal killer on TARGET");
    set_description("This spell is cast upon a target and creates a figment of that target's imagination by drawing upon his deepest fears. Onlookers will see simply a vaguely humanoid shape at first, while the creature will soon take on the form of whatever frightens the target most. The creature's strength depends partly upon drawing on the target's fears and partly upon the caster's strength. Once the killer is unleashed, it becomes a force unto itself, protecting the caster but otherwise attacking at will.");
    mental_spell();
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
     // school specific mage spell
}

string query_cast_string(){
   if(spell_type == "warlock") {
     tell_room(environment(caster),"%^CYAN%^With a mischievous grin, "+caster->QCN+" whispers an invocation.%^RESET%^",caster);
     tell_object(caster,"%^CYAN%^With mischievous thoughts and a grin on your lips, you whisper an invocation.%^RESET%^");
     return "display";
   }
   tell_room(environment(caster),"%^CYAN%^With a mischievous grin, "+caster->QCN+" whispers an incantation.%^RESET%^",caster);
   tell_object(caster,"%^CYAN%^With mischievous thoughts and a grin on your lips, you whisper an incantation.%^RESET%^");
   return "display";
}

int preSpell(){
   if(caster->query_property("phantasmal_killer")) {
        tell_object(caster,"%^CYAN%^You are incapable of controling two such powerful summonings.%^RESET%^");
        return 0;
   }
   return 1;
}

void spell_effect(int prof){
   	int i;
   if(spell_type == "warlock") {
   	tell_object(caster,"%^BOLD%^%^CYAN%^You summon forth a tangible figment of %^BOLD%^%^BLACK%^nightmare%^RESET%^%^CYAN%^, setting it loose on "+target->QCN+"!%^RESET%^");
      tell_room(place,"%^BOLD%^%^CYAN%^As "+caster->QCN+" chants, a figment forms from the air, taking on a vaguely humanoid shape!%^RESET%^",caster);
   }
   else {
   	tell_object(caster,"%^BOLD%^%^CYAN%^You summon forth a figment from the air, setting it loose on "+target->QCN+"!%^RESET%^");
      tell_room(place,"%^BOLD%^%^CYAN%^As "+caster->QCN+" chants, a figment forms from the air, taking on a vaguely humanoid shape!%^RESET%^",caster);
   }

   tell_room(place,"%^BOLD%^%^BLACK%^The shape solidifies and attacks "+target->QCN+"!%^RESET%^",caster);
   tell_object(target,"%^BOLD%^%^BLACK%^The shape solidifies into a most terrifying image and attacks you!%^RESET%^");
   if(!objectp(target) || environment(target) != environment(caster)){
      tell_object(caster,"Your spell ends harmlessly.");
      tell_room(place,""+caster->QCN+"'s spell ends abruptly.",caster);
      dest_effect();
      return;
   }
   addSpellToCaster();
   ob = new("/d/magic/mon/killer");
   ob->set_static_bab(clevel);
   ob->set_damage_bonus(clevel/8);
   ob->set_attack_bonus(clevel/3);
   ob->set_hd(clevel,8);
   ob->set_max_hp((int)target->query_max_hp());
   ob->set_hp((int)ob->query_max_hp());
   ob->set_stats("strength",(10+(clevel/4)));
   ob->set_ac(-1*(clevel/2));
   ob->set_attacks_num(clevel/7);
   ob->set_mlevel("fighter",clevel);
   ob->set_guild_level("fighter",clevel);
   ob->set_property("effective_enchantment", (clevel / 7));
   ob->set_exp(0);
   ob->set_property("spelled", ({TO}) );
   ob->set_property("spell_creature", TO);
   ob->set_property("spell", TO);
   ob->set_property("minion", caster);
   ob->move(place);
   ob->force_me("protect "+caster->query_name());
   ob->force_me("protect "+caster->query_name());
   caster->add_follower(ob);
   ob->force_me("kill "+target->query_name()+"");

   ob->add_id("summoned monster");
   ob->add_id(caster->query_name()+"monster");
   caster->set_property("phantasmal_killer",ob);
   spell_kill(target,caster);
   spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
   set_end_time();
   call_out("dest_effect",spell_duration);
}

void dest_effect() {
    if(objectp(ob)){
      if(objectp(caster)) { caster->remove_protector(ob); }
      ob->die();
    }
    if(objectp(caster)) { caster->remove_property("phantasmal_killer"); }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
