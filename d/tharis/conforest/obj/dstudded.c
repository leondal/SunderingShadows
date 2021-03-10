inherit "/std/armour";

void create()
{
  ::create();
  set_name("studded");
  set("id", ({ "studded","armor", "studded armor",
	"dirty studded","leather" }) );
  set("short", "Dirty studded leather armor");
  set("long","While it is in relatively good shape, this suit of armor "+
	"has seen better days.  The leather reeks as if it has never "+
	"been cleaned before, and the small metal rivets have rusted "+
	"over.");
    set_weight(25);
    set("value", 10);
    set_type("leather");
    set_limbs( ({ "torso" }) );
    set_ac(3);
}
