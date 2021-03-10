#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("pirate");
    set_id(({"emistil","pirate","elven pirate"}));
    set_short("Emistil Darkeyes");
    set_long("
Emistil is the most mysterious of the pirate band.  His manner can best be
described as cheerful, even when he's killing an enemy.  He's quite content
to take orders rather than give them, and he admires Malvira for her sheer
capriciousness.");
    set_race("elf");
    set_gender("male");
    set_hd(12,4);
    set_size(2);
    set_overall_ac(2);
    set_class("mage");
    set_guild_level("mage",10);
    set_max_hp(90);
    set_hp(90);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("no bump",1);
    set_stats("strength",13);
    set_stats("dexterity",14);
    set_stats("constitution",16);
    set_stats("intelligence", 19);
    set_mob_magic_resistance("average");
    set_exp(1200);
    set_alignment(9);
    set("aggressive","aggfunc");
    new("/d/dragon/obj/weapon/shsword")->move_object(this_object());
    command("wield shortsword in right hand");
    new("/d/dragon/obj/armor/scale")->move_object(this_object());
    command("wear scale");
    add_money("gold", 250);
}

void aggfunc() {
  int AL = this_player()->query_alignment();
  if((AL == 1) || (AL == 4) || (AL == 7)) {
    force_me("say How did ya wonder upon the deck of our lovely boat?");
    this_player()->kill_ob(this_object(), 0);
  } else {
    force_me("smile");
    force_me("say What's ya want "+this_player()->query_race()+"!");
  }
}

