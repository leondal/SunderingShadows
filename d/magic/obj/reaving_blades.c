//now used for Dark Sun's Rays.
//Changed to Cyric by Circe 4/14/04 for return of Bane
//reaving_blades.c

#include <std.h>

inherit WEAPONLESS;

void create(){
   ::create();

   set_name("Rays of the Dark Sun");
   set_short("%^BLUE%^Rays of the Dark Sun%^RESET%^");
   set_id(({"blades","bladesx1","reaving blades","dark suns rays","rays"}));
   set_long(
@OLI
These malicious blades of darkness appear for only 
one reason - to spread the malice of the Dark Sun 
and seek out the blood of those who would dare 
oppose his will.
OLI
   );
   set_property("magic",1);
   set_hd(35,1);
   set_hp(1000000);
   set_gender("dark sun's");
   set_race("rays");
   add_limb("Scything blade","",0,0,0);
   add_limb("Slashing blade","",0,0,0);
   set_attack_limbs(({"scything blade","slashing blade"}));
   set_attacks_num(2);
   set_hit_funcs((["scything blade":(:TO,"killem":),"slashing blade":(:TO,"killem":)]));
}

void die(object ob){

}

int do_damage(string limb,int amount){
   return 0;
}

int killem(object targ){
   if(!objectp(targ)) return random(3);

   tell_room(ETO,"%^BLUE%^The spinning blades of darkness slash wildly, cutting anything in their path.");
   return random(3);
}
int isMagic() {return 4;}
