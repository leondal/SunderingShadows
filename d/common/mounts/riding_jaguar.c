//Jaguar mount for new Seneca
//~Circe~ 12/4/07
#include <std.h>
inherit "/std/riding_animal.c";

void create(){
   object ob;
   ::create();
   set_name("riding jaguar");
   set_short("%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^p%^RESET%^"+
      "%^ORANGE%^o%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^t%^BOLD%^"+
      "%^BLACK%^e%^RESET%^%^ORANGE%^d riding jaguar%^RESET%^");
   set_id(({"jaguar","riding jaguar","spotted jaguar","spotted riding jaguar","mount"}));
   set_long("%^RESET%^%^ORANGE%^This fantastic creature has sleek "+
      "lines and exquisite %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^"+
      "l%^RESET%^%^ORANGE%^d%^YELLOW%^e%^RESET%^%^ORANGE%^n fur "+
      "combined with powerful muscles.  %^BOLD%^%^BLACK%^Black "+
      "rosettes%^RESET%^%^ORANGE%^, a circle of spots surrounding "+
      "a larger spot, cover the cat's back, while the spots on its "+
      "chest, head, and legs are %^BOLD%^%^BLACK%^solid black%^RESET%^"+
      "%^ORANGE%^.  This jaguar is larger than most, standing about "+
      "five feet at the shoulder and over eight feet in length.  Its "+
      "eyes are a glittering %^YELLOW%^gold%^RESET%^%^ORANGE%^ and "+
      "reveal a predator's intelligence.  Oddly, this one has been "+
      "saddled, as if to allow someone to ride.%^RESET%^");
   set_level(10);
   set_value(1150);
   set_race("jaguar");
   set_gender("male");
   set_body_type("quadruped");
   add_limb("mouth","head",0,0,0);
   set_attack_limbs(({"left foreleg","right foreleg","mouth"}));
   set_size(2);
   set_hd(10,6);
   set_max_hp(200);
   set_hp(200);
   set_overall_ac(-6);
   set_exp(1);
   set_max_distance(500);
   set_enter_room("slinks in on a spotted jaguar");
   set_exit_room("slinks out on a spotted jaguar");
   set_riding_level(20);
   set_vehicle_short("%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^p%^RESET%^"+
      "%^ORANGE%^o%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^t%^BOLD%^"+
      "%^BLACK%^e%^RESET%^%^ORANGE%^d riding jaguar%^RESET%^");
   set_attacks_num(2);
   set_damage(2,4);
   set_base_damage_type("bludgeoning");
   set_emotes(1,({"%^RESET%^%^ORANGE%^The jaguar stretches and yawns, "+
      "arching its back and revealing sharp %^RESET%^teeth%^ORANGE%^"+
      ".%^RESET%^","%^RESET%^%^ORANGE%^The jaguar swishes its "+
      "%^BOLD%^%^BLACK%^s%^YELLOW%^p%^BLACK%^o%^YELLOW%^t%^BLACK%^t"+
      "%^YELLOW%^e%^BLACK%^d %^RESET%^%^ORANGE%^"+
      "tail.%^RESET%^"}), 0);
   command("message in slinks in");
   command("message out slinks away $D.");
}

int enter(string str){
    int lev, temp;

    lev = TP->query_highest_level();
    temp = TP->query_max_hp();
    if(query_owner() != this_player()) {
        tell_room(ETP, ""+TPQCN+" seems unable to mount the spotted jaguar!", TP);
        return notify_fail("The spotted jaguar won't let you ride!\n");
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