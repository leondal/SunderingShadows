#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/mstaff";

#define MAXUSES 50
int uses;

void create() {
   ::create();
   set_id(({"staff","lesser staff","wood staff","wooden staff","flame staff","staff of summer's flame","summer's flame","red staff"}));
   set_name("fire staff");
   set_short("%^RED%^Staff of %^BOLD%^Summer's Flame%^RESET%^");
   set_obvious_short("%^RESET%^%^RED%^A red wooden staff%^RESET%^");
   set_long(
      "%^RESET%^%^RED%^This simple twisting staff has "+
      "been formed from supple pine wood dyed a fiery "+
      "red.  The staff is very short and fairly nondescript, "+
      "save for its color and the flowing script running "+
      "along its coils."
   );
   set_read(
@CIRCE

   %^RESET%^%^RED%^The heat of %^BOLD%^summer %^RESET%^%^RED%^can sizzle a stone
    %^RESET%^%^RED%^And make a magmin feel right at home
CIRCE
   );
   set_lore("The Staff of Summer's Flame is one of many "+
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
      tell_object(ETO,"%^RED%^The staff sears your flesh as you "+
         "try to wield a power too great for your hands!");
      tell_room(EETO,"%^RED%^"+ETOQCN+" pulls "+ETO->QP+" hands "+
         "away from the staff, leaving charred flesh behind.",ETO);
      return 0;
   }
   if (!ETO->query_property("silent_wield")) {
       tell_object(ETO, "%^RED%^You feel the heat inside the staff as " +
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
   add_action("flame","summer");
}

int flame(string str){
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
      tell_object(ETO,"Who do you want to use summer's fury against? "+
         "You must designate a target!");
      return 1;
   }
   if(!(targ = present(str, EETO))){
      tell_object(ETO,"You do not see that!");
      return 1;
   }
   if(uses < MAXUSES){
      tell_object(ETO,"%^RED%^You focus your energies on the staff "+
         "and begin to chant for flames!");
      tell_room(EETO,"%^RED%^"+ETOQCN+" holds the staff in hand and "+
         "begins to chant.",ETO);
      if((int)targ->query_stats("dexterity") < random(26)){
         tell_object(targ,"%^BOLD%^%^RED%^A slender pillar of scorching "+
            "%^YELLOW%^fl%^RED%^a%^YELLOW%^me %^RED%^streaks down, "+
            "unleashing summer's fury on your flesh!");
         tell_object(ETO,"%^BOLD%^%^RED%^A slender pillar of scorching "+
            "%^YELLOW%^fl%^RED%^a%^YELLOW%^me %^RED%^streaks down, "+
            "unleashing summer's fury on "+targ->QCN+"!");
         tell_room(EETO,"%^BOLD%^%^RED%^A slender pillar of scorching "+
            "%^YELLOW%^fl%^RED%^a%^YELLOW%^me %^RED%^streaks down, "+
            "burning "+targ->QCN+"!",({ETO,targ}));
         targ->do_damage("torso",roll_dice(8,12));
         targ->add_attacker(ETO);
         targ->continue_attack();
         ETO->set_paralyzed(7,"You are busy controlling the staff.");
         return 1;
      }
      tell_object(targ,"%^RED%^You jump aside just as a pillar of "+
         "flame streaks toward you!");
      tell_object(ETO,"%^RED%^"+targ->QCN+" jumps aside just as the "+
         "pillar of flame streaks down towards "+targ->QO+"!");
      tell_room(EETO,"%^RED%^"+targ->QCN+" jumps aside just as a "+
         "pillar of flame streaks down towards "+targ->QO+"!",({targ,ETO}));
      ETO->set_paralyzed(4,"You are busy controlling the staff.");
      targ->add_attacker(ETO);
      return 1;
   }else{
      tell_object(ETO,"The magic of the staff has been depleted.");
      return 1;
   }
}
