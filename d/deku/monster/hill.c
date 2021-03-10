#include "/d/common/common.h"
#include <std.h>

inherit "/std/monster";

create() {
  ::create();
  set_name("Hill giant");
  set_id(({"giant","boris","hill","hill giant"}));
  set_race("giant");
  set_gender("male");
  set_short("Boris, A giant wearing a bloody and mangled hide");

  /*set_long("Boris is a hill giant, rather crude and very large but not "
     "quite as ugly or smelly as an ogre.  His arms and legs are massively "
     "muscled and his scraps of clothing and armor serve to make him look "
     "even larger.  He is a real brute and loyal to the hag, Vexia.  He "
     "looks like he would be very efficient at carrying out her wishes.");*/

  set_long("%^RED%^This massive creature stands over ten feet high, "+
  "his body thick and muscular.  His flesh is a deep brown with a "+
  "hint of red that is complimented by his black hair and even "+
  "blacker eyes.  The musclar arms of this creature are long, "+
  "abnormally so, giving him a very long reach.  He is slightly "+
  "stooped because of the powerful muscles in his upper "+
  "back.  The upper part of his body is concealed beneath a "+
  "mangled and bloodied hide with a thick black fur still attached."+
  "%^RESET%^");  

  set("aggressive",18);
  set_size(3);
  set_body_type("human");
  set_alignment(8);
  set_hd(15 + random(3),2);
  set_stats("strength",21);
  set_stats("charisma", 10);
  set_stats("wisdom", 9);
  set_stats("dexterity", 10);
  set_stats("intelligence",9);
  set_stats("constitution",19);
  set_hp((query_hd() * 8) + random(49));
  RANDGEAR->arm_me(TO, "edgedl", 80, 1);
  add_money("gold", random(500));
  set_exp(query_max_hp() * 15);
}
