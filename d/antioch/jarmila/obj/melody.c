#include <std.h>
 inherit "/d/common/obj/weapon/longsword.c";
void create(){
	::create();
	set_name("%^RESET%^%^GREEN%^m%^RESET%^%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^l%^RESET%^%^BOLD%^%^BLACK%^o%^RESET%^%^BOLD%^%^GREEN%^dy%^RESET%^%^GREEN%^ o%^RESET%^%^WHITE%^f%^RESET%^%^BOLD%^%^GREEN%^ a %^RESET%^%^GREEN%^th%^RESET%^%^BOLD%^%^GREEN%^ou%^RESET%^%^WHITE%^s%^RESET%^%^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^nd no%^RESET%^%^BOLD%^%^GREEN%^t%^RESET%^%^WHITE%^e%^RESET%^%^GREEN%^s%^RESET%^");
	set_id(({ "flute", "thousand notes", "jade flute" }));
	set_short("%^RESET%^%^GREEN%^m%^RESET%^%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^l%^RESET%^%^BOLD%^%^BLACK%^o%^RESET%^%^BOLD%^%^GREEN%^dy%^RESET%^%^GREEN%^ o%^RESET%^%^WHITE%^f%^RESET%^%^BOLD%^%^GREEN%^ a %^RESET%^%^GREEN%^th%^RESET%^%^BOLD%^%^GREEN%^ou%^RESET%^%^WHITE%^s%^RESET%^%^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^nd no%^RESET%^%^BOLD%^%^GREEN%^t%^RESET%^%^WHITE%^e%^RESET%^%^GREEN%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^ja%^RESET%^%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^g%^RESET%^%^WHITE%^e%^RESET%^%^GREEN%^d %^RESET%^%^BOLD%^%^GREEN%^ja%^RESET%^%^WHITE%^d%^RESET%^%^GREEN%^e fl%^RESET%^%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^te%^RESET%^");
	set_long("%^RESET%^%^GREEN%^Formed from a single piece of %^BOLD%^raw jade %^RESET%^%^GREEN%^that has been carved into a tube, this flute is an amazing piece of craftsmanship. As the %^ORANGE%^l%^YELLOW%^ig%^WHITE%^h%^YELLOW%^t %^RESET%^%^GREEN%^travels through the flute, it reflects and refracts the light into a th%^BOLD%^ou%^RESET%^%^GREEN%^s%^BOLD%^%^WHITE%^a%^GREEN%^n%^RESET%^%^GREEN%^d "
"sh%^BOLD%^a%^RESET%^%^GREEN%^r%^RESET%^d%^GREEN%^s. The mouthpiece has been carved and smoothed, and each finger hole is meticulously %^BOLD%^%^BLACK%^carved%^RESET%^%^GREEN%^. The flute extends farther then it should however, and a thin strip of%^MAGENTA%^ silk %^GREEN%^has been tied to the end, as if you could hold it. All along the length of the flute are %^BOLD%^%^BLACK%^engravings %^RESET%^%^GREEN%^and %^BOLD%^%^BLACK%^pictographs%^RESET%^%^GREEN%^.%^RESET%^\n");
	set_value(10000);
	set_lore("%^CYAN%^The melody of a thousand notes was crafted by an elven artificer a thousand years ago. It is said that an avatar of Oghma inhabited the elfs body during its creation, filling the elfs head with every song known to the planes. The artifact moved from bard to bard, and any who held it seemed to become the most renowned and famous, always creating masterpieces. "
"The flute fell into obscurity when it fell into the hands of a young man during a competition in the city of Asgard. To everyones shock the man lost the competition to another bard with a mundane harp. He swore he would find the most complete and perfect music and disappeared.%^RESET%^");
	set_property("lore difficulty",30);
	set_item_bonus("attack bonus",7);
    set_item_bonus("charisma",6);
        set_property("enchantment",7);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^As "+ETOQCN+"%^RESET%^%^CYAN%^ wraps their hands around the "+query_short()+"%^RESET%^%^CYAN%^, it %^BOLD%^glows%^RESET%^%^CYAN%^ softly.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^You wrap your hands around the "+query_short()+"%^RESET%^%^CYAN%^, your head filling with a soft melody.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^"+ETOQCN+"%^RESET%^%^CYAN%^ sets the flute aside, looking around with a smile.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^You set the "+query_short()+"%^RESET%^%^CYAN%^ aside, the world becomes silent again, but you can still remember the melody.%^RESET%^");
     return 1;
}

