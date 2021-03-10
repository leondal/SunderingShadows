#include <std.h>
#include "../arctic.h"
inherit CWEAP"two_hand_sword.c";

void create()
{
   ::create();
    set_obvious_short("a frost covered two handed sword");
    set_name("Winter's Touch");
    set_short("%^RESET%^%^BLUE%^Winter%^RESET%^'%^BLUE%^s Tou%^RESET%^c%^BLUE%^h%^RESET%^%^BOLD%^ two handed sword%^RESET%^");
    set_id(({"sword","two handed sword","winter's touch","winters touch", "winterstouch"}));
    set_long("%^BLUE%^The massive weapon has a double edged blade "
    "that runs straight for six feet where it abruptly comes to a "
    "point.  The long, straight, blade is covered in a thick layer "
    "of frost that cannot be cleaned off.  Runes near the hilt of "
    "the weapon can occasionally be seen glowing in a soft white "
    "light through the frost that is covering them.  The crosspiece "
    "of the blade is formed from blued steel, and the hilt is made "
    "from wrapped leather.");
    set_value(1000);
    set_property("enchantment",4);
    set_prof_type("large blades");
    set_hit((:TO,"hitme":));
    set_wield((:TO,"wieldme":));
    set_unwield((:TO,"unwieldme":));
}

int wieldme() 
{
   if((int)ETO->query_lowest_level() < 20 && ETO) 
   {
      tell_object(ETO,"The blade vibrates violently and you "
          "are unable to wield it.");
      tell_room(EETO, "The sword vibrates out of "+ETO->QCN+"'s hand "
          "when "+ETO->QS+" tries to wield it.",ETO);
      return 0;
   }
   tell_object(ETO,"%^RESET%^%^CYAN%^The leather grip of the sword feels "
       "cold in your hands.%^RESET%^");
   tell_room(EETO,"%^BOLD%^"+ETOQCN+" takes a firm grip on the leather "
       "hilt of the sword.%^RESET%^",ETO);
   return 1;
}

int unwieldme()
{
   tell_object(ETO,"%^BOLD%^Warmth quickly returns to your "
       "fingers after releasing the sword.%^RESET%^");
   tell_room(EETO,"%^CYAN%^"+ETO->QCN+" releases the hilt of the "
       "blade and flexes "+ETO->QP+" fingers.%^RESET%^",ETO);
   return 1;
}

int hitme(object targ)
{
    if(!objectp(targ)) return 0;

    if(random(1000) > 700)
    {

        switch(random(6))
        {
        case 0..1:
            tell_object(ETO,"%^BOLD%^You thrust your sword into "+targ->QCN+"'s "
                "gut before quickly twisting and pulling it free!%^RESET%^");
            tell_object(targ,"%^BOLD%^You gasp in pain as "+ETO->QCN+" thrusts "
                ""+ETO->QP+" sword into your gut then quickly twists and pulls "
                "it free!%^RESET%^");
            tell_room(EETO,"%^BOLD%^"+ETO->QCN+" thrusts his sword into "+targ->QCN+"'s "
                "gut then quickly twists it and pulls it free!%^RESET%^",({ETO,targ}));
            TO->set_property("magic", 1);
            targ->do_damage("torso", (random(6)+5));
            TO->set_property("magic", -1);
            break;
        case 2..3:
            tell_object(ETO,"%^BLUE%^You bring the sword down in a "
                "mighty overhead chop hitting "+targ->QCN+" viciously!%^RESET%^");
            tell_object(targ,"%^BLUE%^"+ETO->QCN+" brings "+ETO->QP+" sword down on "
                "you in a vicious overhead chop!%^RESET%^");
            tell_room(EETO,"%^BLUE%^"+ETO->QCN+" brings "+ETO->QP+ " sword down on "+targ->QCN+""
                " in a vicious overhead chop!%^RESET%^",({ETO,targ}));
            TO->set_property("magic", 1);
            targ->do_damage("torso", (random(11)+10));
            TO->set_property("magic", -1);
            break;
        case 4:
            tell_object(ETO,"%^BOLD%^The %^CYAN%^f%^RESET%^r%^BLUE%^o%^CYAN%^s%^RESET%^t%^CYAN%^y "
                "%^BLUE%^runes %^RESET%^%^BOLD%^on your sword flare angrily as you "
                "slam the flat of your sword into "+targ->QCN+"'s head, stunning "+targ->QO+"!%^RESET%^");
            tell_object(targ,"%^CYAN%^F%^RESET%^r%^BLUE%^o%^CYAN%^s%^RESET%^t%^CYAN%^y "
                "%^BLUE%^runes %^RESET%^%^BOLD%^on "+ETO->QCN+"'s sword glow brightly as "
                ""+ETO->QS+" strikes you in the head with the flat of the blade stunning you!%^RESET%^");
            tell_room(EETO,"%^RED%^The runes on "+ETO->QCN+"'s sword flare as "+ETO->QS+" strikes "
                ""+targ->QCN+" on the head with the flat of the blade, stunning "+targ->QO+""
                "!%^RESET%^",({ETO,targ}));
            targ->set_paralyzed((random(8)+1),"%^BOLD%^Your head is ringing!%^RESET%^");
            TO->set_property("magic", 1);
            targ->do_damage("torso", (random(6)+1));
            TO->set_property("magic", -1);
            break;
        case 5:
            tell_object(ETO,"%^MAGENTA%^You bring your sword back around quickly "
                "into "+targ->QCN+"!%^RESET%^");
            tell_object(targ,"%^MAGENTA%^"+ETO->QCN+" brings "+ETO->QP+" sword back around "
                "quickly for another attack!");
            tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" quickly strikes "+targ->QCN+""
                " again!", ({ETO,targ}));
            ETO->execute_attack();
            break;
        }
    }

return 1;

}
