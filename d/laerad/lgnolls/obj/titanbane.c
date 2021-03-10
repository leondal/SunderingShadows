//Essyllis: Feb 2015
#include <std.h>
#include "../lgnoll.h"
inherit "/d/common/obj/weapon/warhammer";


object targ;
string OWNER;
void init(){
    ::init();
    if(interactive(ETO) && !OWNER) OWNER = ETO->query_name();
}	

void create() {
	::create();
	set_name("TitanBane");
	set_short("%^YELLOW%^Titanbane%^RESET%^");
   set_obvious_short("%^BOLD%^%^ORANGE%^adamantium warwarhammer%^RESET%^");
	set_id(({"hammer","aesatri hammer","hammer asgard","commando hammer","Commando Hammer","Hammer","commando"}));
	set_long("%^GREEN%^This weapon is truly astonishing. The head of this "+
			"%^BOLD%^%^BLACK%^warhammer %^RESET%^%^GREEN%^is crafted from "+
			"one single piece of %^CYAN%^adamantium%^GREEN%^. %^BOLD%^%^CYAN%^M%^WHITE%^i%^CYAN%^thr%^WHITE%^i%^CYAN%^l "+
			"%^WHITE%^r%^CYAN%^u%^WHITE%^ne %^RESET%^%^GREEN%^engravings adorn "+
			"the sides of the %^BOLD%^%^BLACK%^hammerhead%^RESET%^%^GREEN%^. The "+
			"%^BOLD%^%^WHITE%^runes %^RESET%^%^GREEN%^are of %^ORANGE%^ancient %^BOLD%^Aesatri "+
			"%^RESET%^%^ORANGE%^decent%^GREEN%^. On the right side of the %^BOLD%^%^BLACK%^hammerhead "+
			"%^RESET%^%^GREEN%^a %^BOLD%^%^BLUE%^b%^CYAN%^l%^BLUE%^ue sa%^CYAN%^pp%^BLUE%^hi%^CYAN%^r%^BLUE%^e "+
			"%^RESET%^%^GREEN%^with the %^MAGENTA%^symbol of a balanced scales %^GREEN%^can be "+
			"seen. The %^BOLD%^%^BLUE%^gemstone %^CYAN%^p%^BLUE%^u%^CYAN%^ls%^BLUE%^a%^CYAN%^t%^BLUE%^e%^CYAN%^s "+
			"%^RESET%^%^GREEN%^with %^BOLD%^%^MAGENTA%^p%^ORANGE%^o%^MAGENTA%^w%^ORANGE%^e%^MAGENTA%^r "+
			"%^RESET%^%^GREEN%^and makes the %^BOLD%^%^WHITE%^rune-engravings %^MAGENTA%^gl%^ORANGE%^o%^MAGENTA%^w "+
			"%^RESET%^%^GREEN%^in the same %^BOLD%^%^CYAN%^b%^BLUE%^l%^CYAN%^ui%^BLUE%^s%^CYAN%^h "+
			"%^BLUE%^c%^CYAN%^o%^BLUE%^l%^CYAN%^o%^BLUE%^r %^RESET%^%^GREEN%^as the %^BOLD%^%^BLUE%^g%^CYAN%^e%^BLUE%^m%^RESET%^%^GREEN%^. "+
			"The %^BOLD%^%^BLACK%^hammer's %^RESET%^%^GREEN%^shaft is made of ancient "+
			"%^WHITE%^wh%^BOLD%^%^BLACK%^i%^RESET%^t%^BOLD%^e%^RESET%^-%^BOLD%^o%^RESET%^a%^BOLD%^%^BLACK%^k "+
			"%^RESET%^%^GREEN%^and ends in a %^ORANGE%^luxurious raw-leather %^GREEN%^bound "+
			"%^ORANGE%^hilt%^GREEN%^. This magical hammer is a true %^YELLOW%^s%^WHITE%^y%^ORANGE%^mbol "+
			"of J%^WHITE%^u%^ORANGE%^st%^WHITE%^i%^ORANGE%^c%^WHITE%^e%^RESET%^%^GREEN%^.\n");
	set_lore("The hammer of Justice, or at other times also named TitanBane "+
			"is a impressive weapon in the right hands. It belong to the Asgard "+
			"knight Carnac. Besides being a Knight, Carnac was Captain of the "+
			"Asgard commandos. He earned the nickname 'Titan Foe' after a "+
			"campaign to clear the Godsplanes on Laerad of Titans while the carriage "+
			"house was being built. For his dedication in ensuring that Asgard had a "+
			"clear path to the harbor, which at that time was the only trade-route "+
			"to the mainlands, he was rewarded with this hammer by Lord Erldrik Von Helg, "+
			"the Grand-Justicar of Tyr. What happened to Carnac is unknown. Rumors will "+
			"have it that he undertook a journey into the northern mountains on Laerad, "+
			"after rumors that gnolls had been spotted. There is no doubt that this is "+
			"a powerful hammer. But people have reported that only in the hands of a noble "+
			"soul, will it reveals its true power. - Sallonir deldor, Bard of Torm");
	set_property("lore",20);  
	set_weight(15);
	set_value(3000);
	set_property("enchantment",3);
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
	set_hit((:TO,"hitme":));
}

