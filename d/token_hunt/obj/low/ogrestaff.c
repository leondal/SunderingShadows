#include <std.h>
inherit "/d/common/obj/weapon/giant_club.c";

void create() {
    ::create();
    set_name("huge staff");
    set_id(({"staff","huge staff","black staff","painted staff","painted black staff","cudgel","cudgel of war","war cudgel","mighty cudgel","ogre's cudgel","ogre's mighty cudgel"}));
    set_short("%^BLACK%^%^BOLD%^Ogre's Mighty Cudgel of %^RESET%^%^RED%^War%^RESET%^");
    set_obvious_short("%^BLACK%^%^BOLD%^huge %^WHITE%^p%^RESET%^%^RED%^ai%^WHITE%^%^BOLD%^n%^RESET%^%^RED%^te%^WHITE%^%^BOLD%^d%^BLACK%^ black staff%^RESET%^");
    set_long("%^BLACK%^%^BOLD%^This weapon could almost pass for a staff, though it seems like it would be "
"more effective as a short street post.  It would easily be half a foot in diameter, and more than eight feet "
"long, and would be almost impossible for a normal person to even think of using.  Rock-hard black wood forms "
"the staff, though it follows a slightly crooked alignment, as though the maker had trouble shaping the wood.  "
"Or just didn't bother.  Roughly applied splatters of %^RESET%^%^RED%^red%^BLACK%^%^BOLD%^ and%^WHITE%^ "
"white%^BLACK%^ paint leave markings along the length, like some crude form of warpaint.%^RESET%^");
   set_value(0);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
   set_prof_type("staff"); // to force it to work in sleeves like a staff should!
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wield_fun(){
    tell_object(ETO,"%^BLACK%^%^BOLD%^You grasp the massive staff in both hands.%^RESET%^");
    tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" grasps the massive staff in both hands and gives it an "
"experimental swing.%^RESET%^",ETO);
    return 1;
}

int unwield_fun() {
   tell_object(ETO,"%^BLACK%^%^BOLD%^You release your hold on the massive staff.%^RESET%^");
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" releases "+ETO->QP+" hold on the massive staff.%^RESET%^",ETO);
   return 1;
}

int hit_fun(object targ) {
   string *str,dir,dir2,door;
   int para,para2,trip;
   targ = ETO->query_current_attacker();
   if(random(200)<40){
     switch(random(20)){
       case 0..4:
       ETO->execute_attack();
       tell_object(ETO,"%^BLACK%^%^BOLD%^You swing the massive staff forward with the force of both hands "
"behind it, lifting "+targ->QCN+" into the air from the impact!%^RESET%^");
       tell_object(targ,"%^BLACK%^%^BOLD%^"+ETOQCN+" swings the massive staff forward with the force of both "
"hands, lifting you into the air from the painful impact!%^RESET%^");
       tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" swings the massive staff forward with the force of both "
"hands, lifting "+targ->QCN+" into the air from the impact!%^RESET%^",({ETO,targ}));

       str = (string *)EETO->query_exits();
       if (!str || !sizeof(str) || targ->query_size() > 3) {
         tell_room(EETO,"%^RED%^"+targ->QCN+" lands several feet away on the ground with an audible thud! "
"Ouch!%^RESET%^",targ);
         tell_object(targ,"%^RED%^You land on the ground several feet away, knocking the breath from your "
"body!%^RESET%^",targ);
         targ->set_paralyzed(random(6)+10,"You are still trying to gasp air back into your lungs!\n");
         return 0;
       }
       else {
         dir = str[random(sizeof(str))];
         if(door = (string)EETO->query_door(dir)) {
           if(!EETO->query_open(door)) {
             tell_room(EETO,"%^RED%^"+targ->QCN+" flies directly into the closed "+door+" with an audible "
"thud, before landing on the ground! Ouch!%^RESET%^",targ);
             tell_object(targ,"%^RED%^You hit the closed "+door+" and then the ground, knocking the breath "
"from your body!%^RESET%^",targ);
             targ->set_paralyzed(random(6)+10,"You are still trying to gasp air back into your lungs!\n");
             return 0;
           }
         }
         dir2 = (string)EETO->query_exit(dir);
         tell_room(EETO,"%^RED%^"+targ->QCN+" goes flying through the air to the "+dir+"!%^RESET%^",targ);
         targ->move(dir2);
         tell_room(environment(targ),"%^RED%^"+targ->QCN+" comes flying in through the air, landing on the "
"ground with an audible thud!%^RESET%^",targ);
       }
       tell_object(targ,"%^RED%^You land on the ground several feet away, knocking the breath from your body!"
"%^RESET%^",targ);
       targ->set_paralyzed(random(6)+10,"You are still trying to gasp air back into your lungs!\n");
       return 0;
       break;

     case 5..19:
       tell_object(ETO,"%^BLUE%^You grasp both hands around one end of the staff, bringing it overhead and "
"down in a bone-shattering blow at "+targ->QCN+"!%^RESET%^");
       tell_object(targ,"%^BLUE%^"+ETOQCN+" grasps both hands around one end of the staff, bringing it "
"overhead and directly down in a bone-shattering blow at you!%^RESET%^");
       tell_room(EETO,"%^BLUE%^"+ETOQCN+" grasps both hands around one end of the staff, bringing it "
"overhead and directly down in a bone-shattering blow at "+targ->QCN+"!%^RESET%^",({ETO,targ}));
       return 2;
       break;
     }
   }
   return 0;
}