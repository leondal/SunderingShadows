//Original Design by Bannic. Used for Ziva's Shadowlord Rescue Plot, 2019. Kismet.
//This is the lesser version, used in Shadowlord Fortress. Kismet.
#include <std.h>
#include <magic.h>

inherit "/d/common/obj/weapon/dagger.c";


void create(){
	::create();
   	set_name("Silver Edge");
   	set_short("%^RESET%^%^BOLD%^%^WHITE%^Si%^RESET%^l%^BOLD%^%^WHITE%^ver Ed%^RESET%^g%^BOLD%^%^WHITE%^e%^RESET%^");
   	set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^A %^RESET%^%^CYAN%^fine%^RESET%^%^BOLD%^%^WHITE%^ si%^RESET%^l%^BOLD%^%^WHITE%^ver%^RESET%^%^BOLD%^%^BLACK%^ dagger%^RESET%^");
	set_id(({"dagger","silver edge","silver dagger"}));
   	set_long("%^RESET%^This %^BOLD%^%^BLACK%^dagger%^RESET%^ is a piece of %^CYAN%^art%^WHITE%^. Its long, slender shape flows from a elegantly curved blade, through a transitional finger guard in the shape of a %^BOLD%^%^BLACK%^raven%^RESET%^. The %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^WHITE%^r%^RESET%^ consists of hundreds of layers, which is visible whenever light %^BOLD%^%^WHITE%^shimmers %^RESET%^in the surface. Etched along the back of the dagger are small %^GREEN%^e%^RESET%^%^GREEN%^l%^BOLD%^v%^RESET%^%^GREEN%^e%^BOLD%^n %^WHITE%^letters%^RESET%^, filled with %^CYAN%^l%^RESET%^%^CYAN%^i%^BOLD%^q%^RESET%^%^CYAN%^u%^BOLD%^id %^ORANGE%^g%^RESET%^%^ORANGE%^o%^BOLD%^ld%^RESET%^. The %^BOLD%^flowing%^RESET%^, yet ergonomical grip is secured with %^BOLD%^%^BLACK%^dark leather%^RESET%^. The pommel is a %^CYAN%^smooth sphere%^RESET%^ of polished %^YELLOW%^gold%^RESET%^ that is oddly difficult to focus on. When wielded, the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^WHITE%^r%^RESET%^ shines with the radiance of the %^BOLD%^%^CYAN%^moon%^RESET%^ and the pommel %^BOLD%^flares%^RESET%^ with the blessings of the %^BOLD%^%^RED%^sun%^RESET%^.%^RESET%^ ");
	  set_read("%^BOLD%^%^WHITE%^Blessed by %^YELLOW%^The Sun%^BOLD%^%^WHITE%^ and Sharpened by a %^BOLD%^%^CYAN%^Moon Shadow%^BOLD%^%^WHITE%^.%^RESET%^"); 
	set_lore("The deadly sharp %^BOLD%^%^WHITE%^Silver Edge%^RESET%^ was forged by the master weaponsmith Bannic in 748 SG. The once drow turned tiefling, is said to have created the dagger at the request of a follower of Lysara, to aid her in her quest to quell the evil that haunts Deku. It bears only the oddly polished sphere that gives Bannic's weapons their notable characteristics. It has been Blessed by the Sun and sharpened by a Moon Shadow.");
	set_property("lore",13);   
	set_value(10000);	
      set_hit((:TO,"hitme":));
   	set_property("enchantment",2);
	set_item_bonus("attack bonus",1);
    set_item_bonus("damage bonus",1);
   	set_wield((:TO,"wieldme":));
   	set_unwield((:TO,"removeme":));    
}

int wieldme()
{
      tell_object(ETO,"%^BOLD%^%^WHITE%^The dagger fits perfectly in your hand. You feel the blessings of %^BOLD%^%^WHITE%^Lysara%^RESET%^%^BOLD%^%^WHITE%^ and %^YELLOW%^Jarmila%^RESET%^%^BOLD%^%^WHITE%^ smile upon you.%^RESET%^");
      return 1;
}
int removeme()
{
      tell_object(ETO,"%^BOLD%^%^WHITE%^You reluctantly release the dagger%^RESET%^");
      return 1;
}