#include <std.h>
inherit TOWNSMAN;
void create() {
   ::create();
   set_nwp("healing", 15);
  set_name("Pojo");
  set_id(({"pojo","healer",}));
  set_short("Pojo, healer of Torm");
  set("aggressive", 0);
  set_level(19);
  set_long(
  "  Pojo is a diminuative human, so small and wrinkled as to almost think him a gnome."
  "  He smiles a fair bit and shuffles about his shop tidying things and making sure everyone is comfortable."
   "  He has thin white hair that barely trails down to his shoulders and a bit of a beard grows on his face.  Despite his frail appearance, you can tell he has an inner strength as you watch him move about with ease as he competently takes care of his patients."
  );
   set_alignment(5);
  set_emotes(5,({
  "Pojo tends to the wounds of the guards.",
  "Pojo looks you up and down and tsks at the scars.",
  }),0);
  set_race("human");
  add_money("gold", random(20));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_mp(random(500));
  set_stats("strength", 17);
  set_stats("intelligence", 14);
  set_stats("wisdom", 14);
  set_stats("dexterity", 18);
  set_stats("constitution", 15);
  set_exp(10);
  set_hp(149);
}
