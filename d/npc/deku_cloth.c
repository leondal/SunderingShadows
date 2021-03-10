#include <std.h>;

inherit VENDOR;

void make_me() {
  switch(random(2)) {
    case 0:
      set_gender("female");
      set_race("half-elf");
      set_name("Silenna Moonbrook");
      set_id(({ "silenna", "moonbrook", "silenna moonbrook",
      "Moonbrook","Silenna","Moonbrook","Silenna Moonbrook",
      "cloth dealer","cloth saler"}));
      set_short("Silenna Moonbrook, wandering cloth trader");
      set_long("This lady is the obvious mixture of an elven "+
      "and human bloodline.  Her facial features are well "+
      "defined, her small nose sharp, her cheekbones high, and "+
      "her ears slightly pointed.  Her skin is slightly tanned "+
      "and accented by her long auburn hair and deep green "+
      "eyes.  Her body is shapely and she stands near five feet "+
      "tall.  Strangely, she seems out of place here, as she "+
      "carries bolts of fabric in sacks, a backpack, and some "+
      "draped over her arms."+
      " <help shop>");
      break;
    case 1:
      set_gender("male");
      set_race("human");
      set_name("Hydwen Thorngate");
      set_id(({"hydwen","thorngate","hydwen thorngate",
      "Hydwen","Thorngate","Hydwen Thorngate","cloth dealer",
      "dealer","cloth saler"}));
      set_short("Hydwen Thorngate, expert fabric weaver");
      set_long("It is obvious that this man enjoys some of the "+
      "more uncommon luxuries of life.  His skin is light and smooth, "+
      "barely showing any signs of aging.  His hair is a long "+
      "black that gives off a continual wet shine.  The bangs "+
      "from his hair fall down and hang casually in front of "+
      "his light hazel colored eyes.  His body is frail and "+
      "thin.  He carries several bolts of cloth with him, "+
      "mostly carrying it in sacks or other containers but "+
      "occassionally draping some of it over his arms in proud "+
      "display.  <help shop>");
      break;
    }

}
void create() {
 ::create();
  make_me();
  set_alignment(2);
  set_storage_room("/d/npc/storage/deku_cloth_storage");
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

