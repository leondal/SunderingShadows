// fixing it causing an error when it vapes during get *Styx* 4/1/06

#include <std.h>
inherit OBJECT;

void vape_key(object who, object key); 

void create() {
    ::create();
    set_name("key");
    set_id(({"key","mist key","mist_key"}));
   set_short("%^CYAN%^Mist Key%^RESET%^");
    set_long(
        "This key shifts and wavers as you gaze upon it."
);
    set_weight(10);
    set_value(500);
}

void init(){
   object ob;
	::init();

	if(ob = present("mist_key 2",ETO))
	    vape_key(TP, ob);
/***** moving it into a callout so get can finish *Styx*
        tell_object(ETO,"The keys seem to react to each other and one explodes violently.");
        if(objectp(EETO))
	ob->remove();
        TO->remove();  
        ETO->do_damage(roll_dice(4,5));
 }
********/
}

void vape_key(object who, object key) {
   if(!objectp(ETO)) return;
   if(!objectp(TO)) return;
   if(!objectp(who)) return;
   tell_room(ETO,"The keys seem to react to each other and one explodes violently.");
   key->remove();
   who->do_damage(roll_dice(4,5));
//   TO->remove();  // removing it was bugging the move even here
   return;
}
  
