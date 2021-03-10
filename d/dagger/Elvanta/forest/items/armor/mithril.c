inherit "/std/armour";

void create() {
::create();

set_name("mithril");
set("id", ({"mithril", "armor", "mithril armor"}) );
set("short", "A suit of mithril armor");
set("long", "This armor has been made by elves and dwarves since time began, it is the strongest armor available, however, its beauty is only surpassed by the fact that it is weightless.  The comfort of the owner has been taken into account by the makes of this phenomenal armor.");
set_weight(0);
set("value", 2000);
set_type("armor");
set_limbs( ({"torso"}) );
set_ac(8);
}
