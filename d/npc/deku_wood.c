#include <std.h>;

inherit VENDOR;

void make_me() {
  switch(random(2)) {
    case 0:
      set_name("Chalilo Anwyn");
      set_id(({ "chalilo", "anwyn", "chalilo anwyn",
      "Chalilo","Anwyn","Chalilo Anwyn","dealer","wood dealer",
      "woodsman"}));
      set_short("Chalilo Anwyn, woodsman");
      set_long("This massive creature stands close to ten feet "+
      "tall.  His skin is a dark brown with hints of forest "+
      "green, which accents his dark green eyes well.  His entire "+
      "body is void of any hair and the top of his bald head "+
      "has been painted with a forest green substance.  "+
      "He wears a forest green cloak that looks "+
      "like it has been worn for far too long.  He carries several "+
      "different types of wood with him, all of it in sacks "+
      "or the large pack he carries over his back."+
      "<help shop>");
      set_race("voadkyn");
      break;
    case 1:
      set_name("Darian Hylnorn");
      set_id(({"darian","hylnorn","Darian","Hylnorn",
      "darian hylnorn","Darian Hylnorn","dealer",
      "wood dealer","woodsman","trader"}));
      set_short("Darian Hylnorn, dealer of fine woods");
      set_long("This man is quite obviously alert, he is "+
      "constantly glancing around in expectation.  "+
      "He appears very old and quite possibly may have "+
      "simply seen too many winters.  His old, wrinkled flesh, "+
      "is a slightly tanned color.  His eyes are underlined with "+
      "heavy dark tones, suggesting that on top of being old "+
      "he is worn out physically.  Flowing gray hair falls "+
      "down from the top of his head and is streaked with "+
      "lines of light brown.  Despite all, this man stands "+
      "nearly six feet tall, and contrary to what you would "+
      "expect, is not stooped in the least.  There appears "+
      "to be quite a bit of life still left in him.  He carries "+
      "several types of wood with him and sells it to "+
      "anyone he can interest.  <help shop>");
      set_race("human");
      break;
    }

}
void create() {
 ::create();
  set_gender("male");
  make_me();
  set_alignment(2);
  set_storage_room("/d/npc/storage/deku_wood_storage");
  set_hd(14 + random(6),3);
  set_hp(query_hd() * 12 + random(21));
  set_exp(query_max_hp() * 5);
  set_stats("strength",17);
  set_stats("dexterity",14);
  set_stats("constitution",12);
  set_stats("wisdom",19);
  set_stats("intelligence",12);
  set_stats("charisma",14);
  set_speed(100);
  set_items_allowed("material");
  set_nogo( ({ "/d/deku/open/entrance", "/d/deku/keep/rooms/draw", "/d/deku/open/path", "/d/deku/open/stair1", "/d/deku/fortress/foyer", "/d/deku/open/road3", "/d/deku/open/plains/cave01" }) );
}