inherit "/std/armour";

void create()
{
  ::create();
  set_name("studded");
  set("id",({"studded","armor","studded armor","leather"}));
  set("short", "Finely crafted studded leather armor");
  set("long","This suit of armor has been well kept over "+
	"the years.  The leather is looks to have been oiled "+
	"frequently, and the metal rivets must have been "+
	"polished recently.  The armor seems larger than "+
	"normal, certainly too large for a human or elf.");
  set_weight(25);
  set("value", 40);
  set_type("leather");
  set_limbs(({"torso"}));
  set_size(3);
  set_ac(3);
  set_property("enchantment",1);
}