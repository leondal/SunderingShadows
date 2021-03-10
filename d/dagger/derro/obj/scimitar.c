//updated by Circe 4/17/04 to new desc and current code
//fixed several typos but don't see a reason for Adlon saying it all disappeared
//couldn't carry the weight.  I'd assume in that case it should have still landed on the floor.  *Styx*  4/11/02
// found the encumbrance problem being with the code on the old scimitar, updating this to inherit from /d/common while I'm checking things out though *Styx* 8/20/06
// adjusted the light addition from +5 to +3 - too overpowering. N, 11/06.
//Updated stuns to have saving throws, also removed do_damage and replaced with divine damage -Hades 10/18/20

#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/scimitar";

#include "../derrodefs.h"

int align;
int old;
int flag;
object ob2;
string OWNER;
string wielder;
void init(){
    ::init();
    if(interactive(ETO) && ETO==environment(TO)  && !OWNER) OWNER = ETO->query_name();;
}
void create(){
    ::create();
    set_id(({"scimitar","scimitar of the silver moon","sword","silver scimitar"}));
    set_name("silver scimitar");
    set_obvious_short("A shining scimitar");
    set_short("%^BOLD%^%^WHITE%^Scimitar %^CYAN%^of %^WHITE%^the %^CYAN%^silver %^WHITE%^moon%^RESET%^");
    set_long("%^BOLD%^This breathtaking blade seems to %^CYAN%^"+
       "glow %^WHITE%^with its own inner %^YELLOW%^light%^WHITE%^.  "+
       "The slender, curving blade takes the form of a %^CYAN%^"+
       "waxing crescent moon %^WHITE%^and is carved with intricate, "+
       "swirling %^BLUE%^runes%^WHITE%^.  When wielded by one good "+
       "of heart, the %^BLUE%^runes %^WHITE%^glow and pulse as "+
       "if filled with molten platinum.  The hilt of the blade is "+
       "made of contrasting %^BLACK%^black lacquered steel %^WHITE%^"+
       "that provides a firm grip for the stout warrior who wields "+
       "such a blade."
    );
    set_value(4000);
    set_property("enchantment",4);
    set_item_bonus("sight bonus",3);
    set_hit((: TO,"extra_hit" :));
    set_wield((:TO,"extra_wield" :));
    set_unwield((:TO,"extra_unwield" :));
}
int extra_hit(object ob){
    int dam;
    wielder=ETO;
    if(!objectp(ob)) return 1;
    if(!random(7)){
      dam=(random(4)+3);
	switch(random(29)){
	case  0..1:
	    tell_object(ETO,"%^BOLD%^%^CYAN%^As you slice into "+
             ""+ob->QCN+" you see an opening and drive your knee "+
             "into an exposed area!");
	    tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" cuts into "+
             ""+ob->QCN+" and then quickly drives a knee into an "+
             "exposed area before "+ob->QCN+" recovers!",({ETO,ob}));
	    tell_object(ob,"%^BOLD%^%^WHITE%^"+ETOQCN+" slices into "+
             "you and before you can react drives a knee into your ribs!");
      if(!"/daemon/saving_throw_d.c"->fort_save(ob,-20))
	    ob->set_paralyzed(random(5)+2,"You take a couple of deep breaths "+
             "to get your balance again!");

	    return dam+random(5)+3;
	    break;
	case 2:
	    tell_object(ETO,"%^BOLD%^%^WHITE%^The silver blade "+
             "%^FLASH%^flashes%^RESET%^%^BOLD%^ with sunlight "+
             "reflected from inside itself!",ETO);
          tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+"'s sword "+
             "%^FLASH%^flashes%^RESET%^%^BOLD%^ brilliantly as "+
             "it cuts into "+ob->QCN+" who staggers back rubbing "+
             ""+ob->QP+" eyes!",({ETO,ob}));
          tell_object(ob,"%^BOLD%^%^WHITE%^"+ETOQCN+"'s blade "+
             "%^FLASH%^flashes%^RESET%^%^BOLD%^ brilliantly as "+
             "it swings towards you and you can see nothing but "+
             "spots before your eyes!");
      if(!"/daemon/saving_throw_d.c"->reflex_save(ob,-20)){
	    if(!random(3)) ob->set_blind(1);
	    else ob->set_paralyzed(4+random(4),"%^BOLD%^You're "+
             "rubbing the spots out of your eyes.");
      }
          return dam;
	    break;
	case 3..6:
	    tell_room(EETO,"%^BOLD%^%^WHITE%^A huge white owl "+
             "swoops down at "+ob->QCN+"!",ob);
	    tell_room(ob,"%^BOLD%^%^WHITE%^A huge white owl "+
             "swoops down at you!");
	    ob2=new(MON"owl.c");
	    ob2->move(EETO);
	    ob2->force_me("protect "+wielder->query_name());
	    wielder->add_follower(ob2);
	    break;
	case 7..8:
          tell_object(ETO,"%^BOLD%^%^CYAN%^As you sweep the "+
             "blade across "+ob->QCN+" you spin around with "+
             "the same movement and slam the pommel back into "+
             ""+ob->QO+"!");
	    tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+" sweeps "+
             "the blade across "+ob->QCN+" and continues to "+
             "spin around with the movement, bringing the "+
             "pommel smashing back into "+ob->QP+"!",({ETO,ob}));
          tell_object(ob,"%^BOLD%^%^WHITE%^"+ETOQCN+" sweeps "+
             ""+ETO->QP+" scimitar across your body and continues "+
             "to spin with the movement to bring the pommel "+
             "smashing back into you!");
      if(!"/daemon/saving_throw_d.c"->fort_save(ob,-20))
	    ob->set_paralyzed(15,"%^BOLD%^%^CYAN%^You stagger dazed "+
             "from the blow!");
	    return 10;
	    break;
	case 9..26:
       tell_object(ETO,"%^BOLD%^%^WHITE%^The blade flashes "+
             "like moonlight through clouds, and "+ob->QCN+"'s "+
             "body tries to tear itself apart under the light!");
	    tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+"'s scimitar "+
             "flashes as it hits "+ob->QCN+"!",({ETO,ob}));
       tell_object(ob,"%^BOLD%^%^WHITE%^"+ETOQCN+"'s scimitar "+
             "flashes as it bites into your flesh!");
	    ob->cause_typed_damage(ob,0,roll_dice(1,15)+5,"divine");
	    return dam;
	    break;
	case 27:
          tell_object(ETO,"%^BOLD%^%^WHITE%^The blade flashes "+
             "like moonlight through clouds, and "+ob->QCN+"'s "+
             "body tries to tear itself apart under the light!");
	    tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+"'s scimitar "+
             "flashes as it hits "+ob->QCN+"!",({ETO,ob}));
          tell_object(ob,"%^BOLD%^%^WHITE%^"+ETOQCN+"'s scimitar "+
             "flashes as it bites into your flesh!");
      ob->cause_typed_damage(ob,0,roll_dice(1,25)+4,"divine");
	    return random(10)+3;
	    break;
	default:
	    ETO->execute_attack();
	    ETO->execute_attack();
	    ETO->execute_attack();
	    tell_object(ETO,"%^CYAN%^The sword suddenly blurs as it "+
             "speeds your attacks!");
          tell_room(EETO,"%^CYAN%^"+ETOQCN+"'s blade suddenly "+
             "blurs with speed as "+ETO->QS+" attacks!",({ETO,ob}));
          tell_object(ob,"%^CYAN%^"+ETOQCN+" suddenly blurs "+
             "with speed as "+ETO->QP+" scimitar slashes at you!");
       if(!random(25)){
         tell_object(ETO,"%^BOLD%^%^CYAN%^You can't hold onto "+
            "the scimitar as it speeds through the air and it falls "+
            "to the ground, the brilliant sapphire smashing as it impacts!");
         tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+" can't keep a "+
            "grasp on the scimitar, and its brilliant sapphire smashes "+
            "at it hits the ground!.",ETO);
		tell_room(EETO,"The scimitar fades to grey.");
		new(OBJ"oldscimitar.c")->move(EETO);
		TO->remove();
	    }
	    break;
	}
    }
  return (random(5)+1);
}

