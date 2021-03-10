//mini_glyph.c - small remote objects that surround
//the main glyph to allow for interactions from thieves
//and other players
//~Circe~ 1/1/08
// please update mini_snare with changes also; same item for different spell -Nienne.
#include <std.h>
#include <daemons.h>

inherit MONSTER;
//Monster for the invis abilities and such

void set_main_ob(object ob);
void set_mycaster(string str);
void set_glyph_power(int x);
void success();
void failure();
void query_myroom();
string mycaster,myexit;
object main_ob,myroom;
int glyph_power, found, tried;

void create(){
    ::create();
    set_name("mini glyph");
    set_property("no detect",1);
    set_id(({"mini_glyphx111"}));
    set_short(0);
    set_invis();
    add_limb("body","",0,0,0);
    found = 0;
    tried = 0;
   set_property("knock unconscious",1);
}

void reset(){
   ::reset();
   if(found > 0) found = 0;
   if(tried > 0) tried = 0;
}

void init(){
   ::init();
   add_action("search_em","search");
   add_action("disable_em","disable");
}

void set_main_ob(object ob){
   main_ob = ob;
}

void set_myroom(object obj){
   myroom = obj;
}

void query_myroom(){
   return myroom;
}

void set_mycaster(string str){
   mycaster = str;
//   tell_object(find_player(mycaster),"Setting "+mycaster+" as the caster on the mini mes.");
//The above was for debugging - leaving in case needed again.
}

void set_glyph_power(int x){
   glyph_power = x;
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
         tell_object(TP,"You seem to notice a glyph in the room "+
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
      tell_object(TP,"The glyph seems to resist your attempts!");
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
      "glyph, causing it to flash brightly before fading.");
   tell_room(myroom,"A %^BOLD%^%^CYAN%^glyph %^RESET%^on the floor "+
      "flashes brightly once and then fades away.");
   tell_room(ETO,""+TPQCN+" kneels down and seems to be working "+
      "on something.",TP);
   main_ob->self_destruct();
   return;
}

void failure(){
int dam;
   tell_object(TP,"You try to carefully remove the glyph but are "+
      "%^YELLOW%^zapped %^RESET%^for your efforts.");
   tell_room(ETO,""+TPQCN+" kneels down and seems to be working "+
      "for a moment before suddenly being %^YELLOW%^zapped "+
      "%^RESET%^from an unseen source!",TP);
   tell_object(find_player(mycaster),"You sense a disturbance in the glyph's "+
      "energy as someone tampers with it.  You sense that the "+
      "glyph remains intact, however.");
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