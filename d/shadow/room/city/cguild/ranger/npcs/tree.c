#include "/d/shadow/room/city/cguild/ranger/ranger.h"
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("tree");
   set_id(({"tree","small tree","treant","young treant"}));
   set_short("%^RESET%^%^ORANGE%^A young treant%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This small treant stands guard here over the "
"passageways to the forests of the realm.  A thick cover of %^GREEN%^le%^BOLD%^"
"av%^RESET%^%^GREEN%^es %^ORANGE%^sprouts from the branches of his head and arms"
", while his body is coated in %^BOLD%^%^BLACK%^rough bark%^RESET%^%^ORANGE%^.  "
"His legs are nearly indistinguishable from the rest of him - indeed, if he "
"stood still for a while, you would mistake him for another tree!%^RESET%^");
   set_overall_ac(0);
   set_race("tree");
   add_limb("trunk","trunk",0,0,0);
   add_limb("right limb","trunk",0,0,0);
   add_limb("foliage","trunk",0,0,0);
   add_limb("root","trunk",0,0,0);
   add_limb("left limb","trunk",0,0,0);
   set_attack_limbs(({"right limb","left limb"}));
   set_attacks_num(2);
   set_max_hp(100000);
   set_hp(100000);
   set_gender("male");
   set_emotes(1, (({
      "%^MAGENTA%^The treant rumbles:%^RESET%^ This tree was dying when the sky turned black.  Adventurers used the four hearts of the elements to revive Edea and brought dawn to the endless night.",
      "%^MAGENTA%^The treant rumbles:%^RESET%^ Parnelli is a vibrant forest of magic and mystery.",
      "%^MAGENTA%^The treant rumbles:%^RESET%^ The Moonstone Vale is a serene haven in the midst of the cursed Dark forest.",
      "%^MAGENTA%^The treant rumbles:%^RESET%^ The Darkwood forest will bring you back near Shadow, north of here.",
      "%^MAGENTA%^The treant rumbles:%^RESET%^ Many elves make their homes hidden away in the cold Kilkaen forest in the far north.",
      "%^MAGENTA%^The treant rumbles:%^RESET%^ The Shadowlord forest is permeated by the monstrous beings that populate the isle of Deku.",
      "%^MAGENTA%^The treant rumbles:%^RESET%^ Even Peth forest cannot hold back the taint upon Graez, and sadly the forest is dying even now.",
      "%^MAGENTA%^The treant rumbles:%^RESET%^ Yntala is filled with all kinds of twisted beings, unleashed upon the wilds by the foolishness of wizards.",
      "%^MAGENTA%^The treant rumbles:%^RESET%^ Be wary if you choose to travel to the jungles of Attaya, for only the most powerful of the realms could survive the horrors that lurk within.",
   })), 0);
}
