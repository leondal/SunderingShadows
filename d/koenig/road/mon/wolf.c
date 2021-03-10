#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

create(){
  	::create();
  	set_name("wolf");
  	set_id(({"a wolf", "the wolf", "wolf"}) );
  	set_short("a wolf");
  	set_long("This wolf looks at you through amber colored eyes.  You "+
  		"notice it has some very powerful looking jaws...which "+
  		"by the way are full of wide STRONG teeth!"
  	);
  	set_race("wolf");
  	set_gender("male");
  	set_body_type("quadruped");
  	set_hd(3);
  	set_overall_ac(7);
  	set_alignment(5);
  	set_size(1);
  	set_max_hp(45);
  	set_hp(45);
  	set_exp(120);
  	set("aggressive", 10);
  	set_emotes(5, ({
  		"The wolf separates from the shadows never taking his "+
  			"eyes from you.",
  		"Without a sound, not even a growl, he bares his fangs for you to see."
  	}) );
}
