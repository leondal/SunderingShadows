#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/quarter_staff";

#define MAXUSES 100
int uses;
int iced = 0;
void remove_shield();
int OWNED;
string owner;

void create() {
   ::create();
   set_id(({"staff","grand staff","wood staff","wooden staff","shaman staff","staff of the shaman"}));
   set_name("grand staff");
   set_short("%^RED%^Staff of the %^GREEN%^Shaman%^RESET%^");
   set_obvious_short("%^ORANGE%^A grand wooden staff%^RESET%^");
   set_long(
      "%^ORANGE%^This beautiful staff is made of four slender, "+
      "smooth limbs of a pine tree twisted together.  Each "+
      "supple limb has been dyed a different color - from "+
      "%^BLUE%^deep blue %^ORANGE%^and %^GREEN%^vibrant "+
      "green %^ORANGE%^to %^BOLD%^%^RED%^fiery red "+
      "%^RESET%^%^ORANGE%^and %^YELLOW%^brilliant "+
      "yellow%^RESET%^%^ORANGE%^.  At the top of the staff, "+
      "the four woods blend together perfectly into a "+
      "simple knot.  The end of the staff has been tipped "+
      "with mithril, making this a stout walking staff as well.  "+
      "Flowing script runs along each length of wood."
   );
   set_read(
@CIRCE

     %^BOLD%^%^RED%^Summer%^RESET%^%^RED%^'s flame brings death to bear
   %^ORANGE%^The strength of %^YELLOW%^fall %^RESET%^%^ORANGE%^crackles in the air
        %^BOLD%^%^CYAN%^Winter%^RESET%^%^CYAN%^'s ice can chill a heart
      %^GREEN%^And %^BOLD%^spring%^RESET%^%^GREEN%^'s quakes tear men apart
CIRCE
   );
   set_lore("The Staff of the Shaman is a highly-sought-after "+
      "item, especially by the clerics of the realm who understand "+
      "its divine power.  Only in their hands can this staff "+
      "be wielded.  Many lesser staves were made as well, "+
      "all of which possess a small measure of this one's strength "+
      "but there is none that can equal this most impressive staff.  "+
      "It is said that the first staff of this kind was made "+
      "by the grand firbolg Shaman Helgatha Rothmar, who "+
      "was known to have mystical powers over the weather.");
   set_value(8600);
   set_property("enchantment",4);
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"unwieldme":));
}

void init()
{
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
        }
        add_action("flame","summer");
        add_action("lightning","fall");
        add_action("ice","winter");
        add_action("quake","spring");
}

int wieldme(){
   if((string)ETO->query_name() == "firbolg shaman"){
      return 1;
   }
   if(ETO->is_class("cleric") || ETO->is_class("druid")){
       if (!ETO->query_property("silent_wield")) {
           tell_object(ETO, "%^GREEN%^You feel a slight vibration as you " +
               "wield the staff, and you know you can channel the power within.");
           tell_room(EETO, "%^GREEN%^You hear a low hum as " + ETOQCN + " " +
               "takes up the staff.", ETO);
       }
       return 1;
   }
   tell_object(ETO,"You have no idea how to use a staff such as this!");
   return 0;
}

int unwieldme(){
    if (!ETO->query_property("silent_wield")) {
        if (iced != 0) {
            remove_shield();
            remove_call_out("remove_shield");
        }
        tell_object(ETO, "You set aside the power of the staff for now.");
    }
    return 1;
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
         targ->do_damage("torso",roll_dice(12,12));
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
         targ->do_damage("torso",roll_dice(6,12));
         targ->set_paralyzed(3,"You are still shaken from the lightning.");
         targ->add_attacker(ETO);
         targ->continue_attack();
         ETO->set_paralyzed(7,"You are busy controlling the staff.");
         return 1;
      }
      tell_object(targ,"%^ORANGE%^"+ETOQCN+" You withstand the "+
         "electricity of "+ETOQCN+"'s touch.");
      tell_object(ETO,"%^ORANGE%^"+targ->QCN+" withstands the "+
         "electricity of your touch!");
      tell_room(EETO,"%^ORANGE%^"+targ->QCN+" manages to withstand "+
         ""+ETOQCN+"'s electric touch!",({targ,ETO}));
      ETO->set_paralyzed(4,"You are busy controlling the staff.");
      targ->add_attacker(ETO);
      return 1;
      tell_object(ETO,"The magic of the staff has been depleted.");
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
      if(iced == 0){
         tell_object(ETO,"%^CYAN%^Ice crystals begin to form on the "+
            "staff as you chant softly!");
         tell_room(EETO,"%^CYAN%^Ice crystals begin to form on "+
            ""+ETOQCN+"'s staff as "+ETO->QS+" chants!",ETO);
         tell_object(ETO,"%^BOLD%^%^CYAN%^A floating shield made "+
            "entirely of %^WHITE%^ice %^CYAN%^appears before you!");
         tell_room(EETO,"%^BOLD%^%^CYAN%^A floating shield made "+
            "entirely of %^WHITE%^ice %^CYAN%^appears before "+ETOQCN+"!",ETO);
         ETO->add_ac_bonus(4);
         call_out("remove_shield",200+random(50));
         iced = 1;
    ETO->set_paralyzed(4,"You are busy controlling the staff.");
         return 1;
      }else{
         tell_object(ETO,"You already have a shield of ice!");
         return 1;
      }
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
            vars[i]->set_paralyzed(20,"You are stunned from the earthquake.");
        } else {
        tell_object(vars[i],"You manage to keep your feet despite the earthquake!");
        }
    }
    ETO->set_paralyzed(4,"You are busy controlling the staff.");
    return 1;
}

void remove_shield()
{
        tell_room(EETO,"%^CYAN%^The ice shield melts away.");
        ETO->add_ac_bonus(-4);
        iced = 0;
        return 1;
}
