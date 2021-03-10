inherit "/std/armour";

int is_metal() { return 0; }


void create()
{
    ::create();
    set_name("buckler");
    set_id(({ "shield","buckler shield", "buckler" }) );
    set_short("A buckler shield");
    set_long("This shield is made of leather, hardened in boiling oil and then "
	"shaped into an oval shield.");
    set_weight(3);
    set_value(1);
    set_type("thiefshield");
    set_limbs( ({ "right hand" }) );
    set_ac(0);
    set_armor_prof("light");
    set_block_chance(15);
    set_item_bonus("shieldMiss",15); // setting these equal to the old block chance since it's a replacement
}

