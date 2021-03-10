#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/std/monster";

create(){
  ::create();
    set_name("Umzuzalil");
    set_id(({"umzuzalil","torm vizier","vizier","Torm vizier","Umzuzalil" }));
    set_short("Umzuzalil, Torm Vizier" );
    set_long(
    "  This tall dark eyed human views you with poorly disguised hate."
    "  His rich robes are done up tightly to his neck and he holds a gold sceptre in his hands."
    "  Under his robes his body ripples with muscle and there is a dark intelligence lurking behind those cold black eyes."
    "  You suddenly look away, a chill running down your spine, and you are sure that few would dare cross his will in this city."
    );
    set_race("human");
    set_gender("male");
    set_hd(40,1);
    set_max_hp(666);
    set_hp(666);
    set_class("mage");
    set_class("cleric");
    set_mlevel("mage",40);
    set_mlevel("cleric",40);
    set_guild_level("mage",40);
    set_guild_level("cleric",40);
    set_property("no animate",1);
    set_property("no bows",1);
    set_property("no dominate",1);
    set_mob_magic_resistance("average");
    set_property("full attacks",1);
    set_property("no steal",1);
    set_property("no death",1);
    set_overall_ac(-10);
    set_spell_chance(50);
    set_spells(({"meteor swarm","cone of cold",
    "scorcher","lower resistance","fireball","dispel magic" }));
    set_size(2);
    set_money("platinum",random(2000));
    set_exp(35000);
    set_stats("strength",19);
    new(OBJ+"masterkey.c")->move(TO);
    new(OBJ+"magistrobe.c")->move(TO);
    new(OBJ+"rodrule.c")->move(TO);
    present("key",TO)->set_property("monsterweapon",1);
    present("robe",TO)->set_property("monsterweapon",1);
    present("rod",TO)->set_property("monsterweapon",1);
    command("wield rod");
    command("wearall");
}

void heart_beat(){
  ::heart_beat();
  if(!objectp(TO) || !objectp(ETO)) return;
  if(TO->query_hp() < 500){
  TO->add_hp(10);
  }
  if(TO->query_property("magic resistance") < 50) {
  TO->set_mob_magic_resistance("average");
  }
    if(query_paralyzed()) {
        tell_room(ETO,"%^RED%^The vizier chants a quick phrase "+
        "to counter his own paralyzation!%^RESET%^");
        TO->set_paralyzed(0);
        return;
    }
}
