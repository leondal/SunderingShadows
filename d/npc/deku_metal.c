#include <std.h>;

inherit VENDOR;

void make_me() {
  switch(random(2)) {
    case 0:
      set_name("Dynas Gywon");
      set_id(({ "dynas", "Dynas", "dynas gywon","Dynas Gywon",
      "smith","dealer","metal dealer"}));
      set_short("Dynas Gywon, metal keeper extraodinaire");
      set_long("The human before you is a very peculiar individual.  "+
      "He keeps his black hair long and in two separate braids.  "+
      "His soft blue eyes always carry a faraway look, "+
      "suggesting that he's never quite at home.  His skin is "+
      "tanned and calloused, a strange combination for this "+
      "man.  If not for the metal that he carries, in sacks "+
      "and a backpack, then this man could very well appear to be some "+
      "sort of a philospher.  "+
      "<help shop>");
      break;
    case 1:
      set_name("Varn Andrella");
      set_size(3);
      set_id(({"varn","andrella","Varn","Andrella",
      "varn andrella","Varn Andrella","dealer","metal dealer"}));
      set_short("Varn Andrella, experienced metal dealer");
      set_long("At first glance you realize this man is "+
      "enormous.  He is overly tall and his frame very large.  "+
      "His body is well toned and bulges in almost every "+
      "spot with muscles.  His head has been shaved and "+
      "red tattooes have been carefully written onto it.  "+
      "His eyes are a strange green hue and very intense, "+
      "almost piercing to anyone that looks into them.  "+
      "He carries metals in various sacks and yet still doesn't "+
      "appear to grow faint or weary in the least.  "+
      "<help shop>");
      break;
    }

}
void create() {
 ::create();
  set_gender("male");
  make_me();
  set_alignment(2);
  set_race("human");
  set_storage_room("/d/npc/storage/deku_metal_storage");
  set_hd(14 + random(6),3);
  set_hp(query_hd() * 12 + random(21));
  set_exp(query_max_hp() * 5);
  set_stats("strength",17);
  set_stats("dexterity",14);
  set_stats("constitution",12);
  set_stats("wisdom",16);
  set_stats("intelligence",12);
  set_stats("charisma",14);
  set_speed(100);
  set_items_allowed("material");
  set_nogo( ({ "/d/deku/open/entrance", "/d/deku/keep/rooms/draw", "/d/deku/open/path", "/d/deku/open/stair1", "/d/deku/fortress/foyer", "/d/deku/open/road3", "/d/deku/open/plains/cave01" }) );
}

