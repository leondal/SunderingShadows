//made by Essyllis: 11/2016

#include <std.h>
#define WAIT_TIME 300
inherit "/d/common/obj/armour/horseshoes.c";
int used_time;
void init(){
   ::init();
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(living(ETO)){
      add_action("thunderstomp","thunderstomp");
   }
}

void create() {
   ::create();
   set_name("%^YELLOW%^th%^CYAN%^u%^ORANGE%^nd%^CYAN%^e%^ORANGE%^r%^CYAN%^o%^ORANGE%^us hooves%^RESET%^");
   set_id(({"shoes","Shoes","horseshoes","Horseshoes","horse shoes","Horse shoes"}));
   set_short("%^ORANGE%^A pair of %^BOLD%^th%^CYAN%^u%^ORANGE%^nd%^CYAN%^e%^ORANGE%^r%^CYAN%^o%^ORANGE%^us horseshoes%^RESET%^");
   set_obvious_short("%^ORANGE%^Blue colored horseshoes%^RESET%^");
   set_long("%^ORANGE%^These horseshoes seem to be crafted from %^CYAN%^adamantium %^ORANGE%^are nearly a inch thick. The bend "+
   "of the horseshoes are %^CYAN%^inlaid %^ORANGE%^with %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^r%^RESET%^y %^BOLD%^r%^RESET%^u%^BOLD%^n%^RESET%^e%^BOLD%^s "+
   "%^RESET%^%^ORANGE%^which appear to be in a %^MAGENTA%^ancient language%^ORANGE%^. %^BOLD%^Sm%^WHITE%^a%^ORANGE%^ll l%^WHITE%^i%^ORANGE%^gh%^WHITE%^t%^ORANGE%^n%^WHITE%^i%^ORANGE%^ng "+
   "ch%^WHITE%^a%^ORANGE%^rg%^WHITE%^e%^ORANGE%^s %^RESET%^%^ORANGE%^play over the %^BOLD%^%^WHITE%^r%^RESET%^u%^BOLD%^n%^RESET%^e%^BOLD%^s "+
   "%^RESET%^%^ORANGE%^whenever the shoes are in movement and a feint scent of %^BOLD%^%^CYAN%^ozone %^RESET%^%^ORANGE%^can be detected with a "+
   "slight %^BOLD%^el%^RESET%^e%^YELLOW%^ctr%^RESET%^ica%^YELLOW%^l cr%^RESET%^a%^YELLOW%^ck%^RESET%^l%^YELLOW%^e%^RESET%^%^ORANGE%^. "+
   "A tickling sensation can be felt when touching the cold metal.%^WHITE%^\n");
   set_lore("These horseshoes belong to the fabled Labyrinth Minotaur. It is said that even more terrifying than the stomping of "+
   "the Minotaur, is the crackle of electricity which follows every step. Not much is know of the origins of the horseshoes, but "+
   "everyone agree that it seem to have made the wearer resistance to the lightringstorms which occurs in the high mountains."+
   "Even more frightning is the rumors of the minotaurs %^YELLOW%^'thunderstomp'%^RESET%^!");
   set_property("lore difficulty",20); 
   set_property("id difficulty",20); 
   set_weight(3);
   set_type("metal");
   set_value(2500);
   set_property("repairtype",({"armorsmith"})); 
   set_property("enchantment",4);
   set_wear((:TO,"wear_it":));
   set_remove((:TO,"remove_it":));
   set_size(3);
   set_item_bonus("electricity resistance",20);
   
   
   }

int wear_it()
{
	if(ETO->query_level() < 25){
		tell_object(ETO,"%^GREEN%^These horseshoes are too advanced for you");
		if(objectp(EETO)) tell_room(EETO,"%^GREEN%^"+ETO->QCN+"%^RESET%^%^GREEN%^ don't seem to be able to done the horseshoes",ETO);
	return 0;}
	if((string)ETO->query_race() != "minotaur" && (string)ETO->query_race() != "centaur" ){
		tell_object(ETO,"%^RESET%^%^GREEN%^You try to wear the horseshoes, but simply lack the hoofs for it.");
		if(objectp(EETO)) tell_room(EETO,""+ETP->QCN+"%^RESET%^%^GREEN%^Actually tries to wear a pair of horseshoes",ETO);
	return 0;}
	/*if((string)ETO->query_race() != "centaur"){
		tell_object(ETO,"%^RESET%^%^GREEN%^You try to wear the horseshoes, but simply lack the hoofs for it.");
		tell_room(EETO,""+ETP->QCN+"%^RESET%^%^GREEN%^Actually tries to wear a pair of horseshoes",ETO);
	return 0;}
	*/
	tell_object(ETO,"%^ORANGE%^An %^BOLD%^%^CYAN%^e%^ORANGE%^l%^CYAN%^ec%^ORANGE%^t%^CYAN%^ric %^ORANGE%^cr%^CYAN%^a%^ORANGE%^ck%^CYAN%^l%^ORANGE%^e %^RESET%^%^ORANGE%^is heard as you don the %^BOLD%^horseshoes%^RESET%^.");
	if(objectp(EETO)) tell_room(EETO,"%^ORANGE%^An %^BOLD%^%^CYAN%^e%^ORANGE%^l%^CYAN%^ec%^ORANGE%^t%^CYAN%^ric %^ORANGE%^cr%^CYAN%^a%^ORANGE%^ck%^CYAN%^l%^ORANGE%^e %^RESET%^%^ORANGE%^is heard as "+ETP->QCN+" dons the %^BOLD%^horseshoes%^RESET%^.",ETO);
return 1;}

