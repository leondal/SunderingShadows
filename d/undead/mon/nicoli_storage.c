#include "../undead.h"
inherit "/std/obj/fence_store_int";

void create(){
    ::create();
    set_short("Graez thief guild storage room");
    set_long("Better get out of here before the immortals find you.");
    set_exits(([
      "out":TOWN"thieves",
    ]));
}

void reset(){
    object ob;
    ::reset();
        
    if(!present("sheath")) new("/d/tharis/obj/wrist_sheath")->move(TO);
    if(!present("sheath 2")) new("/d/tharis/obj/wrist_sheath")->move(TO);
    if(random(10) < 5 && !present("bag"))
      new("/d/tharis/obj/bpowder")->move(TO);
    if(random(20) < 12 && !present("poison")) {
      new("/cmds/thief/poison")->move(TO);
      new("/cmds/thief/poison")->move(TO);
    }
    if(!random(2) && !present("scroll 3")){
        ob = new("/d/magic/scroll");
        ob->set_spell(4);
        ob->move(TO);
    }
    if(!random(25) && !present("rweapon")) {
      ob = new("/d/common/obj/special/sp_randwpn");
      ob->move(TO);
      ob->remove_property("enchantment");
      ob->set_property("enchantment",random(3)+1);
    }
    while(ob = present("kit")) ob->remove();
    if(ob = present("rod")) ob->remove();
    while(!present("bright white 3")) {
      ob = new ("/d/common/obj/potion/extra_heal");
      ob->set_uses(15 + random(5));
      ob->move(TO);
    }
}
