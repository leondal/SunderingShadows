#include <std.h>;

inherit VENDOR;

void create() {
   ::create();
   set_name("Veric Gorsh");
   set_id(({ "Veric", "veric", "veric gorsh", "dealer", "metal dealer", "vendor"}) );
   set_short("Veric Gorsh, seller of fine woods and metals");
   set_level(19);
   set_long("Veric Gorsh looks you up and down with beady, yellow eyes, and "
	"grins at you with yellow teeth which look to have been stained and "
	"broken from lack of care and many fights.  He looks to take after "
	"his human side more than the orc, but his nose is squat and his "
	"greasy, scraggly black hair falls around his shoulders in an "
	"unkempt manner.  He is very muscular and well built, with many "
	"many scars visible.  He seems to rub his hands together nearly "
	"incessantly, stopping only to help a customer.  Behind him is a "
	"cart stocked messily with wood and metal of various qualities.  "
	"His eyes have a dull hue to them, much like the rest of his "
	"demeanor, only brightening when a possible customer approaches.  "
	"<help shop>"
      );
  set_gender("male");
  set_alignment(6);
  set_race("half-orc");
  set_body_type("human");
  set_storage_room("/d/npc/storage/veric_storage");
  set_hd(19,3);
  set_exp(100);
  set_speed(100);
  set_items_allowed("material");
}

