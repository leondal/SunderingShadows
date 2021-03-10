#include <std.h>

inherit "/d/dagger/tonovi/slave/slaveinh.c";

void create(){
    ::create();
    set_name("elven slave");
    set_id( ({"elf", "elven slave", "slave"}) );
    set_short("Elven Slave");
    set_long(
      "This elf has been sold as a slave in the plaza of Tonovi.  Ripped from his home in the Dagger forest, he shows the scars of whippings to try to tame this fierce warrior to serve a master."
    );
    set_price(20000);
    set_max_hp(200);
    set_hp(query_max_hp());
    set_hd(19,1);
    set_class("fighter");
    set_mlevel("fighter", 19);
    set_property("full attacks", 1);
    set_gender("male");
    if(random(2)) set_gender("female");
    set("race", "elf");
    set_body_type("humanoid");
    set_size(2);
    set_stats("strength", 14);
    set_stats("constitution", 11);
    set_stats("dexterity", 16);
    set_stats("intelligence", 11);
    set_stats("charisma", 11);
    set_stats("wisdom", 11);
    set_alignment(4);
}
