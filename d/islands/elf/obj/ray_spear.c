#include <std.h>
#include "../elf.h"
#include <daemons.h>

inherit "/d/common/obj/weapon/mspear.c";

void create(){
    ::create();
    set_name("Stingray spear");
    set_id( ({"spear", "stingray spear", "stingray stinger","stinger"}) );
    set_short("%^CYAN%^Stingray Spear%^RESET%^");
    set_obvious_short("Stingray stinger");
    set_long("This spear appears to be a giant"+
    " stingray tail mounted on a barnicle covered"+
    " metal shaft.   The tip is dark with poison."+
    "  Some force keeps the tail producing poison"+
    " even while seperated from a living stingray.");
    
    set_lore("The spear at one point was a normal"+
    " weapon.  The style is old.  Likely crafted "+
    "centuries ago it should have decayed to dust"+
    " but some resentment of past sins created"+
    " magic that allowed the spear to reform"+
    " itself with the materials present.");
    set_property("lore",30);
    set_value(1000);
    set_hit((:TO,"hitme":));
    set_property("enchantment",4+random(2));
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
}
int wield_func(string str) {
   write("You wield the spear and the stinger twitches putting a fresh coat of poison on it.");
   return 1;
}
int unwield_func(string str) {
   tell_object(ETO,"You release the spear and are glad to not have this unsettling weapon in your hand.");
   return 1;
}

int hitme(object targ)
{  
   if(!random(16)) {
      tell_object(ETO,"%^BLUE%^You drive the spear's stinger into"+
                " "+targ->QCN+", injecting %^GREEN%^poison%^%BLUE%^ into"+targ->QO+".");
      tell_object(targ,"%^BLUE%^"+ETO->QCN+"'s"+
                " pierces you with a stinger that pumps %^GREEN%^poison%^BLUE%^ into you.");
      tell_room(EETO,"%^BLUE%^"+ETO->QCN+"'s spear's stinger pierces "+targ->QCN+"'s"+
                " body, pumping %^GREEN%^poison%^BLUE%^ into "+targ->QO+".",({ETO,targ}));     

      if(!"/daemon/saving_throw_d.c"->fort_save(targ,-40))
           POISON_D->ApplyPoison(targ,"large_scorpion_venom",TO,"injury");
        return 20;
   }
   
}