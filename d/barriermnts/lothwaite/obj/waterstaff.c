#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/mstaff";

#define MAXUSES 50
int uses;
int iced = 0;
int remove_shield;

void create() {
   ::create();
   set_id(({"staff","lesser staff","wood staff","wooden staff","ice staff","staff of winter's chill","winter's flame","blue staff"}));
   set_name("ice staff");
   set_short("%^RESET%^%^CYAN%^Staff of %^BOLD%^Winter's Chill%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^A blue wooden staff%^RESET%^");
   set_long(
      "%^RESET%^%^CYAN%^This simple twisting staff has "+
      "been formed from supple pine wood dyed a %^BOLD%^"+
      "%^BLUE%^chilling blue%^RESET%^%^CYAN%^.  The staff "+
      "is very short and fairly nondescript, "+
      "save for its color and the flowing script running "+
      "along its coils."
   );
   set_read(
@CIRCE

   %^RESET%^%^CYAN%^The water in %^BOLD%^winter %^RESET%^%^CYAN%^freezes the bone
    %^RESET%^%^CYAN%^And pulls forth ice from the stone
CIRCE
   );
   set_lore("The Staff of Winter's Chill is one of many "+
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
      tell_object(ETO,"%^CYAN%^The icy staff refuses the hand of "+
         "one as inexperienced as yourself!");
      tell_room(EETO,"%^CYAN%^"+ETOQCN+" jerks back "+ETO->QP+" hand "+
         "from the staff as if suddenly frozen.",ETO);
      return 0;
   }
   if (!ETO->query_property("silent_wield")) {
       tell_object(ETO, "%^CYAN%^You feel the ice inside the staff as " +
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
   add_action("ice","winter");
}

int ice(string str){
   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!query_wielded()){
      tell_object(ETO,"You must wield the staff first!");
      return 1;
   }
   if(str){
      tell_object(ETO,"You may only use that on yourself!");
      return 1;
   }
   if(uses < MAXUSES){
      if(iced == 0){
         tell_object(ETO,"%^CYAN%^Ice crystals begin to form on the "+
            "staff as you chant softly!");
         tell_room(EETO,"%^CYAN%^Ice crystals begin to form on "+
            ""+ETOQCN+"'s staff as "+ETO->QS+" chants!",ETO);
         tell_object(ETO,"%^BOLD%^%^CYAN%^A floating shield made "+
            "entirely of %^WHITE%^ice %^CYAN%^appears before you!");
         tell_room(EETO,"%^BOLD%^%^CYAN%^A floating shield made "+
            "entirely of %^WHITE%^ice %^CYAN%^appears before "+ETOQCN+"!",ETO);
         ETO->add_ac_bonus(2);
         call_out("remove_shield",200+random(50));
         iced = 1;
         ETO->set_paralyzed(4,"You are busy controlling the staff.");
         return 1;
      }else{
         tell_object(ETO,"You already have a shield of ice!");
         return 1;
      }
   }else{
      tell_object(ETO,"The magic of the staff has been depleted.");
      return 1;
   }
}

int remove_shield()
{
        tell_room(EETO,"%^CYAN%^The ice shield melts away.");
        ETO->add_ac_bonus(-2);
        iced = 0;
        return 1;
}
