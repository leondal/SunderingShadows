//Coded by Lujke
#define HEART "%^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^e %^RESET%^%^GREEN%^he%^ORANGE%^a%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^t"
#include <std.h>
#include "../tecqumin.h"

inherit ENERGY_SOURCE;

void create() {
    ::create();
    set_name("heart of the jungle");
    set_id( ({"heart","jungle heart","heart of the jungle", "amber stone",
             "xxjungheartxx", "amber", "stone" }) );
    set_obvious_short("%^ORANGE%^A piece of amb%^BOLD%^%^YELLOW%^e%^RESET%^"
                     +"%^ORANGE%^r");
    set_short("%^ORANGE%^heart of the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u"
             +"%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e"
             +"%^RESET%^");
    set_weight(1);
    set_long( (:TO, "long_desc" :) );
    msgs = ({"A thin beam of %^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^b%^BOLD%^"
      +"r%^ORANGE%^a%^GREEN%^nt %^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^"
      +"%^GREEN%^e%^BOLD%^%^WHITE%^r%^GREEN%^g%^YELLOW%^y %^RESET%^streams from"
      +" the " + HEART + " toward its target.", 

      "The "+ HEART + "'s %^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^n%^BOLD%^e%^RESET%^"
     +"%^GREEN%^r%^BOLD%^%^GREEN%^gy%^RESET%^ falters and dies away when it is"
     +" moved",

      "The %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e%^ORANGE%^a%^GREEN%^l%^RESET%^ opens up"
     +" beneath the %^BOLD%^%^CYAN%^e%^BLUE%^y%^CYAN%^e%^RESET%^.%^BOLD%^%^CYAN%^"
     +" Str%^WHITE%^ea%^CYAN%^ms of %^WHITE%^v%^RESET%^a%^BOLD%^%^WHITE%^p"
     +"%^RESET%^ou%^BOLD%^%^WHITE%^r %^RESET%^burst through from behind it under"
     +" high pressure",

      "The beam of %^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^b%^BOLD%^r%^ORANGE%^a"
      +"%^GREEN%^nt %^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^"
      +"%^WHITE%^r%^GREEN%^g%^YELLOW%^y %^RESET%^ flowing from the " + HEART 
      +" slowly soothes the %^BOLD%^%^CYAN%^e%^BLUE%^y%^CYAN%^e%^RESET%^"
      +" further and further shut",

      "The %^BLUE%^beam of %^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^b%^BOLD%^"
      +"r%^ORANGE%^a%^GREEN%^nt %^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^"
      +"%^GREEN%^e%^BOLD%^%^WHITE%^r%^GREEN%^g%^YELLOW%^y %^RESET%^expands as its"
      +" %^BOLD%^%^GREEN%^s%^WHITE%^oo%^GREEN%^th%^RESET%^%^GREEN%^i%^BOLD%^ng"
      +" %^WHITE%^l%^GREEN%^i%^WHITE%^ght%^RESET%^ caresses the"
      +" %^BOLD%^%^CYAN%^e%^BLUE%^y%^CYAN%^e%^RESET%^. Slowly, the"
      +" %^BOLD%^%^CYAN%^e%^BLUE%^y%^CYAN%^e%^RESET%^ loses its watchful"
      +" %^BOLD%^%^CYAN%^g%^WHITE%^l%^CYAN%^eam%^RESET%^ as it droops shut",

      "The %^BOLD%^%^CYAN%^e%^BLUE%^y%^CYAN%^e%^RESET%^ on the image"
      +" of the upright war gauntlet blinks slightly as the %^BLUE%^beam of"
      +" %^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^b%^BOLD%^r%^ORANGE%^a"
      +"%^GREEN%^nt %^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^"
      +"%^WHITE%^r%^GREEN%^g%^YELLOW%^y %^RESET%^hits it. The"
      +" %^BOLD%^%^CYAN%^e%^BLUE%^y%^CYAN%^e%^RESET%^ goes round, before appearing"
      +" to relax, absorbing the incoming energy, which seems to be lulling it shut",

     "Slowly, the beam of %^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^b%^BOLD%^r%^ORANGE%^a"
      +"%^GREEN%^nt %^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^"
      +"%^WHITE%^r%^GREEN%^g%^YELLOW%^y from the " + HEART + " dies away, leaving the"
    +" %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e%^ORANGE%^a%^BOLD%^%^GREEN%^l%^RESET%^"
    +" strengthened and reaffirmed in its wake. It is done.",

     "The %^BOLD%^%^BLUE%^blue %^CYAN%^av%^BLUE%^enturi%^CYAN%^ne"
    +"%^RESET%^ on the image of the upright war gauntlet %^BOLD%^%^CYAN%^br"
    +"%^WHITE%^i%^CYAN%^g%^BLUE%^h%^CYAN%^t%^WHITE%^e%^CYAN%^ns as the %^BLUE%^beam"
    +" of %^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^b%^BOLD%^r%^ORANGE%^a"
    +"%^GREEN%^nt %^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^"
    +"%^WHITE%^r%^GREEN%^g%^YELLOW%^y %^RESET%^hits it. The"
    +" %^BOLD%^%^CYAN%^je%^BLUE%^w%^CYAN%^el%^RESET%^ pulses, seeming to"
    +" %^RESET%^%^BLUE%^absorb%^RESET%^ the incoming energy.",

     "an ERROR message for something the " + HEART + " doesn't do",

     "an ERROR message for something the " + HEART + " doesn't do",

     "an ERROR message for something the " + HEART + " doesn't do",

     "an ERROR message for something the " + HEART + " doesn't do",

     "an ERROR message for something the " + HEART + " doesn't do",

     "an ERROR message for something the " + HEART + " doesn't do",

     "an ERROR message for something the " + HEART + " doesn't do",

      });
}

void init(){
  ::init();
  add_action("unleash_energy", "release");
}

string long_desc(){
  string desc;
  desc = "A heart shaped piece of %^ORANGE%^amb%^BOLD%^%^YELLOW%^e"
            +"%^RESET%^%^ORANGE%^r%^RESET%^. It is warm to the touch and"
            +" seems to glow slightly from inside.";
  if (objectp(ETO) && objectp(EETO) &&(base_name(EETO)== ROOMS + "cavern" || base_name(EETO)== TEST + "cavern")){
    if (EETO->query_seal_revealed()){
      desc += "%^ORANGE%^The heart of the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u"
             +"%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e"
             +"%^RESET%^ %^BOLD%^%^YELLOW%^glows%^RESET%^%^ORANGE%^ more"
             +" brightly in the presence of the %^BOLD%^%^GREEN%^mystic"
             +" s%^RESET%^%^GREEN%^e%^ORANGE%^a%^BOLD%^%^GREEN%^l%^RESET%^%^ORANGE%^."
             +" You feel that you could %^BOLD%^%^BLUE%^release%^RESET%^%^ORANGE%^"
             +" its energy toward the"
             +" %^BOLD%^%^CYAN%^j%^BLUE%^ewe%^CYAN%^l%^RESET%^%^ORANGE%^, in order"
             +" to %^BOLD%^%^BLUE%^strengthen the seal%^RESET%^%^ORANGE%^. On the"
             +" other hand, %^BOLD%^%^BLUE%^unleashing%^RESET%^%^ORANGE%^ the energy"
             +" toward the %^BOLD%^%^CYAN%^e%^BLUE%^y%^CYAN%^e %^RESET%^%^ORANGE%^might"
             +" cause the"
             +" %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e%^ORANGE%^a%^GREEN%^l%^ORANGE%^ to"
             +" open."; 
    }
  }
  return desc;
}
