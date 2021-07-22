// fixed wield/unwield to use ETO & changed prof to staff - last change was 11/02  *Styx* 8/2003
//update with lore and new short/longdesc, set to run from inherit. Nienne, 08/07.

#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/quarter_staff.c";
int xy,CYCLE,uses;
object owned,LOCUST;

void init() {
    ::init();
    if(interactive(TP) && TP == environment(TO) && !owned) {
		owned = TPQN;
		uses = random((int)TP->query_level() * 10) + 100;
    }
}

create() {
    ::create();
    set_name("staff");
    set_id(({"staff","staff of sorrow","carved staff","wooden staff","carved wooden staff"}));
    set_short("%^RESET%^%^ORANGE%^Staff of %^GREEN%^So%^CYAN%^rr%^GREEN%^ow%^RESET%^"); 
    set_obvious_short("%^RESET%^%^ORANGE%^A carved wooden staff%^RESET%^");
    set_long("This long staff is quite plain, cut from a length of %^ORANGE%^red o%^RED%^a%^ORANGE%^k%^RESET%^"
". Despite its mostly mundane appearance, the wood has been well treated and polished, with rounded ends that "
"have been carefully %^CYAN%^smoothed %^RESET%^over. The only decoration to the weapon is a writhing depiction "
"of %^GREEN%^ch%^BOLD%^o%^RESET%^%^GREEN%^ker vi%^BOLD%^n%^RESET%^%^GREEN%^es %^RESET%^that tangle their way "
"up the length of the staff, their tendrils reaching out to cover nearly all surfaces of the wood.");
    set_lore("A series of these weapons, known from legends and lore of " 
"the people of Daggerdale, were forged during the second Drow war, " 
"against the invading darkelves from the northern caves. The priests of " 
"the town were said to have blessed these weapons by calling upon the aid " 
"of all the innocent victims slain by the drow. They then carried the " 
"weapons into battle, and so great was the anguish and sorrow of the dead " 
"that they turned their fury upon their tormentors, and saved the " 
"remaining villagers from an otherwise grisly fate. It is a sad matter " 
"that most of the weapons were lost in the century and more years since, " 
"as another invading force of drow in only recent times decimated and " 
"cursed the once prosperous village."); 
    set_property("lore",13); 
    set_value(1200);
    set_property("enchantment",3);
    set_wield((: TO,"extra_wield" :));
    set_unwield((: TO,"extra_unwield" :));
    set_hit((: TO,"extra_hit" :));
}

int extra_wield()
{
    object player;
    
    player = environment(this_object());
    
    if(!player || !objectp(player))
        return 0;
    
    if((int)player->query_level() < 17) {
	write("You are to inexperienced to wield such a weapon!\n");
	return 0;
    }
    if(!player->is_class("cleric") && !player->is_class("druid")) {
	write("This is not for you!");
	return 0;
    }
    if((string)ETOQN != owned && (string)ETOQN != "sorrow_cleric") {
	write("The staff fails to bond with you and vanishes!");
	TO->remove();
	return 0;
    }
	if (!player->query_property("silent_wield")) {
		tell_object(player, "%^GREEN%^Your heart is filled with ancient anguish and sorrow!%^RESET%^");
		tell_room(environment(player), "%^GREEN%^A look of great sorrow crosses over " + ETOQCN + "'s face.%^RESET%^", player);
	}
    return 1;
}

int extra_unwield() {
	if (!ETO->query_property("silent_wield")) {
		tell_object(ETO, "%^GREEN%^The feelings of sorrow leave your body.%^RESET%^");
		tell_room(EETO, "%^GREEN%^" + ETOQCN + " appears happier now.%^RESET%^", ETO);
	}
    return 1;
}

