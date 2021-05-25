#include <std.h>
inherit MONSTER;

void create() {
   ::create();
   	add_attack_bonus(7);
	add_damage_bonus(7);
   set_nogo(({"/d/shadow/room/pass/pass6","/d/shadow/room/forest/owagon31","/d/shadow/room/forest/long_pond"}));
}

int is_beastrace(object player) {
	string mrace, srace;
      if(!userp(player)) return 0;
      if(player->query_property("shapeshifted")) return 0; // beasties run around all the time, probably shouldn't make them worry. N, 1/14.
      mrace = (string)player->query_race();
      srace = (string)player->query("subrace");
	if(mrace == "goblin" || mrace == "orc" || mrace == "drow" || mrace == "hobgoblin" || mrace == "bugbear" || mrace == "yuan-ti" ||
   mrace == "gnoll" || mrace == "ogre-mage" || mrace == "kobold" || mrace == "half-orc" || mrace == "ogre" || mrace == "minotaur" ||
        mrace == "half-drow" || mrace == "half-ogre" || (mrace == "dwarf" && srace == "gray dwarf"))
          return 1;
      return 0;
}

int is_surfacerace(object player) {
	string mrace, srace;
      if(!userp(player)) return 0;
      if(player->query_property("shapeshifted")) return 0; // beasties run around all the time, probably shouldn't make them worry. N, 1/14.
      mrace = (string)player->query_race();
      srace = (string)player->query("subrace");
        if((mrace == "dwarf" && srace != "gray dwarf") || mrace == "elf" || mrace == "half-elf" || 
        mrace == "gnome" || mrace == "beastman" || mrace == "voadkyn" || mrace == "halfling" || mrace == "wemic" || 
        mrace == "firbolg" || mrace == "centaur")
          return 1;
      return 0;
}

int is_foerace(object player) {
	string mrace;
      if(!userp(player)) return 0;
      if(player->query_property("shapeshifted")) return 0; // beasties run around all the time, probably shouldn't make them worry. N, 1/14.
      mrace = (string)player->query_race();
	if(mrace == "dwarf" || mrace == "elf" || mrace == "half-elf" || mrace == "gnome" || mrace == "centaur" || 
        mrace == "beastman" || mrace == "voadkyn" || mrace == "halfling" || mrace == "wemic" || mrace == "firbolg")
          return 1;
      return 0;
}

int is_friendrace(object player) {
	string mrace, srace;
      if(!userp(player)) return 0;
      if(player->query_property("shapeshifted")) return 0; // beasties run around all the time, probably shouldn't make them worry. N, 1/14.
      mrace = (string)player->query_race();
      srace = (string)player->query("subrace");
      if(mrace == "goblin" || mrace == "orc" || mrace == "drow" || mrace == "troll" || mrace == "hobgoblin" || mrace == "bugbear" || mrace == "minotaur" || mrace == "yuan-ti"||
        mrace == "gnoll" || mrace == "ogre-mage" || mrace == "kobold" || mrace == "half-orc" || mrace == "ogre" || 
        mrace == "half-drow" || mrace == "half-ogre" || mrace == "human" || (mrace == "dwarf" && srace == "gray dwarf"))
          return 1;
      return 0;
}
