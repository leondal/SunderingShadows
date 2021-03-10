 //Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
#define EYE "the %^BOLD%^%^BLUE%^blue eye%^RESET%^ of %^BOLD%^%^RED%^H%^RESET%^e%^BOLD%^%^WHITE%^l%^BLUE%^m%^RESET%^ depicted on the upright war gauntlet"
#define JEWEL "the %^BOLD%^%^BLUE%^blue %^CYAN%^av%^BLUE%^enturi%^CYAN%^ne %^RESET%^set on the wrist of the image of the upright war gauntlet"


inherit OBJECT;

int opening, sealing;


void create() {
    ::create();
    opening = 0;
    sealing = 0;
    set_name("Jetstone");
    set_id( ({"jetstone","stone","jet", "jet stone", "xxjetstonexx" }) );
    set_short("%^BOLD%^%^BLACK%^A piece of jetstone%^RESET%^");
    set_weight(1);
    set_long( (:TO, "long_desc" :) );
}

void init(){
  ::init();
  add_action("release_energy", "release");
}

int unleash_energy(string str){
  int num;
  string what, target;
  if (!objectp(ETO) || !interactive(ETO)){
    return 0;
  }
  if (!objectp(EETO) || (base_name(EETO)!= ROOMS + "cavern" && base_name(EETO)!= TEST + "carved_gate")||!EETO->query_seal_revealed()){
    return notify_fail("There is nowhere suitable to unleash the energy round here at the moment");
    return 0;
  }
  num = sscanf(str, "%s at %s", what, target);
  if (num <2){
    num = sscanf(str, "%s against %s", what, target);
  }
  if (num <2){
    num = sscanf(str, "%s toward %s", what, target);
  }
  if (num <2){
    num = sscanf(str, "%s on %s", what, target);
  }
  if (num <2 ){
    tell_object(ETO, "What do you want to unleash against what?");
    return 1;
  }
  if (what != "energy" && what != "jetstone" && what != "jetstone's energy" ){
    tell_object(ETO, "What do you want to unleash against what?");
    return 1;   
  }
  if (target != "eye" && target != "eye of helm" && target != "blue eye" && target != "blue eye of Helm"
       && target != "jewel" && target != "blue jewel" && target != "aventurine"
       && target != "blue aventurine" && target != "wrist"){
    tell_object(ETO, "What do you want to unleash energy against?");
    return 1;   
  } 
  switch (target){
  case "eye":
  case "eye of helm":
  case "blue eye": 
  case "blue eye of Helm":
    target = EYE;
    opening = 1;
    break;
  case "jewel":
  case "blue jewel":
  case "aventurine":
  case "blue aventurine":
  case "wrist":
    target = JEWEL;
    sealing = 1;
    break;
  }
  tell_object(ETO, "You raise the %^BLUE%^jetstone%^RESET%^ and unleash"
    +" its %^ORANGE%^power%^RESET%^ at " + target + "%^RESET%^. A thin beam"
    +" of %^BOLD%^%^BLACK%^dark en%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^rgy"
    +" %^RESET%^streams from the heart of the stone toward its target.");
  tell_room(EETO, ETO->QCN + " raises  the %^BLUE%^jetstone%^RESET%^ and unleashes"
    +" its %^ORANGE%^power%^RESET%^ at " + target + "%^RESET%^. A thin beam"
    +" of %^BOLD%^%^BLACK%^dark en%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^rgy"
    +" %^RESET%^streams from the heart of the stone toward its target.", ETO);
  switch(target){
  case EYE:
    call_out("open_seal", 3, ETO);
    break;
  case JEWEL:
    call_out("seal_seal", 3, ETO);
    break;
  }
  return 1;
}


void absorb_quali(){
  call_out("absorb_quali2", 2, EETO);
}

void absorb_quali2(object room){
  if (!objectp(room) || !objectp(EETO) || EETO!=room){
    if (objectp(ETO)){
      tell_room(ETO, "Movement interrupts the %^BLUE%^jetstone's%^RESET%^"
        +" absorption of %^BOLD%^%^GREEN%^Q%^RESET%^%^GREEN%^u%^ORANGE%^"
        +"a%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^i's%^RESET%^ essence");
      return;
    }
  }
  tell_room(EETO, "The %^BOLD%^%^GREEN%^gr%^RESET%^%^GREEN%^ee%^BOLD%^n"
    +" %^WHITE%^l%^GREEN%^i%^WHITE%^ghts%^RESET%^ continue to stream into"
    +" the %^BLUE%^jetstone%^RESET%^, which seems to become heavier and"
    +" more potent as it absorbs the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u"
    +"%^BOLD%^%^GREEN%^ngl%^RESET%^%^GREEN%^e %^BOLD%^%^GREEN%^sp"
    +"%^WHITE%^i%^GREEN%^r%^WHITE%^i%^GREEN%^t's%^RESET%^"
    +" enormous power");
  call_out("absorb_quali3", 3, EETO);
}

