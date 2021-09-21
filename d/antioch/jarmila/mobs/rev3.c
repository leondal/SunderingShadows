//Jarmila Rev3.c - LoKi - 2021
// Watchful Templar 


#include <std.h>
#include "../jarmila.h"
inherit MONSTER;

int head_home;

void create()
{
   ::create();
   set_name("watchful templar");
   set_short("%^BLACK%^%^BOLD%^watch%^RESET%^f%^BLACK%^%^BOLD%^ul "+
   "te%^RESET%^m%^BLACK%^%^BOLD%^plar%^RESET%^");
   set_id(({"man","templar","watchful templar"}));
   set_long("%^BLACK%^%^BOLD%^Wearing %^RESET%^light chain "+
   "armor%^BLACK%^%^BOLD%^ and wielding no weapons, this "+
   "%^RESET%^%^MAGENTA%^templar%^BLACK%^%^BOLD%^ of "+
   "the %^WHITE%^light%^BLACK%^%^BOLD%^ is wandering the "+
   "%^RESET%^%^ORANGE%^tent city%^BLACK%^%^BOLD%^ as more "+
   "of a visible presence rather than a real deterrent. He "+
   "smiles %^YELLOW%^brightly%^BLACK%^%^BOLD%^ at each person "+
   "he passes and offers wishes of safety and security to "+
   "each. His %^RESET%^equipment%^BLACK%^%^BOLD%^ is "+
   "immaculately clean and his features %^RESET%^%^RED%^"+
   "comely%^BLACK%^%^BOLD%^ and was obviously chosen to be "+
   "a welcome face in the celebrations.\n%^RESET%^");
   set_gender("male");
   set_race("half-elf");
   set_body_type("humanoid");
   set_hd(1,5);
   set_exp(1);
   set_emotes(10,({
      "%^BOLD%^%^BLUE%^The banners snap in the wind.%^RESET%^",
      "%^BLACK%^%^BOLD%^The templar carefully watches the crowd.%^RESET%^",
      "%^BOLD%^You glimpse a massive silver dragon float on the "+
	  "wind far above you.%^RESET%^",
        }),0);
   command("message in marches in");
   command("message out marches ");
   set_speed(9);
   set_nogo(({ROOMS"trail1",ROOMS"outside"}));
   call_out("head_home",400+random(100));

}

int head_home()
{
   tell_room(ETO,"%^BLACK%^%^BOLD%^The templar continues his patrol%^RESET%^");
   TO->move("/d/shadowgate/void");
   destruct(TO);
   return 1;
}
