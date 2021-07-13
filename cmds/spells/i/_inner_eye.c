//Inner Eye - Mentalism domain scry spell based on Listening
//Shadow.  Silver Sight, Listening Shadow, and Inner Eye are
//all essentially the same spell - if you change one, please
//change all three.
//Rebalancing domains ~Circe~ 5/10/08
// duration on all scrying spells (and between-cast delays where relevant) rebalanced. Nienne, 5/15.
#include <std.h>
#include <magic.h>

inherit SPELL;

object eye;
string theName;
#define DELAY 300
//This *should* equal a 5 minute delay, I think.  That's the
//intention anyway.  ~Circe~ 5/10/08

void create(){
    ::create();
    set_author("circe");
    set_spell_name("inner eye");
    set_spell_level(([ "psion" : 7 ]));
    set_spell_sphere("clairsentience");
    set_discipline("seer");
    set_syntax("cast CLASS inner eye on TARGET");
    set_description("Upon manifesting this power, the psion focuses his inner eye and commands it to watch a particular " +
"place for him.  Without an argument, the eye will watch the room the psion is currently in.  When targeted upon a " +
"person known to the psion, the eye will instead focus on that person.");
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
        tell_object(caster,"You cannot manifest your inner eye "+
            "again so soon.");
        return 0;
    }
    if(caster->query("no pk")){
        tell_object(caster,"%^YELLOW%^You are unable to scry while you have a %^MAGENTA%^NoPK %^YELLOW%^flag.%^RESET%^");
        return 0;
    }
    return 1;
}

string query_cast_string(){
   tell_object(caster,"%^CYAN%^Closing your eyes, you breathe "+
      "deeply and focus your mind.%^RESET%^");
   tell_room(place,"%^CYAN%^"+caster->QCN+" closes "+caster->QP+" "+
      "eyes and breathes deeply.%^RESET%^",caster);
   return "display";
}

void spell_effect(int prof){
   object ob, blockobj;
   int bonus,power;

   if(!arg){
      tell_object(caster,"%^ORANGE%^You focus your %^CYAN%^inner "+
         "eye %^ORANGE%^and rest its gaze here to watch.%^RESET%^");
      if(place->query_property("no scry")){
         tell_object(caster,"Something blocks your attempt!");
         return;
      }
      bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
      power = clevel + bonus + random(6);
      if(blockobj = present("blockerx111", place)){
        if(power < blockobj->query_block_power()){
           tell_object(caster,"Something blocks your attempt!");
           dest_effect();
           return;
        }
      }
      eye = new("/d/magic/obj/innereye");
      eye->set_caster(caster);
      eye->set_property("spell",TO);
      eye->set_property("spelled", ({TO}) );
      eye->set_scry_power(power);
      eye->move(place);
      theName = place->query_short();
      spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
      set_end_time();
      call_out("dest_effect",spell_duration);
      caster->set_property("remote scrying",1);
      addSpellToCaster();
      return;
   }

   if(ob = find_player(caster->realNameVsProfile(arg))){
      if(objectp(ob) && !wizardp(ob)){
         tell_object(caster,"%^ORANGE%^You focus your %^CYAN%^inner "+
         "eye %^ORANGE%^and send it to watch "+capitalize(arg)+".%^RESET%^");
         if(environment(ob)->query_property("no scry")){
            tell_object(caster,"Something blocks your attempt!");
            return;
         }
         bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
         power = clevel + bonus + random(6);
         if(blockobj = present("blockerx111", environment(ob)) || blockobj = present("blockerx111",ob)){
            if(power < blockobj->query_block_power()){
               tell_object(caster, "Something blocks your attempt!");
               return;
            }
         }
         eye = new("/d/magic/obj/innereye");
         eye->set_caster(caster);
         eye->set_property("spell",TO);
         eye->set_property("spelled", ({TO}) );
         eye->set_target(ob);
         eye->set_scry_power(power);
         eye->move(environment(ob));
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
    if(objectp(eye))
        eye->dest_me();
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
