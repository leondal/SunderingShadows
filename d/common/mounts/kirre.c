//kirre.c - New mount (auppenser) for the holy/unholy avenger. Nienne, 2/05
#include <std.h>
inherit "/d/common/mounts/barded_war_horse";

void create(){
   ::create();
   set_name("kirre");
   set_vehicle_short("kirre");
   set_short("%^RESET%^%^CYAN%^A majestic kirre%^RESET%^");
   set_id(({"mount","kirre"}));
   set_race("kirre");
   set_long("%^CYAN%^At first glance, this eight foot long cat looks like a"+
        " large %^ORANGE%^tiger%^CYAN%^. The stripes are similar, but the colors are"+
        " wrong, this cat has %^ORANGE%^bronze%^CYAN%^ and"+
	  " %^BOLD%^%^BLACK%^gray%^RESET%^%^CYAN%^ stripes. Yellow"+
        " eyes stare at you watchfully. A %^RED%^red %^CYAN%^tongue"+
        " rests between sharp %^BOLD%^%^WHITE%^canine teeth"+
	  "%^RESET%^%^CYAN%^. Two %^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^"+
	  " horns are also"+
        " protruding from its head. The cat's tail switches back"+
        " and forth slowly and some deadly looking barbs are on it."+
        " The kirre flexes its front paws, extending its "+
	  "%^BOLD%^%^WHITE%^razor%^RESET%^%^CYAN%^"+
        " sharp claws. In fact, the kirre has eight sets of"+
	  " razor sharp claws...");
   present("barding")->set_short("%^RESET%^protective adamantium barding");
   if(random(2)) set_gender("male");
   else set_gender("female");
   set_body_type("kirre");
   set_exit_room("leaves riding a majestic kirre.");
   add_limb("horns","head",0,0,0);
   add_limb("right leg","torso",0,0,0);
   add_limb("left leg","torso",0,0,0);
   add_limb("torso","torso",0,0,0);
   add_limb("head","torso",0,0,0);
   set_attack_limbs(({"horns","claws"}));
   set_base_damage_type("slashing");
   set_funcs(({"special"}));
   set_func_chance(15);
   TO->force_me("message in treads in with swishing its tail.");
   TO->force_me("message out treads out $D.");
}

void special(object target) {
   tell_room(ETO,"%^BOLD%^%^CYAN%^The kirre fixes "+ETO->QP+" gaze onto "+target->QCN+","+
		" assaulting "+target->QP+" mind with a psychic attack!%^RESET%^",target);
   tell_object(target,"%^BOLD%^%^CYAN%^The kirre fixes "+ETO->QP+" gaze onto you,"+
		" assaulting your mind with a psychic attack!%^RESET%^");
   TO->set_property("magic",1);
   target->do_damage(target->return_target_limb(),(roll_dice(3,6))+6);
   TO->remove_property("magic");
}
