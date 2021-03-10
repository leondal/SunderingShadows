//  A Sword of Dancing
//  Thorn@ShadowGate
//  971005
//  Darkwood Area
//  dancer.c

#include <std.h>

int power, dance;

inherit WEAPON;

void create() {
  ::create();
    set_name("Sword of Dancing");
    set_id(({"sword","dancer","sword of dancing","dancing",
        "dancing sword"}));
    set_short("Sword of Dancing");
    set_long(
@DARKWOOD
..This is a Sword of Dancing, a weapon of ancient power.  The 
hilt of this weapon is of an unknown alloy, wrapped in black velvet. 
The blade is extremely well balanced and made of the same magical
alloy, which is both light, but strong.  When it reaches its full 
power during a battle, it can dance and fight the opponent of its
master on command.

DARKWOOD
    );
    set_weight(15);
    set("value",1000);
    set_wc(1,10);
    set_large_wc(3,6);
    set_size(2);
    set_type("slashing");
    set_property("enchantment",1);
    set_hit((:this_object(), "extra_hit":));
    set_wield((:this_object(), "extra_wield":));
    set_unwield((:this_object(), "extra_unwield":));
    dance = 0;
    power = 1;
}

init() {
	::init();
	add_action("dance", "dance");
	add_action("designate", "designate");
	
}

int extra_hit(object ob) {
  int dam;
	if(power == 4) {
		remove_property("enchantment");
		power = 0;
		write("The Sword of Dancing is ready to dance!");
		dance = 1;
	}
	power++;
	write("The Sword of Dancing is now +"+power+".");
  set_property("enchantment",1);
  return 0;
}

int extra_wield() {
  if(!TP) return 0;
  if((int)TP->query_level() < 10) {
    notify_fail("You may not wield such a powerful weapon!");
    return 0;
  }
  power = 1;
  remove_property("enchantment");
  set_property("enchantment",1);	
  write("%^YELLOW%^The sword slips into your grip perfectly.%^RESET%^");
  say("%^YELLOW%^"+TPQCN+" wields the Sword of Dancing.%^RESET%^");
  return 1;
}

int extra_unwield()
{
  remove_property("enchantment");
  set_property("enchantment",1);	
  dance = 0;
  power = 1;
  return 1;
}

int save_me(string file)
{
  remove_property("enchantment");
  set_property("enchantment",1);
  return ::save_me(file);
}

int dance() {
	object ob;
	if(!dance) return write("The Sword cannot dance yet");
	say("The Sword jumps out of "+TP->query_possessive()+" hand and attacks!\n");
	write("%^YELLOW%^BOLD%^The sword jumps out of your hand and attacks!");
	ob=new("/d/darkwood/equip/dance_mon");
	ob->set_master(TP);
	ob->set_orig(TO);
	TO->move(ob);
	ob->move(environment(TP));
	if(!(ob->restat())) write("The sword refuses to dance");
	return 1;
}

