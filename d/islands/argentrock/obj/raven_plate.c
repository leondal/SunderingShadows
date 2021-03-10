//Crystal Orignal - Updated Code/Added Lore
//Cythera 8/05
#include <std.h>
inherit "/d/common/obj/armour/fullplate.c";

void create(){
	::create();
   	set_name("raven plate");
   	set_short("%^BOLD%^%^BLACK%^Plate of the R%^BOLD%^%^RED%^"+
		"a%^BOLD%^%^BLACK%^v%^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^n%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A suit of black fullplate%^RESET%^");
   	set_id(({"plate","fullplate","full plate","raven plate",""+
		"plate of the raven","raven full plate","raven fullplate"}));
   	set_long(
   		"%^BOLD%^%^BLACK%^The fullplate is truly a work of art. Along the"+
   		" edges in intricate detail are raised sections of the metal in"+
   		" flowing designs. The armor is as sturdy as can be, however, and"+
   		" as much care was obviously given to its defensive capabilities as"+
   		" well as the owner's comfort kept in mind. On the front breastplate"+
   		" is the image of a large raven all in black, with wings stretched out"+
   		" and claws extended. With %^RED%^piercing red eyes%^BLACK%^ and gaped"+
   		" beak it is a fearsome sight.%^RESET%^\n");
	set_lore("The Plate of the Raven were once glorious suits of armor, worn"+
		" by the Starlit Ravens of the elven kingdom of Selu'havessthor, deep "+
		"within the Tsarven empire.  The group known as the Starlit Ravens were "+
            "those trained warriors born of house Heasirretyn, counterpart to house "+
            "Agrashalva in their guardianship of the first house of Selu'havessthor.  "+
            "Perhaps the darkened armor was a sign of their true nature, for sure "+
            "enough, the first house succumbed to darkness and the eventual purging "+
            "from their homeland.  The warriors of the fey'ri took these suits of "+
		"armor with them as a memory of their former lives, though their half-"+
            "demonic nature has long since twisted and corrupted the armor to its "+
            "present day form.");
     	set_property("lore",12);
	set_property("enchantment",4);
	set_size(-1);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
	set_value(5000);}

int wearme(){
     if((int)ETO->query_highest_level() < 30) {
        tell_object(ETO,"The armor doesn't fit you!");
        return 0;
     }
   if(ALIGN->is_good(ETO)) {
      tell_object(ETO,"An ear-splitting scream pierces the air as you try"+
      " to don the plate.");
         tell_room(environment(ETO),"The cry of an angry raven pierces the air!",ETO);
      return 0;
   }
   tell_object(ETO,"%^RED%^As you settle the plate about you it's as though"+
   	" another presence cloaks you in protection.");
   tell_room(environment(ETO),"You almost think you see the eyes of the"+
   	" raven %^BOLD%^%^RED%^flash%^RESET%^ as "+ETO->QCN+" slips"+
   	" into the plate.",ETO);
   		ETO->set_property("evil item",1);
      return 1;
}

int removeme()
{
   tell_object(ETO,"%^BOLD%^%^BLACK%^You feel a sudden vulnerability after"+
   	" taking off the plate.");
   		ETO->set_property("evil item",-1);
   		return 1;
}
