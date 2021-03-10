#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

create(){
  	::create();
  	set_name("grizzly");
  	set_id( ({"bear", "grizzly", "a bear", "a grizzly"}) );
  	set_short("a grizzly");
  	set_long("This bear is way off his beaten track and looks very pissed off!");
  	set_race("bear");
    	set_gender(random(2)?"male":"female");
  	set_body_type("quadruped");
  	set_hd(5,5);
  	set_overall_ac(6);
  	set_alignment(5);
  	set_size(3);
  	set_max_hp(110);
  	set_hp(110);
  	set_exp(420);
  	set("aggressive", 18);
  	set_emotes(10, ({
  		"The Grizzly roars in rage and rushes towards you!",
  		"The Grizzly rears up in front of you, moving in for the HUG."}) );
  	set_achats(8, ({
  		"%^ORANGE%^RRRRRRRRRRROOOOOOOOOOAAAAAAAAAARRRRRRRRRRRR!!!!",
  		"%^CYAN%^A voice inside your head whispers *YOU'RE DINNER PAL!!*"}) );
}
