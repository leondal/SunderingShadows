#include <std.h>
inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_name("knight");
    set_id(({"undead knight","knight","skeletal knight"}));
    set_short("Skeletal Knight of the Kinnesaruda");
    set_long(
      "This undead knight is among the proudest of the undead legions branded by Intruder.  The knights have been granted the powers that they possess through the execution of others."
    );
    set_race("undead");
    set_gender("male");
    set_hd(20,6);
    set_size(2);
    set_overall_ac(-14);
    set_class("fighter");
    set_guild_level("fighter",30);
    set_max_hp(500);
    set_hp(500);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("human");
    set_property("swarm",1);
    set_property("no_bump",1);
    set_stats("strength",22);
    set_stats("dexterity",22);
    set_stats("constitution",22);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_alignment(2);
    set_exp(21000);
    set_emotes(3,({
	"The knight paces from one side of the hallway to the other.",
	"The knight sharpens his swords against the wall.\n %^YELLOW%^Sparks fly everywhere!",
      }),0);
// making the gear monsterweapons so it's more rare and less left lying around
    ob = new("/d/attaya/obj/uarmor.c");
      if(random(3))  ob->set_property("monsterweapon",1);
      ob->move(TO);
      command("wear armour");
    ob = new("/d/attaya/obj/cursed.c");
      if(random(3))  ob->set_property("monsterweapon",1);
      ob->move(TO);
      command("wield sword in right hand");
    ob = new("/d/attaya/obj/cursed.c");
      if(random(3))  ob->set_property("monsterweapon",1);
      ob->move(TO);
    command("wield sword in left hand");
    set_funcs(({"fire"}));
    set_func_chance(20);
    if(!random(20)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("bone dust");
      ob->move(TO);
    }
      set_resistance("negative energy",20);
      set_resistance("positive energy",-20);
}

void die(object ob) {
    tell_room(TO,
      "%^BOLD%^%^MAGENTA%^The brave soul of the knight vanishes into the orifice!\n"
      "His gear glows and most of it vanishes as well.");
    :: die(ob);
}

int aggfunc() {
/* this doesn't work because aggressive functions only get called for is_player()
    string mrace=TP->query_race();
    if (mrace == "undead") {
	command("say Greetings, kindred.");
	return 1;
    } else {
*/
	if(wizardp(TP) || TP->query_true_invis()) return 1;
	TP->kill_ob(TO,0);
	command("say Foolish child...  We ruled this world before your grandparents were even born.  You cannot possibly defeat us!");
}

void fire(object targ) {
    string dam;
// poison was mis-spelled so I guess it was always failing?  *Styx*  12/1/02
   if("daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
	dam="slices";
    } else {
	dam="impales";
    }
    tell_object(targ,
      "%^BOLD%^%^MAGENTA%^ The ancient knight charges towards you and "+dam+" you with his sword!"
    );
    tell_room(environment(targ),
      "%^MAGENTA%^The ancient knight charges with his sword and "+dam+" "+targ->query_cap_name()+"!%^RESET%^"
      ,targ);
    if(dam=="impales") {
	targ->do_damage("torso",roll_dice(6,6));
	tell_object(targ,
	  "%^RED%^You feel intense pain and your ability to fight has been compromised!\n"
	);
    } else {
	targ->do_damage("torso",roll_dice(4,6));
    }
    return 1;
}
