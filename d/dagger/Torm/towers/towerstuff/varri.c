
#include <std.h>
inherit "std/monster";
#include "/d/dagger/Torm/tormdefs.h"

create() {
    ::create();
  set_name("Varri the Lich");
    set_id( ({
  "lich","varri","varri the lich"
      }) );
  set_race("undead");
  set_gender("male");
  set_short(
  "Varri, undead scholar"
    );
    set_long(
  "  Varri appears to have been out of the sun so long his skin has paled to a white that almost seems transclucent."
  "  Blue lines run across his skin, and his robe is ragged after years of use around his experiments."
  "  As you look again you realize there is no movement for breath and his eyes never blink, he's decided that living apparently takes to much of his time away from his studies so he's dealt away with that little inconvienence!"
    );
  set_class("mage");
  set_mlevel("mage",40);
    set_body_type("human");
    set_property("swarm",1);
  set_mob_magic_resistance("average");
    set_spell_chance(85);
  set_guild_level("mage",40);
    set_spells(({
	"cone of cold",
  "hideous laughter",
	"fireball",
	"meteor swarm",
	"prismatic spray",
	"powerword stun",
      }));
    set("aggressive",22);
    set_alignment(4);
    set_size( 2 );
  set_hp(400);
    set_exp(34000);
  set_max_hp(400);
    add_money("silver",random(210));
    add_money("gold",random(620));

  set_property("no bows",1);
  set_property("no rush",1);
}
void set_paralyzed(int time,string message){return 1;}
void set_bound(int time,string message){return 1;}
void set_tripped(int time,string message){return 1;}
void init(){
  ::init();
  if(!(TO)->query_stoneSkinned()){
  TO->set_stoneSkinned(40);
  }
}
