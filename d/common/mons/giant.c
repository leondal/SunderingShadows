/*basic giant file - inherit and change whatever is needed.  Be sure to add treasure, weapons, and equipment, as well as adjust levels and exp if needed. */

#include <std.h>
inherit MONSTER;

void create() {
  ::create();
  set_name("giant");
  set_id(({"giant","monster"}));
  set_race("giant");
  set_gender("male");
  set_short("Giant");
  set_long("This gargantuan humanoid stands around fifteen feet tall with "+
     "broad, hulking shoulders and a mass of curly black hair.  His thick legs "+
     "look much like tree trunks, and he must weigh a few tons.  His gigantic frame "+
     "is swathed in a simple cloth tunic that reaches to his knees and is belted around "+
     "his rotund waist.  A matted beard falls tangled to his chest, and he is most "+
     "definitely in need of a bath.");
  set_level(8);
  set_ac(3);
  set("aggressive",18);
  set_size(3);
  set_body_type("human");
  set_class("fighter");
  set_alignment(6);
  set_hd(8,2);
  set_stats("strength",20);
  set_wielding_limbs(({"right hand","left hand"}));
  set_hp(85+random(20));
  set_funcs(({"hurl"}));
  set_func_chance(20);
  new("/d/deku/misc/stones")->move(TO);
}

void hurl(object targ) {
  int dam;
  int dex;
  dex = targ->query_stats("dexterity");
  if(present("stone", TO)) {
    if(dex > random(20)) {
      tell_room(environment(targ), "%^ORANGE%^The giant hurls a large "
        "stone towards "+targ->query_cap_name()+" but it misses!",targ);
      tell_object(targ, "%^ORANGE%^The giant hurls a large stone at you "
        "but you manage to dodge out of the way!");
      return 1;
    }
    tell_room(environment(targ), "%^MAGENTA%^The giant hurls a large stone towards "+targ->query_cap_name()+"!",targ);
    tell_object(targ, "%^MAGENTA%^The giant hurls a large stone at you!");
    dam = roll_dice(2,10);
    targ->do_damage("torso", dam);
    return 1;
  }
}
