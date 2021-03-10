//Coded by Lujke

#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/glaive";



void create(){
::create();

set_name("%^BLUE%^serrated %^MAGENTA%^gl%^RESET%^a%^BOLD%^%^WHITE%^i"
        +"%^RESET%^%^MAGENTA%^ve");
set_id(({ "glaive","serrated glaive", "polearm"}));
set_short("%^RESET%^%^BLUE%^serrated %^MAGENTA%^gl%^RESET%^a%^BOLD%^"
         +"%^WHITE%^i%^RESET%^%^MAGENTA%^ve%^RESET%^");

set_long("A fine quality polearm, about seven and a half feet in length."
        +" The haft is made of a strange %^BOLD%^%^BLACK%^eb%^RESET%^"
        +"%^ORANGE%^o%^BOLD%^%^BLACK%^ny h%^RESET%^u%^BOLD%^%^BLACK%^ed"
        +" wo%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^d%^RESET%^ and it"
        +" carries a heavy, %^BLUE%^s%^RESET%^e%^BLUE%^rrat%^RESET%^e"
        +"%^BLUE%^d%^RESET%^ and %^ORANGE%^sp%^RESET%^i%^ORANGE%^ked"
        +"%^RESET%^ blade at one end and a sharply pointed %^YELLOW%^sp"
        +"%^WHITE%^i%^YELLOW%^ke%^RESET%^ at the other.");

//set_type("piercing");
//set_prof_type("polearm");
set_value(1500);
//set_size(3);
//set_wc(2,2);
//set_large_wc(2,2);
set_wield((:TO, "wield_glaive":));          
set_property("enchantment", 3);
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
    tell_object(ETO, "%^BOLD%^%^BLUE%^You feel the energy of the"
                    +" %^RESET%^%^MAGENTA%^gl%^RESET%^a%^BOLD%^%^WHITE%^i"
                    +"%^RESET%^%^MAGENTA%^ve%^BOLD%^%^BLUE%^ surge"
                    +" through you and take control of your movements.\n"
                    +"%^YELLOW%^Spinning suddenly, you hook the haft of"
                    +" the %^RESET%^%^MAGENTA%^gl%^RESET%^a%^BOLD%^"
                    +"%^WHITE%^i%^RESET%^%^MAGENTA%^ve%^YELLOW%^ under " 
                    + (string)ob->query_cap_name() + "'s %^YELLOW%^ ankle"
                    +" and push " + (string)ob->QP + " to the"
                    +" %^GREEN%^ground%^YELLOW%^!%^RESET%^");
    tell_object(ob, "%^YELLOW%^Spinning suddenly, " 
                    + (string)ETO->query_cap_name() + " hooks the haft of"
                    +" the %^RESET%^%^MAGENTA%^gl%^RESET%^a%^BOLD%^"
                    +"%^WHITE%^i%^RESET%^%^MAGENTA%^ve%^YELLOW%^ under " 
                    + "your ankle and pushes you to the"
                    +" %^GREEN%^ground%^YELLOW%^!%^RESET%^");
    tell_room(EETO, "%^YELLOW%^Spinning suddenly, " 
                    + (string)ETO->query_cap_name() + " hooks the haft of"
                    +" the %^RESET%^%^MAGENTA%^gl%^RESET%^a%^BOLD%^"
                    +"%^WHITE%^i%^RESET%^%^MAGENTA%^ve%^YELLOW%^ under " 
                    + (string)ob->query_cap_name() + "'s %^YELLOW%^ ankle"
                    +" and pushes " + (string)ob->QP + " to the"
                    +" %^GREEN%^ground%^YELLOW%^!%^RESET%^",({ob,ETO}) );
    ob->set_tripped(1,"You are trying to catch your breath and stand!");
    return 0;
  case 1..5:
    tell_object(ETO, "%^BOLD%^%^RED%^You jam the"
                    +" %^YELLOW%^sp%^WHITE%^i%^YELLOW%^ke%^BOLD%^%^RED%^"
                    +" of the %^RESET%^%^MAGENTA%^gl%^RESET%^a%^BOLD%^"
                    +"%^WHITE%^i%^RESET%^%^MAGENTA%^ve%^BOLD%^%^RED%^"
                    +" into " + (string)ob->query_cap_name() + "'s"
                    +" %^GREEN%^stomach%^RED%^ from close range!");
    tell_object(ob, "%^BOLD%^%^RED%^"+(string)ETO->query_cap_name()
                   +"%^BOLD%^%^RED%^ jams the %^YELLOW%^sp%^WHITE%^i"
                   +"%^YELLOW%^ke %^BOLD%^%^RED%^of the"
                   +" %^RESET%^%^MAGENTA%^gl%^RESET%^a%^BOLD%^%^WHITE%^i"
                   +"%^RESET%^%^MAGENTA%^ve%^BOLD%^%^RED%^ into your"
                   +" %^GREEN%^stomach%^RED%^ from close range!");
    tell_room(EETO, "%^BOLD%^%^RED%^"+(string)ETO->query_cap_name() 
                   +"%^BOLD%^%^RED%^ jams the %^YELLOW%^sp%^WHITE%^i"
                   +"%^YELLOW%^ke %^BOLD%^%^RED%^of the %^RESET%^"
                   +"%^MAGENTA%^gl%^RESET%^a%^BOLD%^%^WHITE%^i%^RESET%^"
                   +"%^MAGENTA%^ve%^BOLD%^%^RED%^ into "
                   + (string)ob->query_cap_name() + "'s %^BOLD%^"
                   +"%^GREEN%^stomach%^RED%^ from close range!",
                    ({ob,ETO}) );
    return (5 + random(10));
  case 6..9:
    tell_object(ETO, "%^YELLOW%^You hew powerfully into "
                   + (string)ob->query_cap_name() + "'s %^YELLOW%^head"
                   +" with a devasting overhand blow with your %^RESET%^"
                   +"%^MAGENTA%^gl%^RESET%^a%^BOLD%^%^WHITE%^i"
                   +"%^RESET%^%^MAGENTA%^ve%^YELLOW%^!");
    tell_object(ob, "%^YELLOW%^" + (string)ETO->query_cap_name()
                   +" %^YELLOW%^hews powerfully into  your head with a"
                   +" devasting overhand blow with "
                   + (string)ETO->QP + " %^RESET%^%^MAGENTA%^gl%^RESET%^a"
                   +"%^BOLD%^%^WHITE%^i%^RESET%^%^MAGENTA%^ve"
                   +"%^YELLOW%^!");
    tell_room(EETO, "%^YELLOW%^" + (string)ETO->query_cap_name()
                   +" %^YELLOW%^hews powerfully into "
                   + (string)ob->query_cap_name() + "'s %^YELLOW%^head"
                   +" with a devasting overhand blow with "
                   + (string)ETO->QP + " %^RESET%^%^MAGENTA%^gl%^RESET%^a"
                   +"%^BOLD%^%^WHITE%^i%^RESET%^%^MAGENTA%^ve%^YELLOW%^!",
                    ({ob,ETO}) );
   return 10+ random(10);
  }
  return 0;
}


int wield_glaive()
{
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  tell_object(ETO, "You close your hands around the haft of the glaive"
                  +" and consider the various ways this versatile weapon"
                  +" might be used.");
  tell_room(EETO, (string)ETO->query_cap_name() + " grips the haft of " 
                  +(string)ETO->QP + " glaive carefully.",ETO );
  return 1;
  
}
