//mod by Styx 5/19/01 to make polearms only random, add new size weapons, & add //short/long bows & arrows
#include <std.h>

inherit "/d/common/inherit/wpn_storage_full.c";
object ob;

void create() {
   ::create();
   set_property("no teleport",1);
   set_short("Offestry Weapons Storage");
   set_long("Offestry Weapons Storage. You probably shouldn't be here.");
}

void reset() {
::reset();
if(!present("double bladed sword"))
new("/d/common/obj/weapon/double_bladed_sword")->move(TO);
if(!present("double axe"))
new("/d/common/obj/weapon/double_axe")->move(TO);
  if(!present("lance")) {
  switch(random(3)) {
      case 0:
        new("/d/common/obj/weapon/mhlance")->move(TO);
         break;
      case 1:
        new("/d/common/obj/weapon/lhlance")->move(TO);
         break;
      case 2:
        new("/d/common/obj/weapon/hhlance")->move(TO);
         break;
   }
  }
  if(ob=present("obsidian shortsword")) ob->remove();
  if(ob=present("obsidian shortsword")) ob->remove();
  if(ob=present("shortsword 2")) ob->remove();
  if(ob=present("shortsword 2")) ob->remove();
  if(ob=present("obsidian long sword")) ob->remove();
  if(ob=present("obsidian long sword")) ob->remove();
  if(ob=present("medium spear 2")) ob->remove();
  if(ob=present("medium spear 2")) ob->remove();
}
