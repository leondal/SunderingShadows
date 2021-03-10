inherit "/std/armour";

void create() 
{
  ::create();
  set_name("studded");
  set("id",({"studded","armor","studded armor","lstudded"}));
  set("short","A large suit of studded leather armor");
  set("long","This armor is made from leather (not hardened "+
	"like regular leather armor) reinforced with close-set "+
	"metal rivets. Similar to the brigadine armor, except "+
	"the spacing is wider.");
  set_weight(30);
  set("value", 30);
  set_type("leather");
  set_size(3);
  set_limbs(({"torso"}));
  set_ac(3);
}
