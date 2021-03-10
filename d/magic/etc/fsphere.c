// A Flaming Sphere!!  Used by the _flaming_sphere.c
// spell for wizards.
// Thorn@ShadowGate
// 6/23/95

#include <std.h>

inherit OBJECT;

object owner;

varargs int do_saving_throw(object player, string type);
int point(string str);

create() {
  ::create();
  set_name("flaming sphere");
  set_id(({ "sphere", "flaming sphere" }));
  set_short("sphere of flame");
  set_long(
@SPHERE

  This is a sphere of fire which a caster can create through the
power of magic.  If you are the caster of this spell, you can have
the sphere attack any one in the room by typing "point <target>".

SPHERE
	     );
  set_weight(1000000000);
  set_value(0);
}

get() {
  this_player()->do_damage(roll_dice(2,4));
  write("You should know better than to try and pick up a ball of fire!\n");
}

init() {
  ::init();
  add_action("point", "point");
}

void set_owner(object ob) { owner = ob; }

void set_wiz_owner(string str) {
  owner = find_player(str);
}

object query_owner() { return owner; }

int point(string str) {
  object target;

  if(TP != owner) return 0;
  target=present(str, environment(this_player()));
  if(!target) {
    notify_fail("That is not here!");
    return 0;
  }
  tell_player(TP, "You send the sphere rolling at "+capitalize(str)+".\n");
  if(!do_saving_throw(target)) {
    target->do_damage("torso", roll_dice(2,4));
    tell_object(target, "The flaming sphere hits you!!\n");
    tell_room(environment(target), "The flaming sphere hits "+
	      target->query_cap_name()+"!\n", ({ target }));
  }
  else tell_object(target, "You successfully dodge the flaming sphere!\n");
  return 1;
}

varargs int do_saving_throw(object player, string type) {
  int temp;

  if(!type) temp = "/daemon/saving_d.c"->saving_throw(player, "spell");
  else temp = "/daemon/saving_d.c"->saving_throw(player, type);
  return temp;
}

