#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

#define SCRY_D "/daemon/ic_scry_locate_d"
object blocker;
int feattracker;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("mind veil");
    set_spell_level(([ "warlock" : 3 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS mind veil");
    set_description("This invocation conjures a shroud of magical energy about the caster, "
"which will oppose all devices and spells that detect, influence or read emotions or thoughts. "
"Mind-effecting spells will not work against the warlock, and basic divination attempts such as "
"alignment will reveal nothing of note. Greater divinations, such as scrying, will be opposed "
"with by caster's own magical strength. This invocation does not work in conjunction with other "
"alignment-altering effects, nor with other scry protection magics.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string() {
    tell_object(caster,"%^CYAN%^You extend your arms to either side, seeking traces of magic with which to conceal yourself.%^RESET%^");
    tell_room(place,"%^CYAN%^"+caster->QCN+" extends "+caster->QP+" arms to either side, grasping at empty air.%^RESET%^",caster);
    return "display";
}

int preSpell(){
   if((int)caster->query_property("hidden alignment")){
      tell_object(caster,"You are already have an alignment altering affect.");
      return 0;
   }
   return 1;
}

void spell_effect(int prof) {
   int num, duration, wis_bonus, power;
   object temp;
   ::spell_effect();

   if(temp = caster->query_property("block scrying")){
      if(!objectp(temp)) caster->remove_property("block scrying");
      else{
         tell_object(caster,"%^BOLD%^RED%^There is already concealing magic shaped around you!");
         TO->remove();
         return;
      }
   }
   if((int)caster->query_property("hidden alignment")){
      tell_object(caster,"You are already have an alignment altering affect.");
      TO->remove();
      return;
   }
   tell_object(caster,"%^CYAN%^Your fingertips ensnare te%^RESET%^n%^CYAN%^dri%^RESET%^l%^CYAN%^s of fil%^RESET%^m%^CYAN%^y en%^RESET%^e%^CYAN%^rgy, and you pull them close, drawing and shaping them about you like a shroud.%^RESET%^");
   tell_room(place,"%^CYAN%^"+caster->QCN+" ensnares te%^RESET%^n%^CYAN%^dri%^RESET%^l%^CYAN%^s of fil%^RESET%^m%^CYAN%^y en%^RESET%^e%^CYAN%^rgy from seemingly nowhere, whisps trailing through "+caster->QP+" fingers as "+caster->QS+" draws them about "+caster->QO+"self.%^RESET%^",caster);
   spell_successful();
   addSpellToCaster();
   caster->set_property("spelled",({TO}));
   blocker = SCRY_D->add_block_scrying(caster);
   if(!objectp(blocker)) {
      tell_object(caster,"%^BOLD%^RED%^Something is wrong that a wiz might want to look at!");
      dest_effect();
      return;
   }
//updated by ~Circe~ 9/16/11 to use bonuses properly
   wis_bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
   power = CLEVEL + wis_bonus + random(6);
   blocker->set_block_power(power);
   caster->set_property("hidden alignment",5);
   if(member_array("unyielding soul",(string*)caster->query_temporary_feats()) == -1) {
      caster->add_temporary_feat("unyielding soul");
      feattracker = 1;
   }
   duration = 6 * clevel  * ROUND_LENGTH;
   spell_duration = duration;
   set_end_time();
   call_out("dest_effect",spell_duration);
}

void dest_effect(){
   if(objectp(caster))
   {
       tell_object(caster,"%^CYAN%^The %^CYAN%^t%^WHITE%^end%^CYAN%^r%^WHITE%^ils%^CYAN%^ of %^CYAN%^f%^WHITE%^i%^CYAN%^l%^WHITE%^my %^WHITE%^e%^CYAN%^n%^CYAN%^e%^WHITE%^rgy%^CYAN%^ flow away from you, leaving you exposed once again.");
       caster->remove_property("hidden alignment");
       if(feattracker == 1) caster->remove_temporary_feat("unyielding soul");
       caster->remove_property_value("spelled", ({TO}) );
   }
   if(objectp(blocker)) blocker->self_destruct();
   ::dest_effect();
   if(objectp(TO)) TO->remove();
}
