//Elephant mount for new Seneca
//~Circe~ 12/3/07
#include <std.h>
inherit "/std/riding_animal.c";

void create(){
   object ob;
   ::create();
   set_name("elephant");
   set_short("%^BOLD%^%^BLACK%^m%^RESET%^o%^BOLD%^%^BLACK%^t"+
      "%^RESET%^t%^BOLD%^%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^d "+
      "gray riding elephant%^RESET%^");
   set_id(({"elephant","riding elephant","gray elephant","mottled gray elephant","mount"}));
   set_long("%^BOLD%^%^BLACK%^Covered with wrinkled m"+
      "%^RESET%^o%^BOLD%^%^BLACK%^t%^RESET%^t%^BOLD%^"+
      "%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^"+
      "gray hide%^BOLD%^%^BLACK%^, this elephant is massive.  "+
      "It has large, thin ears that it flaps often, creating "+
      "a %^CYAN%^breeze%^BLACK%^ to cool the creature.  "+
      "Twin %^WHITE%^ivory tusks %^BLACK%^protrude from either "+
      "side of the prehensile %^RESET%^trunk%^BOLD%^%^BLACK%^.  "+
      "Large %^RESET%^%^ORANGE%^brown eyes %^BOLD%^%^BLACK%^"+
      "with thick lashes survey the scene before the animal, "+
      "belying an intelligence hidden within the massive frame.  "+
      "A %^RESET%^%^ORANGE%^saddle %^BOLD%^%^BLACK%^has been "+
      "placed just below the elephant's head, offering a rider "+
      "a comfortable perch.%^RESET%^");
   set_level(10);
   set_value(1500);
   set_race("elephant");
   set_gender(random(2)?"male":"female");
   set_body_type("quadruped");
   set_attack_limbs(({"left foreleg","right foreleg"}));
   set_size(3);
   set_hd(10,6);
   set_max_hp(200);
   set_hp(200);
   set_overall_ac(-6);
   set_exp(1);
   set_max_distance(500);
   set_enter_room("stomps in on a massive elephant");
   set_exit_room("stomps out on a massive elephant");
   set_riding_level(20);
   set_vehicle_short("%^BOLD%^%^BLACK%^m%^RESET%^o%^BOLD%^%^BLACK%^t"+
      "%^RESET%^t%^BOLD%^%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^d "+
      "gray riding elephant%^RESET%^");
   set_attacks_num(2);
   set_damage(2,4);
   set_base_damage_type("bludgeoning");
   set_emotes(1,({"%^BOLD%^%^BLACK%^The elephant flicks its ears, "+
      "stirring a light %^CYAN%^breeze%^BLACK%^.%^RESET%^","%^BOLD%^"+
      "%^BLACK%^The elephant raises its trunk and trumpets a warning.%^RESET%^"}), 0);
   command("message in stomps in");
   command("message out stomps away $D.");
}

int enter(string str){
    int lev, temp;

    lev = TP->query_highest_level();
    temp = TP->query_max_hp();
    if(query_owner() != this_player()) {
        tell_room(ETP, ""+TPQCN+" seems unable to mount the elephant!", TP);
        return notify_fail("The elephant won't let you ride!\n");
    }
    set_level(lev*1/2);
    set_mlevel("fighter", lev*1/2);
    set_max_hp(temp*2/3);
    set_damage(2,4);
    set_overall_ac(6 - (lev/2));
    set_hp(query_max_hp());
    return ::enter(str);
    return 1;
}