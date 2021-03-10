//windghost.c

#include <std.h>

inherit WEAPONLESS;

void create(){
   int num;
  
   ::create();
    set_name("windghost");
    set_id(({"elemental","windghost","ghost"}));
    set("short","%^RESET%^%^MAGENTA%^Windghost%^RESET%^");
    set("long",
@PEG
    %^MAGENTA%^The windghost appears as a tall humanoid with long whipping hair and wearing a swirling cloak.  Two pupilless white orbs shine forth on the hazy purple face of the windghost.  From the waist down, the windghost's body difuses into the surrounding air, making it look as if it floats above the earth. An etheral two handed great sword is held in the windghost's hands.  The edges of the figure's cloak and hair also are blurred, adding to its hazy ghost like apperance.
PEG
	);
	num = random(100);
	switch(num){
	    case 0..59: set_hd(12,1);
	                break;
	    case 60..94: set_hd(16,1);
	                 break;
	    case 95..99: set_hd(21+random(4),1);
	                 break;
        default: set_hd(12,1);
                 break;
	}
    set_hp(query_hd()*8);
    set_exp(1);
    set_stats("strength",18);
    set_stats("intelligence",10);
    set_stats("dexterity",22);
    set_race("windghost");
    set_damage(2,10);
    set_attacks_num(1);
    set_base_damage_type("slashing");
    set_gender("sexless");
    set_overall_ac(0);
}
int isMagic() {return 5;}
