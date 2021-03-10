#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/mstaff";

#define MAXUSES 50
int uses;

void create() {
   ::create();
   set_id(({"staff","lesser staff","wood staff","wooden staff","fury staff","staff of fall's fury","fall's fury","yellow staff"}));
   set_name("lightning staff");
   set_short("%^RESET%^%^ORANGE%^Staff of %^BOLD%^Fall's Fury%^RESET%^");
   set_obvious_short("%^YELLOW%^A yellow wooden staff%^RESET%^");
   set_long(
      "%^YELLOW%^This simple twisting staff has "+
      "been formed from supple pine wood dyed a brilliant "+
      "yellow.  The staff is very short and fairly nondescript, "+
      "save for its color and the flowing script running "+
      "along its coils."
   );
   set_read(
@CIRCE

   %^RESET%^%^ORANGE%^The fury of %^BOLD%^fall %^RESET%^%^ORANGE%^crackles in the air
   %^RESET%^%^ORANGE%^  With it, nothing else can compare
CIRCE
   );
   set_lore("The Staff of Fall's Fury is one of many "+
      "minor staves made by the Shaman Helgatha Rothmar, who "+
      "was known to have mystical powers over the weather.  "+
      "Legend holds that the shaman also created a greater "+
      "version, which held the power of all four seasons within "+
      "its slender wooden form.");
   set_value(800);
   set_property("enchantment",2);
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"unwieldme":));
}

int wieldme(){
   if((string)ETO->query_name() == "firbolg ghost") return 1;
   if((int)ETO->query_lowest_level() < 15){
      tell_object(ETO,"%^YELLOW%^Lightning arcs along the "+
         "staff - you cannot control its power!");
      tell_room(EETO,"%^RED%^"+ETOQCN+"'s hair stands on end as "+
         "lightning crackles along the staff!",ETO);
      return 0;
   }
   if (!ETO->query_property("silent_wield")) {
       tell_object(ETO, "%^YELLOW%^You feel the energy inside the staff as " +
           "you wield it!");
   }
   return 1;
}

int unwieldme() {
    if (!ETO->query_property("silent_wield")) {
        tell_object(ETO, "You set aside the power of the staff for now.");
    }
    return 1;
}

void init(){
   ::init();
   add_action("lightning","fall");
}

int lightning(string str){
object targ;
   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!query_wielded()){
      tell_object(ETO,"You must wield the staff first!");
      return 1;
   }
   if(!str){
      tell_object(ETO,"Who do you want to use fall's wrath against? "+
         "You must designate a target!");
      return 1;
   }
   if(!(targ = present(str, EETO))){
      tell_object(ETO,"You do not see that!");
      return 1;
   }
   if(uses < MAXUSES){
      tell_object(ETO,"%^RESET%^%^ORANGE%^As you chant, energy begins "+
         "to flow from the staff into your fingertips!");
      tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETOQCN+" begins to chant, "+
         "gathering crackling energy to "+ETO->QP+" fingertips!",ETO);
      if((int)targ->query_stats("constitution") < random(26)){
         tell_object(targ,"%^YELLOW%^Lightning %^CYAN%^arcs "+
            "%^YELLOW%^and %^WHITE%^thunder %^BLACK%^rolls "+
            "%^YELLOW%^as "+ETOQCN+" touches you!");
         tell_object(ETO,"%^YELLOW%^Lightning %^CYAN%^arcs "+
            "%^YELLOW%^and %^WHITE%^thunder %^BLACK%^rolls "+
            "%^YELLOW%^as you touch "+targ->QCN+"!");
         tell_room(EETO,"%^YELLOW%^Lightning %^CYAN%^arcs "+
            "%^YELLOW%^and %^WHITE%^thunder %^BLACK%^rolls "+
            "%^YELLOW%^as "+ETOQCN+" touches "+targ->QCN+"!",({ETO,targ}));
         targ->do_damage("torso",roll_dice(4,12));
         targ->set_paralyzed(3,"You are still shaken from the lightning.");
         targ->add_attacker(ETO);
         targ->continue_attack();
         ETO->set_paralyzed(4,"You are busy controlling the staff.");
         return 1;
      }
      tell_object(targ,"%^ORANGE%^You withstand the "+
         "electricity of "+ETOQCN+"'s touch.");
      tell_object(ETO,"%^ORANGE%^"+targ->QCN+" withstands the "+
         "electricity of your touch!");
      tell_room(EETO,"%^ORANGE%^"+targ->QCN+" manages to withstand "+
         ""+ETOQCN+"'s electric touch!",({targ,ETO}));
      ETO->set_paralyzed(4,"You are busy controlling the staff.");
      targ->add_attacker(ETO);
      return 1;
   }else{
      tell_object(ETO,"The magic of the staff has been depleted.");
      return 1;
   }
}
