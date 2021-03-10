#include <std.h>

inherit MONSTER;
object query_slave();

void create(){
    ::create();
    set_name("Boris");
    set_short("Boris the slave master");
    set_id( ({"boris", "master", "slave master", "slave seller", "merchant"}) );
    set_long(
      "This fat ugly man is the head master of the entire slave trade of Tonovi.  A giant slob, this man revels in the despair he causes others by selling off the elven slaves of Tonovi.  He looks at you as you look at him, and smiles.  Want to buy a slave? he casually asks you."
    );
    set_alignment(3);
    set_gender("male");
    set_race("human");
    set_hd(10, 1);
    set_max_hp(100);
    set_hp(query_max_hp());
}

void init(){
    ::init();
    add_action("buy_slave", "buy");
}

int buy_slave(string str){
    object slave, master, control, ob;
    int price;
    
    if(!str) return notify_fail("Buy what?\n");
    if(str != "slave") return notify_fail("Buy what?\n");

    slave = query_slave();
    control = new("/d/dagger/tonovi/slave/controlob.c");
    master = TP;
    price = slave->query_price();
    if(!TP->query_funds("gold", price)) {
      tell_object(TP, "The salesman gives you a cold stare...  It'll cost ya "+price+" gold buddy!");
      return 1;
    }
    TP->use_funds("gold", price);
    if(ob = present("controlob", master)){
      tell_room(ETO, "%^BOLD%^As the slave master brings another slave for you, they suddenly look at each other, knock you down, and start running!");
      (ob->query_sl_ob())->escape_master();
      slave->move(ETO);
      slave->escape_master();
      control->remove();
      ob->remove();
      return 1;
    }
    control->set_master(master);
    slave->set_master(master);
    control->set_sl_ob(slave);
    slave->set_controller(control);
    control->move(master);
    slave->move(ETO);
    tell_room(ETO, "Ahh, another satisfied customer.");
    return 1;
}

object query_slave(){
    object ob;

    switch(random(100)){
      case 0..75:
        ob = new("/d/dagger/tonovi/slave/slave3.c");
        break;
      case 76..90:
        ob = new("/d/dagger/tonovi/slave/slave2.c");
        break;
     default:
        ob = new("/d/dagger/tonovi/slave/slave1.c");
        break;
    }
    return ob;
}
