//Octothorpe (2/6/10)
//Attaya, Dread Plate of the Kinnesaruda

#include <std.h>
#include <daemons.h>
#define WAIT_TIME 900

inherit "/d/common/obj/armour/field.c";

int used_time;

void create(){
  ::create();
  set_name("spiked field plate");
  set_id(({
     "spiked field plate",
     "field plate",
	 "plate",
	 "dread plate",
	 "dread plate of the kinnesaruda",
	 "kinnesaruda"
   }));
   set_obvious_short("%^BOLD%^%^BLACK%^a suit of sp%^WHITE%^i%^BLACK%^"+
      "ked field plate%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Dr%^RESET%^ea%^BOLD%^%^BLACK%^d Pl"+
      "%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e %^BOLD%^%^BLACK%^of "+
	  "the K%^RESET%^i%^BOLD%^%^BLACK%^nn%^RESET%^e%^BOLD%^%^BLACK%^s"+
	  "%^RESET%^a%^BOLD%^%^BLACK%^r%^RESET%^u%^BOLD%^%^BLACK%^d%^RESET%^a");
   set_long("%^BOLD%^%^BLACK%^This suit of black plate armor is covered "+
      "with dozens of serrated spikes and blades.  If worn by someone "+
	  "adequately cruel, this spiked armor can also double as a "+
	  "weapon of sorts, if the victim was small enough for the wearer "+
	  "to wrap their arms around and %^RESET%^bearhug%^BOLD%^"+
	  "%^BLACK%^.  Besides the plethora of spikes and blades, the "+
	  "plate is devoid identifying marks or flourishes, yet bears a "+
	  "high degree of craftsmanship.  As a whole, this suit of plate "+
	  "is truly terrifying and impressive to behold.%^RESET%^");
   set_lore("This suit of armor is rumored to have been among the first "+
      "products of the undead artificers based in the Cauldron, found "+
	  "at the center of Crystal Mountain on Attaya.  The first account "+
	  "of its appearance is by Tern Olafsson, a Tempussian skald "+
          "attached to the Asgardian expeditionary force in 424 SG.  In "+
	  "Olafsson's epic, 'Guardians of Asgaard,' a brutal encounter "+
	  "between Bishimon and a joint Tsarven-Asgardian patrol is depicted:\n\n "+
	  "A powerful, thorn-skinned fiend, descended \n"+
	  " from above, bringing the sleep of the sword \n"+
	  " with him.  Ali swept forward to honor \n"+
	  " the Lion's sacrifice, finding his end \n"+
	  " in the embrace of the fiend Bishimon. \n\n"+
	  "Guardians of Asgaard, translated by Reza Alameheni (463 SG), "+
	  "lines 1701-1705");
   set_size(-1);
   set_value(12500);
   set_property("lore",25);
   set_property("enchantment",5);
   set("chabonus",-2);
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
}

void init(){
   ::init();
   if(living(ETO)){
      add_action("bearhug","bearhug");
   }
}

int bearhug(string str){
   //Based damage and stun durations off of knockdown since the effect is similar enough - Octothorpe 2/7/10
   string targ;
   object ob;
   if(!str){
      tell_object(ETO,"%^BOLD%^Bearhug what?%^RESET%^");
      return 1;
   }    
   if(sscanf(str,"%s",targ) == 1){
      if(!(query_worn())){
         tell_object(ETO,"You need to be wearing the plate in order "+
	        "to do that.%^RESET%^");
         return 1;
      }
	  if(WAIT_TIME > (time() - used_time)){
         tell_object(ETO,"%^BOLD%^%^You need to wait a little bit longer "+
	        "before trying that again.%^RESET%^");
      return 1;
     }
	  if(ob = present(targ,EETO)){
	     if(living(ob)){
	        switch(random(2)){
			   case 0:
		          tell_object(ETO,"%^RED%^You lunge towards "+
				     ""+ob->QCN+" and "+ob->QS+" is able to "+
					 "evade your attack!%^RESET%^");
			      tell_object(ob,"%^RED%^"+ETOQCN+" lunges towards "+
				     "you with "+ETO->QP+" arms outstretched, but "+
					 "you are able to evade "+ETO->QS+" at the "+
					 "last moment!%^RESET%^");
		          tell_room(EETO,"%^RED%^"+ETOQCN+" lunges towards "+
			         ""+ob->QCN+", but "+ob->QS+" is able to evade "+
					 ""+ETOQCN+"'s reach at the last "+
					 "moment.%^RESET%^",({ETO,ob}));
			      used_time = time();
			      break;
		       case 1:
		          tell_object(ETO,"%^RED%^You wrap your armored arms "+
				     "around "+ob->QCN+", eviscerating "+ob->QO+" "+
					 "with the spikes and blades on your "+
					 "armor!%^RESET%^");
			      tell_object(ob,"%^RED%^"+ETOQCN+" wraps "+ETO->QP+" "+
				     "arms around your body, eviscerating you with "+
					 "the numerous spikes and blades mounted on "+
					 ""+ETO->QP+" armor!%^RESET%^");
			      tell_room(EETO,"%^RED%^"+ETOQCN+" wraps "+ETO->QP+" "+
				     "arms around "+ob->QCN+"'s body, eviscerating "+
			         ""+ob->QO+" with the numerous spikes and blades "+
			         "on "+ETOQCN+"'s armor!%^RESET%^",({ETO,ob}));
                  ETO->use_stamina(roll_dice(1,6));
                  ob->do_damage("torso",roll_dice(3,20));
                  ob->set_paralyzed(roll_dice(2,6),"%^RED%^You are "+
				     "recovering from getting skewered!%^RESET%^");
                  used_time = time();
			      break;
			}
		 }
	  return 1;	 
      }
   }
}   

int wear_func(){
   object ob;
   if(base_name(ETO) == "/d/attaya/mon/bishimon") return 1;
   if(base_name(ETO) != "/d/attaya/mon/bishimon"){
      if((int)ETO->query_highest_level() < 25 /*|| member_array("Gained entry to the Crystal Tower, Defeated Bishimon",ETO->query_mini_quests()) == -1*/){    
	     tell_object(ETO,"%^BOLD%^You are afraid that you will slice an "+
		    "artery open if you try to wear this armor.");
		 return 0;
      }
   if((ob = present("helmet of the Black Dawn",ETO)) && living(ETO) && ob != TO){
      if(ob->query_worn()){
		 set_item_bonus("constitution",2);
      }
	else set_item_bonus("constitution",0);
   } 
   else set_item_bonus("constitution",0);
	  tell_object(ETO,"%^BOLD%^%^BLACK%^You carefully don the spiked "+
	     "plate.");
	  tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" looks truly "+
	     "terrifying as "+ETO->QS+" dons the spiked plate.",ETO);
	  return 1;
   }
}

int remove_func(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^You carefully remove the spiked "+
      "plate, lest you unfortunately slice yourself.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" removes "+ETO->QP+" "+
      "spiked plate, appearing less terrifying than before.",ETO);
   return 1;
}
