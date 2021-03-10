#include <std.h>
#include "../keep.h"
inherit MONSTER;

void create()
{
  object ob;
  ::create();
  set_name("xvart shaman");
  set_id(({"xvart","xvart shaman","shaman"}));
  set_short("A xvart shaman");
  set_long(
  "%^BOLD%^%^BLUE%^The xvart shaman looks like others of her kind with"+
  " bright blue skin and %^RESET%^%^ORANGE%^orange eyes%^BOLD%^%^BLUE%^"+
  " that stare at you. She is wearing a %^RESET%^%^BLUE%^dark blue robe%^BOLD%^"+
  " and holding a %^WHITE%^bone white staff%^BLUE%^ that she shakes every"+
  " now and then. There is a dangerous and evil aura about her."
  );
  set_race("xvart");
  set_body_type("human");
  set_gender("female");
  set_size(1);
  set("aggressive",25);
  set_property("swarm",1);
  set_level(3);
  set_class("mage");
  set_mlevel("mage",3);
  set_guild_level("mage", 3);
  set_stats("intelligence",17);
  set_hp(70);
   set_exp(1000);
   set_max_level(4);
  set_ac(5);
  set_alignment(9);
  new(OBJ2+"srobe")->move(TO);
  command("wear robe");
  new(OBJ2+"sstaff")->move(TO);
  command("wield staff");
  ob=new("/d/magic/scroll");
  ob->set_spell(2);
  ob->move(TO);
  add_money("gold",random(20)+5);
  add_money("silver",random(500)+5);
  add_money("copper",random(5000)+500);
//  set_funcs(({"spells"}));
//  set_func_chance(70);
  set_spells(({ "magic missile", "magic missile","magic missile","magic missile","burning hands" }));
//scorcher seems to be way too powerful even from a 3rd level caster
//so removing it ~Circe~ 6/2/08
  set_spell_chance(40);
  set_emotes(6,({
	"The xvart shaman chants a few low syllables.",
 	"%^YELLOW%^The xvart shaman throws something into the air, and then"+
   " screams and points at you!%^RESET%^"
  }),1);
}
/* changing to use spell function, let it cast at its mage level to be more reasonable for the area; adjusting frequency by how often the spell is listed.  *Styx*  11/5/04
void spells(object targ)
{
  switch(random(100))
  {
    case 0..33:
	new("/cmds/wizard/_scorcher")->use_spell(TO,targ,7);
	break;
    case 34..66:
	new("/cmds/wizard/_burning_hands")->use_spell(TO,targ,7);
	break;
    case 67..99:
	new("/cmds/wizard/_magic_missile")->use_spell(TO,targ,7);
	break;
  }
}
*/