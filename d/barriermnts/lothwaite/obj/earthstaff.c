#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/mstaff";

#define MAXUSES 50
int uses;
int iced = 0;
int remove_shield;

void create() {
   ::create();
   set_id(({"staff","lesser staff","wood staff","wooden staff","spring staff","staff of spring's might","spring's might","green staff"}));
   set_name("earth staff");
   set_short("%^GREEN%^Staff of %^BOLD%^Spring's Might%^RESET%^");
   set_obvious_short("%^RESET%^%^GREEN%^A green wooden staff%^RESET%^");
   set_long(
      "%^RESET%^%^GREEN%^This simple twisting staff has "+
      "been formed from supple pine wood dyed a vibrant "+
      "green.  The staff is very short and fairly nondescript, "+
      "save for its color and the flowing script running "+
      "along its coils."
   );
   set_read(
@CIRCE

   %^RESET%^%^GREEN%^The might of %^BOLD%^spring %^RESET%^%^GREEN%^shakes the earth to the core
     %^RESET%^%^GREEN%^With a fury even the strongest cannot ignore
CIRCE
   );
   set_lore("The Staff of Spring's Might is one of many "+
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
      tell_object(ETO,"%^GREEN%^The vibrations of the staff "+
         "are too great for you to control!");
      tell_room(EETO,"%^RED%^"+ETOQCN+"'s teeth chatter as "+
         ""+ETO->QS+" tries to wield the staff.",ETO);
      return 0;
   }
   if (!ETO->query_property("silent_wield")) {
       tell_object(ETO, "%^GREEN%^You feel the staff shaking as " +
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
   add_action("quake","spring");
}

int quake(string str){
    object *vars;
    int i;
   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!query_wielded()){
      tell_object(ETO,"You must wield the staff first!");
      return 1;
   }
   if(str){
      tell_object(ETO,"The ground will quake for everyone equally!  "+
         "You cannot presume to pick a target for the earth.");
      return 1;
   }
   if(uses < MAXUSES){
      tell_object(ETO,"%^GREEN%^You slam the tip of the staff "+
         "against the earth and begin to chant loudly!");
      tell_room(EETO,"%^GREEN%^"+ETOQCN+" slams the tip of the staff "+
         "against the earth and begins chanting loudly!",ETO);
    vars = all_living(EETO);
    for(i=0;i<sizeof(vars);i++){
        if(vars[i] == ETO) continue;
        if(!"/daemon/saving_d"->saving_throw(vars[i],"paralyzation_poison_death")){
            tell_object(vars[i],"%^BOLD%^%^GREEN%^You are shaken to the core!");
            tell_object(ETO,"%^BOLD%^%^GREEN%^A violent earthquake fills the "+
               "area, shaking those around you!");
            vars[i]->set_paralyzed(15,"You are stunned from the earthquake.");
        } else {
        tell_object(vars[i],"You manage to keep your feet despite the earthquake!");
        }
    }
    ETO->set_paralyzed(4,"You are busy controlling the staff.");
    return 1;
   }else{
      tell_object(ETO,"The magic of the staff has been depleted.");
      return 1;
   }
}
