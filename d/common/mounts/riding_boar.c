//Boar mount for new Seneca
//~Circe~ 12/3/07
#include <std.h>
inherit "/std/riding_animal.c";

void create(){
   object ob;
   ::create();
   set_name("giant boar");
   set_short("%^RESET%^%^ORANGE%^bristly giant boar%^RESET%^");
   set_id(({"boar","giant boar","riding boar","bristly giant boar","mount"}));
   set_long("%^RESET%^%^ORANGE%^Covered in stiff brown bristles, "+
      "this giant boar has a large head and short, stubby legs.  "+
      "It really doesn't look as if it would be very fast, but "+
      "its compactness and strength likely have their uses.  "+
      "%^RESET%^Tusks %^ORANGE%^protrude about six inches "+
      "from the lower jaw, appearing to be quite nasty weapons.  "+
      "Similar %^RESET%^tusks %^ORANGE%^also extend from the upper "+
      "jaw but bend upwards, and look to be relatively harmless.  "+
      "A saddle has been fitted upon the boar's back, giving a "+
      "rider a place to sit.%^RESET%^");
   set_level(10);
   set_value(850);
   set_race("boar");
   set_gender(random(2)?"male":"female");
   set_body_type("quadruped");
   set_attack_limbs(({"left foreleg","right foreleg"}));
   set_size(2);
   set_hd(10,6);
   set_max_hp(200);
   set_hp(200);
   set_overall_ac(-6);
   set_exp(1);
   set_max_distance(500);
   set_enter_room("charges in on a giant boar");
   set_exit_room("charges out on a giant boar");
   set_riding_level(20);
   set_vehicle_short("%^RESET%^%^ORANGE%^bristly giant boar%^RESET%^");
   set_attacks_num(2);
   set_damage(2,4);
   set_base_damage_type("bludgeoning");
   set_emotes(1,({"%^RESET%^%^ORANGE%^The boar grunts and roots around "+
      "on the ground.%^RESET%^","%^RESET%^%^ORANGE%^The boar emits a "+
      "loud squeal.%^RESET%^"}), 0);
   command("message in charges in");
   command("message out charges away $D.");
}

int enter(string str){
    int lev, temp;

    lev = TP->query_highest_level();
    temp = TP->query_max_hp();
    if(query_owner() != this_player()) {
        tell_room(ETP, ""+TPQCN+" seems unable to mount the giant boar!", TP);
        return notify_fail("The giant boar won't let you ride!\n");
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