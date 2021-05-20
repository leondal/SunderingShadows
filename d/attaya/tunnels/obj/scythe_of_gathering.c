//Coded by Lujke

#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/scythe";



void create(){
  ::create();
  set_name("%^RESET%^%^ORANGE%^short handled %^YELLOW%^sc%^WHITE%^y"
          +"%^YELLOW%^the%^RESET%^");
  add_id("short handled scythe");
  add_id("scythe of gathering");
  set_short("%^RESET%^%^YELLOW%^Sc%^WHITE%^y%^YELLOW%^the%^RESET%^"
         +" %^ORANGE%^of %^GREEN%^gathering%^RESET%^");
  set_obvious_short("%^RESET%^%^ORANGE%^long handled %^YELLOW%^sc%^WHITE"
                   +"%^y%^YELLOW%^the%^RESET%^");
  set_long("%^ORANGE%^This %^YELLOW%^sc%^WHITE%^y%^YELLOW%^the%^RESET%^"
        +"%^ORANGE%^ has clearly been adapted from a %^GREEN%^farm tool"
        +"%^ORANGE%^ but is now a weapon of %^RED%^war%^ORANGE%^. The"
        +" handle has been shortened, so that while long enough to gives"
        +" good leverage, it is now manageable for most human sized"
        +" creatures to use one handed. The wicked, curved blade has been"
        +" reinforced and is perfect for lopping any extraneous or"
        +" unprotected body parts.%^RESET%^");

  set_size(2);
  set_value(1500);
  set_wield((:TO, "wield_scythe":));          
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
  int dam;
  if (!objectp(TO)||!objectp(ETO)||!objectp(ob)){return 0;}
  if (random(9)<5)
  {
    return 0;
  }
  switch(random(10))
  {
  case 0..4:
    tell_object(ETO, "%^YELLOW%^You make a good attempt to cut " + ob->QCN 
                   + "%^YELLOW%^ down to size with your " + query_name());
    tell_object(ob, "%^YELLOW%^" + ETO->QCN + " %^YELLOW%^tries to cut"
                    +" you down to size with " + (string)ETO->QP + " " 
                    + query_name());
    tell_room(EETO, ETO->QCN + " %^YELLOW%^tries to cut " + ob->QCN 
                   + "%^YELLOW%^ down to size with " 
                   + (string)ETO->QP + " " + query_name(),({ob,ETO}) );
    return 10+random(10);
  case 5..8:
    tell_object(ETO, "%^YELLOW%^You %^CYAN%^slice%^YELLOW%^ your way"
                    +" through " +ob->QCN+"'s protections with your " 
                    + query_name());
    tell_object(ob, "%^YELLOW%^"+(string)ETO->QCN
                   +"%^YELLOW%^ %^CYAN%^slices%^YELLOW%^ through your"
                   +" protections with " + ETO->QP  
                   +" " + query_name());
    tell_room(EETO, "%^YELLOW%^"+(string)ETO->QCN
                   +"%^YELLOW%^ %^CYAN%^slices%^YELLOW%^ through " 
                   +ob->QCN+"'s protections with " + ETO->QP  
                   +" " + query_name(), ({ob,ETO}) );
    dam = random(5)+8;
    set_property("magic",1);
    ob->do_damage("torso",5 + random(15));
    remove_property("magic");
    break;

    return (0);
  case 9:
    tell_object(ETO, "%^GREEN%^Moving the %^YELLOW%^sc%^WHITE%^y"
                    +"%^YELLOW%^the %^RESET%^%^GREEN%^in a complex,"
                    +" whirling pattern, you attempt to gather in "
                    + ob->QCN +"'s %^BOLD%^life force"
                    +"%^RESET%^%^GREEN%^!");
    tell_object(ob, "%^GREEN%^As " + ETO->QCN + " moves the %^YELLOW%^sc"
                    +"%^WHITE%^y%^YELLOW%^the %^RESET%^%^GREEN%^in a"
                    +" complex, whirling pattern, you are aware of a"
                    +" strange, %^BLUE%^sucking%^GREEN%^ sensation in"
                    +" your chest!");
    tell_room(EETO, "%^GREEN%^Moving the %^YELLOW%^sc%^WHITE%^y"
                    +"%^YELLOW%^the %^RESET%^%^GREEN%^in a complex,"
                    +" whirling pattern, " + ETO->QCN + "%^GREEN%^"
                    +" attempts to gather in " + ob->QCN +"'s"
                    +" %^BOLD%^life force!",({ob,ETO}) );
    if(!"daemon/saving_d"->saving_throw(ob,"death",
    -1*((int)ETO->query_level()/4))){
      tell_object(ETO, "%^GREEN%^It works and you feel your body"
                      +" %^YELLOW%^enhanced%^RESET%^%^GREEN%^ with the"
                      +" gathered %^BOLD%^%^GREEN%^life force%^RESET%^"
                      +"%^GREEN%^ of your opponent!");
      tell_object(ob, "%^MAGENTA%^Your %^YELLOW%^will%^RESET%^%^MAGENTA%^"
                   +" fails you and you feel a %^BOLD%^%^RED%^tearing"
                   +"%^RESET%^%^MAGENTA%^ as your %^BOLD%^%^CYAN%^life"
                   +" force%^RESET%^%^MAGENTA%^ is %^GREEN%^gathered"
                   +"%^MAGENTA%^ into the scythe");
      tell_room(EETO, "%^RED%^"+ ob->QCN + "%^RED%^ cries out in pain as "
                   + ob->QP + " %^BOLD%^%^GREEN%^life force"
                   +"%^RESET%^%^RED%^ is %^GREEN%^gathered into the"
                   +" scythe!",({ob,ETO}) );
      dam = 20 + random (30);
      TO->set_property("magic",1);
      ob->do_damage("torso",dam);
      ETO->do_damage("torso",(-1)*(dam)/(2));
      remove_property("magic");
    }else{
      tell_object(ETO, "%^GREEN%^Your attempt appears to fail, and"
                      +" nothing happens");
      tell_object(ob, "%^GREEN%^Using all your %^YELLOW%^will%^RESET%^"
                     +"%^GREEN%^, you fight off the attempt and keep your"
                     +" %^BOLD%^life force%^RESET%^%^GREEN%^ intact");
      tell_room(EETO, "%^GREEN%^" + TO->QCN + " seems disappointed as"
                     +" nothing happens",({ob,ETO}) );     
    }
    return 0;
  }
  return 0;
}


int wield_scythe()
{
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  tell_object(ETO, "As you take up the " + query_name() + ", you feel the"
                  +" %^BOLD%^%^CYAN%^spirits%^RESET%^ of %^GREEN%^rural"
                  +" folk%^RESET%^ from ages past gather round you, some"
                  +" wishing to protect their %^GREEN%^fields%^RESET%^"
                  +" and others wanting %^MAGENTA%^v%^RED%^e"
                  +"%^MAGENTA%^nge%^RED%^a%^MAGENTA%^nce%^RESET%^ upon"
                  +" those who brought %^BOLD%^%^RED%^war%^RESET%^ to"
                  +" their peaceful lives.");
  tell_room(EETO, (string)ETO->query_cap_name() + " grips the handle of " 
                  +(string)ETO->QP + " " + query_name()+ " and gets a"
                  +" sober look on "+ETO->QP + " face.",ETO );
  return 1;
  
}
