#include "../juran.h"

inherit "/std/trainer";

void create(){
   	::create();
   	set_name("grinder");
   	set_short("Grinder, the weapon skill trainer");
   	set_long("Before you is the biggest meanest looking orc you have ever "+
   		"seen.  He is currently weaponless and standing near the "+
   		"entrance, leaning against the wall.  He looks strong and mean and "+
   		"he is well known for his fighting skills and mastery of the art "+
   		"of all types of fighting.  He is always willing to train people "+
   		"and beat them senseless in the process.  He is not a karate "+
   		"enthusiast, he prefers fighting any one who has a weapon.  "+
   		"That way, he can be proved of his combat mastery.");
   	set_hd(30,4);
   	set_exp(1);
   	set_property("no bows",1);
   	set_stats("strength",10);
   	set_stats("dexterity",20);
   	set_max_hp(300);
   	set_hp(300);
   	set_id(({"grinder","orc","Grinder","trainer","weapon skill trainer"}));
   	set_attack_limbs(({"right hand","left hand"}));
   	set_attacks_num(1);
   	set_damage(1,1);
   	set_race("orc");
   	set_gender("male");
   	set_base_damage_type("bludgeoning");
   	set_overall_ac(0);
     	set_spoken("wizish");
   	remove_std_db();
}
