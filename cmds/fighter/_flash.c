//Modified for fighter update - Octothorpe 6/22/09
//typos fixed by Circe 4/4/05.  Suspect there are still more.
//changed by Circe 5/14/04.  Adding in fighting styles.
//  /cmds/fighter/_flash.c
//  surprise maneuver for dextrous fighters

#include <std.h>
inherit DAEMON;

int abs(int x) {if(x < 0) return 0-x;
   else return x;}

int cmd_flash() {
   string mystyle;
   object ob;
   int temp1, temp2, which, diff, bonus, level;
   object *weapon;
   mystyle = TP->query_fighter_style();
// also adding a bonus to the stun time for single classes *Styx*  11/20/04
// if(sizeof(TP->query_classes()) == 1)
//	bonus = random((int)TP->query_level() / 8)+1;

   if(TP->query_ghost()) {
      notify_fail("You are dead and cannot do that.\n");
      return 0;
   }
   if(TP->query_disable())     return 1;
  if (undefinedp(TP->get_static("flashed")) || (TP->get_static("flashed") < time()) )    {
     TP->set_static("flashed",time()+random(3)+3);
//   write(identify(TP->get_static("flashed")));
    } else { 
// adding to use stamina if they try again too soon *Styx* 9/29/03
       TP->use_stamina(10);
       if(!random(3))
	 tell_object(TP, "You notice the strain of the effort you're expending.");
       return 1;
    }
   if(ETP->query_property("no attack")) {
      notify_fail("You cannot do that here.\n");
      return 0;
   }

   if(TP->query_bound() || TP->query_tripped() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }

   if(!(ob = (object)TP->query_current_attacker())) {
      notify_fail("You are not in battle.\n");
      return 0;
   }
   if(!TP->is_class("fighter")) {
      write("You are not a fighter and cannot do that.");
      return 1;
   }
   temp1 = random(20);
   temp2 = random(20);
   if(temp1 < TP->query_stats("strength"))
      temp1 = temp1;
   else
      temp1 = 0;  
   if(temp2 < ob->query_stats("strength"))
      temp2 = temp2;
   else
      temp2 = 0;          
   diff = abs((random(TP->query_stats("strength"))) - (random(ob->query_stats("strength"))) );
   level = TP->query_class_level("fighter");
   weapon = TP->query_wielded();
   
   if(!sizeof(weapon))
       return notify_fail("You need a weapon to use flash.\n");
   
   if(ob->query_property("weapon resistance")) {
      if((weapon == ({})))
         diff = 0;
      else
         if(weapon[0]->query_property("enchantment") < ob->query_property("weapon resistance") )
         diff = 0;
   }

   if(temp1 > temp2) {
      if(level > 0) which = 0;
      if(level > 5) which = random(2);
      if(level > 15) which = random(3);
      if(level > 25) which = random(4);
      if(level > 35) which = random(5);
      TP->set_static("flashed",time()+random(6)+random(6));
      if(which == 0) {
         switch(mystyle){
            case "peasant":  tell_object(TP,"%^YELLOW%^You turn quickly "+
                                "and plant your elbow in "+ob->QCN+"'s "+
                                "ribs!");
                             tell_object(ob,"%^YELLOW%^"+TPQCN+" turns "+
                                "and elbows you quickly in the ribs!");
                             tell_room(ETP,"%^YELLOW%^"+TPQCN+" turns "+
                                "quickly and elbows "+ob->QCN+" in the "+
                                "ribs!",({TP,ob}));
                             break;
            case "swashbuckler":  tell_object(TP,"%^YELLOW%^With a "+
                                "flourish you whirl, raking your weapon "+
                                "across "+ob->QCN+"'s face!");
                             tell_object(ob,"%^YELLOW%^With a flourish, "+
                                ""+TPQCN+" whirls, raking your face with "+
                                ""+TP->QP+" weapon!");
                             tell_room(ETP,"%^YELLOW%^"+TPQCN+" whirls "+
                                "around with a flourish, raking "+
                                ""+TP->QP+" weapon across "+ob->QCN+"'s "+
                                "face!",({TP,ob}));
                             break;
            case "thug":  tell_object(TP,"%^YELLOW%^Seeing an opening, "+
                             "you rake "+ob->QCN+"'s eyes!");
                             tell_object(ob,"%^YELLOW%^"+TPQCN+" rakes "+
                                "your eyes, leaving you in pain!");
                             tell_room(ETP,"%^YELLOW%^"+TPQCN+" rakes "+
                                ""+ob->QCN+"'s eyes quickly!",({TP,ob}));
                             break;
            case "soldier":  tell_object(TP,"%^YELLOW%^With a "+
                                "well-practiced flick of your wrist, "+
                                "you slam your weapon into "+ob->QCN+"!");
                             tell_object(ob,"%^YELLOW%^With a smooth "+
                                "flick of "+TP->QP+" wrist, "+TPQCN+" "+
                                "slams "+TP->QP+" weapon into you!");
                             tell_room(ETP,"%^YELLOW%^With a smooth "+
                                "flick of "+TP->QP+" wrist, "+TPQCN+" "+
                                "slams "+TP->QP+" weapon into "+
                                ""+ob->QCN+"!",({TP,ob}));
                             break;
            case "dervish":  tell_object(TP,"%^YELLOW%^Gathering "+
                                "energy, you twirl suddenly, striking "+
                                ""+ob->QCN+" twice quickly!");
                             tell_object(ob,"%^YELLOW%^"+TPQCN+" "+
                                "twirls suddenly, striking you with "+
                                "blinding speed!");
                             tell_room(ETP,"%^YELLOW%^"+TPQCN+" "+
                                "twirls suddenly, striking "+
                                ""+ob->QCN+" with "+
                                "blinding speed!",({TP,ob}));
                             break;
            default:         tell_object(TP,"%^BOLD%^%^YELLOW%^You "+
                                "swiftly grab your opponent and toss "+
                                ""+ob->QO+" easily to the ground.%^RESET%^");
                             tell_object(ob,"%^BOLD%^%^YELLOW%^You are "+
                                "grabbed by "+TPQCN+" and thrown to the "+
                                "ground!%^RESET%^");
                             tell_room(ETP,"%^BOLD%^%^YELLOW%^"+TPQCN+" "+
                                "grabs "+ob->QCN+" and hurls "+ob->QO+" "+
                                "to the ground!%^RESET%^",({TP,ob}));
                             break;
         }
         if(level > 20){
            ob->cause_typed_damage(ob, ob->return_target_limb(), diff + random(16), weapon[0]->query_damage_type());
         }
         ob->cause_typed_damage(ob, ob->return_target_limb(), diff, weapon[0]->query_damage_type());
      }
      if(which == 1) {
         switch(mystyle){
            case "peasant":  tell_object(TP,"%^BOLD%^%^BLUE%^You dodge "+
                                "quickly from one side to the other, "+
                                "confusing "+ob->QCN+"!");
                             tell_object(ob,"%^BOLD%^%^BLUE%^"+TPQCN+" "+
                                "dodges quickly from side to side, "+
                                "confusing you!");
                             tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" "+
                                "dodges quickly from side to side, "+
                                "confusing "+ob->QCN+"!",({TP,ob}));
                             break;
            case "swashbuckler":  tell_object(TP,"%^BOLD%^%^BLUE%^"+
                                "You quickly flash a length of silk "+
                                "in front of "+ob->QCN+"'s face, "+
                                "confusing "+ob->QO+"!");
                             tell_object(ob,"%^BOLD%^%^BLUE%^From "+
                                "out of nowhere a length of silk "+
                                "flies into your face, leaving you "+
                                "confused!");
                             tell_room(ETP,"%^BOLD%^%^BLUE%^"+
                                ""+TPQCN+" quickly flash a length of silk "+
                                "in front of "+ob->QCN+"'s face, "+
                                "confusing "+ob->QO+"!",({TP,ob}));
                             break;
            case "thug":  tell_object(TP,"%^BOLD%^%^BLUE%^You toss "+
                                "debris into "+ob->QCN+"'s eyes, "+
                                "leaving "+ob->QO+" confused!");
                             tell_object(ob,"%^BOLD%^%^BLUE%^"+TPQCN+" "+
                                "tosses debris into your eyes, "+
                                "confusing you!");
                             tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" "+
                                "tosses "+
                                "debris into "+ob->QCN+"'s eyes, "+
                                "leaving "+ob->QO+" confused!  What a dirty "+
                                "trick!",({TP,ob}));
                             break;
            case "soldier":  tell_object(TP,"%^BOLD%^%^BLUE%^You feint "+
                                "to the right, then attack from the "+
                                "left, leaving "+ob->QCN+" confused!");
                             tell_object(ob,"%^BOLD%^%^BLUE%^"+TPQCN+" "+
                                "feints right, then you feel an attack "+
                                "from the right, leaving you confused!");
                             tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" "+
                                "feints to the right, then attacks "+
                                "from the left, leaving "+ob->QCN+" "+
                                "confused!",({TP,ob}));
                             break;
            case "dervish":  tell_object(TP,"%^BOLD%^%^BLUE%^You "+
                                "spin quickly, ending up behind "+
                                ""+ob->QCN+", leaving "+ob->QO+" "+
                                "confused!");
                             tell_object(ob,"%^BOLD%^%^BLUE%^"+
                                ""+TPQCN+" suddenly spins out of "+
                                "sight, leaving you confused!");
                             tell_room(ETP,"%^BOLD%^%^BLUE%^"+
                                ""+TPQCN+" suddenly spins behind "+
                                ""+ob->QCN+", leaving "+ob->QO+" "+
                                "looking confused!",({TP,ob}));
                             break;
            default:         tell_object(TP,"%^BOLD%^%^BLUE%^You dodge "+
                                "quickly to the side, and dash about "+
                                "your opponent, confusing "+ob->QO+".%^RESET%^");
                             tell_object(ob,"%^BOLD%^%^BLUE%^Your "+
                                "opponent dashes around you in a blaze, "+
                                "you are momentarily confused!%^RESET%^");
                             tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" "+
                                "dashes around "+ob->QCN+" in a blaze! "+
                                ""+ob->QCN+" looks confused!%^RESET%^",({TP,ob}));
                             break;
         }
