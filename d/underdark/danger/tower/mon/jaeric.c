#include <std.h>
#include "../tower.h";

inherit MONSTER;

void create() {
   ::create();
   set_id(({"jaeric","elistrae","tiefling","mage","archmage","overlord"}));
   set_name("Jaeric");
   set_short("Jaeric Elistrae, the Overlord");
   set_race("tiefling");
   set_gender("female");
   set_hd(80,4);
   set_class("mage");
   set_guild_level("mage",80);
   set_alignment(3);
   set_max_hp(2457);
   set_hp(2457);
   set_overall_ac(-30);
   set_mob_magic_resistance("average");
   set_property("no bows", 1);
   set_size(2);
   set_stats("strength",20);
   set_stats("dexterity",18);
   set_stats("intelligence",25);
   set_stats("wisdom",17);
   set_stats("charisma",21);
   set_stats("constitution",14);
   