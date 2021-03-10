#include <std.h>
inherit ROOM;

init() {
    ::init();
    add_action("ring", "knock");
}
void create(){
    object ob;
    ::create();
    set_property("indoors",1);
    set_property("light",1);
    set_short("%^RED%^The Inner Haven of the Shades of Death%^RESET%^.");
    set_long(
@PACK
%^RED%^This is the Inner Haven of the Illuminati%^RESET%^.
As you enter this room you are struck at how organized it is. There are many candles burning brightly around the room. You see a closed door at the far end. To your right you see a desk and chair. Ahead of you there is a couch for you to sit in comfort while you wait.
PACK
    );
    set_property("no teleport",1);
    set_property("no attack",1);
    set_property("no steal",1);
    set_items(([
	"door" : "There is a small door at the far end and it looks only big enough for an elf to fit through. There is a sign on the door.",
	"desk" : "This desk is made of a dark wood. On top of it you see a name plate that reads: %^BOLD%^%^BLUE%^Mayana Vasquez, Product Control Officer%^RESET%^.",
    "couch" : "This couch is a deep %^RED%^red%^RESET%^ colour. There is the symbol of the %^RED%^Illuminati%^RESET%^ woven into the fabric. The symbol depicts two women with crossed swords standing by eachother, coloured black and gold. ",
     "sign" : "The sign reads: %^BOLD%^%^BLUE%^Signet ring creation room. NO ADMITTANCE!%^RESET%^",
      ]));
    set_exits(([
	"out":"/d/guilds/pack/hall/main"
      ]));
    set_smell("default", "The burning of the candles gives off a strong scent of burning flesh.");
    set_listen("default", "You can hear murmuring of voices and soft laughter.");
}
void reset(){
    ::reset();
    if(!present("mayana")){
	new("/realms/zerina/mon/mayana")->move(this_object());
    }
}

int ring() {
    tell_object(this_player(),
      "%^BOLD%^%^BLUE%^You knock on the door.%^RESET%^");
    tell_room(environment(this_player()),
      (string)this_player()->query_cap_name()+" knocks on the door.",
      ({ this_player() }) );
    call_out("restore_ring",5);
    return 1;
}

int restore_ring() {
    object ring;
    tell_object(this_player(),
      "%^BOLD%^%^BLUE%^A graceful elf enters and offers you a new Signet ring on a velvet cushion.%^RESET%^ ");
    tell_room(environment(this_player()),
      "%^BOLD%^%^BLUE%^The female elf enters and gives "+
      (string)this_player()->query_cap_name()+" a new signet ring.",
      ({ this_player() }) );
    ring = new("/d/guilds/pack/obj/ring");
    ring->move(this_player());
    return 1; 
}
