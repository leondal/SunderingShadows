#include <std.h>

inherit "/std/monster";

void create() {
  ::create();
  set_name("displacer beast");
  set_id(({"Displacer beast","beast","displacer beast"}));
  set_race("quadruped");
  set_gender("male");
  set("short","Displacer beast");
  set("long","This vaguely puma-like creature is bluish black, its tentacles\n"+
             "are dead black, the horney edges of the tentacles are brownish\n"+
             "yellow, and its eyes glow a hellish green.");
  set_body_type("quadruped");
  set_level(6);
  set_class("fighter");
  set("aggressive", 18);
  set_size(3);
  set_alignment(5);
  set_hd(6,1);
  set_hp(52);
  set_new_exp(6, "low");
}
