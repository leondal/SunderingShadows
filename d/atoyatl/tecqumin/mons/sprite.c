//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
inherit MONSTER;
#define EYECOLOUR ({"%^BOLD%^%^GREEN%^green%^RESET%^",\
                    "%^BOLD%^%^YELLOW%^yellow%^RESET%^"})

int climbed;

void create()
{
      ::create();
      set_property("not random monster", 1);
      climbed = 0;
  	set_name("sprite");
  	set_id(({"sprite", "humanoid", "flighty sprite"}));
  	set_short("sprite");
      switch (random(2)){
  	case 0:
        set_gender("male");
        break;
      case 1:
        set_gender("female");
      }
      switch (random(3)){
      case 0:
        set_long("%^BOLD%^%^GREEN%^The sprite is a small, slender humanoid"
                +", with pale green skin, translucent wings and faintly"
                +" elven features. The pointed tips of " + QP +" ears peek"
                +" out from under bark brown ringlets of hair. " 
                + capitalize(QS) + " has large, luminous eyes, whose"
                +" expressiveness is put to use in the array of emotions"
                +" that flicker rapidly across " + QP + " face. From"
                +" soulful lucidity to mirth to mischeif, all in the blink"
                +" of an eye.");
        break;
      case 1:
        set_long("%^BOLD%^%^GREEN%^This little sprite has a snub nose and"
                +" cutesy pinched cheeks. " + capitalize(QP) + " eyes are"
                +" wide, in an almost constant expression of surprise, and"
                + QS + " seems to have barely a moment of stillness at any"
                +" time.");
        break;
      case 2:
        set_long("%^BOLD%^%^GREEN%^A relatively tall sprite, with lighter"
                +" skin than most, and a bluish tinge to " + QP + " hair."
                + capitalize(QS) + " has gossamer like wings, and is"
                +" dressed in soft fabrics, mostly greens and browns.");
        break;
      }
  	set_race("sprite");
  	set_body_type("humanoid");
  	set_hd(35,12);
  	set_size(3);
  	set("aggressive",25);
	set_class("fighter");
	set_mlevel("fighter",35);
	set_level(35);
	set_guild_level("fighter",35);
   	set_hp(random(50)+300);
   	set_exp(5000);
	set_max_level(35);
	set_property("swarm",1);
  	set_overall_ac(-5);
  	set_alignment(4);
      set_property("full attacks",1);
      set_funcs(({"seize"}));
}
