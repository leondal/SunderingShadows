#include <std.h>
#include "kravor.h";

inherit MONSTER;

void create() {
  ::create();
  set_name("guard");
  set("race","undead");
  set_body_type("human");
  set_id(({"doom guard","doom","monster"}));
  set("short","A doom guard");
  set_long(
@MILT
	Nothing more that a suit of armour, this doom guard is now
	an animated creature of great power.  Created by a series
	of arcane enchantments, these frightening automatons are a
	force to be reckoned with.
MILT
);
  set_hd(5,1);
  set_size(2);
  set_wielding_limbs(({"right hand","left hand"}));
  set_stats("intelligence",6);
  set("aggressive",10);

  new(WEAP + "lsword")->move(this_object());
  command("wield sword in right hand");
  new(ARM + "rhelm")->move(this_object());
command("wear armor");
  new(ARM + "rplate")->move(this_object());
command("wear armor");
set_emotes(20,({"The doom guard rattles to attention.",
                "The doom guard faces you silently."}),0);
set_emotes(25,({"The doom guard slashes at you with utter silence!"}),1);
}
