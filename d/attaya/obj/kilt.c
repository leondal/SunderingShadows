//Cythera
// updated cha bonus from the new system. Nienne, 09/07.
#include <std.h>;
inherit "/std/armour";

void create(){
   ::create();
   set_name("kilt");
   set_id(({"kilt","wool kilt","kilt of the four winds","gray kilt"}));
   set_short("%^BOLD%^%^BLACK%^Kilt of the %^RESET%^%^BLUE%^F"+
	"%^BOLD%^%^CYAN%^o%^RESET%^u%^BOLD%^%^BLACK%^r %^WHITE%^W%^CYAN%^"+
	"i%^BLUE%^n%^RESET%^%^BLUE%^d%^RESET%^s");
   set_obvious_short("%^BOLD%^%^BLACK%^A gray wool kilt%^RESET%^");
   set_long("%^RESET%^%^BLUE%^Crafted from tightly woven wool, "+
	"this kilt is extremely light in weight and soft to the touch"+
	".  The deep coloring of the kilt mirrors the sky in the middle"+	
	" of a storm, a %^BOLD%^%^BLACK%^deep dark gray%^RESET%^%^BLUE%^ "+
	"with tinges of %^BOLD%^%^BLUE%^c%^RESET%^%^CYAN%^o%^BLUE%^o%^BOLD%^l"+
	" blue%^RESET%^%^BLUE%^.  The soft wool is woven so tight to shield a "+
	"man from the extremities of the weather.  No pattern is woven into the"+
	" cloth, though on a closer inspection threads of %^BOLD%^%^BLACK%^deep "+
	"gray%^RESET%^%^BLUE%^, %^RESET%^light gray%^BLUE%^, and %^CYAN%^c%^BOLD%^"+
	"%^BLUE%^o%^RESET%^%^BLUE%^o%^CYAN%^l%^BLUE%^ shades of %^BOLD%^blue%^RESET%^"+
	"%^BLUE%^ can be found.  Falling just below the knee, the kilt is pleated in "+
	"a manner to rest on one's hips.  A simple %^BOLD%^%^WHITE%^silver%^RESET%^"+
	"%^BLUE%^ pin secures the kilt in place.%^RESET%^\n");
   set_type("clothing");
   set_limbs(({"right leg","left leg"}));
   set_property("enchantment",5);
   set_item_bonus("charisma",2);
   set_lore("The Kilt of the Four Winds seems tied to a clan of warriors"+
	" who once lived on what is now Graez.  The clan of warriors were "+
	"well known for their fleet movements in battle and their courage. "+
	" It was said that when Attaya first came under threat that the "+
	"Oriaum clan sent their best to help defend the city of Seneca from"+
	" the hordes of Undead.  After driving back the undead from Seneca "+
	"one band of warriors lead by Kalimex was said to have tore through"+
	" the jungle taking the battle to the heart of the Tower of the "+
	"Black Dawn, and deeper.  Kalimex and his companions never "+
	"returned back to Seneca.  Some claim that in an hour of need "+
        "Kalimex will appear within the Tower of Black Dawn, "+
	"to guide those who seek to stem the evils of the Crystal Tower"+
	" to safety.  It is said that with this kilt one may call upon "+
        "some of the minor magic that is woven into the cloth, the ability"+
        " to summon a %^BOLD%^%^CYAN%^breeze%^RESET%^.");
   set_property("lore",12); 
   set_weight(2);
   set_size(2);
   set_value(7500);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
}

void init(){
   ::init();
   add_action("breeze","breeze");
}

int wearme(){
   if((string)ETO->query_gender() != "male"){
      tell_object(ETO,"%^BLUE%^Try as you might, you just can't fit "+
         "into the kilt!");
      return 0;
   }
   if((int)ETO->query_highest_level() < 25) {
    tell_object(ETO,"The kilt blows away out of your grasp.");
        return 0;
   }

   tell_object(ETO,"%^BOLD%^%^BLACK%^You slip into the wool "+
      "kilt and notice how nice your legs look.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" slips into the "+
      "wool kilt, drawing your eyes briefly to his shapely "+
      "legs.",ETO);
   return 1;
}

int unwearme(){
   tell_object(ETO,"%^BLUE%^You remove the kilt, missing it "+
      "already.");
   tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+" removes the kilt "+
      "with a soft sigh.",ETO);
   return 1;
}

int breeze(string str){
   if(!str){
      tell_object(ETO,"%^BOLD%^%^BLUE%^You feel a comforting breeze blow in, cooling you off.");
      tell_room(EETO,"%^BLUE%^%^BOLD%^"+ETOQCN+"'s kilt blows up as a breeze rushes in"+
		", answering any questions one might have about what he wears under the kilt!",ETO);
      return 1;
   }
}
