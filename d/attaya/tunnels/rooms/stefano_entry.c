//stefano_entry.c - The entry point for Stefano's house from the outside world
#include <std.h>
//#include "/d/player_houses/stefano/stefano.h"
#include <move.h>
#include "../tunnel.h"

#define POWNERS ({ "gaius" }) //controls access to most secure parts of the house
#define PGUESTS ({ "nymeria", "testlackey" }) //controls access to the house in general

inherit VAULT;

int rune1;
int rune3;
int rune4;
int rune5;
int rune7;

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(GRASSLANDS);
  set_travel(FOOT_PATH);
  set_name("A sandy bank");
  set_short("A sandy bank");
  set_long(
      "%^GREEN%^You are standing on the %^RESET%^%^ORANGE%^sandy banks"
     +" %^GREEN%^of a flowing %^BLUE%^s%^CYAN%^tr%^RESET%^%^CYAN%^e"
     +"%^BOLD%^%^BLUE%^am%^RESET%^%^GREEN%^.  The stream here is too deep"
     +" to cross, so it blocks your way to the north. Past the stream you"
     +" can see the beginnings of a jungle to the southeast.  You can see"
     +" that that stream appears to continue for a short way to the east,"
     +" before seeming to vanish into the jungle. To the west, you see a"
     +" %^RESET%^grey stone tower%^GREEN%^ standing beside the stream,"
     +" within some well-tended gardens. A couple of smaller buildings"
     +" stand a little further to the west and a tall"
     +" %^BOLD%^%^BLACK%^ir%^RESET%^o%^BOLD%^%^BLACK%^n l%^RESET%^a"
     +"%^BOLD%^%^BLACK%^tt%^RESET%^i%^BOLD%^%^BLACK%^ce f%^RESET%^e"
     +"%^BOLD%^%^BLACK%^nc%^RESET%^e %^GREEN%^has been erected around the"
     +" perimiter of all three structures. There is a %^BOLD%^"
     +"%^BLACK%^gate%^RESET%^%^GREEN%^, but it looks to be closed and"
     +" locked.\n"
  );
  set_items(([
      (({"fence","iron fence","lattice fence"})) : "The twisted %^BOLD%^%^BLACK%^black "+
         "iron lattice%^RESET%^ has been wrought into complex, eye watering patterns.  "+
         "Sometimes there seem to be pictures in it, sometimes symbols, but it is hard to "+
         "focus your eyes and concentrate on any one spot. In the gaps between the iron "+
         "itself, you can see that the air shimmers with a %^CYAN%^faint blue haze%^RESET%^. "+
         "About half way along the fence, you can see a gate.",
      (({"tower","stone tower","grey tower","grey stone tower"})) : "The top of the grey stone "+
         "tower rises above the fence, but it is not very high, and is probably as wide across "+
         "as it is tall. There are a few arrowslits in the walls, but it looks otherwise unremarkable.",
      (({"patterns","shapes","symbols","pictures"})) : "Looking more closely at the gate, "+
         "you can make out the shapes of a number of runes you might be able to study.",
      (({"stream","flowing stream"})) : "The gently bubbling stream is crystal clear, allowing you "+
         "to see the golden, sandy bed below.",
      ({"jungle","jungles","trees"}) : "The jungle to the east is filled with palm trees and "+
         "other tropical plants.  There's a foreboding sort of feel to it.",
      (({"garden","gardens"})) : "Neatly tended lawns interspersed with flowerbeds frame a "+
         "gravel pathway leading to a grey stone tower just on the other side of the fence.",
      "buildings" : "On the other side of the fence are a two buildings.  One has a red tiled "+
         "roof and seems fairly large while the other is small and square with a flat roof.",
      (({"gate","gates"})) : "The gate looks solid, and the same subtle twists of iron play "+
         "tricks with your eyes here as in the fence. It is difficult to make out the exact "+
         "shapes contained within the lattice. There is a heavy lock in the gate.",
  ]));
  set_smell("default","You smell fresh water.");
  set_listen("default","You hear the gentle sound of the stream.");
  set_exits(([
      "south" :"/d/player_houses/stefano/path",
      "east" : TUNNELS+"tun_entry",
  ]));
      set_pre_exit_functions(({"gate"}),({"GoThroughDoor"}));
}
void init() {
   ::init();
   add_action("open_gate","open");
   add_action("study_runes","study");
   add_action("touch_rune","touch");
}

