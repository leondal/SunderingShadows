#include <std.h>;

inherit VENDOR;

void create() {
   ::create();
   set_name("Glarrina");
   set_id( ({ "Glarrina", "glarrina", "cloth", "cloth seller"}) );
   set_short("Glarrina, seller of fine cloths");
   set_long("Glarrina is obviously a merchant and appears ready to assist you "
	"in your purchase of any of the cloth she has in her possession.  She "
	"pulls a small cart behind her that is loaded with all kinds of "
	"cloth.  She is hunched over and appears weary from her travels.  "
	"Her hands are scarred and her fingers calloused.  Her gaze is dark "
	"as she give you a sideways glance, never looking directly into your "
	"eyes.  She rolls her hands together over and over, perhaps a nervous "
	"habit or perhaps from eagerly awaiting and anticipating a transaction."
      );
   set_gender("female");
   set_alignment(6);
   set_race("human");
   set_level(19);
   set_storage_room("/d/npc/storage/glarrina_storage");
   set_hd(19,3);
   set_exp(10);
   set_items_allowed("material");
   set_speed(100);
}

