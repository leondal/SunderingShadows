//funicorn.c - New mount (sune) for the holy/unholy avenger. Nienne, 2/05
#include <std.h>
inherit "/d/common/mounts/barded_war_horse";

void create(){
   ::create();
   set_name("stallion");
   set_vehicle_short("stallion");
   set_short("%^RESET%^%^RED%^A magnificent chestnut stallion "+
	"with a %^BOLD%^%^RED%^flaming%^RESET%^%^RED%^ mane%^RESET%^");
   set_id(({"mount","stallion","chestnut stallion"}));
   set_race("stallion");
   set_long("%^RESET%^%^RED%^A %^BOLD%^%^RED%^fiery%^RESET%^"+
	"%^RED%^ aura radiates from this beautiful creature.  "+
	"The magnificent steed has a gleaming coat of rich "+
	"chestnut hair, with intelligent eyes of %^BOLD%^%^GREEN%^em"+
	"%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^rald%^RESET%^%^RED%^."+
	"  Strands of his %^BOLD%^%^RED%^f%^RESET%^%^RED%^l%^BOLD%^"+
        "%^RED%^a%^RESET%^%^RED%^m%^BOLD%^%^RED%^i%^RESET%^%^RED%^n"+
        "%^BOLD%^%^RED%^g%^RESET%^%^RED%^ mane of flames blow in the"+
        " breeze, and down the creature's muscular neck.  Powerful "+
        "muscles ripple beneath"+
	" his hide, down to the flowing tail of %^BOLD%^%^RED%^f"+
        "%^RESET%^%^RED%^i%^BOLD%^%^RED%^r%^RESET%^%^RED%^e, and the cloven "+
	"hooves of smooth %^BOLD%^%^RED%^ruby red%^RESET%^%^RED%^.  "+
	"This creature is the substance of legend, a breathtaking "+
	"sight to behold.");
   present("barding")->set_short("protective adamantium barding");
   set_gender("male");
   set_exit_room("leaves riding a magnificent stallion.");
   set_funcs(({"special"}));
   set_func_chance(15);
   TO->force_me("message in trots in with its head held high.");
   TO->force_me("message out trots out $D.");
}

void special(object target) {
   tell_room(ETO,"%^RED%^Flames wrap around the ruby red hooves of the "+
		"stallion as he kicks "+target->QCN+".",target);
   tell_object(target,"%^RED%^Flames wrap around the ruby red hooves of the"+
		" stallion as he kicks you!");
   TO->set_property("magic",1);
   target->do_damage(target->return_target_limb(),(roll_dice(3,6))+6);
   TO->remove_property("magic");
}