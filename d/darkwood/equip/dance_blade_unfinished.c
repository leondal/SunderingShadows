//  The blade of the Sowrd of Dancing
//  Thorn@ShadowGate
//  971005
//  Darkwood Area
//  dance_blade.c

#include <std.h>

int power, dance;
object dm;

void heart_beat();

inherit WEAPON;

void create() {
  ::create();
    set_name("blade");
    set_id(({"blade","dancer blade" }));
    set_short("\n");
    set_property("monsterweapon",1);    
    set_long(
@DARKWOOD
  This is a Sword of Dancing, a weapon of ancient power.  The 
hilt of this weapon is of an unknown alloy, wrapped in black velvet. 
The blade is extremely well balanced and made of the same magical
alloy, which is both light, but strong.  When it reaches its full 
power during a battle, it can dance and fight the opponent of its
master on command.

DARKWOOD
    );
    set_weight(15);
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

void heart_beat() {
  if(dance == 1) {
    set_heart_beat(0);
    if(!(TO->remove())) destruct(TO);
    return;
  }
}

int extra_hit(object ob) {
  int dam;
  if(power == 4) {
    remove_property("enchantment");
    power = 0;
    dance = 1;        
    return 0;
  }
  power++;
  say("The dancing blade twirls and hits its master's enemy!");
  set_property("enchantment",1);
  return 0;
}

int extra_wield() {
  if(!TP) return 0;
  if(!TP->is_monster()) if(!TO->remove()) destruct(TO);
  power = 1;
  remove_property("enchantment");
  set_property("enchantment",1);  
  set_heart_beat(1);
  return 1;
}

int extra_unwield()
{
  if(!TO->remove()) destruct(TO);
  return 1;
}

int save_me(string file)
{
  remove_property("enchantment");
  set_property("enchantment",1);
  return ::save_me(file);
}

void set_dm(object ob) {
  dm = ob;
}