int extra_hit(object vic){
    int dam,loc,z;
    xy = random(4)+1;
  if(!objectp(vic)) return 1;
    if(uses < 1) return 1;
    if(random(100) < 50) return 1;
    switch(xy) {
    case 1:
	message("my_action","%^BOLD%^%^GREEN%^"
	  "You deliver the sorrows of humanity upon your foe!\n"
	  "%^BLUE%^Tears flow down "+vic->query_cap_name()+"'s face as "
	  +vic->query_subjective()+" begins to sob uncontrollably!"
	  "%^RESET%^"
	  ,ETO);
	message("other_action","%^BOLD%^%^GREEN%^"
   +ETO->query_cap_name()+
	  " delivers the sorrows of humanity upon "+vic->query_cap_name()+"!\n"
	  "%^BLUE%^Tears flow down "+vic->query_cap_name()+"'s face as "
	  +vic->query_subjective()+" begins to sob uncontrollably!"
	  "%^RESET%^"
	  ,environment(vic),(({ETO, vic})));
	message("my_action","%^BOLD%^%^GREEN%^"
   +ETO->query_cap_name()+
	  " delivers the sorrows of humanity upon you!\n"
	  "%^BLUE%^Tears flow down your face as "
	  "you begin to sob uncontrollably!"
	  "%^RESET%^"
	  ,vic);
	dam = (int)ETO->query_level();
	if(!vic->query_paralyzed())
	    vic->set_paralzyed(random(dam)+12,"%^BLUE%^You are sobbing like a fool!%^RESET%^");
	dam = dam+10;
	dam = random(dam);
	dam = (dam/2)+3;
	if(dam > 9) dam = 9+random(dam/10);
	uses = uses - (dam/2);
	return dam;

    case 2:
	if(present("locust",environment(query_wielded()))) return 1;
	loc = (int)ETO->query_level();
	loc = random(loc) + 3;
	if(loc > 7) loc = 7 + random(loc/9);
	if(loc > 15) loc = 15;
	tell_object(ETO,"%^RED%^You utter an ancient phrase of sorrow!%^RESET%^");
	ETO->force_me("say Lokisav tenuba r'rrklkt Locutis banork!");
	tell_room(environment(query_wielded()),"%^BOLD%^%^GREEN%^A flying horde of giant %^YELLOW%^locusts%^GREEN%^ "
	  "enter the area!%^RESET%^");
	for(z=0;z<loc;z++) {
            new("/d/dagger/marsh/swamp/mon/locust")->move(environment(ETO));
            if(LOCUST = present("locust",environment(ETO))) {
            LOCUST->setup_locust(ETO);
            if(objectp(vic)) vic->add_attacker(LOCUST);
	    }
	}
	dam = 0;
	uses = uses - (loc);
	return dam;

    case 3:
	message("my_action","%^BOLD%^%^RED%^"
	  "You begin to sing the song of sorrow and are hasted in your attacks!"
	  "%^RESET%^"
	  ,ETO);
	message("other_action","%^BOLD%^%^RED%^"
    +ETO->query_cap_name()+
	  " begins to sing the song of sorrow and is hasted in attacking!"
	  "%^RESET%^"
	  ,environment(vic),(({ETO, vic})));
	message("my_action","%^BOLD%^%^RED%^"
    +ETO->query_cap_name()+
	  " begins to sing the song of sorrow and is hasted in attacking you!"
	  "%^RESET%^"
	  ,vic);                	
	if(CYCLE == 0) ETO->force_me("sing `My life suffocates'");
	if(CYCLE == 1) ETO->force_me("sing `I give, You take'");
	if(CYCLE == 2) ETO->force_me("sing `Anger, Misery'");
	if(CYCLE == 3) ETO->force_me("sing `Pure black looking clear'");
	if(CYCLE == 4) ETO->force_me("sing `Drink up, Shoot in'");
	if(CYCLE == 5) ETO->force_me("sing `All have said their prayers'");
	message("my_action","%^RED%^"
	  "You land a quick blow!"
	  "%^RESET%^"
	  ,ETO);	
	vic->do_damage(vic->return_target_limb(),random(3)+1);
	if(CYCLE == 0) ETO->force_me("sing `Planting seeds of hate'");
	if(CYCLE == 1) ETO->force_me("sing `This life that I forsake'");
	if(CYCLE == 2) ETO->force_me("sing `You'll suffer unto me'");
	if(CYCLE == 3) ETO->force_me("sing `My work is done soon here'");
	if(CYCLE == 4) ETO->force_me("sing `Let the beatings begin'");
	if(CYCLE == 5) ETO->force_me("sing `Invade their nightmares'");
	message("my_action","%^RED%^"
	  "You land a quick blow!"
	  "%^RESET%^"
	  ,ETO);	
	vic->do_damage(vic->return_target_limb(),random(3)+1);
	if(CYCLE == 0) ETO->force_me("sing `I've loved, turned to hate'");
	if(CYCLE == 1) ETO->force_me("sing `Been cheated of my youth'");
	if(CYCLE == 2) ETO->force_me("sing `Harvester of sorrow'");
	if(CYCLE == 3) ETO->force_me("sing `Try getting back to me'");
	if(CYCLE == 4) ETO->force_me("sing `Distributor of pain'");
	if(CYCLE == 5) ETO->force_me("sing `To see into my eyes'");
	message("my_action","%^RED%^"
	  "You land a quick blow!"
	  "%^RESET%^"
	  ,ETO);	
	vic->do_damage(vic->return_target_limb(),random(3)+1);
	if(CYCLE == 0) ETO->force_me("sing `Trapped far beyond my fate'");
	if(CYCLE == 1) ETO->force_me("sing `You turned this lie to truth'");
	if(CYCLE == 2) ETO->force_me("sing `Language of the mad'");
	if(CYCLE == 3) ETO->force_me("sing `Get back which used to be'");
	if(CYCLE == 4) ETO->force_me("sing `Your loss becomes my gain'");
	if(CYCLE == 5) ETO->force_me("sing `You'll find where murder lies'");
	dam = random(3) + 1;
	CYCLE = CYCLE + 1;
	uses = uses - dam + 2 + random(4);
	if(CYCLE > 5) CYCLE = 0;
	return dam;

    case 4:
	if((string)WEATHER_D->Check_Weather(ETO) == "It is clear." ||
	  environment(query_wielded())->query_property("indoors")){
	    message("my_action","%^BOLD%^%^CYAN%^"
	      "As you deliver the smiting blow, the staff hums and you feel refreshed!"
	      "%^RESET%^"
	      ,ETO);
	    message("other_action","%^BOLD%^%^CYAN%^"
    +ETO->query_cap_name()+
	      " delivers a blow upon "+vic->query_cap_name()+" and looks refreshed!"
	      "%^RESET%^"
	      ,environment(vic),(({ETO, vic})));
	    message("my_action","%^BOLD%^%^CYAN%^"
    +ETO->query_cap_name()+
	      " delivers a blow upon you and looks refreshed!"
	      "%^RESET%^"
	      ,vic);
	    ETO->add_hp(random(6)+((int)ETO->query_max_hp()/10));
	    uses = uses - random(3) + 3;
	    dam = random(1) + 1;
	    return dam;
	} else {
	    message("my_action","%^BOLD%^%^YELLOW%^"
	      "Lightning streaks from the clouds overhead and strikes "
	      +vic->query_cap_name()+"!"
	      "%^RESET%^"
	      ,ETO);
	    message("other_action","%^BOLD%^%^YELLOW%^"
	      "Lightning streaks from the clouds overhead and strikes "
	      +vic->query_cap_name()+"!"
	      "%^RESET%^"
	      ,environment(vic),(({ETO, vic})));
	    message("my_action","%^BOLD%^%^GREEN%^"
	      "Lightning streaks from the clouds overhead and strikes you!"
	      "%^RESET%^"
	      ,vic);   
	    dam = (int)ETO->query_level();
	    dam = dam/2 + random(dam);
	    vic->do_damage(vic->return_target_limb(),dam);
	    uses = uses - dam/2;
	    dam = random(1) + 1;
	    return dam;
	}
    }
    return 0;
}
