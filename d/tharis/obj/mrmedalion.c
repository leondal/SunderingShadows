//changed to allow only one at a time after seeing several people 
//stacking them.  MR 10 is too good to be stacked with 
//how easy these are to get.  Circe 9/22/04
#include <std.h>
#define MAXUSES 5
#define BONUS 10
inherit ARMOUR;

int uses;

void create(){
	::create();
        set_name("medallion");
        set_id(({"medallion","silver medallion","magic item","magic medallion","silver_medallionxx"}));
        set("short","A simple silver medallion");
	set("long",
@OLI
Hot to the touch, this medallion retrieved from the body of the
ruffian, however simple is too much to explain away. This medallion had 
to have been obtained somewhere. The front contains the pick and axe
of Tharis but the back has imprinted on it an unfamiliar dragon wing
and bone hand.
OLI
	);
	set_weight(2);
	set_value(20);
	set_wear((: this_object(),"wear_me" :));
	set_remove((:this_object(),"remove_me" :));
	set_type("ring");
	set_limbs(({"neck"}));
	set_item_bonus("magic resistance",1);
	set_heart_beat(1);
}

int wear_me(){
	if(uses < MAXUSES){
		write("%^BOLD%^You feel more protected");
		uses += 1;
		return 1;
	}
	else {
		write("%^BOLD%^As you attempt to wear this item,"
		 +"it disintegrates to dust.");
		TO->remove();
	}
}

int remove_me(){
	write("%^BOLD%^You feel the protection receed!");
	return 1;
}

void heart_beat(){
   object ob;
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(!living(ETO)) return;
   if((ob = present("silver_medallionxx",ETO)) && living(ETO) && ob != TO){
      if(TO->query_worn() && ob->query_worn()){
         tell_object(ETO,"%^BOLD%^The magic in the medallions strengthens as "+
            "they begin to glow!");
         tell_room(EETO,"%^BOLD%^The medallions worn by "+ETOQCN+" begin to glow!",ETO);
         tell_room(EETO,"%^YELLOW%^The medallions suddenly disintegrate!");
         ob->remove();
         TO->remove();
      }
   }
}