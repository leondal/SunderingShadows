//Silver Sight - Moon domain scry spell based on Listening
//Shadow.  Silver Sight, Listening Shadow, and Inner Eye are
//all essentially the same spell - if you change one, please
//change all three.
//Rebalancing domains ~Circe~ 5/10/08
// duration on all scrying spells (and between-cast delays where relevant) rebalanced. Nienne, 5/15.
#include <std.h>
#include <magic.h>

inherit SPELL;

object motes,remote;
string theName;
#define DELAY 300
//This *should* equal a 5 minute delay, I think.  That's the
//intention anyway.  ~Circe~ 5/10/08

void create(){
    ::create();
    set_author("circe");
    set_spell_name("silver sight");
    set_spell_level(([ "cleric" : 8, "oracle" : 8 ]));
    set_spell_sphere("divination");
    set_mystery("metal");
    set_domains("moon");
    set_syntax("cast CLASS silver sight on TARGET");
    set_description("This spell will invoke the power of the moon to grant the caster far-reaching sight, allowing her to "
"watch what goes on in the target room.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
}

int preSpell(){
   if(caster->query_property("remote scrying")){
      tell_object(caster,"You have already focused your "+
         "sight elsewhere!");
      return 0;
   }
   if(avatarp(caster)) return 1; // let avatars use to follow players regardless of timer.
   if((int)caster->query_property("remote scrying time")+DELAY > time()){
      tell_object(caster,"You cannot invoke your moon-touched "+
         "sight again so soon.");
      return 0;
   }
   return 1;
}

string query_cast_string(){
   tell_object(caster,"%^BOLD%^As you whisper a prayer, motes of "+
      "%^RESET%^silvery light %^BOLD%^coalesce and dance around "+
      "your eyes.%^RESET%^");
   tell_room(place,"%^BOLD%^As "+caster->QCN+" whispers a prayer, "+
      "motes of %^RESET%^silvery light %^BOLD%^coalesce and dance "+
      "around "+caster->QP+" eyes.%^RESET%^",caster);
   return "display";
}

void spell_effect(int prof){
   object ob, blockobj;
   int bonus,power;

   if(!arg){
      tell_object(caster,"%^BOLD%^You send the motes of light "+
         "into this area, leaving them here to watch for you.%^RESET%^");
      if(place->query_property("no scry"))
      {
         tell_object(caster,"Something blocks your attempt!");
         dest_effect();
         return;
      }
//new power stuff by ~Circe~ 6/20/08 to be in line with
//other scry spells
      bonus = caster->query_stats("wisdom");
      bonus = bonus - 10;
      power = clevel + bonus + random(6);
      if(blockobj = present("blockerx111", place)){
        if(power < blockobj->query_block_power()){
           tell_object(caster,"Something blocks your attempt!");
           dest_effect();
           return;
        }
      }
      motes = new("/d/magic/obj/silverwatcher");
      motes->set_caster(caster);
      motes->set_property("spell",TO);
      motes->set_property("spelled", ({TO}) );
      motes->set_scry_power(power);
      motes->move(place);
      theName = place->query_short();
      spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
      set_end_time();
      call_out("dest_effect",spell_duration);
      caster->set_property("remote scrying",1);
      addSpellToCaster();
      return;
   }

   if(ob = find_player(caster->realNameVsProfile(arg)))
   {
      if(objectp(ob) && !wizardp(ob))
      {
         tell_object(caster,"%^BOLD%^You send the motes of light "+
            "to watch "+capitalize(arg)+".%^RESET%^");
         if(environment(ob)->query_property("no scry"))
         {
            tell_object(caster,"Something blocks your attempt!");
            dest_effect();
            return;
         }
//new power stuff by ~Circe~ 6/20/08 to be in line with
//other scry spells
         bonus = caster->query_stats("wisdom");
         bonus = bonus - 10;
         power = clevel + bonus + random(6);
         if(blockobj = present("blockerx111", environment(ob)) || blockobj = present("blockerx111",ob)){
            if(power < blockobj->query_block_power()){
               tell_object(caster, "Something blocks your attempt!");
               return;
            }
         }
         motes = new("/d/magic/obj/silverwatcher");
         motes->set_caster(caster);
         motes->set_property("spell",TO);
         motes->set_property("spelled", ({TO}) );
         motes->set_target(ob);
         motes->set_scry_power(power);
         motes->move(environment(ob));
         theName = ob->query_short();
         spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
         set_end_time();
         call_out("dest_effect",spell_duration);
         caster->set_property("remote scrying",1);
         addSpellToCaster();
         return;
      }
   }
   tell_object(caster,"Your power goes unfocused.");
}

void dest_effect(){
    if(objectp(motes))
        motes->dest_me();
    if(objectp(caster)) {
      caster->remove_property("remote scrying");
      caster->remove_property("remote scrying time");
      caster->set_property("remote scrying time",time());
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

string query_spell_display(){
   return "Silver Sight: "+theName;
}
