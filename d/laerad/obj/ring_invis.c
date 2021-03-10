//Coded by Bane//
#include <std.h>
inherit ARMOUR;
int uses;
void create(){
    ::create();
    set_id(({"ring","jade ring","jade"}));
    set_name("ring of invisibility");
    set_short("A jade ring");
   set("lore",
	"A fantastic looking jade ring. Easily worth thousands of gold "+
	"this rare beauty radiates a magical aura. A large gem sits "+
	"embedded in it, a fog appears to be swirling around hypnotically "+
	"in the gem. An inscription can be seen on the inside of the band."
    );
   set_long("This ring is made out of a solid piece of carved jade that is an exquisitely dark green, almost black. It is easily worth a small fortune.");
    set_type("ring");
    set_ac(0);
    set_property("enchantment",0);
    set_weight(1);
    set_value(10000);
    set_limbs( ({"right hand","left hand"}) );
    set_remove( (: TO,"remove_ring" :) );
    set_wear( (: TO,"wer_ring" :) );
    uses = random(10)+7;
}
void init(){
    ::init();
    add_action("read_ring","read");
    add_action("invisible","invisible");
    add_action("visible","visible");
}
int read_ring(string str){
    if(!str) notify_fail("Read What?");
    if(str != "ring") return 0;
    write("This is a Ring of Invisibility. To use its abilities type "+
	"either 'invisible' or 'visible'.");
    return 1;
}
int invisible(string str){
    if(query_worn()){
    if((int)this_player()->query_magic_hidden()){
    	notify_fail("You are already invisible.\n");
	return 0;
    }
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    TP->set_magic_hidden(1);
    uses--;
    return 1;
    }
    write("You have to be wearing the ring to do that.\n");
    return 1;
}
int visible(string str){
    if(query_worn()){
    if(!this_player()->query_magic_hidden()){
 	notify_fail("You are already visible.\n");
	return 0;
    }
    TP->set_magic_hidden(0);
    return 1;
    }
    write("You have to be wearing the ring to do that.\n");
    return 1;
}
int remove_ring(){
    if(ETO->query_magic_hidden()){
         ETO->set_magic_hidden(0);
	return 1;
    }
    return 1;
}
int wer_ring(){
    if(uses < 1){
        write("The ring is out of uses.\nIt dissappears from your hand.");
        if(!TO->remove()) destruct(TO);
	return 0;
    }
    return 1;
}
int drop(){
}
int give(){
}

int query_uses() { return uses; }
