//Coded by Bane//
//updated by Circe 5/24/04
#include <std.h>
#include "../undead.h"

inherit "/d/common/obj/weapon/club_lg";

object owned;

void init() 
{
    ::init();
    if(interactive(TP) && !owned) owned = TPQN;
}

void create()
{
    ::create();
    set_id(({"club","club of titans"}));
    set_name("%^MAGENTA%^Club of Titans%^RESET%^");
    set_obvious_short("A massive club");
    set_short("%^MAGENTA%^Club of Titans%^RESET%^");
    set_long("More than a club, this weapon looks to be a "
       "small, thick tree!  The gnarled, knotted body is "
       "made of smooth oak that tapers away from the head.  "
       "A counterbalance of a large, wooden knob has been "
       "carved on the opposite end, completing this simple "
       "but effective weapon.");
    
    set_lore("This is possibly the largest club you have ever seen as it "
        "is meant to be wielded by the Titans themselves.  You can "
        "almost feel the awesome power of the club radiating outward "
        "from its knotted hilt.  Only the most fierce warriors "
        "are worthy of such a weapon, and it is said that the titans "
        "are sometimes angered if they see another using their weapon.");
    
    set_property("lore difficulty",24);
     //set_weight(25);
    set_value(3500);
     //set_size(3);
      //set_wc(2,6);
      //set_large_wc(3,6);
    set_property("enchantment",2);
     //set_type("bludgeoning");
    set_hit((:TO,"extra_hit":));
    set_wield((:TO,"extra_wield":));
}

int extra_hit(object ob)
{
    int roll, roll2;
    roll=random(100)+1;
    roll2=random(20)+1;
    if(!objectp(ob)) return 1;
	
    if(roll > 60 && roll < 80)
    {
        tell_object(ob,"%^BOLD%^%^BLUE%^The club smashes into you "+
           "with the full force of the gods!");
        tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^The "+
           "club smashes into "+ob->QCN+" with the full force of "+
           "the gods!",ob);
        ob->do_damage(ob->return_target_limb(),roll_dice(2,4));
	    return 1;
	}
    	
    if(roll > 79)
    {           
        if(roll2 > 12)
        {
            tell_object(ob,"%^BOLD%^%^RED%^The club's mystic energies "+
                "ensnare you rending your soul!");
            tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^The "+
                "club's mystic energies ensnare "+ob->QCN+" rending "+
                "their soul!",ob);
            ob->set_paralyzed(10,"%^BOLD%^Your soul is still searching "+
                "for its body!");
	        return 1;
	    }
	    return 1;
   	}
}

int extra_wield() 
{
    if((string)TP->query_name() != owned && (string)TP->query_name() != "baldandar") 
    {
        tell_object(ETO,"The Club of the Titans rejects you!");
        TO->remove();
        return 0;
    }
    return 1;
}
