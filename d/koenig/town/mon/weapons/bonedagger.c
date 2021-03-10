//Redesigned dagger to update - Cythera 5/05\\
#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";

void create()
{
   	::create();
   	set_name("fever iron dagger");
   	set_short("%^BOLD%^%^BLACK%^Da%^RED%^r%^BLACK%^kst%^RED%^a%^BLACK%^r Dagger%^RESET%^");
   	set_obvious_short("%^BOLD%^%^RED%^A fever iron dagger%^RESET%^");
   	set_id(({"dagger","darkstar dagger"}));
   	set_long("%^BOLD%^%^BLACK%^Fashioned from %^RED%^fever iron%^BLACK%^"+
		", this thick dagger has a %^RESET%^%^RED%^r%^BOLD%^e%^RESET%^%^RED%^d"+
		"%^BOLD%^%^BLACK%^ tint to it.  The wide thin blade of the dagger is "+
		"designed to pierce flesh.  Carved up the surface of the fever iron"+
		" blade are images of four sided stars, which serve a dual purpose "+
		"as blood grooves.  A %^RED%^st%^WHITE%^a%^RED%^r r%^WHITE%^u%^RED%^by"+
		"%^BLACK%^ cabochon gem is inlaid in a coiled strip of fever iron in"+
		" the pommel.\n"); 
   	set_value(100);
   	set_property("enchantment",2);
	set_lore("Created by a warlock, the Darkstar Dagger is said to "+
		"call upon the power of the red star Alegors, the Star of "+
		"War.  Also known as Tempus' Blood, Alegors is said to rise"+
		" from the eastern sky the night before great battles that "+
		"have long lasting consequences...the battles that legends "+
		"are written about.  The Darkstar Daggers are favored by some"+
		" in Tempus' faith as lucky relics to carry in battle.  There"+
		" are many tales of warriors being able to save their lives "+
		"with their Darkstar Dagger, after being unarmed.");
   	set_property("lore difficulty",10);
	set_hit((:TO,"hitme":));
   	set_wield("%^RED%^A warm feeling spreads from the dagger and into you.");
	set_unwield("%^RED%^You feel a slight chill after unwielding the dagger.");
}

int hitme(object targ){
if(!objectp(targ)) return 0;
if(!objectp(ETO)) return 0;

   if(!random(8)) {
      tell_object(ETO,"%^RED%^You stab the dagger deep into"+
      	" "+targ->QCN+"'s flesh.");
      tell_object(targ,"%^RED%^"+ETO->QCN+" stabs "+ETO->QP+""+
      	" dagger deep into your flesh.");
      tell_room(environment(ETO),"%^RED%^"+ETO->QCN+""+
      	" stabs "+ETO->QP+" dagger deep into"+
      	" "+targ->QCN+"'s flesh.",({ETO,targ}));
      		targ->do_damage("torso",random(4)+2);
      return 1;
   }
}