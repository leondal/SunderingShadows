//storage room for Angus in new Seneca
//~Circe~ 12/11/07
#include <std.h>
#include "../seneca.h"

inherit "/d/common/inherit/armor_storage_full";

void create(){
    ::create();
    set_property("no teleport",1);
    set_light(3);
    set_indoors(1);
    set_name("Seneca Armor Storage");
    set_short("Seneca Armor Storage");
    set_long("This is a storage room filled with all sorts of armor.  "+
       "You shouldn't be here!");
    set_exits(([
       "up" : ROOMS"armor"
    ]));
}

void reset(){
  ::reset();
  if(!present("monk robe") && !random(3))
    new(OBJ"monk_robe")->move(TO);
  if(!present("bronze chestguard") && !random(3))
    new(OBJ"oriaum_bplate")->move(TO);
  if(!present("oriaum helm") && !random(3))
    new(OBJ"oriaum_helm")->move(TO);
  if(!present("horned helm") && !random(2))
    new(OBJ"horned_helm")->move(TO);
/*TO MAKE:
Scale Mail of Cartahenan Army
Maybe 2 or 3 other items
Enchanted stuffs for reequipping - save until faction goes in?
New descriptions for some pieces
*/
}
