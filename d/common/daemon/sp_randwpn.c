#include <std.h>
inherit WEAPON;

int my_weight;

#define SSTRIKES ({"slices","cuts","slashes","maims","mutilates",\
"chops","knifes through","cleaves","hacks into","hews","lacerates",\
"mangles","gashes","sunders","incises" })

#define PSTRIKES ({"pierces","guts","stabs","impales","rends","perforates",\
"spears","gores","punctures","wounds","disfigures" })

#define PLASHES ({"slices","cuts","slashes","maims","mutilates","lacerates",\
"mangles","gashes","wounds","punctures","blasts" })

#define BSTRIKES ({ "slams","smashes","strikes","mauls","crushes","hurts",\
"blasts","batters","smites","whacks","smacks" })

#define CUTS ({	"deeply","lightly","harshly","mercilessly",\
"malevolently","masterfully","cunningly","ruthlessly","intensely",\
"skillfully","sharply","violently","roughly","wildly","severely",\
"impressively","grimly","abruptly","quickly" })

#define SMASHES ({ "harshly","mercilessly","terribly","powerfully",\
"malevolently","masterfully","cunningly","ruthlessly",\
"skillfully","violently","roughly","wildly","severely","impressively",\
"grimly","abruptly","quickly","mightily","forcefully","vigorously",\
"seriously","potently" })

#define COL ({ "%^BOLD%^","%^RED%^","%^BLUE%^","%^YELLOW%^","%^CYAN%^",\
"%^GREEN%^","%^MAGENTA%^","%^BOLD%^RED%^","%^BOLD%^BLUE%^","%^BOLD%^CYAN%^",\
"%^BOLD%^GREEN%^","%^BOLD%^MAGENTA%^","%^ORANGE%^" })

#define WIELDFAIL "%^BOLD%^You are not experienced enough to use this weapon.%^RESET%^"

void create() {
   ::create();
   "/d/common/daemon/sp_randwpn_d.c"->create_weapon(TO);
   set_hit((:TO,"hit_func":));
   set_wield((:TO,"wield_func":));
   set_lore("A glyph inscribed on this weapon indicates it is one of a series "
     "created by the master weaponsmith of the Kinnesaruda empire and "
     "enchanted by the King's personal mage.  These weapons were generally "
     "crafted especially for the most esteemed warriors in the King's army "
     "but most were lost or entombed with their owners as a result of the "
     "war with Intruder.  Some have been re-appearing over the years but "
     "how or why is still unknown.");
}

int wield_func(){
   switch((int)TO->query_property("enchantment")){
      case 1:
         if((int)ETO->query_highest_level() < 5){
            tell_object(ETO,WIELDFAIL);
            return 0;
         }
         break;
      case 2:
         if((int)ETO->query_highest_level() < 10){
            tell_object(ETO,WIELDFAIL);
            return 0;
         }
         break;
      case 3:
         if((int)ETO->query_highest_level() < 15){
            tell_object(ETO,WIELDFAIL);
            return 0;
         }
         break;
      case 4:
         if((int)ETO->query_highest_level() < 20){
            tell_object(ETO,WIELDFAIL);
            return 0;
         }
         break;
      case 5:
         if((int)ETO->query_highest_level() < 25){
            tell_object(ETO,WIELDFAIL);
            return 0;
         }
         break;
      case 6:
         if((int)ETO->query_highest_level() < 30){
            tell_object(ETO,WIELDFAIL);
            return 0;
         }
         break;
   }
   return 1;
}

set_weight(int x) {
   ::set_weight(x);
   my_weight = x;
}

query_weight() {
   return my_weight;
}

int hit_func(object targ) {
    string type, hits, cuts, col, col2, col3, col4, name;
    if(random(5))    return 0;

// added because stab doesn't seem to send a targ when it first does damage *Styx*  3/2/03
    if(!objectp(targ)) return 0;  
    name = TO->query_name();
    type = (string)TO->query_type();
    if(type == "bludgeoning" || type == "bludgeoning") {
	hits = BSTRIKES[random(sizeof(BSTRIKES))];
	cuts = SMASHES[random(sizeof(SMASHES))];
    }
    if(type == "slashing" || type == "slash" || type == "slashing") {
	hits = SSTRIKES[random(sizeof(SSTRIKES))];
	cuts = CUTS[random(sizeof(CUTS))];
    }
    if(type == "pierce" || type == "piercing" || type == "piercing" || type == "piercing") {
	hits = PSTRIKES[random(sizeof(PSTRIKES))];
	cuts = CUTS[random(sizeof(CUTS))];
    }
	if(type == "lash") {
	hits = PLASHES[random(sizeof(PLASHES))];
	cuts = CUTS[random(sizeof(CUTS))];
    }

    col = COL[random(sizeof(COL))];
    col2 = COL[random(sizeof(COL))];
    col3 = COL[random(sizeof(COL))];
    col4 = COL[random(sizeof(COL))];

    switch( random(TO->query_property("enchantment") + 10) ) {
	case 0..2 :	    
	  break;
	case 3..7:
	  tell_object(targ, col+"The "+name+" "+hits+" you!");
	  tell_room(EETO, col+"The "+name+" "+hits+" "+targ->QCN+"!",targ);
	  targ->do_damage(targ->return_target_limb(),random(4)+3);
	  break;
      case 8..9:
        break;
	case 10..11:
	   tell_object(targ, col2+"The "+name+" "+hits+" you with a tremendous force!");
	   tell_room(EETO, col2+"The "+name+" "+hits+" "+targ->QCN+" with a tremendous force!",targ);
	   targ->set_paralyzed(random(3)+1,"You are recovering from that hit.");
//toned down greatly in response to player suggestions.  Circe 4/17/04  Was 15
	   break;
	case 12..13 :
	   tell_object(targ, col3+"The "+name+" "+hits+" you "+cuts+"!");
	   tell_room(environment(ETO), col3+"The "+name+" "+hits+" "+targ->query_cap_name()+" "+cuts+"!",targ);
	   targ->do_damage(targ->return_target_limb(),random(8)+3);
	   break;
	case 14 :
	   tell_object(ETO, col4+"The "+name+" quickens your movements allowing an extra attack!");
	   tell_room(environment(ETO), col4+ETOQCN+" suddenly moves with an inhuman speed!",ETO);
	   ETO->execute_attack();
	   break;
	default:
	   break;
    }
    return 1;
}
