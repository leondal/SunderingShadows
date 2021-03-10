//lion.c - New mount (torm) for the holy/unholy avenger. Nienne, 2/05
#include <std.h>
inherit "/d/common/mounts/barded_war_horse";

void create(){
   ::create();
   set_name("lion");
   set_vehicle_short("lion");
   set_short("%^RESET%^%^ORANGE%^A majestic golden dire lion%^RESET%^");
   set_id(({"mount","lion","dire lion"}));
   set_race("lion");
   set_long("%^ORANGE%^This majestic dire lion has a sleek and powerful body."+
	"  It stands at about five feet at its shoulder, and is covered with "
	"a %^YELLOW%^golden tawny%^RESET%^%^ORANGE%^ pelt.  The lion's %^YELLOW%^"+
	"amber%^RESET%^%^ORANGE%^ eyes shine with the light of a predator."+
	"  Powerful muscles are visible beneath its hide.  Thick and deadly"+
	" claws are housed in the massive paws of this lion.  Its %^BOLD%^"+
	"%^WHITE%^pearly white%^RESET%^%^ORANGE%^ teeth look as if they could"+
	" snap the head off any prey with ease.  Its thick tail swishes behind"+
	" it as it moves with a powerful regal grace.%^RESET%^");
   present("barding")->set_short("%^RESET%^protective adamantium barding");
   if(random(2)) set_gender("male");
   else set_gender("female");
   set_body_type("quadruped");
   set_exit_room("leaves riding a majestic lion.");
   add_limb("jaws","head",0,0,0);
   set_attack_limbs(({"jaws","claws"}));
   set_base_damage_type("slashing");
   set_funcs(({"special"}));
   set_func_chance(15);
   TO->force_me("message in treads in with a powerful regal grace.");
   TO->force_me("message out treads out $D.");
}

void special(object target) {
   tell_room(ETO,"%^ORANGE%^The lion rears up onto its hind legs, lashing out "
"at "+target->QCN+" with its jaws and claws!%^RESET%^",target);
   tell_object(target,"%^ORANGE%^The lion rears up onto its hind legs, "
"lashing out at you with its jaws and claws!%^RESET%^");
   TO->set_property("magic",1);
   target->do_damage(target->return_target_limb(),(roll_dice(3,6))+6);
   TO->remove_property("magic");
}
