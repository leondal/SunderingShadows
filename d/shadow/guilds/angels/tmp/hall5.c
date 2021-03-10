// removing board and protections since the guild is long dead *Styx*  4/3/03
//Coded by Bane//
#include <std.h>
inherit ROOM;
// object ob;
void create(){
    ::create();
    set_property("indoors",0);
    set_property("light",2);
    set_terrain(RUINS);
    set_travel(RUBBLE);
    set_name("An old courtyard");
    set_short("An old courtyard");
    set_long(
	"You have walked into an old courtyard.  Large stone walls and "+
	"rusty iron gates surround the castle.  The cobblestones are worn "+
	"away and coming loose from the ground.  Black clouds roll across "+
	"the sky above, a flash of lightning appears every minute or "+
	"so, illuminating the courtyard."
    );
/*    set_property("no teleport",1);
    set_property("no steal",1);
    set_property("no bump",1);
*/
    set_listen("default","The shrieking wind pierces your ears.");
    set_smell("default","The wind is clean and refreshing.");
    set_exits( ([
	"east":"/d/shadow/guilds/angels/tmp/hall3"
    ]) );
}

/*
void init(){
    ::init();
    if((string)TP->query_guild() == "Fallen Angel"){
    add_action("read","read");
    add_action("return_belt","returnbelt");
    set_name("Fallen Angels courtyard");
    set_short("Fallen Angels courtyard");
    set_long(
        "You have stepped into the courtyard of this tremendous "+
        "stronghold.  Large stone walls and iron gates surround "+
        "the fortress keeping out enemy forces.  The cobblestones "+
        "have been worn away with time.  Black clouds roll across "+
        "the sky above, a flash of lightning appears every minute or "+
	"so, illuminating the courtyard.  A signpost sits near the entrance "+
	"to the fortress."
    );
    } else {
    set_name("An old courtyard");
    set_short("An old courtyard");
    set_long(
	"You have walked into an old courtyard.  Large stone walls and "+
	"rusty iron gates surround the castle.  The cobblestones are worn "+
	"away and coming loose from the ground.  Black clouds roll across "+
	"the sky above, a flash of lightning appears every minute or "+
	"so, illuminating the courtyard."
    );
    }
}
int read(string str){
    if(!str) return notify_fail("Read what?\n");
    if("signpost" != str) return 0;
    write("If you need another belt type <returnbelt> and someone will bring you another.");
    return 1;
}
int return_belt(){
    tell_object(TP,"You shout, 'I need another belt!'");
    tell_room(ETO,""+TP->query_cap_name()+" shouts, 'I need another belt!'",TP);
    call_out("getting",5,TP);
    return 1;
}
int getting(){
    tell_object(TP,"A small man darts into the courtyard, gives you another belt and disappears back into the shadows.");
    tell_room(ETO,"A small man darts into the courtyard, gives "+TP->query_cap_name()+" another belt and disappears back into the shadows.",TP);
    ob=new("/d/shadow/guilds/angels/belt");
    ob->move(TP);
    return 1;
}
*/

void reset(){
    ::reset();
    if(!present("flagg")){
	new("/d/shadow/guilds/angels/tmp/mon/flagg")->move(this_object());
	return 1;
    }
}
