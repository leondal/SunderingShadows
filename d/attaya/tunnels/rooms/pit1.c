#include <std.h>
#include <terrain.h>
#include "../tunnel.h"
inherit ROOM;

void create() {
  ::create();
  set_short("%^BOLD%^%^YELLOW%^A gl%^WHITE%^i%^YELLOW%^tter%^WHITE%^i"
           +"%^YELLOW%^ng tr%^RESET%^%^ORANGE%^ea%^YELLOW%^s%^RESET%^"
           +"%^ORANGE%^u%^YELLOW%^re tr%^RESET%^%^ORANGE%^o%^YELLOW%^ve");
  set_long("%^BOLD%^%^BLACK%^You are in a steep-sided pit, some twenty"
          +" feet deep, with nasty metal spikes at the bottom. The walls" 
          +" are damp with %^RESET%^c%^CYAN%^o%^RESET%^ndens%^CYAN%^a"
          +"%^RESET%^ti%^CYAN%^o%^RESET%^n%^BOLD%^%^BLACK%^, and rats"
          +" scurry around amongst the few pitiful skeletons already down"
          +" here.%^RESET%^");
 set_items( ([ 
 ({ "wall", "walls"}):"%^BOLD%^%^BLACK%^The walls are of black slate"
                     +". They are smooth, and damp with condensation",
  
  "ceiling" : "Up above, you can see a wh%^BOLD%^%^WHITE%^i%^RESET%^sp"
             +"%^BOLD%^%^WHITE%^e%^RESET%^ry, transparent %^CYAN%^i"
             +"%^RESET%^l%^CYAN%^l%^RESET%^u%^CYAN%^si%^RESET%^o%^CYAN%^n"
             +"%^RESET%^ of a %^BOLD%^%^YELLOW%^A gl%^WHITE%^i"
             +"%^YELLOW%^tter%^WHITE%^i%^YELLOW%^ng tr%^RESET%^"
             +"%^ORANGE%^ea%^YELLOW%^s%^RESET%^%^ORANGE%^u%^YELLOW%^re"
             +" tr%^RESET%^%^ORANGE%^o%^YELLOW%^ve", 
  
  "floor" : "The floor is sticky, and strewn with debris",

  "skeletons": "%^BOLD%^%^BLACK%^These poor unfortunates look like they"
              +" died some while ago. You notice that there is nothing"
              +" left of any belongings or clothing, and are those"
              +" %^RESET%^%^ORANGE%^t%^RESET%^oo%^ORANGE%^t%^RESET%^h"
              +" mar%^ORANGE%^k%^RESET%^s %^BOLD%^%^BLACK%^on the bones?"
              +" Either way, they have been %^RESET%^str%^BOLD%^"
              +"%^WHITE%^i%^RESET%^pp%^BOLD%^%^WHITE%^e%^RESET%^d"
              +" c%^BOLD%^%^WHITE%^l%^RESET%^ean%^BOLD%^%^BLACK%^."

   ]) );
        set_climb_exits((["climb":({TUNNELS+"tun17",40,6,100})]));
}

