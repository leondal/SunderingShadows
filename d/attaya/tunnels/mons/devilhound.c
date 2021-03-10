//Coded by Lujke, with code plundered from Cythera and Bane
#include <std.h>
#include "../tunnel.h"
inherit WEAPONLESS;

void create()
{
  ::create();
  	set_name("devil hound");
  	set_id(({"hound","devil hound","dog","monster","black hound",
                       "tun mon"}));
  	set_short("%^BOLD%^%^BLACK%^d%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^v"
               +"%^RED%^i%^BOLD%^%^BLACK%^l h%^RESET%^ou%^BOLD%^"
               +"%^BLACK%^nd");
  	set_long("%^BOLD%^%^BLACK%^A m%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^dn"
              +"%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^ght black h%^RESET%^ou"
              +"%^BOLD%^%^BLACK%^nd, the size of a small pony, with"
              +" %^RESET%^%^RED%^gl%^BOLD%^%^RED%^o%^RESET%^%^RED%^wing"
              +" r%^BOLD%^e%^RESET%^%^RED%^d ey%^BOLD%^e%^RESET%^%^RED%^s"
              +"%^BOLD%^%^BLACK%^ and pointed ears. It snarls constantly,"
              +" %^BOLD%^%^WHITE%^saliva%^BOLD%^%^BLACK%^ dripping from"
              +" its %^BOLD%^%^YELLOW%^vicious yellow fangs%^BOLD%^"
              +"%^BLACK%^. The air around its body seems somehow to"
              +" %^RESET%^%^CYAN%^distort%^BOLD%^%^BLACK%^ and fold in on"
              +" itself.");
  	set_race("devil");
  	set_body_type("quadruped");
  	set_gender("male");
  	set_hd(35,12);
  	set_size(2);
  	set("aggressive",25);
  	set_class("fighter");
  	set_mlevel("fighter",25);
  	add_limb("mouth","head",0,0,0);
  	add_limb("tail","torso",0,0,0);
  	set_attack_limbs(({"mouth","right forepaw","left forepaw",
                            "mouth"}));
  	set_attacks_num(3);
  	set_base_damage_type("piercing");
  	set_damage(3,6);
  	set_hp(random(50)+200);
	set_speed(30);
 	set_nogo(({ "/d/attaya/ugstream",
                 "/d/attaya/rooms/tun15",
                "/d/attaya/rooms/tun02",}));
  	set_exp(4000);
	set_max_level(40);
	set_property("swarm",1);
  	set_overall_ac(-20);
      set_funcs(({"pounce"}));
      set_func_chance(25);
  	set_alignment(3);
  	set_emotes(10,({
		"%^BOLD%^%^BLACK%^The d%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^v"
           +"%^RED%^i%^BLACK%^l h%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^und"
           +" growls menacingly, %^BOLD%^%^WHITE%^s%^RESET%^a%^BOLD%^"
           +"%^WHITE%^li%^RESET%^v%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^"
           +" dripping from its %^RESET%^%^ORANGE%^y%^RESET%^e"
           +"%^ORANGE%^ll%^YELLOW%^o%^RESET%^%^ORANGE%^w %^YELLOW%^f"
           +"%^RESET%^%^ORANGE%^an%^YELLOW%^g%^RESET%^%^ORANGE%^s"
           +"%^BOLD%^%^BLACK%^.",

      	"%^BOLD%^%^BLACK%^The d%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^v"
           +"%^RED%^i%^BLACK%^l h%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^und"
           +" raises its %^RESET%^shaggy muzzle%^BOLD%^%^BLACK%^ and"
           +" howls in fury."
    	}),1);
}
void pounce(object targ){
    if (!objectp(targ)||!objectp(TO)){return;}
    if(!"daemon/saving_d"->saving_throw(targ,"rod_staff_wand", -7)){
	tell_object(targ,"%^RED%^The %^BOLD%^%^BLACK%^h%^RESET%^%^RED%^o"
                      +"%^BOLD%^%^BLACK%^und %^BOLD%^%^RED%^jumps%^BOLD%^"
                      +"%^BLACK%^ up, pushing you over and pinning you to"
                      +" the ground with its massive weight!");
	tell_room(ETO,"%^RED%^The %^BOLD%^%^BLACK%^h%^RESET%^%^RED%^o"
                   +"%^BOLD%^%^BLACK%^und %^BOLD%^%^RED%^jumps%^BOLD%^"
                   +"%^BLACK%^ up, pushing " +targ->query_cap_name()
                   +" over and pinning "+targ->query_objective()+" to the"
                   +" ground with its massive weight!",targ);
	targ->set_paralyzed(30,"You are pinned to the ground under a"
                            +" %^BOLD%^%^WHITE%^sl%^RESET%^%^ORANGE%^a"
                            +"%^BOLD%^%^WHITE%^v%^YELLOW%^e%^BOLD%^"
                            +"%^WHITE%^r%^RESET%^%^ORANGE%^i%^BOLD%^"
                            +"%^WHITE%^ng%^RESET%^ hound!");
      return 1;
    }
    tell_object(targ,"%^BOLD%^%^BLACK%^h%^RESET%^%^RED%^o%^BOLD%^"
                    +"%^BLACK%^und %^BOLD%^%^RED%^jumps%^BOLD%^%^BLACK%^"
                    +" up at you but you dodge out of the way!");
    tell_room(ETO,"%^BOLD%^%^BLACK%^h%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^"
                 +"und %^BOLD%^%^RED%^jumps%^BOLD%^%^BLACK%^ up at"
                 +" "+targ->query_cap_name()+" but "
                 +targ->query_subjective()+" dodges out of the"
                 +" way!",targ);
    return 1;
}
