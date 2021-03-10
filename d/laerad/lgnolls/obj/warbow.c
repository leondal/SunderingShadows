#include <std.h>
inherit "/d/common/obj/lrweapon/longbow.c";
#include "../lgnoll.h"

void create() {
   	::create();
   	set_name("Asgard war bow");
   	set_short("%^YELLOW%^asgard %^RED%^warb%^BLACK%^o%^RED%^w%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^heavy long bow%^RESET%^");
   	set_id(({"long bow","bow","longbow","war bow","warbow"}));
   	set_long("The bow is made out of one %^ORANGE%^solid piece of %^GREEN%^o%^ORANGE%^ak %^WHITE%^and "+
	"then reinforced with %^BOLD%^horn %^RESET%^on both the %^BOLD%^upper %^RESET%^and %^BOLD%^%^BLACK%^lower "+
	"%^RESET%^limb of the bow, making this a %^YELLOW%^p%^RESET%^%^ORANGE%^o%^BOLD%^werf%^RESET%^%^ORANGE%^u%^BOLD%^l "+
	"c%^RESET%^%^ORANGE%^o%^BOLD%^mpos%^RESET%^%^ORANGE%^i%^BOLD%^te b%^RESET%^%^ORANGE%^o%^BOLD%^w%^RESET%^. The "+
	"%^MAGENTA%^n%^BOLD%^%^WHITE%^o%^RESET%^%^MAGENTA%^ck %^WHITE%^in each end of the bow is made of "+
	"%^BOLD%^i%^BLACK%^v%^WHITE%^o%^BLACK%^r%^WHITE%^y %^RESET%^and what really makes this bow special is the "+
	"%^BOLD%^%^BLACK%^bl%^RESET%^a%^BOLD%^%^BLACK%^d%^RESET%^e%^BOLD%^%^BLACK%^s %^RESET%^at the ends of the bow. "+
	"At both ends a %^BOLD%^%^BLACK%^10 inch bl%^RESET%^a%^BOLD%^%^BLACK%^d%^RESET%^e %^RESET%^has "+
	"been firmly attached with %^BOLD%^%^BLACK%^st%^WHITE%^ee%^BLACK%^l %^RESET%^bands which makes the bow deadly "+
	"in %^MAGENTA%^melee %^WHITE%^as well as %^CYAN%^ranged%^WHITE%^. The %^BOLD%^%^BLACK%^bl%^RESET%^a%^BOLD%^%^BLACK%^d%^RESET%^e%^BOLD%^%^BLACK%^s "+
	"%^RESET%^serve the dual purpose of reinforcing the limbs of the bow and protecting the "+
	"%^MAGENTA%^n%^BOLD%^%^WHITE%^o%^RESET%^%^MAGENTA%^cks%^WHITE%^. The %^ORANGE%^h%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^ndle "+
	"%^WHITE%^is made from %^ORANGE%^c%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d "+
	"%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^lk-h%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^de %^WHITE%^which provides excellent grip "+
	"and on top of the handle the %^CYAN%^c%^WHITE%^u%^CYAN%^rv%^WHITE%^e%^CYAN%^d %^WHITE%^a%^CYAN%^rr%^WHITE%^o%^CYAN%^ws-r%^WHITE%^e%^CYAN%^st "+
	"%^WHITE%^of %^BOLD%^p%^GREEN%^o%^WHITE%^lish%^GREEN%^e%^WHITE%^d %^GREEN%^o%^WHITE%^ak %^RESET%^makes sure the arrows "+
	"stay nocked even while running.");
   	set_value(1500);
   	set_property("enchantment",4);
	set_lore("The Warbow was a revered weapon in Asgard. It was designed during Asgard's later years when the troll "+
	"raids from Systyquah became more frequent. The artisan wood-worker 'Alfred Stigsson' was tasked to make a bow "+
	"the asgardian archers could use both at range but also to protect themselves with. The Warbow quickly turned out to be "+
	"a success and soon all archers in Asgard were seen with one. Rumors even had it that a few of these bows were "+
	"enchanted by the Wild elves in Paranelli forests to counter the trolls' regeneration. -- Sallonir deldor, Bard of Torm");
   	set_property("lore difficulty",19);
      set_lrhit((:TO,"extra_lrhit":));
	  set_wield((:TO,"wieldme":));
}


int wieldme(){
	if((int)ETO->query_level() < 20) {
		tell_object(ETO,"%^BOLD%^%^BLUE%^You are not yet strong enough to draw this bow!");
		return 0; }
			tell_object(ETO,"%^YELLOW%^L%^WHITE%^i%^ORANGE%^ght tr%^WHITE%^a%^ORANGE%^c%^WHITE%^e%^ORANGE%^s along the %^RED%^e%^ORANGE%^dges of the %^BLACK%^b%^ORANGE%^o%^BLACK%^w-bl%^ORANGE%^a%^BLACK%^des %^ORANGE%^as you draw the warbow.");
			tell_room(environment(ETO),"%^YELLOW%^The %^BLACK%^blades %^ORANGE%^on %^RESET%^"+ETO->QCN+"'s %^YELLOW%^w%^RESET%^%^ORANGE%^a%^BOLD%^rb%^RESET%^%^ORANGE%^o%^BOLD%^w gleam %^RESET%^%^RED%^sharply %^YELLOW%^as %^RESET%^"+ETO->QS+" %^YELLOW%^wields it.",ETO);
                set_item_bonus("damage bonus",0);
                if((int)ETO->query_stats("strength") < 18){
                        set_item_bonus("damage bonus",3);
                }
                if((int)ETO->query_stats("strength") < 16){
                        set_item_bonus("damage bonus",2);
                }
                if(ETO->query_stats("strength") < 14){
                        set_item_bonus("damage bonus",1);
                }
                if(ETO->query_stats("strength") < 12){
                        set_item_bonus("damage bonus",0);
                }

		return 1;
		
}	
		
