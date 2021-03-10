#include <std.h>
#include "../keep.h"
inherit MONSTER;

void create()
{
  ::create();
  set_name("xvart");
  set_id(({"xvart"}));
  set_short("A xvart");
  set_long("%^RESET%^A small, %^BOLD%^%^BLUE%^bright blue creature %^RESET%^"+
	"stands before you, staring "+
	"at you with his %^ORANGE%^orange eyes.  %^RESET%^"+
	"His head looks like it is far too "+
	"large for his body, and his large ears and nose almost seem "+
	"comical.  His greasy, wirey black hair sticks almost straight "+
	"up from his head.  His small, wirey frame is clothed in what "+
   "looks like the old clothes of human children.");
  set_race("xvart");
  set_body_type("human");
  set_gender("male");
  set_size(1);
  set("aggressive",25);
  set_property("swarm",1);
  set_hd(2,1);
  set_class("fighter");
   set_mlevel("fighter",3);
  set_max_hp(30);
  set_hp(30);
   set_exp(120);
   set_max_level(3);
  set_ac(6);
  set_alignment(9);
  add_money("copper",random(1000)+100);
  add_money("silver",random(50)+20);
   add_money("gold",random(10)+2);
  new("/d/common/obj/weapon/shortsword")->move(TO);
  command("wield sword");
  set_emotes(6,({
   "Xvart screams and rambles on in his high pitched voice, he seems to "+
   "be calling for help.",
 	"The xvart wrinkles his nose and spits at your feet."
  }),1);
}
