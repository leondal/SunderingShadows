//Glyph of Warding
//for the Creation domain spell
//Based somewhat on the scry_blocker.c by Thorn
//~Circe~ 12/31/07
//snare.c is based on similar code (minus warnings to the caster). Please apply updates to both as necessary -Nienne.

#include <std.h>
#include <daemons.h>

inherit MONSTER;
//Monster for the invis abilities and such

object myroom, *already_there, *mini_mes = ({});
int dam, glyph_power;

void self_destruct();
void set_mycaster(string str);
string mycaster;
void set_mygroup(object *obj);
object *mygroup;
void set_myroom(object obj);
void success();
void failure();
void add_mini_me(object ob);
void set_glyph_power(int x);
void query_myroom();

void create(){
    ::create();
    
    set_name("glyph of warding");
    set_property("no detect",1);
    set_id(({"glyphx111"}));
    set_short(0);
    set_invis();
    add_limb("body","",0,0,0);
   set_property("knock unconscious",1);
}

void init(){
int bonus,lvl;
   ::init();
   if(!TP->query_property("already_there") || (string)TP->query_property("already_there") != mycaster && !TP->query_true_invis()){
      if(TP->is_class("thief") && TP->query_hidden()){
         bonus = TP->query_stats("dexterity");
         bonus = (bonus - 10)/2;
         if(TP->is_singleClass()){
            lvl = (TP->query_guild_level("thief"));
            lvl = lvl+bonus;
         }else{
            lvl = 2*((int)TP->query_guild_level("thief"));
            lvl = lvl/3;
            lvl = lvl+bonus;
         }
//The thief code allows for hidden single class thieves to have
//a 50/50 chance of avoiding the glyph by sneaking.  Multi class
//thieves have a lower chance but still have a chance.
         if(random(lvl) > random(glyph_power)){
            success();
         }else{
            failure();
         }
      }else{
//For everyone else, their wisdom gives them a chance to avoid the
//glyph.  So someone with an 18 wisdom has an 18% chance of avoiding
         bonus = TP->query_stats("wisdom");
         if(random(101) < bonus){
            success();
         }else{
            failure();
         }
      }
   }else{
      tell_object(TP,"%^BOLD%^%^CYAN%^You sense the protection of "+
         "the glyph flood the area.%^RESET%^");
   }
}

void add_mini_me(object ob){
   mini_mes += ({ob});
}

void failure(){
   tell_object(find_player(mycaster),"%^BOLD%^%^BLACK%^"+
      ""+TPQCN+" %^BOLD%^%^BLACK%^crosses the %^CYAN%^glyph's %^BLACK%^"+
      "protective circle and is blasted by its power!%^RESET%^");
   tell_room(ETO,"%^BOLD%^%^BLACK%^"+TPQCN+" %^BOLD%^%^BLACK%^crosses "+
      "the %^CYAN%^glyph's %^BLACK%^protective circle "+
      "and is blasted by its power!%^RESET%^",({TP,find_player(mycaster)}));
   tell_object(TP,"%^BOLD%^%^BLACK%^As you enter the area, "+
      "you are blasted by the power of a %^CYAN%^glyph"+
      "%^BLACK%^!%^RESET%^");
   dam = glyph_power/3;
   if(dam < 1) dam = 1;
   if(dam > 12) dam = 12;
   dam = roll_dice(dam,8);
   TP->do_damage(TP->return_target_limb(),dam);
   TP->add_attacker(TO);
   TP->continue_attack();
   if(objectp(TP)) TP->remove_attacker(TO);
   self_destruct();
   return;
}

void success(){
   tell_object(TP,"%^BOLD%^%^WHITE%^You carefully move into the "+
      "area, managing to avoid the %^CYAN%^glyph %^WHITE%^you "+
      "spot on the floor.%^RESET%^");
   return;
}

void set_mycaster(string str){
   mycaster = str;
//   tell_object(find_player(mycaster),"Setting "+mycaster+" as the caster on the main obj.");
//The above was for debugging - leaving in case needed again.
}

void set_mygroup(object *obj){
   mygroup = obj;
}

void set_myroom(object obj){
   myroom = obj;
}

void query_myroom(){
   return myroom;
}

void set_glyph_power(int x){
   glyph_power = x;
}

void die(object ob){
}

void heart_beat(){
    ::heart_beat();
    if(!objectp(myroom)) {
        self_destruct();
        return;
    }
/*
    if(!present(mycaster,ETO)){
        self_destruct();
        return;
    }
*/
    if(!find_player(mycaster)){
        self_destruct();
        return;
    }
}

int do_damage(string str, int i){
    return 0;
}

int is_invincible(){ return 1;}
int is_detectable(){ return 0;}

int id(string str){
    if(objectp(TP) && !avatarp(TP)) return 0;
    else return ::id(str);
}

void self_destruct() {
int i;
object casterobj,*spells = ({});
   if(sizeof(mygroup)>0){
      for(i=0;i<sizeof(mygroup);i++){
         if(!objectp(mygroup[i])) break;
         if(!mygroup[i]->query_property("already_there")) break;
         if((string)mygroup[i]->query_property("already_there") != mycaster) break;
         mygroup[i]->remove_property("already_there");
      }
   }
//   if(sizeof(mini_mes)>0){
      for(i=0;i<sizeof(mini_mes);i++){
         if(objectp(mini_mes[i])){
//            tell_object(find_player(mycaster),"Removing mini mes.");
//The above was for debugging - leaving in case needed again.
            mini_mes[i]->remove();
         }else{
            tell_object(find_player(mycaster),"Uh oh, something's wrong - can't remove mini mes.");
         }
      }
//   }
   casterobj = find_player(mycaster);
   if(objectp(casterobj)){                  // Adjusted by Lujke 5th July 2010, to make this whole  
     casterobj->remove_property("glyphed");  //section dependent on casterobj being a valid object
     spells += casterobj->query_property("dispellable spells");
     for(i=0;i<sizeof(spells);i++){  
        if(objectp(spells[i])){
           if(!spells[i]->query_target_object()){
              if((string)spells[i]->query_spell_name() == "glyph of warding"){
                 if(!objectp(spells[i])) return notify_fail("Your glyph of warding seems to have been lost.\n");
                 tell_object(casterobj,"%^CYAN%^The glyph of warding fades away.", TP);
                 spells[i]->removeSpellFromCaster();
              }
           }
        }
     }
   }
   if(objectp(TO)) TO->remove();
   return;
}
