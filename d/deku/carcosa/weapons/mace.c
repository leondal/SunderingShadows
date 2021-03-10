inherit "/std/weapon";
#define TP this_player()
#define TPQCN this_player()->query_cap_name()
int rand;

create(){
	::create();
	
	set_id(({"mace"}));
	set_name("mace");
	set_short("A Mace");
	set_long("This mace seems to %^RED%^GLOW%^RESET%^ with energy.\n");
	set_weight(5);
	set_size(2);
	set("value",500);
	set_wc(1,6)+1;
	set_large_wc(1,6);
	set_type("bludgeoning");
   set_prof_type("mace");
	set_wield( (:this_object(),"wield_mace":) );
	set_unwield( (:this_object(),"unwield_mace":) );
	set_hit( (:this_object(),"weapon_hit":) ); 
}
int wield_mace(){
	tell_object(TP,"%^CYAN%^Your hand tingles as you wield this weapon.%^RESET%^");
	TP->add_stat_bonus("strength",2);
	return 1;
}
int unwield_mace(){
	tell_object(TP,"The feeling fades from your hand as you unwield this weapon.\n");
	TP->add_stat_bonus("strength",-2);
	return 1;
}
int weapon_hit(){
	object tar = this_player()->query_current_attacker();
	  rand = random(3);

	if(rand == 0){
	  tar->set_paralyzed((roll_dice(2,6)),"A shocking blow disorients you.\n");
	  write(""+TPQCN+" sends a shocking blow into " +tar->query_capital_name()+ ".");
	      }

	else{
	  tell_object(TP,"You smash your foe and hear the sound of crunching bone.\n");
	}

	return 1;
           }
	
     