int wieldme() {

	int align;	
	align=ETO->query_alignment();

	if((string)ETO->query_name() !=OWNER){
		tell_object(ETO,"%^BOLD%^%^RED%^TitanBane tells you:%^BLUE%^ I do not know you. Leave me be!");
		tell_room(EETO,"The Warhammer seem to refuse "+ETO->QCN+"'s touch.",({ETO,targ}));
	return 0; }
	
	if((int)ETO->query_level() < 20) {
		tell_object(ETO,"%^BOLD%^%^RED%^TitanBane tells you:%^BLUE%^ I am not a simple peasant's weapon!");
		return 0; }
    	
	if(align == 1 || align == 4 || align == 7){
		if((string)ETO->query_class()== "paladin"){
			tell_object(ETO,"%^BOLD%^%^RED%^TitanBane tells you:%^BLUE%^I have waited for a person such as you, M'Lord.");
			tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+"'s %^BOLD%^%^CYAN%^warhammer starts glowing bright blue as "+ETO->QCN+"%^BOLD%^%^CYAN%^ wields it.",ETO);
			set_item_bonus("charisma",2);
			set_item_bonus("damage bonus",2);
			set_item_bonus("attack bonus",2);
			return 1;
		}
			tell_object(ETO,"%^BOLD%^%^RED%^TitanBane tells you:%^BLUE%^ Hrm. Very well, you do have a good soul.");
			tell_room(environment(ETO),"%^RESET%^%^CYAN%^"+ETO->QCN+"'s%^RESET%^%^CYAN%^ warhammer gives a warm blue glow as "+ETO->QCN+"%^RESET%^%^CYAN%^ wields it.",ETO);	
			set_item_bonus("charisma",0);
			set_item_bonus("damage bonus",1);	
			set_item_bonus("attack bonus",1);
	return 1;}
	

	if(align == 2 || align == 5 || align == 8){
		if((string)ETO->query_class() == "paladin"){
			tell_object(ETO,"%^BOLD%^%^RED%^TitanBane tells you:%^BLUE%^ You have a noble heart, but I sense shadows in your soul.");
			tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s %^BOLD%^%^BLUE%^warhammer gives a blue glow as "+ETO->QCN+" %^BOLD%^%^BLUE%^wields it.",ETO);
			set_item_bonus("charisma",1);
			set_item_bonus("damage bonus",0);
			set_item_bonus("attack bonus",2);
			return 1;
		}
			tell_object(ETO,"%^BOLD%^%^RED%^TitanBane tells you:%^BLUE%^ I find you are a questionable character. Rectify your ways and we can become better friends.");
			tell_room(EETO,"%^BLUE%^"+ETO->QCN+"'s warhammer flashes a bluish color as "+ETO->QCN+" wields it.",ETO);
			set_item_bonus("charisma",0);
			set_item_bonus("damage bonus",0);
			set_item_bonus("attack bonus",1);
		return 1;}

	else{
		tell_object(ETO,"%^BOLD%^%^RED%^TitanBane tells you:%^BLUE%^Unhandle me ... Scum!");
		tell_room(EETO,"%^BOLD%^%^WHITE%^As "+ETO->QCN+"%^BOLD%^%^WHITE%^ tries to wield the warhammer, it %^RED%^fl%^WHITE%^a%^RED%^shes br%^WHITE%^i%^RED%^ght r%^WHITE%^e%^RED%^d%^WHITE%^ burning "+ETO->QCN+"%^BOLD%^%^WHITE%^ badly!",ETO);
		ETO->do_damage("torso",random(20)+20);
		return 0;}
}

