// please update mini_glyph with changes also; same item for different spell -Nienne.
#include <std.h>
#include <daemons.h>
inherit "/d/magic/obj/mini_glyph";

void create(){
    ::create();
    set_name("mini snare");
}

int search_em(string str){
   int bonus;
   string roomname;
   roomname = file_name(myroom);
   myexit = ETO->query_direction(roomname);
//   tell_object(find_player(mycaster),"Myexit is "+myexit+".");
//The above was for debugging - leaving in case needed again.
   if(!str || str != myexit){
      if(TP->is_class("thief")){
         if((int)TP->query_guild_level("thief") > random(glyph_power)){
            tell_object(TP,"Something catches your eye to the "+myexit+".");
//random chance to find a clue by inspecting
            return 1;
         }
      }
      return 0;
   }
   if(str && str == myexit){
//      tell_object(find_player(mycaster),"Right direction.");
//The above was for debugging - leaving in case needed again.
      if(!TP->is_class("thief")) return 1;
      bonus = (int)TP->query_guild_level("thief");
      if(!TP->is_singleClass()) bonus = (bonus*2)/3;
//      tell_object(find_player(mycaster),"Bonus = "+bonus+".");
//      tell_object(find_player(mycaster),"Glyph power = "+glyph_power+".");
//The above was for debugging - leaving in case needed again.
      if(random(bonus) > random(glyph_power)){ 
//fair roll versus the caster to notice the glyph
         tell_object(TP,"You seem to notice a snare in the room "+
            "to the "+myexit+".  If you like, you may try to "+
            "<disable direction> to end its effect, though this "+
            "could have disastrous consequences.  You may also "+
            "be able to simply sneak in without stepping on it.");
         found++;
         return 1;
      }else{
         tell_object(TP,"You do not find anything unusual to the "+str+".");
         return 1;
      }
   }else{
      return 0;
   }
}

int disable_em(string str){
int bonus;
string roomname;
roomname = file_name(myroom);
myexit = ETO->query_direction(roomname);
//   tell_object(find_player(mycaster),"Myexit is "+myexit+".");
//The above was for debugging - leaving in case needed again.
   if(!str || str != myexit) return 1;
   if(!TP->is_class("thief")){
      tell_object(TP,"What?");
      return 1;
   }
   if(found < 1){
      tell_object(TP,"What?");
//must be found before it can be disabled
      return 1;
   }
   if(tried > 0){
      tell_object(TP,"The snare seems to resist your attempts!");
//can't keep trying until you get it
      return 1;
   }
   bonus = (int)TP->query_guild_level("thief");
   if(!TP->is_singleClass()) bonus = (bonus*2)/3;
   if((bonus*2)< glyph_power){ failure(); return 1; }  
//so lowbie thieves can't disable really high level glyphs
   if(random(bonus) > (random(glyph_power))+10){
      success();
      return 1;
   }else{
      failure();
      return 1;
   }
}

void success(){
   tell_object(TP,"Working carefully, you manage to disable the "+
      "snare, causing its surface to glow briefly before fading, "+
      "as the hidden spikes tumble harmlessly aside.");
   tell_room(myroom,"The snare on the floor glows briefly once "+
      "and then fades away, as the hidden spikes tumble harmlessly "+
      "aside.");
   tell_room(ETO,""+TPQCN+" kneels down and seems to be working "+
      "on something.",TP);
   main_ob->self_destruct();
   return;
}

void failure(){
int dam;
   tell_object(TP,"You try to carefully remove the snare but fumble "+
      "it, upsetting a spike in the process which embeds itself in "+
      "your hand!");
   tell_room(ETO,""+TPQCN+" kneels down and seems to be working "+
      "for a moment before jerking away in pain, a spike embedded "+
      "in "+TP->QP+" hand!",TP);
   tell_object(find_player(mycaster),"You sense a disturbance in the snare's "+
      "energy as someone tampers with it.  You sense that the "+
      "snare remains intact, however.");
   dam = glyph_power/3;
   if(dam < 1) dam = 1;
   if(dam > 12) dam = 12;
   dam = roll_dice(dam,4);
//half-damage of the glyph itself
   TP->do_damage(TP->return_target_limb(),dam);
   TP->add_attacker(TO);
   TP->continue_attack();
   if(objectp(TP)) TP->remove_attacker(TO);
   tried = 1;
   return;
}