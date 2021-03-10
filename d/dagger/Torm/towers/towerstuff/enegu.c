#include <std.h>
#include "/d/dagger/Torm/tormdefs.h"
#include "/d/dagger/Torm/tormdefs.h"
inherit MONSTER;
  int done;
void stab(object targ);
void create() {
    object ob;
    ::create();
    set_name("Enegu, the Butcher");
    set_id(({"butcher","enegu","enegu the butcher","cook",
                    }));
    set_short("Enegu, the Butcher");

    set_long(
        "  A blazing light fills the eyes of this fiend."
        "  Tall and thin beyond belief, Enegu looks as if his life has been sucked from his scarecrows frame."
        "  A tarnished dagger is in his hand and he constantly toys with it as he snickers and grins as he looks around the room."
        "  His eyes settle on you and you realize that there is no sanity behind those fanatical eyes and that your life is forfeit to this monster."
        );
    add_search_path("/cmds/assassin");
    set_class("thief");
    set_mlevel("thief",40);
    set_guild_level("thief",40);
    set_race("human");
    set_class("thief");
    set_level(40);
    set_gender("male");
    set_hd(40,6);
    set_size(2);
    set_overall_ac(-10);
    set_guild_level("thief",40);
    set_max_hp(400);
    set_hp(400);
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("no_bump",1);
    set_property("no bows",1);
    set_property("no rush",1);
    set_stats("strength",22);
    set_stats("dexterity",18);
    set_stats("constitution",17);
    set_thief_skill("move silently",95);
    set_thief_skill("hide in shadows",95);
    add_search_path("/cmds/thief");
    set_scrambling(1);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_exp(30000);
    set_alignment(9);
    set_emotes(15, ({
            }),1);
    ob = new("/d/attaya/obj/screamer.c");
	ob->set_property("monsterweapon",1);
    ob->move(TO);
    command("wield dagger in left hand");
    ob = new(TOWS"greed.c");
    if(!random(5))
        ob->set_property("monsterweapon",1);
    ob->move(TO);
    command("wield dagger in right hand");
}
void die(object ob) {
  tell_room(
  "%^BOLD%^%^RED%^Enegu stagers back and coughs blood, the light fades from his eye and his daggers clatter as he drops to the floor."
      "%^RESET%^"
  );
  ::die(ob);
}
int aggfunc() {
    if(wizardp(TP)) return 1;
  if(!(done)){
  done=1;
 command("say What??  You're not a student here!!!.  You're after my life aren't you?");
  command("say You'll die like everyone else who's tried!");
  command("stab "+TP->query_name());
  }
  command("crit "+TP->query_name());
}
void set_paralyzed(int time,string message){return 1;}
void set_tripped(int time, string message){return 1;}
void set_bound(int time, string message){return 1;}