int hit_func(object target) {
   object ob;
   if(!objectp(target)) return 0;
   if(random(1000) < 300){
      switch(random(11)){
           case 0..4:
            ETO->execute_attack();
              tell_room(environment(ETO),"%^GREEN%^%^BOLD%^"+ETO->query_cap_name()+" "+
			  "%^GREEN%^%^BOLD%^turns as "+ETO->query_subjective()+" %^GREEN%^%^BOLD%^"+
			  "spins quickly, hitting "+target->query_cap_name()+"%^GREEN%^%^BOLD%^ "+
			  "again!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^GREEN%^%^BOLD%^A song of winds and dance fill your "+
			"head as you turn to attack "+target->query_cap_name()+"%^GREEN%^%^BOLD%^ "+
			"again!%^RESET%^",({environment(ETO),target}));
            tell_object(target, ""+ETO->query_cap_name()+" %^GREEN%^%^BOLD%^smiles at "+
			"something as "+ETO->query_subjective()+" %^GREEN%^%^BOLD%^spins quickly "+
			"around to attack you again!%^RESET%^",({environment(ETO),ETO}));
                  return roll_dice(3,10)+5;
              break;
           case 5..10:
         tell_room(environment(ETO),""+ETO->query_cap_name()+" %^RED%^%^BOLD%^places "+
		 "the flute to their lips, firing a blast of power "+
		 "towards "+target->query_cap_name()+"%^RED%^%^BOLD%^in a forceful "+
		 "explosion!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^RED%^%^BOLD%^You place the flute to your lips, "+
			"playing a song of dragon's magesty that "+
			"engulfs "+target->query_cap_name()+"%^RED%^%^BOLD%^ in a "+
			"forceful explosion of energy!%^RESET%^",({environment(ETO),target}));
            tell_object(target, ""+ETO->query_cap_name()+" %^RED%^%^BOLD%^places "+
			"the flute to their lips, and you are suddenly engulfed in a burst "+
			"of energy!%^RESET%^",({environment(ETO),ETO}));
                  return roll_dice(6,10)+10;
              break;
         case 11:
            tell_room(environment(ETO),"%^RESET%^%^CYAN%^As "+ETO->query_cap_name()+" %^RESET%^"+
			"%^CYAN%^steps away from the fight and plays a soft melody on the flute, "+
			"then tells "+target->query_cap_name()+"%^RESET%^%^CYAN%^ to "+
			"sleep!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^RESET%^%^CYAN%^An elven lulluby comes to "+
			"mind and you play it softly on the flute, "+
			"telling "+target->query_cap_name()+"%^RESET%^%^CYAN%^ to "+
			"sleep!%^RESET%^",({environment(ETO),target}));
            tell_object(target, "%^RESET%^%^CYAN%^As "+ETO->query_cap_name()+" %^RESET%^"+
			"%^CYAN%^plays a soft song on the flute, you recognize a lulluby you "+
			"heard years ago, and fall to the ground asleep%^RESET%^",({environment(ETO),ETO}));
            target->set_paralyzed(20,"%^BLACK%^%^BOLD%^You cant wake from the lulluby.%^RESET%^");
            if(!random(3)) target->set_blind(1);
            else target->set_paralyzed(3+random(4), "%^BLACK%^%^BOLD%^Your eyes are "+
			"still drowsy!%^RESET%^");
            break;
      }
   }
}
