//Redesigned to update - Cythera 5/05\\
#include <std.h>
inherit "/d/common/obj/weapon/fan.c";

void create()
{
   	::create();
   	set_name("fever iron fan");
   	set_short("%^BOLD%^%^BLACK%^Da%^RED%^r%^BLACK%^kst%^RED%^a%^BLACK%^r War Fan%^RESET%^");
   	set_obvious_short("%^BOLD%^%^RED%^A fever iron war fan%^RESET%^");
   	set_id(({"war fan","darkstar war fan","fever iron war fan","fan"}));
   	set_long("%^BOLD%^%^BLACK%^With its %^RED%^fever iron%^BLACK%^"+
		" base, this red tinted war fan has martial look to it.  "+
		"Opening the fan up reveals plates of fever iron that "+
		"have been stacked next to each other.  The tips of the"+
		" each plate create a diagonal point, perfect for slashing"+
		" or piercing flesh.  The interior of the fan has been "+
		"stained dark black with images of %^RED%^red%^BLACK%^"+
		" four pointed stars scattered around.  A "+
		"%^RED%^st%^WHITE%^a%^RED%^r r%^WHITE%^u%^RED%^by%^BLACK%^"+
		" cabochon gem has been inlaid at the base of the fan.%^RESET%^\n"); 
   	set_value(100);
   	set_property("enchantment",2);
	set_lore("Created by a warlock, the Darkstar War Fan is said to "+
		"call upon the power of the red star Alegors, the Star of "+
		"War.  Also known as Tempus' Blood, Alegors is said to rise"+
		" from the eastern sky the night before great battles that "+
		"have long lasting consequences...the battles that legends "+
		"are written about.  The Darkstar War Fans are favored by some"+
		" in Tempus' faith as lucky relics to carry in battle, usually"+
		" by woman or exotic fighters");
   	set_property("lore difficulty",10);
	set_hit((:TO,"hitme":));
   	set_wield("%^RED%^A warm feeling spreads from the fan and into you.");
	set_unwield("%^RED%^You feel a slight chill after unwielding the fan.");
}

int hitme(object targ){
if(!objectp(targ)) return 0;
if(!objectp(ETO)) return 0;

   if(!random(8)) {
      tell_object(ETO,"%^RED%^You slash the war fan deep into"+
      	" "+targ->QCN+"'s flesh.");
      tell_object(targ,"%^RED%^"+ETO->QCN+" slashes "+ETO->QP+""+
      	" war fan deep into your flesh.");
      tell_room(environment(ETO),"%^RED%^"+ETO->QCN+""+
      	" slashes "+ETO->QP+" war fan deep into"+
      	" "+targ->QCN+"'s flesh.",({ETO,targ}));
      		targ->do_damage("torso",random(4)+2);
      return 1;
   }
}