#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();
string view_gate();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(GAME_TRACK);
  set_name("Before some carved gates");
  set_short("%^GREEN%^Before some %^RESET%^carved %^GREEN%^gates%^RESET%^");
  set_long( (:TO, "long_desc":) );
  set_items (([ ({"gateway", "carved gateway", "strange gateway", "gate"}): 
     (:TO, "view_gate":)       ]) );
  set_search("gate",(:TO, "gate_search":));
  set_search("gateway",(:TO, "gate_search":));
  set_search("carved gateway",(:TO, "gate_search":));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.");
  set_exits((["northeast": TEST + "start"]));
}
void init() {
   ::init();
   add_action("open_gate", "open");
   add_action("read_runes", "read");
   add_action("show_face", "show");
}

string view_gate(){
  string desc, *deeds;
  desc = "The gateway appears to jut out from the front of the moss covered"
        +" mound of earth. It is formed of ancient, grey stone that has been"
        +" carved into the shape of two interlocking heads, facing one"
        +" another. On the left is the head of a jaguar, on the right is"
        +" that of a winged serpent.";
  if (query_exit("down") =="/d/shadowgate/void"){
    desc += " The design and carving is clever and"
        +" intricate, making it difficult to discern where one face ends"
        +" and the other begins. It is possible, however, to make out a"
        +" faint line between the two, which must indicate the point at"
        +" which the gateway would open. If you could get it open, of"
        +" course." ;
  } else {
    desc += " The two faces are far apart at the moment, as the gate has"
        +" opened up between them revealing the way down into an%^BLUE%^"
        +" underground %^BOLD%^%^BLACK%^c%^RESET%^a%^BOLD%^%^BLACK%^vern"
        +"%^RESET%^.";
  }
  deeds = TP->query_mini_quests();
  if (sizeof(deeds)<1 || member_array("Found the carved gate", deeds)==-1){
    TP->set_mini_quest("Found the carved gate");
  }
  return desc;
}

string long_desc(){
return "%^GREEN%^A strange %^RESET%^gateway%^GREEN%^ is here, emerging from a"
      +"%^ORANGE%^ mound of earth%^GREEN%^, in the middle of the jungle."
      +" %^BOLD%^%^GREEN%^Vibrant %^RESET%^%^GREEN%^gr%^BOLD%^%^GREEN%^ee"
      +"%^RESET%^%^GREEN%^n %^BOLD%^%^GREEN%^pl%^RESET%^%^GREEN%^a%^BOLD%^"
      +"%^GREEN%^nts%^RESET%^%^GREEN%^ with thick, waxy leaves gather"
      +" round the bases of %^BOLD%^%^BLACK%^ancient%^RESET%^%^GREEN%^"
      +" growth trees with thick boles and %^RESET%^%^ORANGE%^twisted"
      +" branches%^GREEN%^. %^BOLD%^%^WHITE%^F%^MAGENTA%^l%^BOLD%^"
      +"%^WHITE%^ow%^CYAN%^e%^BOLD%^%^WHITE%^rs%^RESET%^%^GREEN%^ with"
      +" %^BOLD%^%^MAGENTA%^v%^YELLOW%^i%^MAGENTA%^v%^CYAN%^i%^MAGENTA%^"
      +"d %^BLUE%^c%^RED%^o%^YELLOW%^l%^MAGENTA%^o%^CYAN%^u%^YELLOW%^r"
      +"%^BLUE%^s%^RESET%^%^GREEN%^ spring out from %^BOLD%^%^BLACK%^dark"
      +"%^RESET%^%^GREEN%^, surprising corners and thick, %^RESET%^"
      +"%^ORANGE%^trailing vines%^GREEN%^ wrap around the trees and other"
      +" plants. The plants grow quickly here, and such trails as there"
      +" are change as often as the lives and habits of the animals and"
      +" other creatures who inhabit this place.\n";
}

string gate_search(){
  return "You find some runes carved around the edge of the gateway. You don't"
        +" recognise them, but somehow you seem to be able to read them.";
}

int read_runes(string str){
  string * deeds;
  str = lower_case(str);
  if (str != "runes"){
    return 0;
  }
  tell_object(TP, "%^MAGENTA%^The strange runes somehow make sense to you,"
                  +" although the script is not one that is known to you. You"
                  +" read:%^RESET%^\nThe way of passing is clear, to those we"
                  +" know who can show their face to the gateway");
  tell_room(TO, TPQCN + " bends down to read some runes round the edge of the"
                +" gateway", TP);
  deeds = TP->query_mini_quests();
  if (sizeof(deeds)<1 || member_array("Read the runes on the carved gate", deeds)==-1){
    TP->set_mini_quest("Read the runes on the carved gate");
  }
  return 1;  
}

int open_gate(string str){
  str = lower_case(str);
  if (str!="gate" && str !="gateway"){
    return 0;
  }
  tell_object(TP, "There doesn't seem to be any way of opening it");
  tell_room(TO, TPQCN + " looks around the gateway but doesn't seem to find any"
              +" way to open it.", TP);
  return 1;
}

int show_face(string str){
  string show_what, to_what;
  object head;
  if (sscanf(str, "%s to %s", show_what, to_what)!=2){
    return 0;
  }
  if (to_what != "gate" && to_what !="gateway" && to_what != "carved gateway" 
                       && to_what != "the gateway"){
    return 0;
  }
  if (show_what == "face" || show_what == "my face" || show_what == "a face"){
    tell_object (TP, "You show your face to the gateway.");
    tell_room(TO, TPQCN + " shows " + TP->QP + " face to the strange carved"
             +" gateway", TP);
    call_out("rebuttal", 2, TP);
  }
  head = present("tecqumin head", TP);
  if (objectp(head)){
    if (head->id(show_what)){
      tell_object(TP, "You hold the " + head->query_short() + " up, presenting"
                     +" its face to the gateway"); 
      tell_room(TO, TPQCN + "%^RESET%^ holds a " + head->query_short() + " up,"
                    +" presenting its face to the gateway.");
      call_out("grant_entry", 3);
    }
  }
}

void rebuttal(object looker){
  if (!objectp(looker) || !present(looker, TO)){
    return;
  }
  tell_room(TO, "A voice that is not one voice, but a myriad whispering tongues"
              +" speaking together issues clearly from the gateway:"
             +" %^CYAN%^Who are you that looks upon the gateway? You are not one"
             +" known to us, stranger. Pass you shall not!");
}

void grant_entry(){
  tell_room(TO, "A voice that is not one voice, but a myriad whispering tongues"
              +" speaking together issues clearly from the gateway:"
             +" %^CYAN%^Ah! Qualtaolheth, you return to us. Welcome, brother.");
  call_out("grant_entry2", 2);
}

void grant_entry2(){
  tell_room(TO, "%^ORANGE%^A harsh grating sound of stone moving against stone fills"
             +" your ears as the %^RESET%^carved gateway swings open, the faces of"
             +" %^BOLD%^%^BLACK%^jaguar%^RESET%^ and %^BOLD%^%^GREEN%^w%^CYAN%^i"
             +"%^GREEN%^nged s%^RED%^e%^GREEN%^rp%^CYAN%^e%^GREEN%^nt shifting"
             +" apart with a slow, grudging motion.");
  add_exit( TEST + "cavern", "down");
}
