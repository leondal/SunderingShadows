#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("guard");
    set_id(({"gate guard","guard","seneca gate guard"}));
    set_short("Seneca gate guard");
    set_long("
    Powerful guards stand at attention at the gates of the coastal city of Seneca.  They shall fight to their deaths if the need arises to protect their homeland from invaders.
    They are fierce opponents of the Kinnesaruda and their evil influences.
");
    set_race("human");
    set_gender("male");
    set_hd(30,6);
    set_size(2);
    set_overall_ac(-14);
    set_class("fighter");
    set_guild_level("fighter",30);
    set_max_hp(500);
    set_hp(500);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("no_bump",1);
    set_stats("strength",25);
    set_stats("dexterity",22);
    set_stats("constitution",22);
     set("aggressive", 0);
     set_property("full attacks",1);
    set_mob_magic_resistance("average");
    set_alignment(1);
    set_exp(10000);
    set_emotes(5,({
    "The guard paces from one side of the gate to the other.",
    "The guard sharpens his claymore against the wall.
\n %^YELLOW%^Sparks fly everywhere!",
    "The guard nods to you.",
    "The guard watches your actions closely.",
   "The guard looks with great attentiveness at something happening behind you.",
   "The guard leans his heavy sword over his shoulder.",
   "The guard looks you over.",
   "The guard looks at the sky.",
   "The guard leans against the gate.",
   "The guard starts polishing his claymore.",
   "The guard stands perfectly still and rigid for a moment.",
   "The guard looks at his compatriot.",
    }),0);
    new("/d/attaya/seneca/obj/bronzemesh.c")->move(TO);
    command("wear armour");
    new("/d/attaya/seneca/obj/claymore.c")->move(TO);
    command("wield sword in right hand and left hand");
    set_funcs(({"fire"}));
    set_func_chance(20);
}
void die(object ob) {
    message("environment",
    "%^RED%^The guard coughs up blood and drops to his knees."
    ,environment(TO));
    :: die(TO);
}
void fire(object targ) {
    string dam;
    if("daemon/saving_d"->saving_throw(targ,"impale")) {
	dam="hurts";
    } else {
	dam="impales";
    }
    tell_object(targ,
       "%^BOLD%^%^MAGENTA%^ The guard charges towards you and "+dam+ " you with his claymore!"
    );
    tell_room(environment(targ),
        "%^MAGENTA%^The guard charges with his claymore and "
	"impales "+targ->query_cap_name()+"!%^RESET%^"
    ,targ);
    if(dam=="impales") {
	targ->do_damage("torso",roll_dice(6,6));
	tell_object(targ,
     "%^RED%^You feel intense pain and your abillity to fight has been comprimised!\n"
	);
    } else {
	targ->do_damage("torso",roll_dice(4,6));
    }
    return 1;
}
