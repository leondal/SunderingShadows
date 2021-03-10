#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("silk shirt");
   set_short("%^BOLD%^%^BLUE%^Blue silk shirt%^RESET%^");
   set_id(({"silk shirt","shirt","blue shirt","blue silk shirt"}));
   set_long("%^BOLD%^%^BLUE%^The silk shirt is incredibly soft against"+
   " your skin. It is obviously of the highest quality silk and it is"+
   " a dark shade of ocean blue. Around the cuffs and the collar has"+
   " been embroidered a wave-like pattern in %^RESET%^%^BLUE%^darker"+
   " blue%^BOLD%^ silk. The sleeves are puffed out at the wrists where"+
   " they are clasped back in tightly to leave the hands free from"+
   " entaglements.");
   set_weight(2);
   set_value(100);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_wear("%^BOLD%^%^BLUE%^The silk shirt is incredibly smooth and soft"+
   " against your skin.%^RESET%^");
   set_remove("%^BLUE%^You immediately miss the cool touch of the silk on"+
   " your skin.%^RESET%^");
}
