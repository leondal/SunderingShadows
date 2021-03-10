#include <std.h>
#include "../darkportal.h"
inherit MONSTER;
object equipment;
void create(){
::create();
set_name("minotaur");
  set_id(({"Minotaur","minotaur","warrior","fighter"}));
set_short("Minotaur Warrior");
set_long("Before you stands a raging Minotaur half-man, half-beast. "+
"He has to huge horns comeing out of his head. His fear are cloven.  And his eys glow "+
"red.");
set_race("Minotaur");
set_gender("male");
set_alignment(9);
set_body_type("human");
set_class("fighter");
set_mlevel("fighter",25);
set_guild_level("fighter",25);
add_search_path("/cmds/fighter");
set_property("full attacks",1);
set_funcs(({"rushem","goreem"}));
set_func_chance(30);
set_stats("strength",20);
set_hd(30,1);
set_hp(300);
set_max_hp(300);

equipment = new(OBJ+"fflail.c")->move(TO);
command("wield flail in right hand");
}

void rushem(object targ){
  command("rush "+targ->query_cap_name());
}

void goreem(object targ){
  tell_object(targ, "%^BOLD%^%^RED%^The Minotaur gores you with his horns%^RESET%^");
tell_room(environment(targ), "The Minotaur sweeps his horns into "+
""+targ->query_cap_name()+" causing %^RED%^ blood %^RESET%^to spray everywhere!",targ);
  targ->do_damage("torso",50);
targ->set_paralyzed(random(10)+10,"%^CYAN%^You are in agony as you inards drip to the floor%^RESET%^");
}
