//updated base damage - Circe 4/29/04
#include <std.h>

inherit "/d/common/obj/weapon/whip.c";
int unwield_glaive();
int wield_glaive();
int hit_stuff(object ob);
void set_unwield_state();


void create(){
    ::create();
    set_id(({"whip","fire whip","devil whip","weapon"}));
    set_short("%^BOLD%^%^BLACK%^D%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^"
             +"v%^RED%^i%^BOLD%^%^BLACK%^l's %^BOLD%^%^RED%^F%^RESET%^"
             +"%^RED%^i%^BOLD%^%^RED%^re W%^RESET%^%^RED%^h%^YELLOW%^i"
             +"%^RED%^p");
  set_unwield_state();
  set_wield((:TO, "wield_whip":));          
  set_unwield((:TO, "unwield_whip":));  
  set_property("enchantment", 5);
  set_hit((:TO, "hit_stuff":));

}


int hit_stuff(object targ)
{
  set_property("magic",0);
  if (!objectp(targ)||!objectp(TO)||!objectp(ETO)||!objectp(EETO))
  {
    return 0;
  }
  if (random(8)){return 0;}
  if (targ->query_paralyzed())
  {
    if(!"daemon/saving_d"->saving_throw(targ,"rod_staff_wand",
       -1*((int)ETO->query_level()/5)))
    {
      tell_object(targ,"%^BOLD%^%^RED%^The flame of "+(string)ETO->QCN 
                     +"'s%^BOLD%^%^RED%^ whip burns your flesh!");
      tell_object(ETO,"%^BOLD%^%^RED%^The flame of your whip burns "
                      + targ->QCN +"'s%^BOLD%^%^RED%^ flesh!");
      set_property("magic",1); 
      return (10+random(20));
    }
  
  }
  if(!"daemon/saving_d"->saving_throw(targ,"rod_staff_wand",
    -1*((int)ETO->query_level()/5)))
  {
    tell_object(targ,"%^RED%^With a wave of " + ETO->QP +" arm, "
                      + ETO->QCN +" sends the %^BOLD%^"
                      +"%^RED%^f%^YELLOW%^l%^RESET%^%^RED%^a%^BOLD%^"
                      +"%^RED%^me%^RESET%^%^RED%^ of the %^BOLD%^"
                      +"%^RED%^whip%^RESET%^%^RED%^ snaking out. You"
                      +" watch in horror as you are %^MAGENTA%^completely"
                      +" entangled%^RED%^!");
    tell_object(ETO,"%^RED%^With a wave of your arm, you send the"
                     +" %^BOLD%^%^RED%^f%^YELLOW%^l%^RESET%^%^RED%^a"
                     +"%^BOLD%^%^RED%^me%^RESET%^%^RED%^ of the %^BOLD%^"
                      +"%^RED%^whip%^RESET%^%^RED%^ snaking out. "
                      + targ->QCN + " is %^MAGENTA%^completely"
                      +" entangled%^RED%^!");
    tell_room(EETO,"%^RED%^With a wave of " + ETO->QP +" arm, "
                   + ETO->QCN +" sends the %^BOLD%^%^RED%^f%^YELLOW%^l"
                   +"%^RESET%^%^RED%^a%^BOLD%^%^RED%^me%^RESET%^%^RED%^"
                   +" of the %^BOLD%^%^RED%^whip%^RESET%^%^RED%^ snaking"
                   +" out. " + targ->query_cap_name() + " is"
                   +" %^MAGENTA%^completely entangled%^RED%^!"
                   ,({targ, ETO}) );
    targ->set_paralyzed(20,"You are %^MAGENTA%^entangled%^RESET%^ by"
                            +" the %^RED%^fl%^YELLOW%^a%^RESET%^%^RED%^m"
                            +"%^BOLD%^%^RED%^i%^RESET%^%^RED%^ng"
                            +" wh%^YELLOW%^i%^RED%^p%^RESET%^!");
    return 1;
  }
  tell_object(targ,ETO->QCN + " sends the %^BOLD%^%^RED%^f%^YELLOW%^l"
                  +"%^RESET%^%^RED%^a%^BOLD%^%^RED%^me%^YELLOW%^ of the"
                  +" %^BOLD%^%^RED%^whip%^YELLOW%^ snaking out toward"
                  +" you but you dodge out of the way!");
  tell_object(ETO,"%^RED%^With a wave of your arm, you send the"
                 +" %^BOLD%^%^RED%^f%^YELLOW%^l%^RESET%^%^RED%^a"
                 +"%^BOLD%^%^RED%^me%^YELLOW%^ of the %^BOLD%^"
                 +"%^RED%^whip%^YELLOW%^ snaking out toward " 
                 + targ->QCN +", but " + targ->QS + " dodges out of the"
                 +" way!");
  tell_room(EETO,ETO->QCN + " sends the %^BOLD%^%^RED%^f%^YELLOW%^l"
                  +"%^RESET%^%^RED%^a%^BOLD%^%^RED%^me%^YELLOW%^ of the"
                  +" %^BOLD%^%^RED%^whip%^YELLOW%^ snaking out toward "
                  +targ->query_cap_name()+" but "+targ->QS+" dodges out"
                  +" of the way!"
                 ,({targ, ETO}) );
  return 1;
}

