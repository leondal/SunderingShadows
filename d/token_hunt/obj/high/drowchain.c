//Octothorpe (4/6/10)
//Adamantine Chain
//Based upon Elven Chainmail, by Dinji
//d/islands/common/obj/e_chain.c

#include <std.h>
inherit "/d/common/obj/armour/hide.c";
int con;

void create(){
   ::create();
   set_name("chain tunic");
   set_id(({
      "chain",
	  "chain tunic",
	  "tunic",
	  "chaintunic",
	  "chainshirt",
	  "chain shirt",
	  "drow chain",
	  "drowish chain",
	  "drow chain mail",
	  "drowish chain mail",
	  "drow chainmail",
	  "drowish chainmail",
	  "chain mail",
	  "mail"
   }));
   set_short("%^BOLD%^%^BLACK%^Dr%^WHITE%^o%^BLACK%^w%^WHITE%^i"+
      "%^BLACK%^sh Ch%^WHITE%^ai%^BLACK%^nm%^WHITE%^ai%^BLACK%^"+
	  "l%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^d%^RESET%^u%^BOLD%^%^BLACK%^ll "+
      "adamantine chain tunic%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This armored tunic has been forged out "+
      "of a supple mesh that is fairly lightweight, yet bears some "+
	  "level of density to offer a good level of protection.  The mesh "+
	  "is made out of dull adamantine that is incapable of any gleaming "+
	  "and seems to swallow any light around it.  An intricate pattern "+
	  "resembling %^WHITE%^sp%^RESET%^i%^BOLD%^derw%^RESET%^e%^BOLD%^bs "+
	  "%^BOLD%^%^BLACK%^crawls all over the mesh, attesting to the high "+
	  "level of craftsmanship.%^RESET%^");
   set_lore("This chain mail tunic is the drow equivalent of elven chain "+
      "mail.  Drow mail borders on the edge of phantastic legend since "+
	  "few examples make it to the surface, or last very long once they "+
	  "reach there.  Once the mail, or most other drow artifacts, are "+
	  "taken away from the peculiar natural and magical emanations of "+
	  "the Underdark they slowly begin to degrade and lose their "+
	  "special qualities.  Most of the scholarship on the subject "+
	  "suggests drow artifacts can only last up to three or four "+
	  "weeks on the surface, before being rendered inert and "+
	  "crumbling into dust.");
   set_value(0);
   set_heart_beat(1);
   set_size(-1);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
//   set_property("enchantment",5);
   set_item_bonus("stealth",3);
   set_property("lore difficulty",23);
   set_property("phialable",1);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
   con = 100;
   set_overallStatus(220);
   set_property("no disenchant",1);
}

void heart_beat(){
//   int place;
   object place;
   int x;
   if(userp(ETO)) place = EETO;
   else place = ETO;
   if(!objectp(place)) return;
   x = (int)TO->query_overallStatus();
   if(random(100000) > 99995){
      if(ETO->is_container()){ return;}
      if((int)place->query_property("indoors") < 1){
	     con--;
		 if(!random(5)){
		    tell_object(ETO,"%^BOLD%^%^BLACK%^The chain mail degrades "+
		       "a little bit while being outdoors.%^RESET%^");
		 }
         switch(con){
	        case 80..100:
		       if(!random(20)){
		          TO->set_overallStatus(x - 1);
		       }
            break;
		    case 60..79:
		       if(!random(20)){
		          TO->set_overallStatus(x - 1);
		       }
			   if((int)TO->query_property("enchantment") > 4){
			      TO->set_property("enchantment",-1);
			   }
			   break;
		    case 40..59:
		       if(!random(20)){
		          TO->set_overallStatus(x - 1);
		       }
			   if((int)TO->query_property("enchantment") > 3){
			      TO->set_property("enchantment",-1);
			   }
			   break;
            case 20..39:
		       if(!random(20)){
		          TO->set_overallStatus(x - 1);
		       }
			   if((int)TO->query_property("enchantment") > 2){
			      TO->set_property("enchantment",-1);
			   }
			   break;
		    case 1..19:
		       if(!random(20)){
		          TO->set_overallStatus(x - 1);
		       }
		       if((int)TO->query_property("enchantment") > 1){
			      TO->set_property("enchantment",-1);
			   }
			   break;
            case 0:
               TO->remove();
			   break;
	     }	
      }
   }	  
}

int wear_fun(){
   if((int)ETO->query_lowest_level() < 25){
     tell_object(ETO,"%^BOLD%^%^BLACK%^The chain tunic does not "+
	    "seem to fit you properly.%^RESET%^");
	 return 0;
   }
   tell_object(ETO,"%^BOLD%^%^BLACK%^As you wear the chain tunic, "+
      "several sp%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^d%^RESET%^%^RED%^"+
	  "e%^BOLD%^%^BLACK%^rs briefly scurry across the %^BOLD%^"+
	  "%^WHITE%^sp%^RESET%^i%^BOLD%^derw%^RESET%^e%^BOLD%^b "+
	  "%^BOLD%^%^BLACK%^design on the mail.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^As "+ETOQCN+" dons the chain "+
      "tunic, several sp%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^d%^RESET%^"+
	  "%^RED%^e%^BOLD%^%^BLACK%^rs briefly scurry across the %^BOLD%^"+
	  "%^WHITE%^sp%^RESET%^i%^BOLD%^derw%^RESET%^e%^BOLD%^b %^BOLD%^"+
	  "%^BLACK%^design on the mail.%^RESET%^",ETO);
   return 1;
}

int remove_fun(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^Your skin feels like it is "+
      "crawling with sp%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^d%^RESET%^"+
	  "%^RED%^e%^BOLD%^%^BLACK%^rs for a few seconds after you "+
	  "remove the chain tunic.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" looks uncomfortable "+
      "for a brief instant after removing the chain tunic.%^RESET%^",ETO);
   return 1;
}

int struck_fun(int damage, object what, object who){
   if(!random(3)){
      tell_room(EETO,"%^BOLD%^%^BLACK%^The %^BOLD%^%^WHITE%^sp"+
	     "%^RESET%^i%^BOLD%^derw%^RESET%^e%^BOLD%^b %^BOLD%^"+
		 "%^BLACK%^design on the mail flares with an angry "+
		 "%^RESET%^%^RED%^red %^BOLD%^%^BLACK%^as "+who->QCN+" "+
		 "strikes "+ETOQCN+".%^RESET%^",({ETO, who}));
      tell_object(who,"%^BOLD%^%^BLACK%^The %^BOLD%^%^WHITE%^sp"+
	     "%^RESET%^i%^BOLD%^derw%^RESET%^e%^BOLD%^b %^BOLD%^"+
		 "%^BLACK%^design on "+ETOQCN+"'s mail flares an "+
		 "angry %^RESET%^%^RED%^red %^BOLD%^%^BLACK%^as "+
		 "you strike "+ETOQCN+".%^RESET%^");
      tell_object(ETO,"%^BOLD%^%^BLACK%^The %^BOLD%^%^WHITE%^sp"+
	     "%^RESET%^i%^BOLD%^derw%^RESET%^e%^BOLD%^b %^BOLD%^"+
		 "%^BLACK%^design on your mail flares an angry %^RESET%^"+
		 "%^RED%^red %^BOLD%^%^BLACK%^as you are struck by "+
		 "a blow.%^RESET%^");
      return 0;
   }
   return damage;
}

int reset_counter(){
   con = 100;
   return 1;
}

int test_heart(){ return 1;}
