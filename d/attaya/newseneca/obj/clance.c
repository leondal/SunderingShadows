//Coded by Hades 9/15/11
#include <std.h>
inherit "/d/common/obj/weapon/lance.c";
object lancegirl;

void create(){
    ::create();
    set_id(({"lance","feathered lance","celestial lance"}));
    set_name("celestial lance");
    set_short("%^RESET%^c%^CYAN%^e%^BOLD%^l%^RESET%^estial l%^CYAN%^a%^BOLD%^n%^RESET%^ce");
	set_obvious_short("%^RESET%^A h%^CYAN%^u%^RESET%^ge f%^CYAN%^e%^BOLD%^a%^RESET%^ther c%^CYAN%^o%^BOLD%^v%^RESET%^ered l%^CYAN%^a%^BOLD%^n%^RESET%^ce");
    set_long(
      "%^CYAN%^This lance is insanely large.  "+
	  "It looks almost like some kind of a %^BOLD%^giant"+
	  " birds body%^RESET%^%^CYAN%^.  The whole thing has a "+
	  "natural curve to it ending in an upwards"+
	  " point.  The top of the lance has a %^RESET%^bone "+
	  "white%^CYAN%^ make to it and the under side is "+
	  "covered with bright %^MAGENTA%^purple feathers.  "+
	  "%^RESET%^%^CYAN%^This lance has continues past the handle"+
	  " and completely covers the lower part of"+
	  " the wearers arm.  It continues past the"+
	  " arm ending several feet back into a %^RESET%^white"+
	  " point.%^CYAN%^  This elegant weapon looks like it "+
	  "would be impossible to carry. "+
	  " However, it is surprisingly light.%^RESET%^");
    set_weight(5);
	set_property("enchantment",5);
	set_lore("This weapon is the key to a contract with a celestial"+
	" spirit.  Ages ago a heroic knight received this for his "+
	"commitment to justice and brave actions.  A contract binds "+
	"the celestial to the weapon as well as the wielder"+
	" to the celestial.\n One can _summon_ or _release_ the celestial.");
	set_property("lore difficulty",35);
    set_value(15000);
	set_hit((:TO,"hit_fun":));
 
}
void init(){
    ::init();
    add_action("summon","summon");
    add_action("release","release");
}

int release(string str){
 if(!objectp(ETO) || !objectp(EETO) || !objectp(lancegirl)) return 0;
 if (ETO->query_bound() || ETO->query_unconscious()) {
       ETO->send_paralyzed_message("info",ETO);
       return 0;
    }

    if(!str) return 0;

	if(str != "celestial"){ notify_fail("release who?  The celestial?\n");
	           return 0; }
    
    if(!lancegirl) return 0;

    lancegirl->die();
    return 1;
	
}

int summon(string str){
 if(!objectp(ETO) || !objectp(EETO)) return 0;
 if (ETO->query_bound() || ETO->query_unconscious()) {
       ETO->send_paralyzed_message("info",ETO);
       return 0;
    }

    if(!str) return 0;
	if(!ETO->is_class("paladin") ) 
    return notify_fail("Only knights can use this lance.\n");
	if(str != "celestial"){ notify_fail("summon who?  The celestial?\n");
	           return 0; }
    
    if(!lancegirl){
	  tell_room(EETO,"%^YELLOW%^Feathers burst in a storm"+
	    " from the lance leaving a winged woman behind in the wake.");
	  lancegirl = new("/realms/hades/lancegirl");
	  lancegirl->move(EETO);
      ETO->add_follower(lancegirl);
      lancegirl->set_lance(TO, ETO);
	  }
	else
	 tell_object(ETO,"The celestial is already summoned.");

    return 1;
	
}

int hit_fun(object targ) {
   ::check(targ);
   if(!objectp(ETO)) return 0;
   if(!objectp(targ)) return 0;
   
   switch (random(200)){
   
  case 1..20:  tell_object(targ,"%^CYAN%^The lance drive into you "+
   "followed by a %^BOLD%^gust of wind%^RESET%^%^CYAN%^ that drives you back.");
     tell_room(EETO,"%^CYAN%^The lance drive into "
	   +targ->QCN+" followed by a %^BOLD%^gust of"+
	   " wind%^RESET%^%^CYAN%^ that drives "+targ->QO+
	   " back. ",targ);
	 targ->set_tripped(1,"%^GREEN%^You try to get up, "+
	     "but the world is spinning.");
     break;
     
  case 21..40:      
       tell_room(EETO, "%^CYAN%^Winds gather around "+ETO->QCN+"'s body.", ETO);
	   tell_object(ETO, "%^CYAN%^Words for a spell enter your mind and you begin casting.");
       new("/cmds/spells/g/_gust_of_wind")->use_spell(ETO,targ,15,100,"mage");
     break;
       
  case 41..60: 
	  tell_object(targ,"%^CYAN%^"+ETO->QCN+"'s lance drives into you,"+
	   " sending you up into the air and back several paces.");
	  tell_room(EETO, "%^CYAN%^The lance is driven into "+targ->QCN+" sending them"+
	  " up into the air and back several paces.",targ);
	  break;	  
	  }
   //will save to unsummon 1 fodder
   if( (member_array("summoned monster",targ->query_id()) != -1) &&
      !"/daemon/saving_throw_d.c"->will_save(targ,-15)) {
     tell_room(EETO,"%^BOLD%^There is a flash of %^YELLOW%^gold lightning%^WHITE%^ as the lance strikes "
	 +targ->QCN+" leaving %^CYAN%^nothing%^WHITE%^ behind in when it dims.");
	 targ->move("/d/shadowgate/void");
	 targ->die();
	 return 1;
   }
   return roll_dice(2,6)+20;
}
int wieldme()
{
   if(ETO->query_property("evil item")) {
      tell_object(ETO,"The lance refuses to be"+
	  " wielded while you are using such evil items!");
      return 0;
   }
        if(ETO->is_class("paladin")) {
                tell_object(ETO,"%^CYAN%^The Celestial Lance glows with a soft blue light"+
                " as you wield it.");
                tell_room(environment(ETO),"%^CYAN%^The lance glows with a soft"+
                " blue light as "+ETO->QCN+" wields it.",ETO);
      ETO->set_property("good item",1);
                return 1;
        }
}
int removeme()
{
        if(ETO->is_class("paladin")) {
                tell_object(ETO,"%^CYAN%^The Celestial Lance ceases to glow.");
                tell_room(environment(ETO),"%^CYAN%^The lance stops glowing as"+
                " "+ETO->QCN+" releases it.",ETO);
    
      ETO->set_property("good item",-1);
                return 1;
        }
   ETO->set_property("good item",-1);
        return 1;
}
