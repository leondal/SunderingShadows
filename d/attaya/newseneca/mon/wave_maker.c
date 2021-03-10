//to generate waves more often than on reset for new Seneca
//~Circe~ 6/17/08
#include <std.h>

inherit MONSTER;

int count;

void create(){
   ::create();
   set_name("wave maker");
   set_property("no detect",1);
   set_id(({"wave_maker"}));
   set_short(0);
   set_invis();
   add_limb("body","",0,0,0);
   count = 0;
   heart_beat();
}

void die(object ob){
}

void heart_beat(){
   ::heart_beat();
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   count++;
   if(count == 8){
      switch(random(5)){
         case 0: tell_room(ETO,"%^CYAN%^A small wave laps gently "+
                    "on the shore.%^RESET%^");
                 break;
         case 1: tell_room(ETO,"%^BOLD%^%^WHITE%^Foam%^RESET%^%^CYAN%^ "+
                    "sprays high into the air as a %^BOLD%^wave%^RESET%^ "+
                    "%^RESET%^%^CYAN%^breaks on the shore.%^RESET%^");
                 break;
         case 2: tell_room(ETO,"%^BOLD%^%^BLUE%^The light plays upon "+
                    "the water, making it sparkle b%^GREEN%^l%^CYAN%^u"+
                    "%^BLUE%^e%^GREEN%^-%^CYAN%^g%^BLUE%^r%^GREEN%^e"+
                    "%^CYAN%^e%^BLUE%^n.%^RESET%^");
                 break;
         case 3: tell_room(ETO,"%^BOLD%^%^CYAN%^A series of waves "+
                    "strikes the shore in succession, driving the "+
                    "surf further up the beach.%^RESET%^");
                 break;
         default: tell_room(ETO,"%^BOLD%^%^BLUE%^The music of the "+
                    "sea reaches a crescendo as a particularly "+
                    "large %^CYAN%^wave%^BLUE%^ pounds the shore.%^RESET%^");
                  break;
      }
      count = 0;
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

void set_invis(){
   if(TO->query_invis()) return;
   else ::set_invis();
   return;
}