int removeme() {

	if((string)ETO->query_class() == "paladin"){
		tell_object(ETO,"%^BOLD%^%^RED%^TitanBane tells you:%^BLUE%^We did well. Till next time, Sir.");
		tell_room(EETO,"%^RESET%^%^CYAN%^"+ETO->QCN+"'s%^RESET%^%^CYAN%^ hammer stops glowing as "+ETO->QCN+"%^RESET%^%^CYAN%^ releases it.",ETO);
		return 1;
	}
	tell_object(ETO,"%^BOLD%^%^RED%^TitanBane tells you:%^BLUE%^ You fought well. You have earned a rest.");
	tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s%^BOLD%^%^BLUE%^ hammer stops glowing as "+ETO->QCN+"%^BOLD%^%^BLUE%^ releases it.",ETO);
	return 1;
}


int hitme(object targ) {
    object *ebils;
	int bolts, i;
	ebils = ETO->query_attackers();
	if(!living(ETO) || !living(targ)) {return 0;}
        if(random(1000) < 200) {
			switch(random(100)){
			
			case 0..49:{
			if((string)targ->query_name() == "titan"){
				tell_object(ETO,"%^BOLD%^%^RED%^The Warhammer pulsates with raw p%^ORANGE%^o%^RED%^w%^ORANGE%^e%^RED%^r as you connect with a d%^ORANGE%^e%^RED%^v%^ORANGE%^a%^RED%^st%^ORANGE%^a%^RED%^t%^ORANGE%^i%^RED%^ng bl%^ORANGE%^o%^RED%^w!");
				tell_room(EETO,"%^BOLD%^%^RED%^"+ETO->QCN+"%^BOLD%^%^RED%^'s hammer pulsates with power as it delivers a devastating blow to "+targ->QCN+"!",ETO);
				targ->do_damage("torso",roll_dice(4,6)+10);
			return 1;}
			
			if((string)ETO->query_class() == "paladin"){
				tell_object(ETO,"%^CYAN%^You can feel the %^ORANGE%^W%^CYAN%^a%^ORANGE%^rh%^CYAN%^a%^ORANGE%^mm%^CYAN%^e%^ORANGE%^r %^CYAN%^almost guiding itself to %^WHITE%^"+targ->QCN+"%^CYAN%^'s %^BOLD%^%^BLACK%^we%^ORANGE%^a%^BLACK%^k p%^ORANGE%^o%^BLACK%^ints!");
				tell_room(EETO,"%^CYAN%^"+ETO->QCN+"'s warhammer smashes into a weak spot in "+targ->QCN+"'s defences!",({ETO,targ}));
				tell_object(targ,"%^CYAN%^"+ETO->QCN+"'s blow smashes into your armor's weakest point!");
				set_property("magic",1);
				targ->do_damage(targ->return_target_limb(),roll_dice(2,4)+4);
				set_property("magic",-1);
			return 1;}
			
			
			else{
				tell_object(ETO,"%^BOLD%^%^BLUE%^The Warhammer p%^CYAN%^u%^BLUE%^ls%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BLUE%^s as your %^BLACK%^blow connects %^BLUE%^to "+targ->QCN+"!");
				tell_object(targ,"%^BOLD%^%^BLUE%^You flinch in %^RESET%^%^RED%^pain %^BOLD%^%^BLUE%^as the p%^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^w%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^r of %^RESET%^"+ETO->QCN+"%^BOLD%^%^BLUE%^'s %^CYAN%^w%^ORANGE%^a%^CYAN%^rh%^ORANGE%^a%^CYAN%^mm%^ORANGE%^e%^CYAN%^r %^BLUE%^shakes through you!");
				tell_room(EETO,"%^BOLD%^CYAN%^"+targ->QCN+" %^CYAN%^flinches in pain as %^WHITE%^"+ETO->QCN+"%^CYAN%^'s warhammer %^RED%^smites "+targ->QO+"!",({ETO,targ}));		
				targ->do_damage(targ->return_target_limb(),roll_dice(1,6)+2);	
			return 1;}
			break; }
			
			
			case 50..84:{
			if((string)targ->query_name() == "titan"){
				tell_object(ETO,"%^CYAN%^You hurl %^YELLOW%^TitanBane %^RESET%^%^CYAN%^at the %^GREEN%^titan%^BOLD%^%^WHITE%^, %^RESET%^%^CYAN%^hitting it as the %^BOLD%^%^BLACK%^warhammer %^RESET%^%^CYAN%^flies out, %^BOLD%^and again as it returns to your hand!");
				tell_room(EETO,""+ETO->QCN+" %^BOLD%^%^CYAN%^hurls his %^BLACK%^W%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^rh%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^mm%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r %^CYAN%^at the %^RESET%^"+targ->QCN+"%^BOLD%^%^CYAN%^, str%^ORANGE%^i%^RESET%^%^CYAN%^k%^YELLOW%^i%^CYAN%^ng it as it flies out, %^RESET%^%^CYAN%^and again as it returns to %^WHITE%^"+ETO->QCN+"%^CYAN%^'s hand!",ETO);
				ETO->execute_attack();
				ETO->execute_attack();
			return 1;}
			if((string)ETO->query_class() == "paladin"){
				tell_object(ETO,"%^BOLD%^%^RED%^TitanBane tells you:%^BLUE%^ M'Lord! Worry not, I will fix that!");
				tell_object(ETO,"%^BOLD%^Bright light from the %^BLACK%^h%^WHITE%^a%^BLACK%^mm%^WHITE%^e%^BLACK%^r %^ORANGE%^e%^WHITE%^ng%^ORANGE%^u%^WHITE%^lf%^ORANGE%^e%^WHITE%^s you %^ORANGE%^e%^WHITE%^nt%^ORANGE%^i%^WHITE%^r%^ORANGE%^e%^WHITE%^l%^ORANGE%^y %^WHITE%^and you %^CYAN%^feel better.");
				tell_object(targ,""+ETO->QCN+"%^GREEN%^'s hammer glows %^CYAN%^bl%^BOLD%^i%^WHITE%^n%^CYAN%^d%^RESET%^%^CYAN%^ly %^BOLD%^%^BLUE%^bl%^RESET%^%^CYAN%^u%^BOLD%^e%^RESET%^%^GREEN%^, %^BOLD%^%^WHITE%^freezing %^RESET%^%^GREEN%^you on the spot!");
				tell_room(EETO,"%^GREEN%^The %^BOLD%^%^BLACK%^Hammer %^RESET%^%^GREEN%^wielded by %^WHITE%^"+ETO->QCN+" %^CYAN%^gl%^BOLD%^ow%^WHITE%^s %^RESET%^%^CYAN%^bl%^BOLD%^in%^WHITE%^di%^CYAN%^ng%^RESET%^%^CYAN%^ly bl%^BOLD%^u%^WHITE%^e %^RESET%^%^GREEN%^until the %^BOLD%^%^CYAN%^light %^RESET%^%^GREEN%^engulfes both %^WHITE%^"+targ->QCN+" %^GREEN%^and %^WHITE%^"+ETO->QCN+"%^GREEN%^.",({ETO,targ}));
				targ->set_paralyzed(random(4)+4,"You are as frozen to the spot!");
				ETO->add_hp(random(10)+10);
				set_property("magic",1);
				targ->do_damage(targ->return_target_limb(),roll_dice(2,6));
				set_property("magic",-1);
			return 1;}
			else{
				tell_object(ETO,"%^BOLD%^%^RED%^TitanBane tells you:%^BLUE%^ Careful now. I will buy you a few seconds!");
				tell_object(ETO,"%^CYAN%^A beam of %^BOLD%^b%^BLUE%^r%^CYAN%^ight bl%^BLUE%^u%^CYAN%^e %^RESET%^%^CYAN%^light hits %^WHITE%^"+targ->QCN+" %^CYAN%^in the face, %^YELLOW%^d%^BLACK%^i%^ORANGE%^s%^BLACK%^o%^ORANGE%^r%^BLACK%^i%^ORANGE%^e%^BLACK%^n%^ORANGE%^t%^BLACK%^i%^ORANGE%^ng %^RESET%^%^CYAN%^"+targ->QO+"!");
				tell_object(targ,"%^BOLD%^%^CYAN%^The hammer sends a beam of blue light at you!"); 
				tell_room(EETO,""+ETO->QCN+"%^CYAN%^s warhammer sends a %^BOLD%^%^WHITE%^beam %^RESET%^%^CYAN%^of %^BOLD%^blue light %^RESET%^%^CYAN%^into %^WHITE%^"+targ->QCN+"%^CYAN%^s face!",({ETO,targ}));
				targ->set_paralyzed(random(4)+4,"%^BOLD%^%^WHITE%^The light has left you all disoriented!");
				set_property("magic",1);
				targ->do_damage(targ->return_target_limb(),roll_dice(1,6));
				set_property("magic",-1);
			return 1;}
			break;}
			
			case 85..99:{
			if((string)targ->query_name() == "titan"){
				tell_object(ETO," %^BOLD%^%^RED%^You jump high into the air and smash the %^ORANGE%^hammer %^RED%^into the %^BLACK%^ground%^RED%^, causing the %^GREEN%^titan %^RED%^to fall over!");
				tell_room(EETO,""+ETO->QCN+"%^BOLD%^%^RED%^jumps impossibly high in the air and smashes %^RESET%^"+ETO->QP+" %^BOLD%^%^RED%^Warhammer into the ground, knocking over the titan!",ETO);
				targ->set_tripped(3);
			return 1;}
			if((string)ETO->query_class() == "paladin"){
				tell_object(ETO,"The hammer forces you to lift it into the air and yell 'Smite Them!' as it releases blue bolts at your enemies!");
				tell_room(EETO,""+ETO->QCN+" %^YELLOW%^lifts %^RESET%^"+ETO->QP+" %^BOLD%^Warhammer %^ORANGE%^above "+ETO->QP+" head and releases %^CYAN%^several %^BLUE%^blue bolts %^ORANGE%^from it!",ETO);
				tell_object(ETO,""+targ->QCN+"%^BOLD%^%^BLUE%^ is blasted with a %^CYAN%^bolt%^BLUE%^ from your %^YELLOW%^Warhammer!");
				if(!sizeof(ebils)) return 10;
				bolts = roll_dice(1,6)+2;
				for(i = 0;i<bolts;i++) {
				targ = ebils[random(sizeof(ebils))];
				tell_object(ETO,""+targ->QCN+"%^BOLD%^%^BLUE%^ is blasted with a %^CYAN%^bolt%^BLUE%^ from your %^YELLOW%^Warhammer!");
				tell_room(EETO,""+targ->QCN+"%^BOLD%^%^BLUE%^ is blasted with a %^CYAN%^bolt%^BLUE%^ from "+ETO->QCN+"'s %^BOLD%^%^YELLOW%^Warhammer!",({ETO,targ}));
				tell_object(targ,"%^YELLOW%^You are struck by a %^BLUE%^blue bolt %^ORANGE%^from %^RESET%^"+ETO->QCN+"%^YELLOW%^'s %^WHITE%^Warhammer!");
				set_property("magic",1);
				targ->do_damage(targ->return_target_limb(),roll_dice(2,4));
				set_property("magic",-1);}
			return 1;}
			else{
				tell_object(ETO,"%^BOLD%^%^RED%^TitanBane tells you:%^BLUE%^ Protect yourself, you are bleeding!");
				tell_object(ETO,"%^CYAN%^The hammer flashes %^BOLD%^%^BLUE%^c%^CYAN%^oo%^BLUE%^l b%^CYAN%^lu%^BLUE%^e %^RESET%^%^CYAN%^and you feel a bit better!");
				tell_object(targ,"%^BOLD%^%^BLUE%^The %^BLACK%^Warhammer %^BLUE%^wielded by %^RESET%^"+ETO->QCN+" %^BOLD%^%^BLUE%^flashes a %^RESET%^%^CYAN%^cool %^BOLD%^blue %^BLUE%^color as it hits you!");
				tell_room(EETO,"The Warhammer wielded by "+ETO->QCN+" flashes slightly and "+ETO->QS+" looks slightly refreshed",({ETO,targ}));
				set_property("magic",1);
				targ->do_damage(targ->return_target_limb(),roll_dice(3,4));
				set_property("magic",-1);
				ETO->add_hp(random(10)+5);
			return 1;}
			break;}
			}
	}

}

