// Stoker, an unnatural being of fire
// thorn@shadowgate
// 26 June 2000
// Dark Tower Level 3 (Great Walls of Fire!)
// stoker.c

#include <std.h>

inherit WEAPONLESS;

int okdie = 0;

void create(){
   int num;

   ::create();
   set_name("Stoker");
   set_id(({"stoker","fire elemental","elemental",}));
   set_short("Stoker");
   set_alignment(9);
   set_long(
@PEG
  %^BOLD%^%^RED%^Stoker looks like a Greater Fire Elemental, but is much more.
Originally, a wizard who crossed Thanatos, Stoker was magically
merged with a Greater Fire Elemental in an excruciatingly painful
process.  If you look at him now, you can not only see the flames,
but also a the shadow of a charred human form beneath.
PEG
   );
   set_hd(35,1);
   set_hp(280);
   set_exp(30000);
   set_stats("strength",18);
   set_stats("intelligence",17);
   set_stats("dexterity",6);
   set_race("elemental");
   add_limb("torso","torso",50,0,2);
   add_limb("right flame","torso",50,0,2);
   add_limb("left flame","torso",50,0,2);
   add_limb("base","torso",50,0,2);
   set_attack_limbs(({"left flame", "right flame"}));
   set_damage(3,10);
   set_attacks_num(2);
   set_base_damage_type("bludgeoning");
   set_gender("sexless");
   set_overall_ac(-3);
   set_property("weapon resistance", 4);
   set_property("no stab", 1);
   set_property("no paralyze", 1);
   set_guild_level("fighter", 25);
   set_guild_level("mage", 35);
   set_spell_chance(50);
   set_spells(({
     "scorcher",
     "burning hands",
     "fireball",
     "magic missile",
	 "wall of fire"
   }));
   set_mob_magic_resistance("average");
   
}

void init() {
    ::init();
    add_action("no_rush","rush");
}

int no_rush(string str) {
    object targ;
    targ = this_player();

    tell_room(environment(targ),
      "%^RED%^BOLD%^"+this_player()->query_cap_name()+" rushes into Stoker, and succeeds only in burning himself!",
      ({ targ }));
	tell_object(targ, "%^RED%^BOLD%^As you try to rush Stoker, you run right through his flames, causing you to be burned!");
    targ->cause_typed_damage(targ, "torso", roll_dice(2, 6), "fire");
    return 1;
}

void die(object ob) {
	if(okdie == 2) {
      message("environment",
        "%^YELLOW%^BOLD%^Stoker shrieks as he loses control of the %^RED%^flames%^YELLOW%^!\n"
        "He falls to his knees as the flames consume the remainder of his body!\n"
        "Only a charred, smoking skeleton remains."
        ,environment(TO));
      TO->set_name("Charred skeleton");
      ::die(ob);
	}
        okdie++;
    message("environment",
      "%^YELLOW%^BOLD%^Instead of dying, Stoker partially reforms his body from the %^RED%^flames%^YELLOW%^!\n"
      "You feel a deep dread fill your insides....\n"
      ,environment(TO));
    TO->set_hp(140);
	return;
}



