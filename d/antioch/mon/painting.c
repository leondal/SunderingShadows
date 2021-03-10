#include "/d/antioch/areadefs.h"
inherit "/std/monster";
void create() {
     ::create();
     set_name("painting guard");
     set_id( ({ "a painting guard", "painting", "guard" }) );
     set_short("A painting guard");
     set_long("He sits here with dignity, showing his loyalty to Ignatius.");
     set_level(7);
     set_alignment(6);
     set("class", "fighter");
     set("race", "undead");
     set_hd(7,0);
     set_gender("male");
     set_body_type("elf");
     set_hp(300);
     set_exp(600);
     set_wielding_limbs( ({"right hand"}) );
     new("/d/antioch/weapon/paintbrush.c")->move(this_object());
     command("wield paintbrush");
 }