void absorb_quali3(object room){
  object ob;
  if (!objectp(room) || !objectp(EETO) || EETO!=room){
    if (objectp(ETO)){
      tell_room(ETO, "Movement interrupts the %^BLUE%^jetstone's%^RESET%^"
        +" absorption of %^BOLD%^%^GREEN%^Q%^RESET%^%^GREEN%^u%^ORANGE%^"
        +"a%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^i's%^RESET%^ essence");
      return;
    }
  }
  tell_room(EETO, "The stream of %^WHITE%^l%^GREEN%^i%^WHITE%^ghts dies"
    +" away as the last of the essence of"
    +" %^BOLD%^%^GREEN%^Q%^RESET%^%^GREEN%^u%^ORANGE%^a%^BOLD%^%^GREEN%^"
    +"l%^RESET%^%^GREEN%^i%^RESET%^ trickles into the %^BLUE%^jetstone");
  ob = new(OBJ + "powerstone");
  ob->move(ETO);
  move("/d/shadowgate/void");
}

int release_energy(string str){
  if (!objectp(ETO) || !interactive(ETO)){
    return 0;
  }
  if (!objectp(EETO) || (base_name(EETO)!= ROOMS + "carved_gate" && base_name(EETO)!= TEST + "carved_gate")){
    return 0;
  }
  if (EETO->query_exit("down")!="/d/shadowgate/void"){
    return 0;
  }
  tell_object(ETO, "You raise the %^BLUE%^jetstone%^RESET%^ toward the"
    +" %^ORANGE%^gate%^RESET%^ and mentally allow it to %^CYAN%^release"
    +" %^RESET%^some of the energy it contains");
  tell_room(EETO, ETO->QCN + " raises the %^BLUE%^jetstone%^RESET%^"
    +" toward the %^ORANGE%^gate%^RESET%^", ETO);
  call_out("release2", 2);
}

void release2(){
  if (!objectp(ETO) || !interactive (ETO)){
    return;
  }
  if (!objectp(EETO) || (base_name(EETO)!= ROOMS + "carved_gate" && base_name(EETO)!= TEST + "carved_gate")){
    return;
  }
  if (EETO->query_exit("down")!="/d/shadowgate/void"){
    tell_room(EETO, "The vibrations in the %^BLUE^%^jetstone%^RESET%^"
      +" subside.");
    return;
  }
  tell_object(ETO, "The %^BLUE%^jetstone's%^RESET%^ vibrations increase"
    +" to an audible hum and it grows warm in your hands.");
  tell_room(EETO, "The %^BLUE%^jetstone's%^RESET%^ vibrations increase"
    +" to an audible hum.", ETO);
  call_out("release3", 3);
}

void release3(){
  if (!objectp(ETO) || !interactive (ETO)){
    return;
  }
  if (!objectp(EETO) || (base_name(EETO)!= ROOMS + "carved_gate" && base_name(EETO)!= TEST + "carved_gate")){
    return;
  }
  if (EETO->query_exit("down")!="/d/shadowgate/void"){
    tell_room(EETO, "The vibrations in the %^BLUE^%^jetstone%^RESET%^"
      +" subside.");
    return;
  }
  tell_room(EETO, "A beam of dull blue energy emerges from the"
    +" jetstone, casting the gate in a monochrome light.");
  call_out("release4", 1);
}

void release4(){
  if (!objectp(ETO) || !interactive (ETO)){
    return;
  }
  if (!objectp(EETO) || (base_name(EETO)!= ROOMS + "carved_gate" && base_name(EETO)!= TEST + "carved_gate")){
    return;
  }
  if (EETO->query_exit("down")!="/d/shadowgate/void"){
    tell_room(EETO, "The lightfades from the %^BLUE^%^jetstone%^RESET%^"
      +" and the vibrations subside.");
    return;
  }
  tell_room(EETO, "Slowly, and with great reluctance, the gate creaks"
    +" open, revealing the opening to a cavern descending below"
    +" ground.");
  if (base_name(EETO) == ROOMS + "carved_gate"){
    EETO->add_exit(ROOMS + "cavern", "down");
  } else {
    EETO->add_exit(TEST + "cavern", "down");
  }
}

string long_desc(){
  string desc;
  desc = "%^BOLD%^%^BLACK%^A simple stone of jet, shaped into a flat"
            +" oval, with a jaguar's face carved into the front. Intricate"
            +" runeshapes surround the jaguar face and adorn a circled"
            +" pentagram inscribed on the back of the stone.";
  if (objectp(ETO) && TP == ETO && objectp(EETO)  
       && base_name(EETO)==ROOMS + "carved_gate"       
       && EETO->query_exit("down") == "/d/shadowgate/void"){
    desc += " %^RESET%^The %^BLUE%^jetstone%^RESET%^ vibrates and pulls"
      +" toward the gate. You have the feeling that you could%^BOLD%^"
      +" %^YELLOW%^release%^RESET%^ its energy against the gate.";
  }
  return desc;
}

