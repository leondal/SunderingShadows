//Jarmila Rev2.c - LoKi - 2021
// Devout Follower 


#include <std.h>
#include "../jarmila.h"
inherit MONSTER;

int head_home;

void create()
{
   ::create();
   set_name("devout follower");
   set_short("%^RESET%^%^ORANGE%^devo%^BLACK%^%^BOLD%^u%^RESET%^%^ORANGE%^t fol%^BLACK%^%^BOLD%^l%^RESET%^%^ORANGE%^ower%^RESET%^");
   set_id(({"man","follower","devout follower"}));
   set_long("%^YELLOW%^Dressed in a %^RESET%^%^ORANGE%^"+
   "homespun robe%^YELLOW%^, this man is a devout follower "+
   "of the %^WHITE%^light%^YELLOW%^. Around his neck hangs "+
   "a %^RESET%^%^ORANGE%^wooden holy symbol%^YELLOW%^ without "+
   "adornment and in his hands he carries a bundle of "+
   "%^RESET%^parchment%^YELLOW%^. His %^RESET%^%^ORANGE%^"+
   "long hair%^YELLOW%^ has been tied back with leather "+
   "string. His skin is %^RESET%^%^RED%^suntanned%^YELLOW%^ "+
   "and it is obvious he spends the majority of his time in "+
   "the %^RED%^sun%^YELLOW%^. Every once and awhile he looks "+
   "up at the %^WHITE%^glow%^YELLOW%^ and smiles.\n%^RESET%^");
   set_gender("male");
   set_race("half-elf");
   set_body_type("humanoid");
   set_hd(1,5);
   set_exp(1);
   set_emotes(10,({
      "%^BOLD%^%^BLUE%^The banners snap in the wind.%^RESET%^",
      "%^RED%^%^BOLD%^The follower reads aloud from a parchment of worship.%^RESET%^",
      "%^YELLOW%^A cheer rises up from a nearby tent.%^RESET%^",
        }),0);
   command("message in wanders in");
   command("message out wanders ");
   set_speed(9);
   set_nogo(({ROOMS"trail1",ROOMS"outside"}));
   call_out("head_home",400+random(100));

}

int head_home()
{
   tell_room(ETO,"%^RESET%^%^BOLD%^The man runs after a parchment "+
   "blown away by the wind%^RESET%^");
   TO->move("/d/shadowgate/void");
   destruct(TO);
   return 1;
}
