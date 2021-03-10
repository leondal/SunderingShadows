//Coded by Lujke

#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/whip";

void create(){
::create();

set_name("%^RESET%^%^MAGENTA%^orch%^BOLD%^%^MAGENTA%^e%^RESET%^"
        +"%^MAGENTA%^v%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^d"
        +" %^GREEN%^root%^RESET%^");
set_id(({ "whip","root", "orchevid root", "weapon"}));
set_short("%^GREEN%^A long, whiplike plant root%^RESET%^");
set_long("%^GREEN%^A cordlike %^BOLD%^%^GREEN%^plant%^RESET%^%^GREEN%^"
        +" root, almost ten feet in length, with an %^BOLD%^%^GREEN%^ev"
        +"%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^"
        +" smelling %^BOLD%^%^BLACK%^b%^BOLD%^%^MAGENTA%^u%^BOLD%^"
        +"%^BLACK%^lb%^RESET%^%^BLUE%^ou%^BOLD%^%^BLACK%^s black pr"
        +"%^BOLD%^%^MAGENTA%^o%^BOLD%^%^BLACK%^tr%^RESET%^%^BLUE%^u"
        +"%^BOLD%^%^BLACK%^ber%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^nce"
        +" %^RESET%^%^GREEN%^at the far end.%^RESET%^");
set_value(3000);
set_property("enchantment", 5);
add_poisoning(25);
set_hit((:TO, "hit_stuff":));
set_weapon_speed(1);
}

void init()
{
  ::init();
}

int hit_stuff(object ob)
{ 
  if (!objectp(TO)||!objectp(ETO)||!objectp(ob)){return 0;}
  if (random(17)<15)
  {
    return 0;
  }
  switch(random(10))
  {
  case 0:
    tell_object(ETO, "");
    tell_object(ob, "");
    tell_room(EETO, "",({ob,ETO}) );
    ob->set_tripped(1,"You are trying to catch your breath and stand!");
    return 0;
  case 1..5:
    tell_object(ETO, "");
    tell_object(ob, "");
    tell_room(EETO, "",
                    ({ob,ETO}) );
    return (5 + random(10));
  case 6..9:
    tell_object(ETO, "");
    tell_object(ob, "");
    tell_room(EETO, "",
                    ({ob,ETO}) );
   return 10+ random(10);
  }
  return 0;
}