//         ob->set_tripped(1,"You are momentarily confused!");
// changing to use paralyzed so the duration isn't so crazy *Styx*  11/20/04
         if(level > 20){
            ob->set_paralyzed(random(8)+4+bonus,"You are momentarily confused!");
         }
         ob->set_paralyzed(random(4)+4+bonus,"You are momentarily confused!");
      }
      if(which == 2) {
         switch(mystyle){
            case "peasant":  tell_object(TP,"%^BOLD%^%^GREEN%^You "+
                                "clap both of "+ob->QCN+"'s temples, "+
                                "stunning "+ob->QO+"!");
                             tell_object(ob,"%^BOLD%^%^GREEN%^"+TPQCN+" "+
                                "claps your temples, leaving your "+
                                "ears ringing!");
                             tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" "+
                                "claps "+ob->QCN+"'s temples, leaving "+
                                ""+ob->QO+" dazed!",({TP,ob}));
                             break;
            case "swashbuckler":  tell_object(TP,"%^BOLD%^%^GREEN%^"+
                                "You flip quickly through the air, "+
                                "striking "+ob->QCN+"'s chin as you "+
                                "pass!");
                             tell_object(ob,"%^BOLD%^%^GREEN%^"+
                                ""+TPQCN+" flips through the air, "+
                                "somehow smacking your chin with "+
                                ""+TP->QP+" weapon!");
                             tell_room(ETP,"%^BOLD%^%^GREEN%^"+
                                ""+TPQCN+" flips through the air, "+
                                "somehow smacking "+ob->QCN+"'s "+
                                "chin with "+
                                ""+TP->QP+" weapon!",({TP,ob}));
                             break;
            case "thug":  tell_object(TP,"%^BOLD%^%^GREEN%^With "+
                                "a vicious kick, you buckle "+
                                ""+ob->QCN+"'s kneecap!");
                             tell_object(ob,"%^BOLD%^%^GREEN%^"+
                                ""+TPQCN+" kicks you hard in the "+
                                "kneecap, sending you to the ground!");
                             tell_room(ETP,"%^BOLD%^%^GREEN%^"+
                                ""+TPQCN+" kicks "+ob->QCN+" hard "+
                                "in the kneecap, sending "+ob->QO+" "+
                                "to the ground!",({TP,ob}));
                             break;
            case "soldier":  tell_object(TP,"%^BOLD%^%^GREEN%^In a "+
                                "fluid, disciplined move, you slam "+
                                "the butt of your weapon into "+
                                ""+ob->QCN+"'s sternum!");
                             tell_object(ob,"%^BOLD%^%^GREEN%^"+
                                ""+TPQCN+" slams the butt of "+TP->QP+" "+
                                "weapon into your sternum!");
                             tell_room(ETP,"%^BOLD%^%^GREEN%^"+
                                ""+TPQCN+" slams the butt of "+TP->QP+" "+
                                "weapon into "+ob->QCN+"'s "+
                                "sternum!",({TP,ob}));
                             break;
            case "dervish":  tell_object(TP,"%^BOLD%^%^GREEN%^You "+
                                "circle "+ob->QCN+" and strike the "+
                                "base of "+ob->QP+" neck!");
                             tell_object(ob,"%^BOLD%^%^GREEN%^"+
                                ""+TPQCN+" circles, and you suddenly "+
                                "feel a hard blow against the base of "+
                                "you neck!");
                             tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" "+
                                "circles "+ob->QCN+" and strikes the "+
                                "base of "+ob->QP+" neck!",({TP,ob}));
                             break;
            default:         tell_object(TP,"%^BOLD%^%^GREEN%^You smack "+
                                "your opponent on the head, dazing "+
                                ""+ob->QO+".%^RESET%^");
                             tell_object(ob,"%^BOLD%^%^GREEN%^"+TPQCN+" "+
                                "strikes you stoutly, knocking you "+
                                "into a daze.%^RESET%^");
                             tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" "+
                                "strikes "+ob->QCN+" stoutly in the "+
                                "head!%^RESET%^",({TP,ob}));
                             break;
         }