int extra_lrhit(object targi){
	object acid;
   if(!objectp(targi)) return 0;
   if(!objectp(ETO)) return 0;
   targi = ETO->query_current_attacker();
   if(random(1000)<200) {
	   switch(random(20)){
		   case 0:{
			   tell_object(ETO,"%^ORANGE%^As you fire the arrow at %^WHITE%^"+targi->QCN+" %^ORANGE%^the %^BOLD%^%^BLACK%^arrow %^RESET%^%^CYAN%^transforms %^ORANGE%^into a %^GREEN%^green bolt %^ORANGE%^of %^BOLD%^%^GREEN%^acid%^RESET%^%^GREEN%^!%^WHITE%^");
			   tell_object(targi,ETO->QCN+" %^ORANGE%^fires an %^BOLD%^%^BLACK%^arrow %^RESET%^%^ORANGE%^at you that transforms into a %^GREEN%^green bolt %^ORANGE%^of %^BOLD%^%^GREEN%^acid%^RESET%^%^GREEN%^!%^WHITE%^");
			   tell_room(EETO,ETO->QCN+" %^ORANGE%^fires an %^BOLD%^%^BLACK%^arrow %^RESET%^%^ORANGE%^at %^WHITE%^"+targi->QCN+" %^ORANGE%^that transforms into a %^GREEN%^green bolt %^ORANGE%^of %^BOLD%^%^GREEN%^acid%^RESET%^%^GREEN%^!%^ORANGE%^",ETO);
			   	acid = new(OBJ"acid");
				acid->move(targi);
				acid->hurt(targi);
			   return 1;
			   break;
		   }
			   
		   case 1..9:{
      tell_object(ETO,"%^YELLOW%^You pull the %^BLACK%^Warbow %^ORANGE%^to its %^RED%^full strength and "+
	  "%^ORANGE%^score a s%^RESET%^%^ORANGE%^o%^BOLD%^l%^RESET%^%^ORANGE%^i%^BOLD%^d h%^RED%^i%^ORANGE%^t on "+targi->QCN+"!%^RESET%^");
      tell_object(targi,"%^ORANGE%^The p%^BOLD%^%^RED%^o%^RESET%^%^ORANGE%^w%^BOLD%^%^RED%^e%^RESET%^%^ORANGE%^r "+
	  "in "+ETO->QCN+"'s shot nearly made the %^BOLD%^%^BLACK%^arrow %^RESET%^%^ORANGE%^go str%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^ight "+
	  "thr%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^ugh you!%^RESET%^");
      tell_room(EETO,ETO->QCN+" %^ORANGE%^fires a p%^RED%^o%^ORANGE%^w%^RED%^e%^ORANGE%^rf%^RED%^u%^ORANGE%^l shot, burrowing the "+
	  "%^BOLD%^%^BLACK%^arrows shaft %^RESET%^%^RED%^deep %^ORANGE%^in %^WHITE%^"+targi->QCN+"%^ORANGE%^'s body!",({ETO,targi}));
      set_property("magic",1);
      targi->do_damage(targi->return_target_limb(),random(5)+5);
      remove_property("magic");
      return 1; break;
		   }
		   
		case 10..19:{
      tell_object(ETO,"%^CYAN%^As %^WHITE%^"+targi->QCN+"%^CYAN%^ comes too close, you twist the "+
	  "b%^ORANGE%^o%^CYAN%^w and %^RED%^slash %^WHITE%^"+targi->QO+" %^CYAN%^across %^WHITE%^"+
	  ""+targi->QP+" %^CYAN%^torso with your %^BOLD%^%^BLACK%^bow-blades!%^RESET%^");
      tell_object(targi,"%^CYAN%^Just as you get close to %^WHITE%^"+ETO->QCN+", "+ETO->QS+" %^CYAN%^twists the "+
	  "bow and slashes you with the %^BOLD%^%^BLACK%^bow-blades!%^RESET%^");
	  tell_room(EETO,"%^CYAN%^Just as %^WHITE%^"+targi->QCN+" %^CYAN%^catches up to %^WHITE%^"+ETO->QCN+", "+ETO->QS+" "+
	  "%^CYAN%^twists the bow and %^RED%^slashes %^WHITE%^"+targi->QCN+" %^CYAN%^with the "+
	  "%^BOLD%^%^BLACK%^bow-blades%^RESET%^%^CYAN%^!%^WHITE%^%^RESET%^",ETO);
      set_property("magic",1);
      targi->do_damage(targi->return_target_limb(),(random(8)+5));
      remove_property("magic");
      return 1;
	  break;
   }
}
}
}

