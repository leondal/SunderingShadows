//Tiger mount for new Seneca
//~Circe~ 12/3/07
#include <std.h>
inherit "/std/riding_animal.c";

void create(){
   object ob;
   ::create();
   set_name("riding tiger");
   set_short("%^RESET%^%^ORANGE%^sleek %^YELLOW%^r%^RESET%^"+
      "%^ORANGE%^i%^YELLOW%^d%^RESET%^%^ORANGE%^i%^YELLOW%^n"+
      "%^RESET%^%^ORANGE%^g tiger%^RESET%^");
   set_id(({"tiger","riding tiger","sleek tiger","sleek riding tiger","mount"}));
   set_long("%^RESET%^%^ORANGE%^This beautiful animal has sleek "+
      "b%^YELLOW%^a%^WHITE%^n%^BLACK%^d%^RESET%^%^ORANGE%^e"+
      "%^YELLOW%^d %^RESET%^%^ORANGE%^fur.  The face is a deep "+
      "russet across the nose, striped with %^BOLD%^%^BLACK%^black "+
      "%^RESET%^%^ORANGE%^and fading to %^BOLD%^%^WHITE%^white "+
      "%^RESET%^%^ORANGE%^along the neck.  A series of s%^YELLOW%^"+
      "t%^BLACK%^r%^YELLOW%^i%^RESET%^%^ORANGE%^p%^YELLOW%^e%^BLACK%^"+
      "s %^RESET%^%^ORANGE%^runs vertically along the body and rings "+
      "the long tail, which often swishes lazily.  A quick glance "+
      "at this tiger's %^YELLOW%^eyes %^RESET%^%^ORANGE%^and "+
      "%^RESET%^teeth %^ORANGE%^reveal that the animal is anything "+
      "but lazy.  Amazingly, a saddle has been fitted onto the "+
      "breathtaking creature's back, giving a rider a place to sit.%^RESET%^");
   set_level(10);
   set_value(850);
   set_race("tiger");
   set_gender(random(2)?"male":"female");
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
   set_enter_room("prowls in on a sleek tiger");
   set_exit_room("prowls out on a sleek tiger");
   set_riding_level(20);
   set_vehicle_short("%^RESET%^%^ORANGE%^sleek %^YELLOW%^r%^RESET%^"+
      "%^ORANGE%^i%^YELLOW%^d%^RESET%^%^ORANGE%^i%^YELLOW%^n"+
      "%^RESET%^%^ORANGE%^g tiger%^RESET%^");
   set_attacks_num(2);
   set_damage(2,4);
   set_base_damage_type("bludgeoning");
   set_emotes(1,({"%^RESET%^%^ORANGE%^The tiger stretches and yawns, "+
      "arching its back and revealing sharp %^RESET%^teeth%^ORANGE%^"+
      ".%^RESET%^","%^RESET%^%^ORANGE%^The tiger swishes its r"+
      "%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^g"+
      "%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^d %^RESET%^%^ORANGE%^"+
      "tail.%^RESET%^"}), 0);
   command("message in prowls in");
   command("message out prowls away $D.");
}

int enter(string str){
    int lev, temp;

    lev = TP->query_highest_level();
    temp = TP->query_max_hp();
    if(query_owner() != this_player()) {
        tell_room(ETP, ""+TPQCN+" seems unable to mount the sleek tiger!", TP);
        return notify_fail("The sleek tiger won't let you ride!\n");
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