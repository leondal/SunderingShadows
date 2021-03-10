#include <std.h>

inherit "/std/monster";

void create() {
  ::create();
  set_name("wasp");
  set_id(( { "wasp", "giant wasp"} ));
  set_race("wasp");
  set_gender("female");
  set_short("%^YELLOW%^large w%^RESET%^%^ORANGE%^a%^YELLOW%^s%^RESET%^%^ORANGE%^p%^RESET%^");
  set_long("%^RESET%^%^ORANGE%^This is a very large %^BOLD%^%^BLACK%^black %^RESET%^%^ORANGE%^wasp with %^YELLOW%^yellow stripes %^RESET%^%^ORANGE%^running across its elongated body.%^RESET%^\n");
  set_hd(2,2);
  set_alignment(6);
  set_body_type("insectoid-winged");
  set_size(1);
  set_hp(15);  
  set_stats("dexterity",20);
  set_overall_ac(6);
  set_exp(100); 
  set("aggressive", 19);
  set_achats(2, ({ 
        "The wasp flies around you angrily, diving in to try to sting!", 
        "The wasps swarm around you!" }) );
  set_funcs(({"bite"}));
  set_func_chance(15);
}

void bite(object targ) {
    targ->do_damage("torso",random(6)+2);
     tell_room(ETO,"%^YELLOW%^The wasp bites at "+targ->query_cap_name()+"'s skin!",targ);
    tell_object(targ, "The wasp bites at your skin!");
}