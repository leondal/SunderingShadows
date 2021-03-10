// spear of time 
//hades 5/11
#include <std.h>
#include "../elf.h"

inherit "/d/common/obj/weapon/spear_lg.c";

void create(){
    ::create();
    set_name("%^BOLD%^%^WHITE%^Spe%^CYAN%^ar of T%^CYAN%^i%^WHITE%^me%^RESET%^");
    set_id( ({"spear", "spear of time", "time spear"}) );
    set_short("%^RESET%^%^BOLD%^Spe%^CYAN%^a%^WHITE%^r of T%^CYAN%^i%^WHITE%^me%^RESET%^");
    set_obvious_short("%^RESET%^%^BOLD%^Swirling White Spear%^RESET%^");
    set_long("This spear is made of some strange shimmering "+
	"material.  It looks almost like it is made of liquid "+
	"but is solid to the touch.  The spear glimmers in the"+
	" light sending rays out in random chaotic directions.  "+
	"It has what looks to be a large diamond mounted on the tip.  %^RESET%^");
    
        set_lore("These spears are products of high magic "+
		"created by a group of elven magi.  Such magic is "+
		"consider dangerous, not only have elven magi lost "+
		"their lives in such rituals but the realm itself "+
		"can be sundered if something goes wrong.  The spear"+
		" itself is said to hold power over the very fabric of time.");
        set_property("lore",30);
        set_value(10000);
        set_hit((:TO,"hitme":));
        set_property("enchantment",4);
        set_wield((:TO,"wield_func":));
        set_unwield((:TO,"unwield_func":));
}
int wield_func(string str) {
   if((int)ETO->query_level() < 20) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^The spear fades away as you"+
                " try to wield it, only to resolidify.");
        return 0;
}
        tell_object(ETO,"%^BOLD%^The spear seems cool to the touch as"+
                " you grasp the shaft.\n %^CYAN%^You feel one with time and space.");
        return 1;
}
int unwield_func(string str) {
        tell_object(ETO,"%^BOLD%^You release your hold of the cool"+
                " shaft of the spear.  You feel more mundane without it.");
        return 1;
}

int hitme(object targ)
{ int i;
  object *attackers;
 
   if(!random(16)) {
      tell_object(ETO,"%^BOLD%^You drive the spear into"+
                " "+targ->QCN+", freezing "+targ->QO+" in t%^CYAN%^i%^WHITE%^me.");
      tell_object(targ,"%^BOLD%^"+ETO->QCN+"'s"+
                " strikes you with a flash that freezes you in t%^CYAN%^i%^WHITE%^me.");
      tell_room(EETO,"%^BOLD%^"+ETO->QCN+"'s spear strikes "+targ->QCN+"'s"+
                " body, freezing "+targ->QO+" in time.",({ETO,targ}));             
      targ->set_paralyzed(5+random(5),"%^BOLD%^Time has stopped...");
        return 1;
   }
   if(!random(50)) {
     attackers = ETO->query_attackers();
   
     tell_object(ETO,"%^BOLD%^A brilliant %^CYAN%^flash%^WHITE%^"+
	   " explodes from your spear freezing your attackers."); 
     tell_room(EETO,"%^BOLD%^"+ETO->QCN+"'s"+
          " spear lets out a %^CYAN%^blinding "+
		  "light%^WHITE%^ that freezes %^CYAN%^time%^WHITE%^ for "+targ->QP+" attackers!",({ETO}));
    for(i=0; i < sizeof (attackers); i++) 
	  {attackers[i]->set_paralyzed(random(10),"%^BOLD%^Time has stopped!");}                   
        return 1;
   }
}
