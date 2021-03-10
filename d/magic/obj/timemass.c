#include <std.h>;
inherit OBJECT;

object spell;

void create(){
   ::create();
   set_name("silvery haze");
   set_id( ({"haze","silvery haze","time hop haze"}) );
   set_short("%^BOLD%^A %^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v"
      "%^RESET%^e%^BOLD%^r%^RESET%^y %^BOLD%^haze%^RESET%^");
   set_long("A strange %^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^"
      "e%^BOLD%^r%^RESET%^y haze hangs in the air here, coalescing into "
      "a vaguely humanoid shape before dissipating and reforming again.");
   set_weight(450);
}

void set_spell(object ob){
    spell=ob;
    return 1;
}

