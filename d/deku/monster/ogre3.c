#include <std.h>
inherit "/d/deku/inherits/ogre";

create() {
  ::create();
  set_id(({"ogre","dekuogre","ogre guard","drunken ogre","drunken ogre guard", "guard"}));
  set("short", "Drunken Ogre guard");
  set("long","The foul smell of sweat and ale assults your nose as you get within "
	"yards of this creature.  His sickly violet skin almost seems yellowed, "
	"perhaps from a life of being intoxicated.  His purple eyes look bloodshot, "
	"the red standing out markedly against his violet skin.  A plethora of "
	"warts dot his face and travel down below his hide armor.  Limp strands "
	"of filthy brown hair cling to his sweaty skin.");
  set("aggressive",5);
  set_level(6);
  set_exp(370);
  set_hp(60);
  set_max_hp(query_hp(TO));
    new("/d/common/obj/weapon/club")->move(TO);
    command("wield club");
  add_money("gold",random(50)+20);
}
