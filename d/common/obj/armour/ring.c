inherit "/std/armour";

void create() {
    ::create();
    set_max_dex_bonus(5);
    set_armor_prof("medium");
    set_name("ringmail");
    set("id", ({ "ring","armor", "ring mail","mail" }) );
    set("short", "A suit of ring mail armor");
    set("long", 
	"This armor is an early, and less effective version of chain mail " 
	"in which metal rings are sewn directly to leather backing, instead "
	"of being interlaced. "
       );
    set_weight(16);
    set("value", 100);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    set_ac(4);
}

int is_metal() { return 1; }
