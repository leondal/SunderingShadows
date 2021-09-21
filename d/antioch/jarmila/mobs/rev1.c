//Jarmila Rev1.c - LoKi - 2021
// Colorful Reveller 


#include <std.h>
#include "../jarmila.h"
inherit MONSTER;

int head_home;

void create()
{
   ::create();
   set_name("colorful reveler");
   set_short("%^RED%^c%^RESET%^%^BOLD%^ol%^GREEN%^o%^RESET%^%^BOLD%^rful r%^BLUE%^e%^RESET%^%^BOLD%^vel%^YELLOW%^e%^RESET%^"+
   "%^BOLD%^r%^RESET%^");
   set_id(({"woman","reveler","colorful reveler"}));
   set_long("%^RESET%^%^BOLD%^Dressed in %^BLUE%^colorful "+
   "%^YELLOW%^silk %^RED%^clothing%^RESET%^%^BOLD%^, "+
   "this woman is constantly dancing to the "+
   "%^MAGENTA%^music%^RESET%^%^BOLD%^ from all of the "+
   "%^RESET%^%^ORANGE%^tents%^RESET%^%^BOLD%^. With her %^YELLOW%^long "+
   "hair%^RESET%^%^BOLD%^ flowing in the %^RESET%^%^CYAN%^wind"+
   "%^RESET%^%^BOLD%^ she is the very image of someone enthralled "+
   "with pure %^CYAN%^happiness%^RESET%^%^BOLD%^. %^RED%^c%^RESET%^%^BOLD%^ol"+
   "%^GREEN%^o%^RESET%^%^BOLD%^rful"+
   "%^RESET%^%^BOLD%^ ri%^BLUE%^b%^WHITE%^bo%^RED%^n%^WHITE%^s "+
   "are tied to her wrists and ankles.\n%^RESET%^");
   set_gender("female");
   set_race("human");
   set_body_type("humanoid");
   set_hd(1,5);
   set_exp(1);
   set_emotes(10,({
      "%^BOLD%^%^BLUE%^The banners snap in the wind.%^RESET%^",
      "%^RED%^%^BOLD%^The reveler dances to the music.%^RESET%^",
      "%^YELLOW%^You feel a rush of happiness from the glow above.%^RESET%^",
        }),0);
   command("message in dances in");
   command("message out dances ");
   set_speed(9);
   set_nogo(({ROOMS"trail1",ROOMS"outside"}));
   call_out("head_home",400+random(100));

}

int head_home()
{
   tell_room(ETO,"%^YELLOW%^The woman dances away into a tent%^RESET%^");
   TO->move("/d/shadowgate/void");
   destruct(TO);
   return 1;
}
