//turn undead was erroring so added hd, which also brought stats up to 25
//from all 1's so I adjusted a few back down.  *Styx*  11/23/01
#include <std.h>
inherit "std/monster";

create() {
object ob;
    ::create();
    set_name("Magus Prime");
    set_id(({"magus","magus prime","prime"}));
    set_race("undead");
    set_gender("female");
    set_short("%^BOLD%^%^MAGENTA%^Magus Prime%^RESET%^" );
    set_long("Her name is forgotten by all those in the tower.  This slender "+
        "female human is a contradiction it seems in her surroundings.  Her milky"+
        " white flesh peaks out from the suggestive garments she wears.  Her "+
        "purple leather pants are so tight that they seem like a second skin to"+
        " her legs.  A length of purple cloth cowls across her breasts, drawing "+
        "attention there.  Her dark auburn hair is pulled back in a simple tail "+
        "at the base of her neck.  Standing barefoot and wearing only a pair of "+
        "bracers, a tangible aura of arcane power radiates around her.");
      //"The Magus Prime is the teacher of magic here.  She is a learned warmage.
      //She hides beneath a dark robe and, beneath the shadows, only her mouth and chin
      //are visible.\n There is a chill in the air about her.
    set_class("mage");
    set_mlevel("mage", 60);
    set_hd(60,5);
    set_body_type("human");
    set_property("swarm",1);
    set_property("no death",1);
    set_mob_magic_resistance("average");
    set_spell_chance(100);
    set_guild_level("mage",60);
    set_stats("strength", 15);
    set_stats("wisdom", 15);
    set_stats("constitution",16);
    set_spells(({
	"greater shout",
	"lightning orb",
	"meteor swarm",
	"dispel magic",
	"powerword stun",
        "magic missile"
      }));
    set_ac(-15);
    set_alignment(6);
    set_size(2);
   set_hp(3000);
    set_sp(200);
    set_exp(34000);
   set_max_hp(3000);
   set("aggressive","aggfunc");
    add_money("silver",random(210)+400);
    add_money("gold",random(620)+500);
    new("/d/laerad/obj/bracers7.c")->move(TO);
    command("wear bracers");
   new("/d/attaya/obj/pants.c")->move(TO);
   new("/d/attaya/obj/silkdrape.c")->move(TO);
    command("wearall");
}
int aggfunc() {
        if(!TP->query_true_invis()) kill_ob(TP,1);
        call_out("spell_effect",1);
        force_me("kill "+TPQN+ "");
                return 1;
}
int spell_effect(){
   force_me("watch");
   new("/cmds/spells/b/_blink.c")->use_spell(TO,TO,60,100,"mage");
   new("/cmds/spells/s/_stoneskin.c")->use_spell(TO,TO,60,100,"mage");
  // new("/cmds/wizard/_wall_of_fire.c")->use_spell(TO,TO,60);
   //new("/cmds/wizard/_ice_storm.c")->use_spell(TO,TO,60);
   //new("/cmds/wizard/_faithful_phantom_guardians.c")->use_spell(ETO,"bats",60);
}