int extra_wield(){
  if(!interactive(TP)) return 1;
    if((string)ETO->query_name() !=OWNER){
	tell_object(ETO,"%^BOLD%^%^CYAN%^The scimitar does not know you!");
	return 0;
    }
    if((int)ETO->query_highest_level()<20){
	tell_object(ETO,"The scimitar will not be wielded by such a "+
         "weak hand as yours.");
	tell_room(EETO,""+ETOQCN+" seems to be "+
         "having difficulty figuring out which end of the "+
         "scimitar to use.",ETO);
	return 0;
    }
   if(ALIGN->is_evil(ETO)){
     tell_object(ETO,"%^BOLD%^%^RED%^The scimitar burns your "+
        "hands as you try to wield it!");
     tell_room(EETO,"%^BOLD%^%^RED%^The scimitar flashes as "+
        ""+ETOQCN+" tries to wield it, burning "+ETO->QO+"!",ETO);
     ETO->force_me("drop scimitar of the silver moon");
     ETO->cause_typed_damage(ETO,0,roll_dice(1,50)+25,"divine");
     return 0;
   }
   tell_object(ETO,"The scimitar glows brightly as you wield it.");
   tell_room(EETO,"The scimitar glows brightly as "+ETOQCN+" "+
      "wields it.",ETO);
   ETO->set_property("good item",1);
   return 1;
}

int extra_unwield(){
    tell_room(EETO,""+ETOQCN+"'s sword dims as it is released.",ETO);
    tell_object(ETO,"The sword dims as you let it go.");
    ETO->set_property("good item",-1);
    return 1;
}
