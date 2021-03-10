//removed hint that prompted players to type <free the slaves> since no such function exists ~Circe~ 7/24/19
#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>
#include "/d/common/common.h"

inherit VAULT;
int weapons, armor, chest;

void create(){
    weapons = 1;
    armor = 1;
    chest = 1;
    ::create();
    set_name("mound13");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_short("%^BOLD%^%^WHITE%^A Large Chamber%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This chamber is obviously some sort of preparation chamber for matches"+
             " that are to take place in the %^BOLD%^%^RED%^arena %^BOLD%^%^WHITE%^to the south. All"+
             " along the walls are %^BOLD%^%^BLACK%^cages %^BOLD%^%^WHITE%^with different %^BOLD%^%^YELLOW%^races %^BOLD%^%^WHITE%^which"+
             " will be utilized to fight for the pleasure of the pleasure of the creatures here. The floor"+
             " is cold here, but is very hard and the room is well maintained."+
             " \n\n%^BOLD%^%^YELLOW%^Along the wall are also a %^BOLD%^%^RED%^weapons %^BOLD%^%^YELLOW%^rack"+
             " and an %^BOLD%^%^RED%^armor %^BOLD%^%^YELLOW%^rack. Along with the racks, there is an"+
             " old %^BOLD%^%^RED%^chest %^BOLD%^%^YELLOW%^sitting between them.");

    set_smell("default","\n%^BOLD%^%^BLACK%^The smell stench of rotting food within this lair.%^RESET%^");
    set_listen("default","%^RESET%^%^RED%^You hear yips and barks from down the hall.%^RESET%^");
    set_search("default","What is it you wish to search?");
    set_search("weapons",(:TO,"searchingweap":));
    set_search("armor",(:TO,"searchingarm":));
    set_search("chest",(:TO,"searchingchest":));
    set_exits(([
		"west" : MOUND"tunnel4",
		"south"	: MOUND"mound14",
	]));
	set_items(([
      "arena" : "%^RESET%^%^RED%^Through the gate to the south you see what looks to be a large dirt area, obviously some sort of fighting pit.",
      "cages" : "%^RESET%^%^ORANGE%^Different cages are filled with slaves of many races, some in horrific condition.%^RESET%^",
      "races" : "%^BOLD%^%^YELLOW%^There are elves, humans, gnomes, and halflings filling these cages.",
      "weapons" : "%^BOLD%^%^YELLOW%^This rack contains weapons of various types and sizes.",
      "armor" : "%^BOLD%^%^RED%^This is a rack that contains different styles and types of armor.",
      "chest" : "%^BOLD%^%^WHITE%^This chest seems to contain a few vials of healing potions.",
   ]) );
	set_door("gate","/d/antioch/greaterantioch/rooms/mound/mound14","south","somekey");
	set_open("gate",0);
	set_string("gate","open","%^RESET%^%^BLUE%^The massive metal gate rises and you hear barks and snarls coming from the south.");
    set_string("gate","close","%^RESET%^%^BLUE%^The massive metal gate shuts heavily as the chains release the strain.");
    set_door_description("gate","These are two huge solid wooden doors that
come together in the middle. They are bound together with giant dwarven
forged iron bands.");
    lock_difficulty("gate",-2000,"lock");
}

void searchingweap() {
   object ob;
if(!weapons) {
      write("%^BOLD%^%^BLACK%^You realize you've taken all the weapons available...you hope this is enough.");
      return;
   }
   else{
 write("%^BOLD%^%^YELLOW%^You find various mundane weapons on the rack!");
         tell_room(TO,"%^BOLD%^%^YELLOW%^"+TPQCN+" searches through various weapons on the rack%^RESET%^.",TP);
         ob = new("/d/common/obj/weapon/dagger.c")->move(TO);
         ob = new("/d/common/obj/weapon/flail.c")->move(TO);
         ob = new("/d/common/obj/weapon/longsword.c")->move(TO);
         ob = new("/d/common/obj/weapon/two_hand_sword.c")->move(TO);
         ob = new("/d/common/obj/weapon/halberd.c")->move(TO);
         ob = new("/d/common/obj/weapon/whip.c")->move(TO);
         ob = new("/d/common/obj/weapon/lance.c")->move(TO);
         ob = new("/d/common/obj/weapon/mstaff.c")->move(TO);
      }
      weapons = 0;
}

void searchingarm() {
   object ob;
if(!armor) {
      write("%^BOLD%^%^BLACK%^You realize you've taken all the armor available...you hope this is enough.");
      return;
   }
   else{
 write("%^BOLD%^%^YELLOW%^You find various mundane armors on the rack!");
         tell_room(TO,"%^BOLD%^%^YELLOW%^"+TPQCN+" searches through various armors on the rack%^RESET%^.",TP);
         ob = new("/d/common/obj/armour/banded.c")->move(TO);
         ob = new("/d/common/obj/armour/coif.c")->move(TO);
         ob = new("/d/common/obj/armour/greaves.c")->move(TO);
         ob = new("/d/common/obj/armour/robe.c")->move(TO);
         ob = new("/d/common/obj/armour/studded.c")->move(TO);
         ob = new("/d/common/obj/armour/srobe.c")->move(TO);
         ob = new("/d/common/obj/armour/shelm.c")->move(TO);
         ob = new("/d/common/obj/armour/lrobe.c")->move(TO);
         ob = new("/d/common/obj/armour/gauntlets.c")->move(TO);
         ob = new("/d/common/obj/armour/greaves.c")->move(TO);
      }
      armor = 0;
}

void searchingchest() {
   object ob;
if(!chest) {
 write("%^BOLD%^%^BLACK%^You find nothing.");
      return;
   }
   else{
 write("%^BOLD%^%^YELLOW%^You find some random things stuffed in the chest!");
         tell_room(TO,"%^BOLD%^%^YELLOW%^"+TPQCN+" finds random things stuffed in the chest%^RESET%^.",TP);
         ob = new("/d/common/obj/potion/healing");
         ob->set_uses(random(10)+15);
         ob->move(TO);
         ob = new("/d/common/obj/potion/healing");
         ob->set_uses(random(10)+15);
         ob->move(TO);
         ob = new("/d/magic/comp_bag.c")->move(TO);
         ob = new("/d/magic/psi_comp_bag.c")->move(TO);
         RANDTREAS->find_stuff(TO,"component",3);
         RANDTREAS->find_stuff(TO,"component",3);
         RANDTREAS->find_stuff(TO,"component",3);
         RANDTREAS->find_stuff(TO,"component",3);
         RANDTREAS->find_stuff(TO,"component",3);
         RANDTREAS->find_stuff(TO,"component",3);
         RANDTREAS->find_stuff(TO,"component",3);
         RANDTREAS->find_stuff(TO,"component",3);
         RANDTREAS->find_stuff(TO,"component",3);
         RANDTREAS->find_stuff(TO,"psi_component",3);
         RANDTREAS->find_stuff(TO,"psi_component",3);
         RANDTREAS->find_stuff(TO,"psi_component",3);
         RANDTREAS->find_stuff(TO,"psi_component",3);
         RANDTREAS->find_stuff(TO,"component",3);
      }
      chest = 0;
}

void reset(){
 ::reset();
	if(!present("slave"))
		new(MON+"slave")->move(this_object());
}

