//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"


inherit ENERGY_SOURCE;

void create() {
    ::create();
    opening = 0;
    sealing = 0;
    set_name("Jetstone");
    set_id( ({"jetstone","stone","jet", "jet stone", "xxjetstonexx" }) );
    set_short("%^BOLD%^%^BLACK%^A piece of jetstone%^RESET%^");
    set_weight(1);
    set_long( (:TO, "long_desc" :) );
    msgs = ({"A thin beam of %^BOLD%^%^BLACK%^dark"
      +" en%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^rgy %^RESET%^streams from the"
      +" heart of the stone toward its target.",

      "The %^BLUE%^j%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^tst%^RESET%^"
      +"o%^BLUE%^ne's %^BOLD%^%^RED%^bl%^RESET%^%^RED%^ood"
       +" r%^BOLD%^e%^RESET%^%^RED%^d%^RESET%^ %^BOLD%^%^RED%^en%^RESET%^%^RED%^"
      +"er%^BOLD%^gy%^RESET%^ falters and dies away when it is moved",

      "The cracks in the seal widen, and"
    +" %^BOLD%^%^CYAN%^str%^WHITE%^ea%^CYAN%^ms of"
    +" %^WHITE%^v%^RESET%^a%^BOLD%^%^WHITE%^p%^RESET%^ou%^BOLD%^%^WHITE%^r"
    +" %^RESET%^burst through from behind them under high pressure",

      "The beam of %^BOLD%^%^RED%^bl%^RESET%^%^RED%^ood"
      +" r%^BOLD%^e%^RESET%^%^RED%^d%^RESET%^ %^BOLD%^%^RED%^en%^RESET%^%^RED%^"
      +"er%^BOLD%^gy%^RESET%^ flowing from the %^BLUE%^j%^BOLD%^%^BLACK%^e%^RESET%^"
      +"%^BLUE%^tst%^RESET%^o%^BLUE%^ne%^RESET%^ opens the"
      +" %^BOLD%^%^CYAN%^e%^BLUE%^y%^CYAN%^e%^RESET%^ wider and wider, until cracks"
      +" begin to form in the seal around it.",

      "The %^BLUE%^beam of %^BOLD%^%^BLACK%^dark"
    +" en%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^rgy %^RESET%^widens and gradually"
    +" turns %^BOLD%^%^RED%^bl%^RESET%^%^RED%^ood"
    +" r%^BOLD%^e%^RESET%^%^RED%^d%^RESET%^. Slowly, the"
    +" %^BOLD%^%^CYAN%^e%^BLUE%^y%^CYAN%^e%^RESET%^ is forced further and further"
    +" open.",

      "The %^BOLD%^%^CYAN%^e%^BLUE%^y%^CYAN%^e%^RESET%^ on the image"
    +" of the upright war gauntlet widens as the %^BLUE%^beam of %^BOLD%^%^BLACK%^"
    +"dark en%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^rgy %^RESET%^hits it. The"
    +" %^BOLD%^%^CYAN%^e%^BLUE%^y%^CYAN%^e%^RESET%^ goes round, before appearing"
    +" to tense, straining against the incoming energy, which seems to be"
    +" attempting to push it open.",

     "Slowly, the %^BLUE%^beam%^RESET%^ of energy from the"
    +" %^BOLD%^%^BLACK%^jetstone%^RESET%^ dies away, leaving the"
    +" %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e%^ORANGE%^a%^BOLD%^%^GREEN%^l%^RESET%^"
    +" strengthened and reaffirmed in its wake. It is done.",

     "The %^BOLD%^%^BLUE%^blue %^CYAN%^av%^BLUE%^enturi%^CYAN%^ne"
    +"%^RESET%^ on the image of the upright war gauntlet %^BOLD%^%^CYAN%^br"
    +"%^WHITE%^i%^CYAN%^g%^BLUE%^h%^CYAN%^t%^WHITE%^e%^CYAN%^ns as the %^BLUE%^beam"
    +" of %^BOLD%^%^BLACK%^dark en%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^rgy %^RESET%^"
    +"hits it. The %^BOLD%^%^CYAN%^je%^BLUE%^w%^CYAN%^el%^RESET%^ pulses, seeming"
    +" to %^RESET%^%^BLUE%^absorb%^RESET%^ the incoming energy.",

     "You raise the %^BLUE%^jetstone%^RESET%^ toward the"
    +" %^ORANGE%^gate%^RESET%^ and mentally allow it to %^CYAN%^release"
    +" %^RESET%^some of the energy it contains",

     " raises the %^BLUE%^jetstone%^RESET%^ toward the %^ORANGE%^gate%^RESET%^",

     "The vibrations in the %^BLUE^%^jetstone%^RESET%^ subside.",

     "The %^BLUE%^jetstone's%^RESET%^ vibrations increase to an audible hum and it"
    +" grows warm in your hands.",

     "The %^BLUE%^jetstone's%^RESET%^ vibrations increase to an audible hum.",

     "A beam of dull blue energy emerges from the jetstone, casting the gate in a"
    +" monochrome light.",

     "The light fades from the %^BLUE^%^jetstone%^RESET%^ and the vibrations subside.",
      });
}

void init(){
  ::init();
}

string long_desc(){
  string desc;
  desc = "%^BOLD%^%^BLACK%^A simple stone of jet, shaped into a flat"
            +" oval, with a jaguar's face carved into the front. Intricate"
            +" runeshapes surround the jaguar face and adorn a circled"
            +" pentagram inscribed on the back of the stone. The%^CYAN%^"
            +" pentagram %^BOLD%^CYAN%^gl%^RESET%^%^CYAN%^o%^BOLD%^CYAN%^ws"
            +" %^BOLD%^%^BLACK%^with an eerie %^RESET%^inner%^BOLD%^%^BLACK%^"
            +" l%^BOLD%^%^CYAN%^i%^BOLD%^%^BLACK%^ght.";
  if (objectp(ETO) && TP == ETO && objectp(EETO)
       && (base_name(EETO)==JUNG_ROOM10 + "carved_gate" || base_name(EETO)==TEST + "carved_gate")
       && EETO->query_exit("down") == "/d/shadowgate/void"){
    desc += " %^RESET%^The %^BLUE%^jetstone%^RESET%^ vibrates and pulls"
      +" toward the gate. You have the feeling that you could%^BOLD%^"
      +" %^YELLOW%^release%^RESET%^ its energy against the gate.";
  }
  if (objectp(ETO) && TP == ETO && objectp(EETO)
       && (base_name(EETO)==ROOMS + "cavern" || base_name(EETO)==TEST + "cavern")
       && EETO->query_seal_revealed()){
    desc += " %^RESET%^The %^BLUE%^jetstone%^RESET%^ vibrates and pulls"
      +" toward the seal. You have the feeling that you could%^BOLD%^"
      +" %^YELLOW%^unleash%^RESET%^ its energy against the eye on the gauntlet.";
  }

  return desc;
}
