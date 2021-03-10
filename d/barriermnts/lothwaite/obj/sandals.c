//sandals.c - for Lothwaite, Circe 12/19/04
#include <std.h>
inherit ARMOUR;

#define GEMS ({"%^BOLD%^%^WHITE%^sno%^BLACK%^w%^WHITE%^flake %^BLACK%^obs%^WHITE%^i%^BLACK%^dian","%^RESET%^%^ORANGE%^tig%^YELLOW%^e%^RESET%^%^ORANGE%^r's eye","%^RESET%^%^RED%^carn%^BOLD%^e%^RESET%^%^RED%^lian","%^BOLD%^%^RED%^red jasper","%^YELLOW%^citrine","%^RESET%^%^ORANGE%^py%^YELLOW%^ri%^RESET%^%^ORANGE%^te","%^GREEN%^aventurine","%^BOLD%^%^MAGENTA%^rose quartz","%^MAGENTA%^am%^BOLD%^e%^RESET%^%^MAGENTA%^thy%^BOLD%^s%^RESET%^%^MAGENTA%^t","%^CYAN%^aquamarine","%^CYAN%^turq%^BOLD%^uo%^RESET%^%^CYAN%^ise","%^BOLD%^%^WHITE%^clear calcite"})

void create() {
   string GEM;
   int i;
   ::create();
   i = random(sizeof(GEMS));
   GEM = GEMS[i];
   set_id(({"sandals","leather sandals","fine sandals","fine leather sandals"}));
   set_name("fine leather sandals");
   set_short("%^RESET%^%^ORANGE%^fine leather sandals%^RESET%^");
   set_long(
      "%^RESET%^%^ORANGE%^These sandals would make even the largest "+
      "feet appear dainty.  They are made of thick leather soles "+
      "fitted with thin leather thongs that crisscross the top of "+
      "the foot before buckling at the ankle with a pretty "+GEM+" "+
      "clasp%^RESET%^."
   );
   set_value(50);
   set_size(3);
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
}