//Updated description and mechanics - Octothorpe 11/10/09
//Coded by the one and only master of monsters...BANE//

#include <std.h>
inherit WEAPONLESS;

void create(){
    ::create();
    set_id(({"tshala","Tshala","laeradmon"}));
    set_name("tshala");
    set_short("%^RESET%^%^RED%^f%^ORANGE%^l%^YELLOW%^a%^RED%^m"+
	   "%^YELLOW%^i%^RESET%^%^ORANGE%^n%^RED%^g ts%^ORANGE%^h"+
	   "%^YELLOW%^a%^BOLD%^%^RED%^l%^YELLOW%^a%^RESET%^");
    set_long("%^RESET%^%^RED%^The ts%^ORANGE%^h%^YELLOW%^a%^BOLD%^"+
	   "%^RED%^l%^YELLOW%^a %^RESET%^%^RED%^is a slender column of "+
	   "undulating flame that loops and darts dazzlingly in the air.  "+
	   "The faint outline of a feminine face is apparent within the "+
	   "flame, bewitching those who gaze upon it with its constant "+
	   "shimmering, due to the intense heat.%^RESET%^");
    set_body_type("snake");
    set_race("tshala");
    set_gender("female");
    set_size(1);
    set_alignment(8);
    set_overall_ac(-4);   // was 0
    set("aggressive",16);
    set_property("strength","fire");
    set_mob_magic_resistance("average");
	set_property("weapon resistance",2);
    set_attack_limbs(({"head","tail"}));
    set_attacks_num(4);
    set_base_damage_type("bludgeoning");
    set_damage(1,12);
    set_class("mage");
    set_hd(19,38);    // was 9
    set_guild_level("mage",19);
    set_max_level(22);
    set_hp(210); 
    set_attack_bonus(1);
    set_exp(14000);
    set_spells(({"fireball","scorcher","burning hands",}));
    set_spell_chance(80);	// was only 15
    set_attack_bonus(4);
    set_funcs(({"blaze"}));
    set_func_chance(50);
    set_stats("strength",15);
    set_stats("dexterity",20);
    set_stats("intelligence",18);
    set_stats("wisdom",16);
    set_stats("constitution",15);
    set_stats("charisma",14);
	set_moving(1);
	set_speed(10);
	set_nogo(({"/d/laerad/wasteland/waste1"}));
	force_me("message in flies in.");
	force_me("message out flies to the $D.");
	set_emotes(5,({"The %^RED%^The ts%^ORANGE%^h%^YELLOW%^a%^BOLD%^"+
	   "%^RED%^l%^YELLOW%^a %^RESET%^performs a deft pirouette in "+
	   "the air.%^RESET%^"}),0);
}

void blaze(){
    object *vars;
    int i;
    vars = all_living(ETO);
    vars = vars - ({TO});
	if(!objectp(vars)) return;
    if(!objectp(TO)) return;
    for(i=0;i<sizeof(vars);i++){
	   tell_object(vars[i],"%^BOLD%^RED%^The %^RESET%^%^RED%^ts%^ORANGE%^"+
	      "h%^YELLOW%^a%^BOLD%^%^RED%^l%^YELLOW%^a %^BOLD%^%^RED%^burns "+
		  "with tremendous fury, setting the nearby area ablaze!%^RESET%^");
	   if(!"/daemon/saving_d"->saving_throw(vars[i],"spells")){
	      tell_object(vars[i],"%^BOLD%^RED%^You are burnt "+
		     "horribly!%^RESET%^");
	      vars[i]->do_damage("torso",roll_dice(4,12));
	      add_attack_bonus(query_attack_bonus()+1);
	   }  
	   else{
	      tell_object(vars[i],"%^BOLD%^RED%^You are burnt "+
		     "lightly!%^RESET%^");
	      vars[i]->do_damage("torso",roll_dice(2,12));
		  add_attack_bonus(query_attack_bonus()+1);
	   }
    }
}

//Borrowing following from blood hawk to get a good variety
///d/shadow/room/meadows/mons/bhawk.c
void die(mixed ob){
    int gem;
	switch(random(10)){
	   case 0..2:  break;
       case 3..4:  new("/d/antioch/valley/obj/gem")->move(ETO);
                gem++;
       case 5..6:  break;
       case 7..8:  new("/d/antioch/valley/obj/gem")->move(ETO);
                gem++;
       case 9:     new("/d/antioch/valley/obj/gem")->move(ETO);
                gem++;
                break;   
	}
    if(gem){
       tell_room(ETO,"%^BOLD%^As the %^RESET%^%^RED%^f%^ORANGE%^l"+
	      "%^YELLOW%^a%^RED%^m%^YELLOW%^i%^RESET%^%^ORANGE%^n%^RED%^g "+
		  "%^BOLD%^%^WHITE%^form dissipates in the air, something shimmering drops "+
		  "out of the air.%^RESET%^");
	}	  
    else{
       tell_room(ETO,"%^BOLD%^The %^RESET%^%^RED%^f%^ORANGE%^l%^YELLOW%^"+
	      "a%^RED%^m%^YELLOW%^i%^RESET%^%^ORANGE%^n%^RED%^g %^BOLD%^"+
		  "%^WHITE%^form dissipates into thin air!%^RESET%^");
	}
    if(objectp(TO)) { TO->remove(); }
}
