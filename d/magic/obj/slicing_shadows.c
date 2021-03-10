//Used for slicing shadows

#include <std.h>

inherit WEAPONLESS;

void create(){
   ::create();

   set_name("slicing shadow");
   set_short("A cloud of shadows");
   set_id(({"shadows","shadowsx1","slicing shadow","cloud","cloud of shadows"}));
   set_long("%^BOLD%^%^BLACK%^An inky dark cloud of moving"+
		" and rolling shadows fills the area.  Within the bubbling"+
		" shadows, whiplike whorls can be seen.  The shapes appear"+
		" and disappear quickly, as the cloud is in a perpetual "+
		"state of movement.");
   set_property("magic",1);
   set_hd(35,1);
   set_hp(1000000);
   set_gender("slicing");
   set_race("shadow");
   add_limb("whiplike whorl","",0,0,0);
   add_limb("shadow tendril","",0,0,0);
   set_attack_limbs(({"whiplike whorl","shadow tendril"}));
   set_attacks_num(2);
   set_hit_funcs((["whiplike whorl":(:TO,"killem":),"shadow tendril":(:TO,"killem":)]));
}

void die(object ob){

}

int do_damage(string limb,int amount){
   return 0;
}

int killem(object targ){
   if(!objectp(targ)) return random(3);

   tell_room(ETO,"%^BOLD%^%^BLACK%^The whiplike tendrils of shadow"+
		" lash out of the cloud, slicing through the air with"+
		" deadly percision.");
   return random(3);
}
int isMagic() {return 4;}