int wield_whip()
{
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  tell_object(ETO, "%^BOLD%^%^BLACK%^As you pick up the whip handle, a"
                  +" %^RESET%^%^RED%^br%^BOLD%^%^RED%^i%^RESET%^%^RED%^"
                  +"ght %^BOLD%^%^RED%^f%^YELLOW%^l%^RESET%^%^RED%^a"
                  +"%^BOLD%^%^RED%^me springs forth from the strands of"
                  +" %^BOLD%^%^BLACK%^black leather");
  tell_room(EETO, "%^BOLD%^%^BLACK%^" + (string)ETO->QCN + "%^BOLD%^"
                  +" %^BLACK%^picks up the whip handle. As "
                  + (string)ETO->QS +" %^BOLD%^%^BLACK%^does, a %^RESET%^"
                  +"%^RED%^br%^BOLD%^%^RED%^i%^RESET%^%^RED%^ght%^BOLD%^"
                  +" %^RED%^f%^YELLOW%^l%^RESET%^%^RED%^a%^BOLD%^%^RED%^"
                  +"me springs forth from the strands of %^BOLD%^"
                  +"%^BLACK%^black leather",ETO);
  set_name("whip of fire");
  set_obvious_short("%^YELLOW%^wh%^RED%^i%^YELLOW%^p %^RESET%^%^RED%^of"
                   +" f%^BOLD%^%^RED%^i%^RESET%^%^RED%^re%^RESET%^");
  set_long("%^BOLD%^%^RED%^A long, snaking %^YELLOW%^wh%^RED%^i%^YELLOW%^"
          +"p of f%^YELLOW%^l%^RESET%^%^RED%^a%^BOLD%^%^RED%^me sprouts"
          +" from the %^BOLD%^%^BLACK%^black leather whip handle%^RED%^."
          +" The f%^YELLOW%^l%^RESET%^%^RED%^a%^BOLD%^%^RED%^me writhes"
          +" and swirls like a l%^RESET%^%^RED%^i%^BOLD%^%^RED%^v"
          +"%^RESET%^%^RED%^i%^BOLD%^%^RED%^ng thing.");


  return 1;
}

int unwield_whip()
{
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  tell_object(ETO, "%^RED%^As you release the %^BOLD%^%^BLACK%^whip"
                  +" handle%^RESET%^%^RED%^, the br%^BOLD%^%^RED%^i"
                  +"%^RESET%^%^RED%^ght %^BOLD%^%^RED%^f%^YELLOW%^l"
                  +"%^RESET%^%^RED%^a%^BOLD%^%^RED%^me %^BOLD%^%^BLACK%^w"
                  +"%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^nks out.");
  tell_room(EETO, "%^RED%^As " + (string)ETO->QCN + "%^RESET%^%^RED%^"
                 +" releases "+ETO->QP + " grip on the%^BOLD%^%^BLACK%^"
                 +" whip handle%^RESET%^%^RED%^, the br%^BOLD%^%^RED%^i"
                 +"%^RESET%^%^RED%^ght %^BOLD%^%^RED%^f%^YELLOW%^l"
                 +"%^RESET%^%^RED%^a%^BOLD%^%^RED%^me %^BOLD%^%^BLACK%^w"
                 +"%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^nks out.",ETO);
  set_unwield_state();
  return 1;
}

void set_unwield_state()
{
  set_name("the handle of a whip");
  set_obvious_short("handle of a whip");
  set_long("This appears to be the handle of a whip, with %^BOLD%^"
          +"%^BLACK%^black leather%^RESET%^ strands plaited together"
          +" over the grip. It looks like the rest of the whip has"
          +" been cut away, and the loose strands hang limply");
}
