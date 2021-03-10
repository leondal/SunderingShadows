//panther.c - New mount (panther) for the holy/unholy avenger. Nienne, 2/05
#include <std.h>
inherit "/d/common/mounts/barded_war_horse";

void create(){
   ::create();
   set_name("panther");
   set_vehicle_short("panther");
   set_short("%^BOLD%^%^BLACK%^A majestic dire panther%^RESET%^");
   set_id(({"mount","panther","dire panther"}));
   set_race("panther");
   set_long("%^GREEN%^This majestic dire panther has a sleek and powerful body."+
	"  It stands at about five feet at its shoulder, and is covered with "
	"a %^BOLD%^%^BLACK%^jet black%^RESET%^%^GREEN%^ pelt.  The panther's %^YELLOW%^"+
	"amber%^RESET%^%^GREEN%^ eyes shine with the light of a predator."+
	"  Powerful muscles are visible beneath its hide.  Thick and deadly"+
	" claws are housed in the massive paws of this lion.  Its %^BOLD%^"+
	"%^WHITE%^pearly white%^RESET%^%^GREEN%^ teeth look as if they could"+
	" snap the head off any prey with ease.  Its thick tail swishes behind"+
	" it as it moves with silent stalking steps.%^RESET%^");
   present("barding")->set_short("%^RESET%^protective adamantium barding");
   if(random(2)) set_gender("male");
   else set_gender("female");
   set_body_type("quadruped");
   set_exit_room("leaves riding a majestic panther.");
   add_limb("jaws","head",0,0,0);
   set_attack_limbs(({"jaws","claws"}));
   set_base_damage_type("slashing");
   set_funcs(({"special"}));
   set_func_chance(15);
   TO->force_me("message in stalks in sleekly.");
   TO->force_me("message out stalks out $D.");
}

void special(object target) {
   tell_room(ETO,"%^GREEN%^The panther lunges at "+target->QCN+","+
		"swipping with "+ETO->QP+" large claws!%^RESET%^",target);
   tell_object(target,"%^GREEN%^The panther lunges at you, its large"+
		" claws tearing through your flesh!%^RESET%^");
   TO->set_property("magic",1);
   target->do_damage(target->return_target_limb(),(roll_dice(3,6))+6);
   TO->remove_property("magic");
}