//         ob->set_tripped(2,"You are stunned from the blow!");
// changing to use paralyzed so the duration isn't so crazy *Styx*  11/20/04
         ob->set_paralyzed(random(4)+6+bonus,"You are stunned from the blow!");
         if(level > 30){
            TP->cause_damage_to(ob,ob->return_target_limb(),diff+random(16));
         }
      }
      if(which == 3) {
         switch(mystyle){
            case "peasant":  tell_object(TP,"%^BOLD%^%^BLUE%^You "+
                                "plant your foot behind "+ob->QCN+"'s "+
                                "leg and push hard against "+ob->QP+" "+
                                "chest, sending "+ob->QO+" sprawling "+
                                "on the ground!");
                             tell_object(ob,"%^BOLD%^%^BLUE%^"+
                                ""+TPQCN+" shoves hard against your "+
                                "chest, and you feel yourself trip "+
                                "over something, landing sprawled "+
                                "on the ground!");
                             tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" "+
                                "plants "+TP->QP+" foot behind "+
                                ""+ob->QCN+"'s "+
                                "leg and pushes hard against "+ob->QP+" "+
                                "chest, sending "+ob->QO+" sprawling "+
                                "on the ground!",({TP,ob}));
                             break;
            case "swashbuckler":  tell_object(TP,"%^BOLD%^%^BLUE%^You "+
                                "flip high in the air, planting your "+
                                "feet on "+ob->QCN+"'s shoulders and "+
                                "knocking "+ob->QO+" to the ground "+
                                "before flipping lightly to the ground "+
                                "again!");
                             tell_object(ob,"%^BOLD%^%^BLUE%^"+TPQCN+" "+
                                "suddenly flips in the air, landing "+
                                "on your shoulders and sending you "+
                                "to the ground hard!");
                             tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" "+
                                "flips high in the air, planting "+
                                ""+TP->QP+" "+
                                "feet on "+ob->QCN+"'s shoulders and "+
                                "knocking "+ob->QO+" to the ground "+
                                "before flipping lightly to the ground "+
                                "again!",({TP,ob}));
                             break;
            case "thug":  tell_object(TP,"%^BOLD%^%^BLUE%^You elbow "+
                                ""+ob->QCN+" in the stomach, then "+
                                "bring your knee crashing into "+
                                ""+ob->QP+" nose when "+ob->QS+" "+
                                "doubles over!");
                             tell_object(ob,"%^BOLD%^%^BLUE%^"+
                                ""+TPQCN+" elbows you hard in "+
                                "stomach, sending you doubling over!  "+
                                "Before you can react, "+TP->QS+" "+
                                "smashes your nose with "+TP->QP+" "+
                                "knee!");
                             tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" "+
                                "elbows "+
                                ""+ob->QCN+" in the stomach, then "+
                                "brings "+TP->QP+" knee crashing into "+
                                ""+ob->QP+" nose when "+ob->QS+" "+
                                "doubles over!",({TP,ob}));
                             break;
            case "soldier":  tell_object(TP,"%^BOLD%^%^BLUE%^You "+
                                "lunge forward, sweeping "+ob->QCN+"'s "+
                                "foot with your weapon!");
                             tell_object(ob,"%^BOLD%^%^BLUE%^You "+
                                "feel something sweep your foot, then "+
                                "find yourself flat on your back, "+
                                "looking up at "+TPQCN+"!");
                             tell_room(ETP,"%^BOLD%^%^BLUE%^With a "+
                                "fluid, practiced motion, "+TPQCN+" "+
                                "lunges forward and sweeps "+ob->QCN+""+
                                "'s feet out from under "+
                                ""+ob->QO+"!",({TP,ob}));
                             break;
            case "dervish":  tell_object(TP,"%^BOLD%^%^BLUE%^You "+
                                "leap into the air, spinning and "+
                                "kicking "+ob->QCN+"'s head with "+
                                "the back of your heel, sending "+
                                ""+ob->QO+" to the ground!");
                             tell_object(ob,"%^BOLD%^%^BLUE%^"+TPQCN+" "+
                                "leaps into the air, spinning and "+
                                "kicking your head with "+
                                "the back of "+TP->QP+" heel, sending "+
                                ""+ob->QO+" to the ground in pain!");
                             tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" "+
                                "leaps into the air, spinning and "+
                                "kicking "+ob->QCN+"'s head with "+
                                "the back of "+TP->QP+" heel, sending "+
                                ""+ob->QO+" to the ground!",({TP,ob}));
                             break;
            default:         tell_object(TP,"%^BOLD%^%^BLUE%^You "+
                                "launch yourself at your opponent "+
                                "and tackle "+ob->QO+" to the "+
                                "ground!%^RESET%^");
                             tell_object(ob,"%^BOLD%^%^BLUE%^"+
                                ""+TPQCN+" tackles you to the ground, "+
                                "knocking the wind out of you!%^RESET%^");
                             tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" "+
                                "tackles "+ob->QCN+" to the ground, "+
                                "knocking the wind out of "+
                                ""+ob->QO+"!%^RESET%^",({TP,ob}));
                             break;
         }
         ob->set_tripped(1,"You are trying to catch your breath and stand!");
         TP->cause_damage_to(ob,ob->return_target_limb(),diff+random(16));
      }
      if(which == 4) {
         switch(mystyle){
            case "peasant":  tell_object(TP,"%^YELLOW%^You place a "+
                                "swift punch beneath "+ob->QCN+"'s "+
                                "chin as you strike "+ob->QO+" with "+
                                "your weapon as well!");
                             tell_object(ob,"%^YELLOW%^You feel a "+
                                "quick punch beneath your chin as "+
                                ""+TPQCN+"'s weapon strikes you as well!");
                             tell_room(ETP,"%^YELLOW%^"+TPQCN+" "+
                                "punches "+ob->QCN+"'s "+
                                "chin swiftly as "+TP->QS+" strikes "+
                                ""+ob->QO+" with "+
                                ""+TP->QP+" weapon as well!",({TP,ob}));
                             break;
            case "swashbuckler":  tell_object(TP,"%^YELLOW%^You duck "+
                                "and roll along the ground, bringing "+
                                "your weapon up between "+ob->QCN+"'s "+
                                "legs!");
                             tell_object(ob,"%^YELLOW%^"+TPQCN+" "+
                                "suddenly ducks and rolls along the "+
                                "ground as you feel a sharp pain "+
                                "between your knees!");
                             tell_room(ETP,"%^YELLOW%^"+TPQCN+" ducks "+
                                "and rolls along the ground, bringing "+
                                ""+TP->QP+" weapon up between "+
                                ""+ob->QCN+"'s "+
                                "legs!  OUCH!",({TP,ob}));
                             break;
            case "thug":  tell_object(TP,"%^YELLOW%^With a smirk, "+
                                "you headbutt "+ob->QCN+" furiously!");
                             tell_object(ob,"%^YELLOW%^With a smirk, "+
                                ""+TPQCN+" headbutts you furiously!");
                             tell_room(ETP,"%^YELLOW%^With a smirk, "+
                                ""+TPQCN+" headbutts "+ob->QCN+" "+
                                "furiously!",({TP,ob}));
                             break;
            case "soldier":  tell_object(TP,"%^YELLOW%^With a quick "+
                                "sprint, you dash weapon first into "+
                                ""+ob->QCN+"!");
                             tell_object(ob,"%^YELLOW%^With a quick "+
                                "sprint, "+TPQCN+" dashes weapon "+
                                "first into you!");
                             tell_room(ETP,"%^YELLOW%^With a quick "+
                                "sprint, "+TPQCN+" dashes weapon "+
                                "first into "+ob->QCN+"!",({TP,ob}));
                             break;
            case "dervish":  tell_object(TP,"%^YELLOW%^You strike "+
                                ""+ob->QCN+", then whirl suddenly, "+
                                "striking "+ob->QO+" again!");
                             tell_object(ob,"%^YELLOW%^"+TPQCN+" strikes "+
                                "you, then whirls suddenly, "+
                                "striking you again!");
                             tell_room(ETP,"%^YELLOW%^"+TPQCN+" strikes "+
                                ""+ob->QCN+", then whirls suddenly, "+
                                "striking "+ob->QO+" again!",({TP,ob}));
                             break;
            default:         tell_object(TP,"%^BOLD%^%^YELLOW%^You "+
                                "jump into the air, twist your body "+
                                "into a flip, and land feet first "+
                                "into your opponent's chest!%^RESET%^");
                             tell_object(ob,"%^BOLD%^%^YELLOW%^"+TPQCN+" "+
                                "leaps into the air and lands a flying "+
                                "kick deep into your chest.%^RESET%^");
                             tell_room(ETP,"%^BOLD%^%^YELLOW%^"+TPQCN+" "+
                                "leaps into the air and lands a flying "+
                                "kick deep into "+ob->QCN+"'s chest."+
                                "%^RESET%^",({TP,ob}));
                             break;
         }
         TP->cause_damage_to(ob,ob->return_target_limb(),diff+random(24));
         ob->set_paralyzed(random(6)+6+bonus,"You are stunned from the blow!");
      }
     TP->set_disable(3,ob);  // was 5, changing to use stamina if try too soon above *Styx*
   }
   return 1;
}

void help() {
   write(
@HELP
Syntax: <flash>

Allows you to surprise your enemy with various moves.
Based on your background, you may select a certain 
style at creation.  See <help styles>.
HELP
   );
}
