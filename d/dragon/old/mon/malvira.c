#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("pirate");
    set_id(({"malvira","pirate","human pirate"}));
    set_short("Malvira Dalant");
    set_long("
A life of hardship and ill treatment has turned this once starry-eyed girl
into a ruthless, serpent-hearted pirate.  Malvira Dalant is treacherous,
foul-tempered and sadistic.");
    set_race("human");
    set_gender("female");
    set_hd(10,4);
    set_size(2);
    set_overall_ac(2);
    set_class("fighter");
    set_guild_level("fighter",10);
    set_max_hp(100);
    set_hp(110);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("no bump",1);
    set_stats("strength",16);
    set_stats("dexterity",19);
    set_stats("constitution",15);
    set_mob_magic_resistance("average");
    set_exp(1100);
    set_alignment(9);
    set("aggressive","aggfunc");
    new("/d/common/obj/weapon/dagger")->move(TO);
    command("wield dagger in right hand");
    new("/d/common/obj/weapon/dagger")->move(TO);
    command("wield dagger in left hand");
    new("/d/dragon/obj/armor/leather")->move_object(this_object());
    command("wear leather");
    add_money("gold", 50);
}

void aggfunc() {
  int AL = this_player()->query_alignment();
  if((AL == 1) || (AL == 4) || (AL == 7)) {
    force_me("say No one boards this ship and gets away with it!");
    this_player()->kill_ob(this_object(), 0);
  } else {
    force_me("bow");
    force_me("say Are you aboard, in offering your service?");
  }
}

