//storage room for weaponsmith in new Seneca
//~Circe~ 1/19/08
#include <std.h>
#include "../seneca.h"

inherit "/d/common/inherit/wpn_storage_full";

void create(){
    ::create();
    set_property("no teleport",1);
    set_light(3);
    set_indoors(1);
    set_name("Seneca Weapon Storage");
    set_short("Seneca Weapon Storage");
    set_long("This is a storage room filled with all sorts of "+
       "weapons.  You shouldn't be here!");
    set_exits(([
       "up" : ROOMS"weapon"
    ]));
}

void reset(){
  ::reset();
  if(!present("special two-handed bastard sword") && !random(2))
    new(OBJ"ench_bastard_two")->move(TO);
  if(!present("special battle axe") && !random(2))
    new(OBJ"ench_battle_axe")->move(TO);
  if(!present("special claw") && !random(2))
    new(OBJ"ench_claw")->move(TO);
  if(!present("special dagger") && !random(2))
    new(OBJ"ench_dagger")->move(TO);
  if(!present("special flail") && !random(2))
    new(OBJ"ench_flail")->move(TO);
  if(!present("special lance") && !random(2))
    new(OBJ"ench_lance")->move(TO);
  if(!present("special longsword") && !random(2))
    new(OBJ"ench_longsword")->move(TO);
  if(!present("special mace") && !random(2))
    new(OBJ"ench_mace")->move(TO);
  if(!present("special staff") && !random(2))
    new(OBJ"ench_mstaff")->move(TO);
  if(!present("special rapier") && !random(2))
    new(OBJ"ench_rapier")->move(TO);
  if(!present("special short sword") && !random(2))
    new(OBJ"ench_shortsword")->move(TO);
  if(!present("special warhammer") && !random(2))
    new(OBJ"ench_warhammer")->move(TO);
  if(!present("special whip") && !random(2))
    new(OBJ"ench_whip")->move(TO);
}
