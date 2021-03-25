//Coded by Lujke, with code plundered from Cythera and Bane
#include <std.h>
#include "../tunnel.h"
inherit WEAPONLESS;

void create()
{
  ::create();
  	set_name("tunnel worm");
  	set_id(({"worm","tunnel worm","giant worm","monster","tun mon"}));
  	set_short("%^RESET%^%^MAGENTA%^A t%^BLUE%^u%^MAGENTA%^nnel w"
               +"%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^rm%^RESET%^");
  	set_long("description: %^RESET%^%^MAGENTA%^ This is a huge, bloated"
              +" %^BOLD%^%^MAGENTA%^pink worm%^RESET%^%^MAGENTA%^ with no"
              +" eyes, just a gaping maw of %^BOLD%^%^WHITE%^needle sharp"
              +" teeth%^BOLD%^%^MAGENTA%^. Its body is sectioned like an"
              +" %^ORANGE%^e%^MAGENTA%^a%^ORANGE%^rthworm%^MAGENTA%^, and"
              +" it sh%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^mmers as it"
              +" pulses along the tunnel.");
  	set_race("worm");
  	set_body_type("snake");
  	set_gender("neuter");
  	set_hd(35,12);
  	set_size(2);
      set_max_level(25);
      set_size(2);
      set_exp(5000);
      set_overall_ac(1);
      set_max_hp(random(140)+200);
      set_hp(query_max_hp());
      set_alignment(8);
      set_level(20);
      set_class("fighter");
      set_mlevel("fighter",20);
      set("aggressive",25);
      set_property("swarm",1);
      set_property("no bows",1);
      set_stats("strength",18);
      add_limb("mandibles","mouth",0,0,0);
      set_attack_limbs(({"mandibles"}));
      set_attacks_num(2);
      set_base_damage_type("piercing");
      set_damage(2,8);


  	set_speed(30);
 	set_nogo(({ TUNNELS+"tun09", TUNNELS + "lair"}));
	set_max_level(40);
	set_property("swarm",1);
  	set_overall_ac(-20);
  	set_alignment(5);
  	set_emotes(10,({
		"%^MAGENTA%^The %^BOLD%^%^MAGENTA%^worm%^RESET%^%^MAGENTA%^"
           +" nibbles at your clothing",
      	TO->query_cap_name() + " %^MAGENTA%^undulates its body"
    	}),1);
}