int remove_it(){
	tell_object(ETO,"%^ORANGE%^The air smell of %^CYAN%^ozone %^ORANGE%^as you remove the horseshoes%^WHITE%^");
	tell_room(EETO,"%^ORANGE%^The air smell of %^CYAN%^ozone %^ORANGE%^as "+ETP->QCN+" removes the horseshoes%^WHITE%^",ETO);
return 1;}

int thunderstomp(string str){
   
   string targ;
   object ob;
   if(!str){
      tell_object(ETO,"%^ORANGE%^You stomp your %^BOLD%^%^BLACK%^hoof %^RESET%^%^ORANGE%^into the ground "+
	  "causing %^BOLD%^b%^WHITE%^o%^ORANGE%^lts of l%^WHITE%^i%^ORANGE%^gh%^WHITE%^t%^ORANGE%^n%^WHITE%^i%^ORANGE%^ng "+
	  "%^RESET%^%^ORANGE%^to raise up around you!%^WHITE%^");
      return 1;
   }    
   if(sscanf(str,"%s",targ) == 1){
      if(!(query_worn())){
         tell_object(ETO,"You need to be wearing the horseshoes if you want to stomp with them%^RESET%^");
         return 1;
      }
	  if(WAIT_TIME > (time() - used_time)){
         tell_object(ETO,"%^BOLD%^%^The thunderous powers are still recharging!%^RESET%^");
      return 1;
     }
	  if(ob = present(targ,EETO)){
	     if(living(ob)){
	        switch(random(4)){
			   case 0:
		          tell_object(ETO,"%^YELLOW%^You lunge towards "+
				     ""+ob->QCN+" and stomp your hoof into the ground. But "+ob->QS+" is able to "+
					 "evade the lightning barrage!%^RESET%^");
			      tell_object(ob,"%^YELLOW%^"+ETOQCN+" lunges towards "+
				     "you and stomps "+ETO->QP+" hoof into the ground, launcing a barrage of lightning at you! "+
					 "you are able to evade "+ETO->QS+"'s thunderstomp at the "+
					 "last moment!%^RESET%^");
		          tell_room(EETO,"%^YELLOW%^"+ETOQCN+" lunges towards "+
			         ""+ob->QCN+" and thunderstomps the ground, but "+ob->QS+" is able to evade "+
					 ""+ETOQCN+"'s barrage of lightning!"+
					 "moment.%^RESET%^",({ETO,ob}));
			      used_time = time();
			      break;
		       case 1..3:
		          tell_object(ETO,"%^ORANGE%^You launch towards %^WHITE%^"+ob->QCN+" %^ORANGE%^and "+
				  "%^BOLD%^b%^WHITE%^o%^ORANGE%^lts of l%^WHITE%^i%^ORANGE%^gh%^WHITE%^t%^ORANGE%^n%^WHITE%^i%^ORANGE%^ng "+
				  "st%^WHITE%^r%^ORANGE%^ik%^WHITE%^e%^ORANGE%^s %^RESET%^"+ob->QO+" "+
				  "%^ORANGE%^as your %^BOLD%^thunderstomp %^RESET%^%^ORANGE%^hits the ground.%^WHITE%^");
			      tell_object(ob,""+ETO->QCN+" %^ORANGE%^launch towards %^WHITE%^you %^ORANGE%^and "+
				  "%^BOLD%^b%^WHITE%^o%^ORANGE%^lts of l%^WHITE%^i%^ORANGE%^gh%^WHITE%^t%^ORANGE%^n%^WHITE%^i%^ORANGE%^ng "+
				  "st%^WHITE%^r%^ORANGE%^ik%^WHITE%^e%^ORANGE%^s %^RESET%^you %^ORANGE%^as %^WHITE%^"+ETO->QP+" "+
				  "%^YELLOW%^th%^WHITE%^u%^ORANGE%^nd%^WHITE%^e%^ORANGE%^rst%^WHITE%^o%^ORANGE%^mp "+
				  "%^RESET%^%^ORANGE%^hits the ground infront of you!%^WHITE%^");
			      tell_room(EETO,"%^BOLD%^b%^WHITE%^o%^ORANGE%^lts of "+
				  "l%^WHITE%^i%^ORANGE%^gh%^WHITE%^t%^ORANGE%^n%^WHITE%^i%^ORANGE%^ng st%^WHITE%^r%^ORANGE%^ik%^WHITE%^e%^ORANGE%^s "+
				  "%^RESET%^"+ob->QCN+" %^ORANGE%^as %^WHITE%^"+ETO->QCN+"%^ORANGE%^'s "+
				  "%^BOLD%^th%^WHITE%^u%^ORANGE%^nd%^WHITE%^e%^ORANGE%^rst%^WHITE%^o%^ORANGE%^mp %^RESET%^%^ORANGE%^hits "+
				  "the ground!%^WHITE%^",({ETO,ob}));
                  ETO->use_stamina(roll_dice(1,6));
				  ob->do_damage(ob->return_target_limb(),roll_dice(3,20));
                  ob->set_paralyzed(roll_dice(2,6),"%^RED%^Your muscles are in spasms from being struck by %^YELLOW%^lightning bolts!%^RESET%^");
                  used_time = time();
			      break;
			}
		 }
	  return 1;	 
      }
   }
}   
