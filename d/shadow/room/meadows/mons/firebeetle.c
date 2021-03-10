#include <std.h>
//Raising the exp per Ares order to increase leveling speed. Dinji 8/14/07
#include "../meadow.h"
inherit WEAPONLESS;

void create()
{
  ::create();
  set_name("fire beetle");
  set_id(({"beetle","fire beetle","giant fire beetle","monster"}));
  set_short("A giant fire beetle");
  set_long("A large, black beetle moves swiftly through the grasslands "+
   "around you.  Its plating is a dark, matte black and it looks like "+
	"it would be hard to see the beetle at night...if it wasn't for "+
	"the fact that its eyes and abdomen gave off a steady, %^RED%^red "+
   "glow%^CYAN%^.  A huge pair of mandibles jut out from under its "+
   "head and look out of proportion to the rest of its body.");
  set_hd(9,5);
  set_race("beetle");
  set_body_type("insectoid");
  set_gender("neuter");
  set_size(1);
  set("aggressive",15);
  set_property("swarm",1);
  //set_level(9);
  //set_class("fighter");
  //set_mlevel("fighter",9);
  set_hp(random(15)+70);
   //set_exp(300);
   set_new_exp(6,"normal");
  set_damage(1,6);
  set_attacks_num(2);
  set_base_damage_type("piercing");
  add_limb("mandibles","head",0,0,0);
  set_attack_limbs(({"mandibles"}));
  set_ac(5);
  set_alignment(5);
  add_money("silver",random(300)+50);
  set_emotes(4,({
   "%^RED%^The fire beetle stares at you with eyes that seem "+
   "to give off a red glow.%^RESET%^",
	"%^CYAN%^The beetle makes a clanking noise as it opens and "+
	"shuts its huge mandibles.%^RESET%^"
  }),0);
  set_emotes(4,({
	"%^RED%^The fire beetle stares at you with eyes that seem "+
   "to give off a red glow.%^RESET%^",
	"%^CYAN%^The beetle makes a clanking noise as it opens and "+
	"shuts its huge mandibles.%^RESET%^"
  }),1);
   set_max_level(10);
}

void die(object obj)
{
   switch(random(15)) {
      case 0..10:
         break;
      case 11..13:
         new(OBJ+"gland")->move(TO);
         break;
      case 14:
         new(OBJ+"gland")->move(TO);
         new(OBJ+"gland")->move(TO);
         break;
      case 15:
         new(OBJ+"gland")->move(TO);
         new(OBJ+"gland")->move(TO);
         new(OBJ+"gland")->move(TO);
         break;
   }
   ::die(obj);
}
