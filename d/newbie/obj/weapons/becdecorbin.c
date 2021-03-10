#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_id(({
  "bec de corbin","pole arm","polearm","corbin",
      }));
    set_name(
  "bec de corbin"
    );
    set_short(
  "Bec de corbin"
    );
    set_long(
  "  This long pole arm has a speartip with a crows beak shaped spike jutting from the base of the point."
  "  On the reverse side of the beak a clawed hammer gives extra weight to the weapon for the crushing blows it would need to drive it through plate armor."
  );
    set_size(3);
    set_weight(10);
    set_value(10);
    set_type(
  "piercing"
    );
    set_prof_type(
      "polearm"
    );
    set_weapon_speed(8);
    set_wc(
  1,8
    );
    set_large_wc(
  1,6
    );
    set("read","Another fine newbie product from Amidon.\n");
}