int open_gate(string str) {
   if(!str) {
     tell_object(TP,"Open what?");
     return 1;
   }
   if(str == "gate" || str == "gates") {
      tell_object(TP,"There is no handle on the gate, and it seems to be locked shut.");
      tell_room(ETP,TPQCN+" runs "+TP->query_possessive()+" hands along the tower but seems "+
         "unable to find a handle.",TP);
      return 1;
   }
   else return 1;
}
int study_runes(string str) {
   string mname=TP->query_name();

   if(!str || str != "runes") {
   tell_object(TP,"What are you trying to study?");
   return 0;
   }
//   if(TP->is_class("mage") || TP->is_class("bard")) {
   if(avatarp(TP) || member_array(mname,PGUESTS) != -1 || member_array(mname,POWNERS) != -1 || ((int)TP->query_skill("spellcraft") > 29)){
      tell_object(TP,"You can make out the runes for magic, power, trap, "+
         "opening, gates, danger, negation and spirits.");
      tell_room(ETP,""+TPQCN+" tilts "+TP->query_possessive()+" head and looks at the fence.",TP);
      return 1;
   }
/*   else if(TP->is_class("thief") && random(3)) {
      tell_object(TP,"You can make out the runes for magic, power, trap, "+
         "opening, gates, danger, negation and spirits.");
      tell_room(ETP,""+TPQCN+" tilts "+TP->query_possessive()+" head and looks at the fence.",TP);
      return 1;
   }
*/
   else{
      tell_object(TP,"You can make out 8 distinct runes within the lattice of the gate, "+
         "but try as you might, you cannot understand their meanings.");
      tell_room(ETP,""+TPQCN+" tilts "+TP->query_possessive()+" head and looks at the fence.",TP);
      return 1;
      }
}

/*%^BOLD%^%^CYAN%^touch_rune should be the mechanism to "unlock" the gate and lead into the tower.  They should have to touch the runes in the proper order (7,1,3,4,5 - or negation, magic, trap, opening, gates) to get in.%^RESET%^*/

int touch_rune(string str) {
object ob;
   if(!str) {
   tell_object(TP,"Which rune do you wish to touch?");
   return 1;
   }
   if(str =="rune 7" && !rune7){
      rune7=1;
      tell_object(TP,"You touch the rune and a tingle of energy runs through your fingertips.");
      tell_room(ETP,""+TPQCN+" reaches out and touches a shape in the fence.",TP);
      return 1;
      } 
   else if(str =="negation" && !rune7){
      rune7=1;
      tell_object(TP,"You touch the rune and a tingle of energy runs through your fingertips.");
      tell_room(ETP,""+TPQCN+" reaches out and touches a shape in the fence.",TP);
      return 1;
      } 
   else if(str =="rune 1" && rune7 && !rune1){
      rune1=1;
      tell_object(TP,"You touch the rune and a tingle of energy runs through your fingertips.");
      tell_room(ETP,""+TPQCN+" reaches out and touches a shape in the fence.",TP);
      return 1;
      }
   else if(str =="magic" && rune7 && !rune1){
      rune1=1;
      tell_object(TP,"You touch the rune and a tingle of energy runs through your fingertips.");
      tell_room(ETP,""+TPQCN+" reaches out and touches a shape in the fence.",TP);
      return 1;
      }
   else if(str =="rune 3" && rune7 && rune1 && !rune3){
      rune3=1;
      tell_object(TP,"You touch the rune and a tingle of energy runs through your fingertips.");
      tell_room(ETP,""+TPQCN+" reaches out and touches a shape in the fence.",TP);
      return 1;
      }
   else if(str =="trap" && rune7 && rune1 && !rune3){
      rune3=1;
      tell_object(TP,"You touch the rune and a tingle of energy runs through your fingertips.");
      tell_room(ETP,""+TPQCN+" reaches out and touches a shape in the fence.",TP);
      return 1;
      }
   else if(str =="rune 4" && rune7 && rune1 && rune3 && !rune4){
      rune4=1;
      tell_object(TP,"You touch the rune and a tingle of energy runs through your fingertips.");
      tell_room(ETP,""+TPQCN+" reaches out and touches a shape in the fence.",TP);
      return 1;
      }
   else if(str =="opening" && rune7 && rune1 && rune3 && !rune4){
      rune4=1;
      tell_object(TP,"You touch the rune and a tingle of energy runs through your fingertips.");
      tell_room(ETP,""+TPQCN+" reaches out and touches a shape in the fence.",TP);
      return 1;
      }
   else if(str =="rune 5" && rune7 && rune1 && rune3 && rune4 && !rune5){
      rune5=1;
      tell_object(TP,"You touch the rune and a tingle of energy runs through your fingertips.");
      tell_room(ETP,""+TPQCN+" reaches out and touches a shape in the fence.",TP);
      tell_room(ETP,"After the final rune is touched, all the symbols in the "+
         "%^BOLD%^%^BLACK%^black iron lattice%^RESET%^ flash %^BOLD%^%^CYAN%^bright blue%^RESET%^ "+
         "for an instant.");
      tell_object(TP,"A small iron key appears in your hand.");
      ob = new("/d/player_houses/obj/rune_key");
      if(ob->move(TP) != MOVE_OK){ 
      ob->move(ETP);
      }
      ob->move(TP);
      add_exit(SHOUSE"garden1","gate");
      return 1;
      }
   else if(str =="gates" && rune7 && rune1 && rune3 && rune4 && !rune5){
      rune5=1;
      tell_object(TP,"You touch the rune and a tingle of energy runs through your fingertips.");
      tell_room(ETP,""+TPQCN+" reaches out and touches a shape in the fence.",TP);
      tell_room(ETP,"After the final rune is touched, all the symbols in the "+
         "%^BOLD%^%^BLACK%^black iron lattice%^RESET%^ flash %^BOLD%^%^CYAN%^bright blue%^RESET%^ "+
         "for an instant.");
      tell_object(TP,"A small iron key appears in your hand.");
      ob = new("/d/player_houses/obj/rune_key");
      if(ob->move(TP) != MOVE_OK){ 
      ob->move(ETP);
      }
      ob->move(TP);
      add_exit(SHOUSE"garden1","gate");
      return 1;
      }
   else{
      tell_object(TP,"The rune glows suddenly %^BOLD%^%^CYAN%^blue%^RESET%^ as you touch "+
         "it, and you jerk your hand back in surprise as you realize it is icy cold!");
      tell_room(ETO,""+TPQCN+" jerks "+TP->query_possessive()+" hand back from the fence suddenly.",TP);
      rune7=0;
      rune1=0;
      rune3=0;
      rune4=0;
      rune5=0;
      return 1;
      }
}

int GoThroughDoor(){
   string mname=TP->query_name();
   if(avatarp(TP) || member_array(mname,PGUESTS) != -1 || member_array(mname,POWNERS) != -1 || ((int)TP->query_skill("spellcraft") > 29)){
//   if((wizardp(TP)) || (mname == "stefano")){
      return ::GoThroughDoor();
   }
   if(present("rune_key",TP)){
      return ::GoThroughDoor();
   }
   tell_object(TP,"%^BOLD%^%^CYAN%^As you try to step through the gates, the runes begin to swirl!  "+
      "A %^WHITE%^white mist %^CYAN%^rises in the air and streaks toward you!");
   tell_room(ETP,"%^BOLD%^%^CYAN%^As "+TPQCN+" tries to step through the gates, the runes begin to swirl!  "+
      "A %^WHITE%^white mist %^CYAN%^rises in the air and streaks toward "+TP->query_objective()+"!",TP);
   if(!"daemon/saving_d"->saving_throw(TP,"spell")) {
      tell_object(TP,"%^BOLD%^%^MAGENTA%^The mist slams into you, seeping into your limbs and draining away "+
         "your life.");
      TP->do_damage("torso",random(100)+50);
      TP->add_attacker(TO);
      TP->continue_attack();
      if(!objectp(TP)) return 0;
      TP->remove_attacker(TO);
      return 0;
   }
   tell_object(TP,"%^RESET%^%^MAGENTA%^You manage to move aside just as the spell hits, avoiding must of the damage.");
   TP->do_damage("torso",random(25)+25);
   TP->add_attacker(TO);
   TP->continue_attack();
   if(!objectp(TP)) return 0;
   TP->remove_attacker(TO);
   return 0;
}
